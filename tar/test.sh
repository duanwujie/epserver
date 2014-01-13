#!/bin/bash


if [ $1 == 0 ]
then
        ./atar cf test.tar test/
else
        ./atar xf test.tar
fi
