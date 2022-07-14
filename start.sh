#!/bin/bash
make re
make clean
rm resources\ 2/players/akilk.filler
mv akilk.filler resources\ 2/players/
echo "done"
cd resources\ 2  && ./filler_vm -f ./maps/map01 -p1 players/champely.filler -p2 players/akilk.filler
