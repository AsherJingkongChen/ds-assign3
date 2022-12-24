#! /usr/bin/env bash
# before running this script, please enter `chmod +x clear.sh`

[ -d "bin" ] && rm -r bin && echo "rm -r bin";
[ -d "log" ] && rm -r log && echo "rm -r log";
[ -d "output" ] && rm -r output && echo "rm -r output";
