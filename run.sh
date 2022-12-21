#! /usr/bin/env bash
# before running this script, please enter `chmod +x run.sh`

FROM=10;
TO=30;

NAMES=(
  "bptree"
);

mkdir "output";
mkdir "output/test-m";

for name in ${NAMES[@]}; do
  output_name="output/test-m/$name.log";
  > $output_name;

  do_skipping=0;
  for (( size=$FROM; size<=$TO; size++ )); do
    binary_name="bin/test-m/$name";
    echo "testing: $binary_name $size $do_skipping" \
         ">> $output_name";

    $binary_name $size $do_skipping >> $output_name;
    do_skipping=$?;
  done
done

./get_result.sh
