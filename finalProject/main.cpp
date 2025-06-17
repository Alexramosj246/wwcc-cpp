#include "Game.h"
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/*
 * Interactive Story Game - [the Old Hotel]
 * Author: [Alejandro Ramos-Juarez]
 * Date: [06/17/2025]
 *
 * ==== Project Features ====
 * Variables (3+ types): Lines 183-187
 * If/else statements: Lines 131-142
 * Switch statement: Line 129, 237, 279, 296
 * For Loop: Line 92
 * While Loop: Line 44
 * Function w/ return: in game.h (line 57, 58)
 * Void function: Line 35-41
 * Function w/ params: Line 75-79
 * Vector usage: Lines 217
 * Struct/Class: in game.h (line 30)
 * Enum: in game.h (line 10-27)
 * File Reading: Lines 35-49
 * File Writing: none :(
 * Modern Feature (auto): Lines 84
 * Modern Feature none :(
 * ==========================
 */


void printIntro(){
	ifstream file("intro.txt");

	if (!file) {
		cerr << "Error: Could not open intro.txt\n";
		return;
	}

	string line;
	while (getline(file, line)) {
		cout << line << endl;
	}
	
	file.close();
}

void playerName(Player& player) {
	string name;
	cout << "Enter Character name:" << endl;
	getline(cin, name); 
	player.setName(name);
	cout << endl;
	cout << "Name: " << name << " \nObjective: Escape the McFlee Hotel!" << endl << endl;
}

void showPlayerHealth(const Player& player) {
	cout << endl;
	cout << "\n[Health Status] " << player.getName() << "'s health: " << player.getHealth() << " HP\n " << endl;
}

void Player::takeDamageHealth(int amount){
	health -= amount;
	if (health < 0){
		health = 0;
		cout << "You Died!";
	}
	cout << "Ouch! You took " << amount << " damage!" << endl;
	cout << getName() << " has: " << health << " HP left!" << endl;
}

void Player::restoreHealth(int amount){
	health += amount;
	if (health > 100){
		health = 100;
	}
	cout << "You restored: " << amount << " HP. Current health is now: " << health << " HP\n ";
}

void handleInventory(Player& player) {
	auto& inv = player.getInventory();
	cout << "\n===Inventory====\n";

	if (inv.empty()){
		cout << "You have nothing in your backpack!\n";
		return;
	}
	
	for (size_t i = 0; i < inv.size(); ++i){
		cout << i + 1 << ". " << inv[i] << '\n';
	}

	int itemChoice;
	cout << "\nSelect an item: ";
	cin >> itemChoice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (itemChoice == 0) {
		cout << "<You put your backpack away>" << endl;
		return;
	}

	if (itemChoice < 1 || static_cast<size_t>(itemChoice) > inv.size()){
		cout << "Invalid item selection.\n";
		return;
	}

	string selectedItem = inv[itemChoice - 1];

	int actionInput;
	cout << "\nWhat would you like to do with \"" << selectedItem << "\"?\n";
	cout << "1. Use\n";
	cout << "2. Drop\n";
	cout << "3. Cancel\n";
	cout << "Enter your choice: ";
	cin >> actionInput;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (actionInput < 1 || actionInput > 3) {
		cout << "Invalid Action!\n";
		return;
	}

	playerInventory action = static_cast<playerInventory>(actionInput);

	switch (action) {
		case playerInventory::USE:
			if (selectedItem == "Flashlight") {
				cout << "You turned on the Flashlight.";
			} else if (selectedItem == "Map") {
				cout << "<You opened the Map>";
			} else if (selectedItem == "Cigarettes"){
				cout << "\nI should stop lighting up...\n";
				player.takeDamageHealth(15);
			} else if (selectedItem == "Snickers bar"){
				player.restoreHealth(10);
				cout << "\nI wasn't myself there for a second.\n";
				inv.erase(inv.begin() + (itemChoice - 1));
			} else {
				cout << "You try to use the " << selectedItem << ", but nothing happens.\n";
			}
			break;
			case playerInventory::DROP: 
				cout << "You dropped the " << selectedItem << ".\n";
				inv.erase(inv.begin() + (itemChoice - 1 ));
				break;
			case playerInventory::CANCEL: 
				cout << "Action canceled!\n";
				break;
			default: 
				cout << "Invalid Action.\n";
				break;
	}

}

void loadSceneFromFile(){
	ifstream file("scenes/sceneNum1.txt");
		if (!file) {
		cerr << "Error: Could not open sceneNum1.txt\n";
		return;
	}

	string line;
	while (getline(file, line)){
		cout << line << endl;
	}

	file.close();
}

void loadMapFromFile(const Player& player) {
	ifstream file("scenes/scenes.txt");
	if (!file) {
		cerr << "Error: Could not open scenes.txt\n";
		return;
	}

	string line;
	int x = player.getX();
	int y = player.getY();
	string targetMarker = "# " + to_string(x) + " " + to_string(y);

	bool sceneFound = false;

	cout << "\n====Location Description====" << endl;

	while (getline(file, line)) {
		if (line == targetMarker) {
			sceneFound = true;
			while (getline(file, line) && (line.empty() || line[0] != '#')) {
				cout << line << endl;
			}
			break;
		}
	}

	if (!sceneFound) {
		cout << "There's nothing here.\n";
		player.showPosition();
	}

	cout << "=================================" << endl;
	file.close();
}

void lookAround(const Player& player) {
	cout << "\n=====Location====\n";
	player.showPosition();
}


void gameLoop(){
	vector<string> startingItems = {"Map", "Flashlight", "Snickers bar", "Fidget Spinner", "Cigarettes" };
	Player player("mainPlayer", "in a rainy night in Downtown Evergreen", 100, startingItems );

	printIntro();
	playerName(player);
	loadSceneFromFile();
	
	int command = 0;

	do {
		cout << "\n====Player Menu====" << endl;
		cout << "\n1. Move Player\n"
			<< "2. Open Backpack\n"
			<< "3. Show Health\n"
			<< "4. Look around\n"
			<< "5. Quit\n" 
			<< "Enter Command number: ";
		cin >> command;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (command) {
			case 1: movePlayer(player); 
			break;
			case 2: handleInventory(player); 
			break;
			case 3: showPlayerHealth(player); 
			break;
			case 4: lookAround(player);
			break;
			case 5: cout << "Exiting game...\n";
			break;
			default: cout << "Unknown command. Please enter numbers 1-5";
			break;
		}	
	} while (command != 5);
}

void startGame(){
	gameLoop();
}

//===========================================================
int main(){
	startGame(); 
	return 0;
}
//============================================================

void movePlayer(Player& player){
	int move = 0;

	cout << "\nWhat direction do you want to move? : " << endl;
	cout << "1. North\n";
	cout << "2. South\n";
	cout << "3. East\n";
	cout << "4. West\n";
	cout << "Enter your choice: " << endl;
	cin >> move;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Direction dir;

	switch (move){
		case 1: dir = Direction::NORTH;
		break;
		case 2: dir = Direction::SOUTH;
		break;
		case 3: dir = Direction::EAST;
		break;
		case 4: dir = Direction::WEST;
		break;
		default: 
			cout << "Invalid Choice!" << endl;
			return;
	}

	player.move(dir);

	cout << player.getName() << " moved ";
	switch (dir) {
		case Direction::NORTH: cout << "north.\n";
		break;
		case Direction::SOUTH: cout << "south.\n";
		break;
		case Direction::EAST: cout << "east.\n";
		break;
		case Direction::WEST: cout << "west.\n";
		break;
	}

	player.showPosition();
	loadMapFromFile(player);

}