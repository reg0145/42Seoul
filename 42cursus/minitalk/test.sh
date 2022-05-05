#! /bin/bash
for var in {1..10000}
do
  ./client $1 $var 
done
