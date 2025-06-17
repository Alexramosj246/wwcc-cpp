#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Location{
	BASEMENT,
	OLD_HOTEL,
	DOWNTOWN,
};

enum class playerInventory{
	USE = 1,
	DROP,
	CANCEL,
};

enum class Direction{
	NORTH,
	EAST,
	SOUTH,
	WEST
};


class Player{
private:
	string name;
	string context;
	int health;
	vector<string> inventory;
	int x, y;


public:
	Player(string n, string c, int h, const vector<string>& inv) 
		: name(n), context(c), health(h), inventory(inv), x(0), y(0) {}


	string getName() const{ return name; }
	void setName(const string& newName) {name = newName; }

	int getHealth() const { return health; }
	int& getHealth() {return health; }
	void takeDamageHealth(int amount);
	void restoreHealth(int amount);
	
	string getContext() const {return context; }

	vector<string>& getInventory() {return inventory; }
	const vector<string>& getInventory() const { return inventory; }

	int getX() const { return x; }
	int getY() const { return y; }

	void move (Direction dir){
		switch (dir){
			case Direction::NORTH: y++;
			break;
			case Direction::SOUTH: y--;
			break;
			case Direction::EAST: x++;
			break;
			case Direction::WEST: x--;
			break;
		}
	}

	void showPosition() const {
		cout << "Current Position: (" << x << ", " << y << ")\n";
	}
};


void printIntro();
void startGame();
void gameLoop();
void loadSceneFromFile();
void loadMapFromFile(const Player& player);


void playerName(Player& player);

void showPlayerHealth(const Player& player);
void handleInventory(Player& player);
void movePlayer(Player& player);


#endif