#! /usr/bin/env bash
# before running this script, please enter `chmod +x onepass.sh`

[ ! -d "log" ] && mkdir "log";

echo "(./build.sh g++-12 > log/build.sh.log) &&";
echo "(./run.sh > log/run.sh.log) &&";
echo "(./summary.sh > log/summary.sh.log);";

(./build.sh g++-12 > log/build.sh.log) && \
(./run.sh > log/run.sh.log) && \
(./summary.sh > log/summary.sh.log);
