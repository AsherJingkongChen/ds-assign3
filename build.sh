#! /usr/bin/env bash
# before running this script, please enter `chmod +x run.sh`

# arguments
# [$1]: CXX and CXXFLAGS
#
if [ $# -ge 1 ]; then
  CXX=$1;
else
  CXX="g++";
fi

CXX_FLAGS="-std=c++14 -O3 -Wall";
NAMES=(
  "create_result_header"
  "bptree"
);

echo "checking CXX compiler";
$CXX --version;

mkdir "bin";
mkdir "bin/test-m";

for name in ${NAMES[@]}; do
  source_name="test-m/$name.cpp";
  binary_name="bin/test-m/$name";
  echo "compiling: $CXX $CXX_FLAGS" \
       "$source_name -o $binary_name";

  if $CXX $CXX_FLAGS $source_name -o $binary_name; then
    echo "succeeded: $source_name";
  else
    echo "failed: $source_name";
  fi
done
