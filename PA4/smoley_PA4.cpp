/*
	Jonathan Smoley
	CPSC 121, Spring 2021
	February 24, 20121
	PA4
	Make a program to play Craps that validates user input
	I utilized these sources: inputValidationAndPauseCLSExample.cpp
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	// variable declaration block
	int die1 = 0, die2 = 0, sumDice = 0, points = 0, wager = 0;
	int bankBalance = 0, sumDice2 = 0, initialWager = 0;
	char choice = '\0';

	srand(time(0));
	
	// do-while loop to run both menu and Craps rounds
	do
	{
		// repeated menu after each round of Craps is played
		cout << "Choose your course of action below:\n";
		cout << "To show game (r)ules type the letter 'r'.\n";
		cout << "To (p)lay the game Craps type the letter 'p'.\n";
		cout << "To (q)uit and exit this screen type the letter 'q'.\n";
		cout << endl;
		cin >> choice;
		
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a valid character option.\n" << endl;
			cin >> choice;
		}
		
		// outside switch to analyze menu options
		switch(choice)
		{
			// print out rules of the game
			case 'r':
				cout << "\nThese are the rules of Craps:" << endl;
				cout << "1) Two six sided dice are rolled." << endl;
				cout << "2) On the first roll, if the summed result is a\n" 
					<< "7 or 11 the player wins. If the result is a 2, 3,\n"
					<< " or 12 the player loses (the house wins)." << endl;
				cout << "3) However, if the summed result of the first\n"
					<< "throw is a 4, 5, 6, 8, 9, or 10, the sum is added\n"
					<< " to the player's point value." << endl;
				cout << "4) If the player progesses to later rolls, the\n"
					<< " player must roll a sum that equals their point\n"
					<< " value." << endl;
				cout << "5) Lastly, if in the stage of rolling to match a\n"
					<< " point value, the player loses if a 7 is rolled\n"
					<< " before that point value is rolled." << endl;
				cout << endl;
				break;
			// play craps in full	
			case 'p':
				cout << "Welcome to Craps!\n" << endl;
				cout << "Enter your starting bank balance: ";
				cin >> bankBalance;
				
				// validate user's bank balance
				if(bankBalance <= 0)
				{
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Enter a valid value for bank balance." << endl;
					cin >> bankBalance;
				}
				
				cout << "Enter a starting wager: ";
				cin >> initialWager;
				
				// validate user's initial wager
				if(initialWager >= bankBalance)
				{
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Enter a wager that you can back please." << endl;
					cin >> wager;
				}
				
				die1 = (rand() % 6) + 1;
				die2 = (rand() % 6) + 1;
				sumDice = die1 + die2;
				
				// inner while loop to control roll results
				while(sumDice)
				{
					// inner if-else if-else statement for roll result
					if(sumDice == 7 || sumDice == 11)
					{
						cout << "Sum: " << sumDice << " (Die1: " << die1
							<< " Die2: " << die2 << ")" << endl;
						cout << sumDice << "\nYou won!" << endl;
						bankBalance += initialWager;
					}
					else if(sumDice == 2 || sumDice == 3 || sumDice == 12)
					{
						cout << "Sum: " << sumDice << " (Die1: " << die1
							<< " Die2: " << die2 << ")" << endl;
						cout << sumDice << "\nYou lost!" << endl;
						bankBalance -= initialWager;
						break;
					}
					else
					{
						// inner while loop for point part of gameplay
						while(sumDice != points)
						{
							cout << "Sum: " << sumDice << " (Die1: " << die1
								<< " Die2: " << die2 << ")" << endl;
							points = sumDice;
						
							cout << "You need to roll to make your point ("
								<< sumDice << ")." << endl;
							
							cout << "Press enter to continue...\n";
							cin.ignore(256, '\n');
							cin.get();
						
							cout << "Total wager so far: $" << initialWager << endl;
							cout << "Available bank balance: $" 
								<< bankBalance - initialWager << endl;
							cout << "Increase, Decrease, or keep your current wager."
								<< endl;
							cin >> wager;
							
							// validate wager value
							if(wager >= (bankBalance - initialWager))
							{
								cin.clear();
								cin.ignore(256, '\n');
								cout << "Enter a wager that you can back please." << endl;
								cin >> wager;
							}
						
							die1 = (rand() % 6) + 1;
							die2 = (rand() % 6) + 1;
							sumDice = die1 + die2;
							
							// inner if statement for result of point roll
							if(sumDice == points)
							{
								cout << "Sum: " << sumDice << " (Die1: " 
									<< die1 << " Die2: " << die2 << ")"
									<< endl;
								cout << "\nYou won!" << endl;
								bankBalance += wager;
								initialWager += wager;
							}
							else if(sumDice == 7)
							{
								cout << "Sum: " << sumDice << " (Die1: " 
									<< die1 << " Die2: " << die2 << ")"
									<< endl;
								cout << "\nYou lost!" << endl;
								bankBalance -= wager;
								initialWager += wager;
								break;
							}
							else
							{
								cout << "Sum: " << sumDice << " (Die1: " 
									<< die1 << " Die2: " << die2 << ")"
									<< endl;
								cout << "\nYou did not get the point value ("
									<< sumDice << ")." << endl;
								initialWager += wager;
							}
						}
				}
				break;
			}
			// exit out of program/menu
			case 'q':
				cout << "Thanks for playing Craps today?\n" << endl;
				break;
		}
	} while(choice != 'q');

	return 0;
}
