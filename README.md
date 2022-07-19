# filler

Filler is a game, where you need to fill the board with your territory over the enemy’s territory. On every move you get a Tetris-like figure that looks like one of these:
Your task is to “attach” it to your territory so that only one cell of territory crosses the new figure. In the end, you need to put your figures in such a way that your territory is bigger than the opponent’s one. I created a simple algorithm - go over all opportunities to attach a new piece to territory and choose the one that is closest to the enemy’s territory. That is to minimize the enemy’s possibilities for the move and stop him from growing the territory. 

Here is an example of a gameplay:

![filler](https://github.com/AntonKilk/filler/blob/master/img/filler.gif)

To use it, clone the repo and:
- do `make`. After that  run a virtual machine with a map and players like this: `./filler_vm -f ./maps/map00 -p1 players/carli.filler -p2 players/akilk.filler` or:
- run a script `bash start.sh` to install and run one game.
