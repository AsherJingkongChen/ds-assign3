#! /usr/bin/env bash
# before running this script, please enter `chmod +x run.sh`

FROM=10;
TO=16;

NAMES=(
  "bptree"
);

for name in ${NAMES[@]}; do
  output_name="output/test/$name.log";
  > $output_name;
((i=1;i<=END;i++))
  for (( size=$FROM; size<=$TO; size++ )); do
    binary_name="bin/test/$name";
    echo "testing $name with size in 2 power of $size";

    ($binary_name $size) 2>&1 | tee -a $output_name;
  done
done

for name in ${NAMES[@]}; do
  # cat TODO
done
