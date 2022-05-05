#! /bin/bash
for var in {1..200000}
do
  ./test_pid &
done
