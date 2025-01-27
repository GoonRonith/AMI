#! /bin/bash

foo(){
    echo "foo is called"
}

foo

add(){
    a=1
    b=2
    c=$(($a+$b))
    echo "sum of $a and $b is:$c"
}

add


sub(){
    a=$1
    b=$2
    c=$(($a-$b))
    echo "substraction of $a and $b is:$c"
}

sub 10 5
