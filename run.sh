#! /usr/bin/env bash
# before running this script, please enter `chmod +x run.sh`

FROM=10;
TO=30;

NAMES=(
  "insert/bptree"
  "search/bptree"
);

mkdir "output";
mkdir "output/test";
mkdir "output/test/insert";
mkdir "output/test/search";

for name in ${NAMES[@]}; do
  output_name="output/test/$name.log";
  > $output_name;

  do_skipping=0;
  for (( size=$FROM; size<=$TO; size++ )); do
    binary_name="bin/test/$name";
    echo "testing: $binary_name $size $do_skipping" \
         ">> $output_name";

    $binary_name $size $do_skipping >> $output_name;
    do_skipping=$?;
  done
done

./result.sh
