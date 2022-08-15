#!/bin/bash
make re
make clean
rm resources/players/akilk.filler
mv akilk.filler resources/players/
echo "done"
cd resources  && ./filler_vm -f ./maps/map00 -p1 players/carli.filler -p2 players/akilk.filler
