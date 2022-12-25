#! /usr/bin/env bash
# before running this script, please enter `chmod +x build.sh`

source config.sh;

# argument
# [$1]: CXX
# [$2...]: CXXFLAGS
#
if [ $# -ge 1 ]; then
  CXX=$1;
fi

if [ $# -ge 2 ]; then
  CXXFLAGS="${@:2} $CXXFLAGS";
fi

echo "using CXX compiler and CXXFLAGS:";
$CXX $CXXFLAGS --version;

if [ $? -ne 0 ]; then
  echo "CXX compiler is not found";
  exit 1;
fi

[ ! -d "bin" ] && mkdir "bin";
[ ! -d "bin/test" ] && mkdir "bin/test";
[ ! -d "bin/test/insert" ] && mkdir "bin/test/insert";
[ ! -d "bin/test/search" ] && mkdir "bin/test/search";

for name in ${BUILD_NAMES[@]}; do
  source_name="test/$name.cpp";
  binary_name="bin/test/$name";

  echo "compiling: $CXX $CXXFLAGS" \
       "$source_name -o $binary_name";

  if $CXX $CXXFLAGS $source_name -o $binary_name; then
    echo "succeeded: $source_name";
  else
    echo "failed: $source_name";
    exit 1;
  fi
done
