/*
Name: Jonathan Smoley
Class: CPSC 121, Spring 2021
Date: January 29, 2021
Programming Assignment: PA1
Description: This program computes the overall cost for a user's trip
through the use of the user's planned location, expenses, and time on
vacation.
Notes: I built off the starter code, making this my own.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	string origin, destination;
	int daysGone, hoursGone, numTickets;
	double ticketCost, rentalCost, dailyFoodCost;
	double subtotal, totalCost, dailyCost, serviceFee;
	
	// greeted the user and introduced the virtual agent
	cout << "Hello, this is your the Travel Budgeting Service!" << endl;
	cout << "My name is Piers and I need a vacation as much as you do." << endl;
	cout << endl;
	
	// asking for user's destination and affirming it with output
	cout << "Where are you wasting your money to travel to today?" << endl;
	cin >> destination;
	cout << endl;
	cout << "Really, " << destination << "?" << " That ain't worth it." << endl;
	cout << endl;
	
	// asking for user's origin and affiring it with output
	cout << "And what dump are you leaving to do so?" << endl;
	cin >> origin;
	cout << endl;
	cout << origin << " is much better than where you're going." << endl;
	cout << endl;
	
	// determining the length of the user's trip in days and hours
	cout << "Alright, how many days will you be gone for?" << endl;
	cin >> daysGone;
	hoursGone = daysGone * 24; // converts days of the trip to hours of the trip
	cout << endl;
	cout << "You must be rich cause " << hoursGone << " hours in " 
		<< destination << " is WAY out of my price range." << endl;
	cout << endl;
	
	// asks for cost of and number of tickets the user has and outputs them
	cout << "Do you have a wallet-busting price for a ticket to " 
		<< destination << "?" << endl;
	cin >> ticketCost;
	cout << endl;
	cout << "How many of these tickets have you purchased?" << endl;
	cin >> numTickets;
	cout << endl;
	cout << "Then it's " << numTickets << " tickets to " << destination 
		<< " at " << fixed << setprecision(2) << ticketCost << " dollars per ticket." << endl;
	cout << endl;
	
	// tells the user to input the price of a rental car and outputs the info
	cout << "I assume your royal laziness is planning to rent a car." << endl;
	cout << "How much is that per day?" << endl;
	cin >> rentalCost;
	cout << endl;
	cout << "For " << rentalCost << " that had better be some car." << endl;
	cout << endl;
	
	// the daily cost of food planned in requested and outputted
	cout << "Lastly, how much will you spend on food daily?" << endl;
	cin >> dailyFoodCost;
	cout << endl;
	cout << "You pig, at least bring me back some then." << endl;
	cout << endl;
	
	// tells user to wait and computes trip and service costs
	cout << "Allow me to organize this info for you!" << endl;
	cout << endl;
	subtotal = (ticketCost * numTickets) + (rentalCost * daysGone) 
		+ (dailyFoodCost * daysGone);
	dailyCost = subtotal / daysGone;
	serviceFee = pow(subtotal, (3.0 / 5.0));
	totalCost = subtotal + serviceFee;
	
	// notifies the user of tip costs and added service cost 
	cout << "Though I want to go too, I am glad I'm not paying a raw "
		<< fixed << setprecision(2) << subtotal << " dollars to go from\n" 
		<< origin << " to " << destination << "." << endl; 
	cout << "That is " << fixed << setprecision(2) << dailyCost << " dollars per day." << endl;
	cout << "With the expense for my services costing " << serviceFee 
		<< " dollars, you pay a total of\n" << fixed << setprecision(2) << totalCost 
		<< " for this trip." << endl;
	cout << endl;
	
	/*
	* Function: if ()
	* Date Created: 1/29/21
	* Date Last Modified: 1/29/21
	* Description: This function recalls the results of the serviceFee and subtotal
	* computations to check if the user is receiving a good deal on their trip.
	* Input parameters: serviceFee and subtotal as double variables.
	* Returns: A positive or negative statement depending of whether or not 
	* the service fee is greater than, equal to, or less than 4% of the subtotal.
	* Pre: The computer calls in the serviceFee and subtotal.
	* Post: The user is notified as to how good a deal they are receiving.
	*/
	
	if (serviceFee / subtotal >= (0.04 * subtotal)) {
		cout << "You can get a better deal if you spend more money!" << endl;
		cout << endl;
	}
	else {
		cout << "You sure are looking to waste money on this trip." << endl;
		cout << endl;
	}
	
	// ends interactions with the user
	cout << "Thank you for choosing this Travel Budgeting Service.\n"
	<< "Maybe now I can plan a trip for myself!" << endl;
	
	return 0;
}
