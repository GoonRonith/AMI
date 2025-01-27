#!/bin/bash

#code1
# echo "Positive Negative check"
# read -p "Enter a number: " n

# if [ "$n" -gt 0 ]
# then
#     echo "positive"
# else
#     echo "negative"
# fi


#code2

echo "Odd Even Program"
read -p "Enter a number: " n
if [ $((n % 2)) -eq 0 ]
then
echo "Even"
else
echo "Odd"
fi