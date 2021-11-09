/*
	Jonathan Smoley
	PA8: Definitions file
	CPSC121 Spring 2021
	Function definitions file that is
		linked to the prototypes in
		the header file. Thus, these
		are called into use in main().
*/

#include "PA8Header.h"

/**************************************************************
Function: displayBoard()
Date Created: 4/10/21
Date Last Modified: 4/12/21
Description: outputs current board with player position and
	cleared tiles shown
Input parameters: board[][BOARD_SIZE], rows, cols, currRow,
	currCol
Returns: N/A
**************************************************************/
void displayBoard(char board[][BOARD_SIZE], int rows, int cols, int currRow, int currCol)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			if(i == currRow && j == currCol)
			{
				cout << static_cast<char>(PLAYER_MARKER);
			}
			else
			{
				cout << board[i][j];
			}	
		}
		cout << endl;
	}
}

/**************************************************************
Function: generateTile()
Date Created: 4/10/21
Date Last Modified: 4/10/21
Description: chooses a random tile type out of 4
Input parameters: N/A
Returns: TILE_TYPES[randIndex]
**************************************************************/
char generateTile(void)
{
	int randIndex = rand() % NUM_TILE_TYPES;
	return TILE_TYPES[randIndex];
}

/**************************************************************
Function: initBoard()
Date Created: 4/10/21
Date Last Modified: 4/10/21
Description: outputs starting board by calling random tiles
	and sorting them into a 2D array
Input parameters: board[][BOARD_SIZE], rows, cols
Returns: N/A
**************************************************************/
void initBoard(char board[][BOARD_SIZE], int rows, int cols)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			board[i][j] = generateTile();
		}
	}
}

/**************************************************************
Function: menuPrompt()
Date Created: 4/10/21
Date Last Modified: 4/10/21
Description: outputs list of actions the player can take
Input parameters: N/A
Returns: N/A
**************************************************************/
char menuPrompt(void)
{
	char choice = '\0';
	cout << "Pick a direction to move in:" << endl;
	cout << "Directions: (u)p, (d)own, (l)eft, (r)ight " << endl;
	cout << "Actions: (s)earch tile, (c)lear tile" << endl;
	cout << "Options: (i)nventory, (q)uit" << endl;
	cin >> choice;
	return choice;
}

/**************************************************************
Function: readDouble()
Date Created: 4/10/21
Date Last Modified: 4/12/21
Description: outputs current player position under player marker
Input parameters: board[][BOARD_SIZE], currRow, currCol
Returns: N/A
**************************************************************/
void displayBoardPosition(char board[][BOARD_SIZE], int currRow, int currCol)
{
	
	cout << "Current Tile: " << board[currRow][currCol] << endl;
}

/**************************************************************
Function: displayPlayerStats()
Date Created: 4/10/21
Date Last Modified: 4/11/21
Description: outputs player's health, attack, and defense from
	a singluar 1D array
Input parameters: playerStats[3]
Returns: N/A
**************************************************************/
void displayPlayerStats(int playerStats[3])
{
	cout << "Health: " << playerStats[0] << " Attack: " << playerStats[1] 
		<< " Defense: " << playerStats[2] << endl;
}

/**************************************************************
Function: displayInventoryStats()
Date Created: 4/10/21
Date Last Modified: 4/13/21
Description: outputs inventory of player if requested
Input parameters: playerCurrentInventoryStats[][2], 
	inventoryDescription[MAX_INVENTORY_SIZE], numItems
Returns: N/A
**************************************************************/
void displayInventoryStats(int playerCurrentInventoryStats[][2], string inventoryDescription[MAX_INVENTORY_SIZE], int numItems)
{
	for(int i = 0; i < numItems; i++)
	{
		cout << inventoryDescription[i] << " - strength: " << playerCurrentInventoryStats[i][0] << " Defensive: ";
		if(playerCurrentInventoryStats[i][1] == 1)
		{
			cout << "Yes" << endl;
		}
		else if(playerCurrentInventoryStats[i][1] == 0)
		{
			cout << "No" << endl;
		}
	}
}

/**************************************************************
Function: displayScore()
Date Created: 4/110/21
Date Last Modified: 4/11/21
Description: outputs new score value after an iteration in main
Input parameters: score
Returns: N/A
**************************************************************/
void displayScore(int score)
{
	cout << "Current Score: " << score << endl;
}

/**************************************************************
Function: updateStats()
Date Created: 4/10/21
Date Last Modified: 4/13/21
Description: adds loot to collection of parallel arrays used
Input parameters: playerStats[3], playerCurrentInventoryStats[][2],
	numItems, inventoryDescription[MAX_INVENTORY_SIZE]
Returns: N/A
**************************************************************/
void updateStats(int playerStats[3], int playerCurrentInventoryStats[][2], int& currentInventoryCount, string inventoryDescription[MAX_INVENTORY_SIZE], int randomlyGeneratedLootIndex)
{
	srand(time(NULL));	
	
	randomlyGeneratedLootIndex = rand() % NUM_LOOT_ITEMS;
	
	playerCurrentInventoryStats[currentInventoryCount][0] = LOOT_LIST_VALUES[randomlyGeneratedLootIndex][0];
	
	playerCurrentInventoryStats[currentInventoryCount][1] = LOOT_LIST_VALUES[randomlyGeneratedLootIndex][1];
	
	if(playerCurrentInventoryStats[currentInventoryCount][1] == 1)
	{
		playerStats[2] += playerCurrentInventoryStats[randomlyGeneratedLootIndex][0];
	}
	else if(playerCurrentInventoryStats[currentInventoryCount][1] == 0)
	{ 
		playerStats[1] += playerCurrentInventoryStats[randomlyGeneratedLootIndex][0];
	}
	
	inventoryDescription[currentInventoryCount] = LOOT_LIST_DESCRIPTIONS[randomlyGeneratedLootIndex];
	
	currentInventoryCount++;
}

/**************************************************************
Function: validateMove()
Date Created: 4/10/21
Date Last Modified: 4/12/21
Description: decides if a user moves to a place on the board
Input parameters: newPosition
Returns: logical value to boolean validMove
**************************************************************/
bool validateMove(int newPosition)
{
	if(newPosition == BOARD_SIZE || newPosition < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

/**************************************************************
Function: fightMonster()
Date Created: 4/10/21
Date Last Modified: 4/13/21
Description: runs fight mechanism and returns result of fight
Input parameters: playerStats[3], playerCurrentInventoryStats[][2],
	numItems, board[][BOARD_SIZE], currRow, currCol
Returns: bool wonFight
**************************************************************/
bool fightMonster(int playerStats[3], int playerCurrentInventoryStats[][2], int monsterStats[2], int numItems, char board[][BOARD_SIZE], int currRow, int currCol)
{
	bool playerState = false;
	
	cout << "Player attacks for " << playerStats[1];
	if(playerStats[1] >= monsterStats[0])
	{
		cout << " and the monster is slain!" << endl;
		playerStats[1] -= monsterStats[0];
		playerState = true;
	}
	else if(playerStats[1] < monsterStats[0])
	{
		cout << " but the monster survives!" << endl;
		cout << "Monster fights back and causes " << monsterStats[1] << " damage!" << endl;
		if(playerStats[1] >= monsterStats[1])
		{
			playerState = true;
		}
		else if(playerStats[2] < monsterStats[1])
		{
			if(playerStats[2] > 0)
			{
				playerStats[2] -= monsterStats[1];
			}
			else
			{
				playerStats[0] -= abs(playerStats[2]);
			}
			//playerStats[2] = 0;
			playerState = true;
		}
	}
	else if(playerStats[0] <= 0)
	{
		playerState = false;
	}
	
	return playerState;
}

/**************************************************************
Function: wipeInventory()
Date Created: 4/10/21
Date Last Modified: 4/13/21
Description: clears the inventory of player after a fight
Input parameters: playerCurrentInventoryStats[][2], 
	inventoryDescription[MAX_INVENTORY_SIZE]
Returns: N/A
**************************************************************/
void wipeInventory(int playerCurrentInventoryStats[][2], string inventoryDescription[MAX_INVENTORY_SIZE], int& currentInventoryCount)
{
	for(int i = 0; i < MAX_INVENTORY_SIZE; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			playerCurrentInventoryStats[i][j] = 0;
		}
		inventoryDescription[i] = "";
	}
	currentInventoryCount = 0;
}

/**************************************************************
Function: clearTile()
Date Created: 4/10/21
Date Last Modified: 4/12/21
Description: clears the board tile if action is requested
Input parameters: board[][BOARD_SIZE], currRow, currCol
Returns: N/A
**************************************************************/
void clearTile(char board[][BOARD_SIZE], int currRow, int currCol)
{
	board[currRow][currCol] = CLEAR_VALUE;
}

/**************************************************************
Function: displayEndSequence()
Date Created: 4/12/21
Date Last Modified: 4/12/21
Description: outputs end message if user quits or loses the game
Input parameters: gameScore
Returns: N/A
**************************************************************/
void displayEndSequence(int gameScore)
{
	cout << "Game Over!" << endl;
	cout << "Score: " << gameScore << endl;
}
