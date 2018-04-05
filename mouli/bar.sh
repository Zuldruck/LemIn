#! /bin/bash
max=100
min=0
if [[ $# -ne 1 ]]
then
    echo "bad argu"
    exit 1
fi

val=0
let "val = $1 * 20 / 100"
equal='='

echo -n $1 "% ["

i=0
while [[ $i -ne $val ]]
do
    echo -ne $equal
    let "i = i + 1"
done

while [[ $i -ne 20 ]]
do
    echo -ne " "
    let "i = i + 1"
done
echo "]"


exit 0
