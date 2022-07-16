#!/bin/bash
make re
make clean
rm resources\ 2/players/akilk.filler
mv akilk.filler resources\ 2/players/
echo "done"
cd resources\ 2  && ./filler_vm2 -f ./maps/map00 -p2 players/abanlin.filler -p1 players/akilk.filler
