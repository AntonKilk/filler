#!/bin/bash
# Script for quick first game vs superjeannot on small map
make re
make clean
cd resources  && ./filler_vm -f ./maps/map00 -p1 players/superjeannot.filler -p2 ../akilk.filler