# filler

Filler is a game, where you need to fill the board with your territory over enemy’s territory. On every move you get a tetris-like figure that looks like one of these:

Your task is to “attach” it to your territory so that only one cell of territory crosses the new figure.
In the end you need to put your figures in that way that your territory is bigger than the opponent’s one.
I created a simple algorithm - go over all opportunities to attach a new piece to territory and choose the one that is closest to enemy’s territory. That is to minimize enemy’s possibilities for move and stop him growing the territory.
Here is the example game play:

![filler](https://github.com/AntonKilk/filler/blob/master/img/filler.gif)
