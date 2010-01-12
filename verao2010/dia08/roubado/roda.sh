#!/bin/bash

for ARQ in *.in
do
  ./$1 < $ARQ > $(basename $ARQ .in).out
done
