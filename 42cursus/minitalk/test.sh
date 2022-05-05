#! /bin/bash
for var in {1..10}
do
	./client $1 $var & 
done
