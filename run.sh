#! /usr/bin/env bash
# before running this script, please enter `chmod +x run.sh`

source .config;

# check timeout command
#
echo "using timeout command:";
timeout --version;

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

for name in ${NAMES[@]}; do
  output_name="output/test/$name.log";
  > $output_name;

  is_first_skip=1;
  do_skipping=0;
  for (( size=$FROM; size<=$TO; size++ )); do
    binary_name="bin/test/$name";

    # insert: may timeout
    # search: may timeout
    #
    case "$name" in
      insert*)
        echo "testing: timeout $TIMEOUT_SECOND $binary_name" \
             "$size $do_skipping >> $output_name";

        timeout $TIMEOUT_SECOND \
        $binary_name $size $do_skipping >> $output_name;
      ;;

      search*)
        echo "testing: timeout $TIMEOUT_SECOND $binary_name" \
             "$size $do_skipping >> $output_name";

        timeout $TIMEOUT_SECOND \
        $binary_name $size $do_skipping >> $output_name;
      ;;
    esac

    do_skipping=$?;

    # remedy the output at first timeout
    #
    if [ $is_first_skip -eq 1 ] && 
       [ $do_skipping   -ne 0 ]; then

      timeout $TIMEOUT_SECOND \
      $binary_name $size $do_skipping >> $output_name;

      is_first_skip=0;
    fi
  done
done
