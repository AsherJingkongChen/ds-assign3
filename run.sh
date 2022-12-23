#! /usr/bin/env bash
# before running this script, please enter `chmod +x run.sh`

source .config;

# check timeout command
#
echo "using timeout command:";
timeout --version;

[ ! -d "output" ] && mkdir "output";
[ ! -d "output/test" ] && mkdir "output/test";
[ ! -d "output/test/insert" ] && mkdir "output/test/insert";
[ ! -d "output/test/search" ] && mkdir "output/test/search";

for name in ${NAMES[@]}; do
  output_name="output/test/$name.log";
  > $output_name;

  do_skipping=0;
  for (( size=$FROM; size<=$TO; size++ )); do
    binary_name="bin/test/$name";
    echo "testing: timeout $TIMEOUT_SECOND $binary_name" \
         "$size $do_skipping" \
         ">> $output_name";

    timeout $TIMEOUT_SECOND \
    $binary_name $size $do_skipping >> $output_name;
    do_skipping=$?;
  done
done
