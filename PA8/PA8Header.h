/*
	Jonathan Smoley
	PA8: Header file
	CPSC121 Spring 2021
	Header file to store libraries,
		global constants, and the
		13 function prototypes for
		functions used in main().
*/

#ifndef PA8HEADER
#define PA8HEADER

#include <iostream> //for IO
#include <iomanip> //for formatting output
#include <ctime> //for seeding random number generator with time
#include <cstdlib> //for rand()
#include <string> //for string data type and member functions like getline()

using namespace std;

// global constant variables
const int BOARD_SIZE = 5, MAX_INVENTORY_SIZE = 10, NUM_TILE_TYPES = 4;
const int CLEAR_VALUE = ' ', PLAYER_MARKER = '@', NUM_LOOT_ITEMS = 10;
const int TILE_TYPES[] = {'+', '-', '~', '='};
const int LOOT_LIST_VALUES[NUM_LOOT_ITEMS][2] = { {30, 0}, {25, 0}, {27, 0}, {15, 0}, {45, 0}, {25, 1}, {33, 1}, {30, 1}, {45, 1}, {37, 1} };
const string LOOT_LIST_DESCRIPTIONS[NUM_LOOT_ITEMS] = {"Sword", "Axe", "Bow", "Dagger", "Holy Hand Grenade", "Guantlets", "Chain mail", "Helmet", "Body Armor", "Shield"};

// function prototypes
void displayBoard(char board[][BOARD_SIZE], int rows, int cols, int currRow, int currCol);
char generateTile(void);
void initBoard(char board[][BOARD_SIZE], int rows, int cols);
char menuPrompt(void);
void displayBoardPosition(char board[][BOARD_SIZE], int currRow, int currCol);
void displayPlayerStats(int playerStats[3]);
void displayInventoryStats(int playerCurrentInventoryStats[][2], string inventoryDescription[MAX_INVENTORY_SIZE], int numItems);
void displayScore(int score);
void updateStats(int playerStats[3], int playerCurrentInventoryStats[][2], int& currentInventoryCount, string inventoryDescription[MAX_INVENTORY_SIZE], int randomlyGeneratedLootIndex);
bool validateMove(int newPosition);
bool fightMonster(int playerStats[3], int playerCurrentInventoryStats[][2], int monsterStats[2], int numItems, char board[][BOARD_SIZE], int currRow, int currCol);
void wipeInventory(int playerCurrentInventoryStats[][2], string inventoryDescription[MAX_INVENTORY_SIZE], int& currentInventoryCount);
void clearTile(char board[][BOARD_SIZE], int currRow, int currCol);
void displayEndSequence(int gameScore);

#endif

