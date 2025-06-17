# The Old Hotel

## How to Play
This game uses numbers to select your choice. 


## Story Synopsis

This is an escape game.
You the player are stuck in the basement of an old hotel in the city of Evergreen.


## Controls

- Enter numbers to make choices

## Features Implemented

List all C++ features used:
-Variables (3+ types)
-If/else statements
-Switch statement
-For Loop
-While Loop
-Function w/ return
-Void function
-Function w/ params
-Vector
-Struct/Class
-Enum
-File Reading
-Modern Feature (auto)


## File Structure

- main.cpp: Main game logic
- intro.txt: Game intro
- game.h : header file for declarations, definitions and classes. 
- scenes.txt: these are more like the in-game dialogue
- scenesNum1.txt : this is more like the cutscenes in a game. provides context.

## Challenges Faced

[Discuss any difficulties and how you solved them]
My difficulties was the file i/o.
At first I made a bunch of .txt files using dynamic file I/O
(example: scene_1_3.txt, scene_2_3.txt).
I ended up using one scene.txt in place of that.

Another dificulty is using pointers and "this->". I steered away from using that as I struggle to fully grasp the concept.

## Future Improvements

[What would you add with more time?]
I spent way to much on the way the characters position in a (x,y) map and how to handle the inventory.

I would work more in the actual storyline of the game and add to my inventory(pick up items). 
Have an actual ending with combat actions.
Better use of enum class.
Have a game summary as well with a save/load option. 


