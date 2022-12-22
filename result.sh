#! /usr/bin/env bash
# before running this script, please enter `chmod +x result.sh`

source .config;

echo "creating header for $RESULT_NAME";
echo $RESULT_HEADER > $RESULT_NAME;

for name in ${NAMES[@]}; do
  output_name="output/test/$name.log";
  echo "cat $output_name >> $RESULT_NAME";

  cat $output_name >> $RESULT_NAME;
done
