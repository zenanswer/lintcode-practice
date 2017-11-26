#!/usr/bin/env bash

g++ -std=c++11 test$1.cpp -o test$1
if [ $? -eq 0 ]
then
  echo "==== Build success ===="
  ./test$1
  rm -fr ./test$1
else
  echo "==== Build failed ===="
fi
