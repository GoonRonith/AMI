#! /bin/bash
echo "current working directory:"
# #way1
# dir=`pwd`
# echo $dir

#way2
dir=$(pwd)
echo $dir

newFile=$(cat > new.txt)
echo $newFile
