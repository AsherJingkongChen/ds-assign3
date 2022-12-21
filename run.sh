#! /usr/bin/env bash
# before running this script, please enter `chmod +x run.sh`

for i in {10..16}; do
  ./bin/test-bptree $i;
done
