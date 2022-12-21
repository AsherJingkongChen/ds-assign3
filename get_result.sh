#! /usr/bin/env bash
# before running this script, please enter `chmod +x get_result.sh`

NAMES=(
  "bptree"
);

CREATE_RESULT_HEADER="bin/test-m/create_result_header";
RESULT_NAME="output/test-m/result.csv";
echo "creating header for $RESULT_NAME";
$CREATE_RESULT_HEADER > $RESULT_NAME;

for name in ${NAMES[@]}; do
  output_name="output/test-m/$name.log";
  echo "cat $output_name >> $RESULT_NAME";

  cat $output_name >> $RESULT_NAME;
done
