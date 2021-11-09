/*
	CPSC 121
	PA8 - Adventure Game
	Jonathan Smoley
	Spring 2021
	This game was built as an addition 
		to the given starter code for
		PA8. It formulates an adventure
		game for the user to play.
*/

#include "PA8Header.h"

int main()
{
	// variable declaration block
	int gameScore = 0, currentInventoryCount = 0, currRow = 0, currCol = 0;
	int monsterChance = 0, monsterStats[2];
	int randomlyGeneratedLootIndex = 0, playerStats[3] = {100, 50, 0};
	int playerCurrentInventoryStats[MAX_INVENTORY_SIZE][2];
	char choice = '\0';
	char board[BOARD_SIZE][BOARD_SIZE];
	bool validMove = false, displayInventory = false;
	bool isMonster = false, wonFight = false;
	string inventoryDescription[MAX_INVENTORY_SIZE] = {"Empty", "", "", "", "", "", "", "", "", ""};
	
	//initialize our game board with randomly generated tiles
	initBoard(board, BOARD_SIZE, BOARD_SIZE);
	
	do
	{
		srand(time(NULL)); // seeds the rand() for truly random numbers
		displayScore(gameScore); // outputs game score before each action
		displayPlayerStats(playerStats); // shows current playerStats[] values
		displayBoard(board, BOARD_SIZE, BOARD_SIZE, currRow, currCol); // outputs current game board
		displayBoardPosition(board, currRow, currCol); // tells current position
		choice = menuPrompt(); // provides list of actions user can take
		
		switch(choice)
		{
		case 'u':
			// moves up
			currRow--;
			validMove = validateMove(currRow); // requests move validation
			if(validMove == false)
			{
				currRow++;
			}
			system("clear");
			break;
		case 'd':
			// moves down
			currRow++;
			validMove = validateMove(currRow); // requests move validation
			if(validMove == false)
			{
				currRow--;
			}
			system("clear");
			break;
		case 'l':
			// moves left
			currCol--;
			validMove = validateMove(currCol); // requests move validation
			if(validMove == false)
			{
				currCol++;
			}
			system("clear");
			break;
		case 'r':
			// moves right
			currCol++;
			validMove = validateMove(currCol); // requests move validation
			if(validMove == false)
			{
				currCol--;
			}
			system("clear");
			break;
		case 'i':
			// displays player inventory
			displayInventoryStats(playerCurrentInventoryStats, inventoryDescription, currentInventoryCount);
			cout << "Press Enter To Continue...";
			cin.ignore(256, '\n');
			cin.get();
			system("clear");
			break;
		case 's':
			// searchs a tile, checks if tile is already cleared
			if(board[currRow][currCol] != CLEAR_VALUE)
			{
				// creates 50% chance that a monster is found
				isMonster = rand() % 2;
				if(isMonster == 1)
				{
					// creates random health and attack values of monster
					monsterStats[0] = static_cast<int>((static_cast<double>(rand() % 15 + 1) / 10) * playerStats[0]);
					monsterStats[1] = static_cast<int>((static_cast<double>(rand() % 10 + 1) / 10) * playerStats[1]);
					
					// status update on player and monster stats
					cout << "Player Health: " << playerStats[0] << endl;
					cout << "Player Attack/Defense: " << playerStats[1] 
						<< "/" << playerStats[0] + playerStats[2] << endl;
					cout << "Monster Health/Attack: " << monsterStats[0] 
						<< "/" << monsterStats[1] << endl;
					cout << "Result: " << endl;
					
					// runs fight between player and monster & returns player's status
					wonFight = fightMonster(playerStats, playerCurrentInventoryStats, monsterStats, currentInventoryCount, board, currRow, currCol);
					
					if(wonFight == true) // if player survives
					{
						cout << "You have slain the monster!" << endl;
						// clears inventory of player after a fight
						wipeInventory(playerCurrentInventoryStats, inventoryDescription, currentInventoryCount);
						clearTile(board, currRow, currCol);
						gameScore += 10; // add to overall score
						
						// wait for player to continue game
						cout << "Press Enter To Continue...";
						cin.ignore(256, '\n');
						cin.get();
						system("clear");
						break;
					}
					else if(wonFight == false) // if player is slain by monster
					{
						cout << "You succumbed to the monster's might!" << endl;
						choice = 'q'; // exit loop before next iteration
						break;
					}
				}
				else if(isMonster == 0)
				{
					// update for when a monster is not found
					cout << "No monster was found." << endl;
					updateStats(playerStats, playerCurrentInventoryStats, currentInventoryCount, inventoryDescription, randomlyGeneratedLootIndex);
					cout << "You found a " 
					<< inventoryDescription[currentInventoryCount - 1] 
					<< ". (strength: " 
					<< playerCurrentInventoryStats[currentInventoryCount - 1][0] 
					<< ", Defensive? ";
					if(playerCurrentInventoryStats[currentInventoryCount - 1][1] == 1)
					{
						cout << "Yes)" << endl;
					}
					else
					{
						cout << "No)" << endl;
					}
					clearTile(board, currRow, currCol);
					gameScore += 10; // increment overall score with high point value
					
					// wait for player to continue game
					cout << "Press Enter To Continue...";
					cin.ignore(256, '\n');
					cin.get();
					system("clear");
					break;
				}
			}
			else if(board[currRow][currCol] == CLEAR_VALUE) // check if tile is clear
			{
				system("clear");
				break;
			}
		case 'c':
			// clears a tile, checks if tile is already cleared
			if(board[currRow][currCol] != CLEAR_VALUE)
			{
				isMonster = rand() % 10 + 1;
				if(isMonster == 3)
				{
					// random health and attack values for monster
					monsterStats[0] = static_cast<int>((static_cast<double>(rand() % 15 + 1) / 10) * playerStats[0]);
					monsterStats[1] = static_cast<int>((static_cast<double>(rand() % 10 + 1) / 10) * playerStats[1]);
					
					// player and monster stat update
					cout << "Player Health: " << playerStats[0] << endl;
					cout << "Player Attack/Defense: " << playerStats[1] 
						<< "/" << playerStats[0] + playerStats[2] << endl;
					cout << "Monster Health/Attack: " << monsterStats[0] 
						<< "/" << monsterStats[1] << endl;
					cout << "Result: " << endl;
					
					// run the fight between player and monster
					wonFight = fightMonster(playerStats, playerCurrentInventoryStats, monsterStats, currentInventoryCount, board, currRow, currCol);
					
					if(wonFight == true)
					{
						cout << "You have slain the monster!" << endl;
						// clears the inventory after a fight
						wipeInventory(playerCurrentInventoryStats, inventoryDescription, currentInventoryCount);
						clearTile(board, currRow, currCol);
						gameScore++; // adds low points to overall score
						
						// wait for player to continue playing game
						cout << "Press Enter To Continue...";
						cin.ignore(256, '\n');
						cin.get();
						system("clear");
						break;
					}
					else if(wonFight == false) // if player is slain by monster
					{
						cout << "You succumbed to the monster's might!" << endl;
						choice = 'q';
						break;
					}
				}
				else
				{
					// when monster is not found at current tile
					cout << "No monster was found." << endl;
					updateStats(playerStats, playerCurrentInventoryStats, currentInventoryCount, inventoryDescription, randomlyGeneratedLootIndex);
					cout << "You found a " 
					<< inventoryDescription[currentInventoryCount - 1] 
					<< ". (strength: " 
					<< playerCurrentInventoryStats[currentInventoryCount - 1][0] 
					<< ", Defensive? ";
					if(playerCurrentInventoryStats[currentInventoryCount - 1][1] == 1)
					{
						cout << "Yes)" << endl;
					}
					else
					{
						cout << "No)" << endl;
					}
					clearTile(board, currRow, currCol);
					gameScore++;
					// wait for player to continue game
					cout << "Press Enter To Continue...";
					cin.ignore(256, '\n');
					cin.get();
					system("clear");
					break;
				}
			}
			else if(board[currRow][currCol] == CLEAR_VALUE) // check if tile is clear
			{
				system("clear");
				break;
			}
		}
		system("clear"); // basic final clear after each iteration as a buffer
	} while(choice != 'q');
	
	// clears console for final time before showing final message
	system("clear");
	
	//displays game results
	displayEndSequence(gameScore);

	return 0;
}
