#! /usr/bin/env bash
# before running this script, please enter `chmod +x summary.sh`

source config.sh;

if [ ! -d "output" ] ||
   [ ! -d "output/test" ] ||
   ([ ! -d "output/test/insert" ] &&
    [ ! -d "output/test/search" ]); then

  echo "no output found, please run ./run.sh first";
  exit 1;
fi

[ ! -d "output/test/summary" ] && mkdir "output/test/summary";

summary_csv_name="output/test/summary/$SUMMARY_NAME.csv";

echo "creating CSV header for $summary_csv_name";
echo $SUMMARY_HEADER > $summary_csv_name;

for name in ${RUN_NAMES[@]}; do
  output_name="output/test/$name.log";

  echo "cat $output_name >> $summary_csv_name";
  cat $output_name >> $summary_csv_name;
done
