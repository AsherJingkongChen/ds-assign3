#! /usr/bin/env bash
# before running this script, please enter `chmod +x run.sh`

FROM=10;
TO=16;

NAMES=(
  "bptree" 
);

echo "running $NAMES with size in 2 power from $FROM to $TO";

for name in ${NAMES[@]}; do
  for size in {$FROM..$TO}; do
    (./bin/$name $size) 2>&1 >> data/$name.log
  done
done
