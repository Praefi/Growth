# Growth
An advanced game

I created this repository to work with some of my friends on the Game "Growth" which i wrote with sixteen days of Programming-Experience. I am a mathematic student with no focus on informatic and thats the reason why my code is just exploding and annoying for professionals, but it's the result of using almost all what i learned yet (in 16 days). Hoping to evolve this game to an app one day, i will try my best. What a pity that programming is a brand new world for me.
Uploading my project is hopefully the right step according to develop my idea without losing possesion.
P.S.: I am sorry for my english, i liked german as subject much more in school.

*************************************************************************************
If you try to play Growth_contact on the seperated website, you should read this:

What is Growth-Contact and how to play it?

Growth-contact is a cube-based 2D game for 2 persons. On the surface you can see a field of squares, each of them is in exactly one of the following, different coloured states:
	gray:	 The square is „dead“.
	yellow: The square belongs to player 1.
	purple: The square belongs to player 2.

The squares you own build your organism. After a players turn his/her organism takes one step of development, that means:
	A dead square having 3 squares of this player in the 8 squares surrounding it will turn
	into a players square.
	If a player's square has less than 2 or more than 3 other by him/her owned squares in the 	surrounding, it will return into a dead square.
This algorithim is not working step by step, so the development has no effect on itself.
Using this algorithim you have to reduce the number of your opponent's squares to zero. But how?

At the beginning of your turn you get a number which is bound to two options:
	1: Plus or Minus.
	2: Move or Change.
	3: Destroy or Revive.
	4: Move or Boost.
	5: 2-new or 4/5-new.
	6: 1-min or 4-max.

You can always skip the choice of an option, but what are the options saying?
Plus: Click on a square of yours. After that you can click on a dead square in its surrounding 	which will be owned by you now.
Minus: Click on a square of yours, it will be dead now.
Move: Click on a square of yours, after that you can click on a dead square having an edge with it 	together. The positions of these two squares will change now.
Change: Click on a square of yours, then click on a square of your opponent which is in its 	surrounding. These two squares will change positions now.
Destroy: Click on a square of yours, then click on a square of your opponent which is in its 	surrounding. The opponents square will be dead now.
Revive: Each square of yours, which will be dead after the development, having no squares of yours 	in its surrounding which were your squares before the development, will be yours again.
Boost: If a opponents square is in the surrounding of one of your squares, it will be counted as one 	of your squares in the development, but only in the step of creating new squares, not while 	looking for squares of yours to die.
2-new: The number of your squares surrounding a dead square for creating a new one changes from 	3 to 2 for the next step of development.
4/5-new: The number of your squares surrounding a dead square for creating a new one changes 	from 3 to 4/5 for the next step of development.
1-min: The minimum number of your squares which have to surround a square of yours changes 	from 2 to 1 for the next step of development.
4-max: The maximum number of your squares which are allowed to surround a square of yours 	changes from 3 to 4 for the next step of development.

Now it's time to reveal why the games titel has the part „contact“ in it:
	Every time a square of yours is touching a square of your opponent, the number of squares 	owned by a player which are connected to the touching one (which counts too) using same 	edges of his/her squares are count for each player.
	Then the player with the higher count gets the squares of the opponent, in the situation of 	equal counts nothing happens, except the number of squares is 1. In that case the active 	player, means the player which made the last turn, will win this battle.

Understanding the algorithim of development, playing this game will causes no troubles after a period of time.
If there are still questions, you are free to ask me.

***********************************************************************************************
