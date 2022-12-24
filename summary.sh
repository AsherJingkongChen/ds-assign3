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

echo "creating header for $RESULT_NAME";
echo $RESULT_HEADER > $RESULT_NAME;

for name in ${NAMES[@]}; do
  output_name="output/test/$name.log";
  echo "cat $output_name >> $RESULT_NAME";

  cat $output_name >> $RESULT_NAME;
done
