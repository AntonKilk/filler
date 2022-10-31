# filler

Filler is a game, where you need to fill the board with your territory over the enemy’s territory. On every move you get a Tetris-like figure that looks like one of these:
Your task is to “attach” it to your territory so that only one cell of territory crosses the new figure. In the end, you need to put your figures in such a way that your territory is bigger than the opponent’s one. I created a simple algorithm - go over all opportunities to attach a new piece to territory and choose the one that is closest to the enemy’s territory. That is to minimize the enemy’s possibilities for the move and stop him from growing the territory. 

Here is an example of a gameplay:

![filler](https://github.com/AntonKilk/filler/blob/master/img/filler.gif)

This is how initial board looks like in a console:

![image](https://user-images.githubusercontent.com/51739460/179686811-311bb1d5-2c7b-4ec9-95aa-41bafc98b81a.png)

Example of tokens:

![image](https://user-images.githubusercontent.com/51739460/179687031-18ebf811-a14e-45c8-89b3-7b5d014440be.png)

To use it, clone the repo and:
- do `make`. After that  run a virtual machine with a map and players like this: `./filler_vm -f ./maps/map00 -p1 players/carli.filler -p2 players/akilk.filler` or:
- run a script `bash start.sh` to install and run one game.
NB! The game is runnning in the console only. No visualizer applied.
