#! /bin/bash

if [ $# -ne 1 ]
then
	echo "USAGE: ./script.sh [prog lem]"
	exit 1
fi

mkdir report
rm -rf ./report/*

pourc=100
ant=42
room=4


./bar.sh 0

while [[ $pourc -ne 10 ]]
do
    timeout 5 ./gmin.pl $room $pourc $ant > map

    if [ $? -ne 124 ]
    then

	timeout 30 ./lem_in < map > /dev/null
	ret=$?


	if [ $ret -eq 124 ]
	then
	    echo -e "\033[31mtimeout 30 s\033[0m" "room" $room "pourc" $pourc
	    echo -e "\033[31mtimeout 30 s\033[0m" "room" $room "pourc" $pourc > ./report/report.log
	    cp map report/$pourc$room.map
	elif [[ ret -ne 0 ]]
	then
	    echo -e "\033[31mInvalid exit status\033[0m" $ret "room" $room "pourc" $pourc
	    cp map report/$pourc$room.map
	else
	    ret=0
	fi

    fi


    if [[ $room -eq 100 ]]
    then
	room=4
	let "pourc = pourc - 10"
	bar=0
	let "bar = 100 - pourc"
	./bar.sh $bar
    else
	let "room = room + 1"
    fi

done
