#! /usr/bin/env bash
# before running this script, please enter `chmod +x run.sh`

source config.sh;

# check timeout command
#
echo "using timeout command:";
timeout --version;

if [ $? -ne 0 ]; then
  echo "timeout command is not found";
  exit 1;
fi

if [ ! -d "bin" ] ||
   [ ! -d "bin/test" ] ||
   [ ! -d "bin/test/insert" ] ||
   [ ! -d "bin/test/search" ]; then

  echo "no executable found, please run ./build.sh first";
  exit 1;
fi

[ ! -d "output" ] && mkdir "output";
[ ! -d "output/test" ] && mkdir "output/test";
[ ! -d "output/test/insert" ] && mkdir "output/test/insert";
[ ! -d "output/test/search" ] && mkdir "output/test/search";

for name in ${RUN_NAMES[@]}; do
  output_name="output/test/$name.log";
  > $output_name;

  is_first_skip=1;
  do_skipping=0;
  for (( size=$FROM; size<=$TO; size++ )); do
    binary_name="bin/test/$name";

    echo "testing: timeout $TIMEOUT_SECOND $binary_name" \
          "$size $do_skipping >> $output_name";

    timeout $TIMEOUT_SECOND \
    $binary_name $size $do_skipping >> $output_name;

    do_skipping=$?;

    # remedy the output at timeout
    #
    if [[ $(tail -1 $output_name) != *"$size"* ]] && 
       [ $do_skipping -ne 0 ]; then

      echo "> remedy the output for this timeout";

      timeout $TIMEOUT_SECOND \
      $binary_name $size $do_skipping >> $output_name;

      is_first_skip=0;
    fi
  done
done
