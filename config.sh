#! /usr/bin/env bash
# before running this script, please enter `chmod +x config.sh`

chmod +x *.sh;

[ -f ~/.zshrc ] && source ~/.zshrc;
[ -f ~/.bashrc ] && source ~/.bashrc;
[ -f ~/.tcshrc ] && source ~/.tcshrc;
[ -f ~/.profile ] && source ~/.profile;
[ -f ~/.bash_profile ] && source ~/.bash_profile;

CXX="g++";

CXXFLAGS=\
"-std=c++17 \
-O3 \
-w";

PYTHON="python3";

RUN_NAMES=(
  "insert/array_of_sorted_arrays"
  # "insert/btree"
  # "insert/hashtable"
  # "insert/skiplist"
  # "insert/treap"
  # "search/array_of_sorted_arrays"
  # "search/btree"
  # "search/hashtable"
  # "search/skiplist"
  # "search/treap"
);

RUN_NAMES=(
  "${RUN_NAMES[@]}"
  "insert/L_array_of_sorted_arrays"
);

BUILD_NAMES=(
  "${RUN_NAMES[@]}"
);

FROM=16; TO=25;
TIMEOUT_SECOND="1h";

SUMMARY_HEADER=\
"structure_name,\
operation_name,\
size_in_2_power_of,\
time_in_millisecond";

SUMMARY_NAME="summary_L";
