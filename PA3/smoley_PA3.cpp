/*
Name: Jonathan Smoley
Class: CPSC 121, Spring 2021
Date: February 14, 20121
Programming Assignment: PA3
Description: This program runs 5 different tasks, each requesting input 
	from the user. Also, breaks given between tasks to split activities.
Notes: I utilized these sources: zyBooks Unit 2.14 & Unit 2.15,
	cppreference.com Ascii chart
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	
	// variables initialized
	string str = " ", letterGrade = " ", userStr = " ",
		task = "\n";
	int strIndex = 0, courses = 0, creditHrs = 0, totHrs = 0,
		num = 0, lineSum = 0, multiChoice = 0, i = 0;
	double gradePts = 0.0, averageGP = 0.0, topGP = 0.0;
		
/*
	Task 1: Ask user for a string & print each character on a new line
		using first a while loop then a for loop.
*/

	cout << "Task 1" << endl;
	cout << "********************************" << endl;
	cout << "Please enter a string:" << endl;
	getline(cin, str);
	
	// while loop version of solution
	cout << "While loop solution:" << endl;
	while(strIndex < str.length()) {
		cout << str.at(strIndex) << endl;
		strIndex++;
	}

	// for loop version of solution
	cout << "For loop solution:" << endl;	
	for(int i = 0; i < str.length(); i++) {
		cout << str.at(i) << endl;
	}
	cout << "\n" << endl;
	
	// prompt to separate tasks
	cout << "Press enter to continue..." << endl;
	getline(cin, task);
	
/*
	Task 2: Find the GPA for a student based on total grade points
		and credit hours received/taken.
*/

	cout << "Task 2" << endl;
	cout << "********************************" << endl;
	cout << "Please enter the number of courses: ";
	cin >> courses;
	
	// for loop to collect course information,
	// if statement to choose correct gradePts,
	// computation to add course-specific (gradePts * creditHrs)
	for(int j = 0; j < courses; j++) {
		cout << "Please enter the credit hours for course #" << j + 1
			<< ": ";
		cin >> creditHrs;		
		// sum of credit hours attempted
		totHrs += creditHrs;
		cout << "Please enter the letter grade for course #" << j + 1
			<< ": ";
		cin >> letterGrade;
		
		// copied from the table in the requirements
		if(letterGrade == "A") { 
			gradePts += 4.0;
		} else if(letterGrade == "A-"){
			gradePts += 3.7;
		} else if(letterGrade == "B+"){
			gradePts += 3.33;
		} else if(letterGrade == "B"){
			gradePts += 3.0;
		} else if(letterGrade == "B-"){
			gradePts += 2.7;
		} else if(letterGrade == "C+"){
			gradePts += 2.3;
		} else if(letterGrade == "C"){
			gradePts += 2.0;
		} else if(letterGrade == "C-"){
			gradePts += 1.7;
		} else if(letterGrade == "D+"){
			gradePts += 1.3;
		} else if(letterGrade == "D"){
			gradePts += 1.0;
		} else if(letterGrade == "D-"){
			gradePts += 0.7;
		} else {
			gradePts += 0.0;		
		}

		// sum for numerator of GPA computation
		topGP += gradePts * static_cast<double>(creditHrs);
		gradePts = 0;
		creditHrs = 0;
	}
	
	// calculates & prints the user's GPA
	averageGP = topGP / static_cast<double>(totHrs);
	cout << "Your GPA is: " << fixed << setprecision(2) << averageGP
		<< "\n" << endl;
	
	// prompt to separate tasks
	cout << "Press enter to continue..." << endl;
	getline(cin, task);
	getline(cin, task);
	
/*
	Task 3: Code a program that changes a lowercase string to an
	uppercase string using a while loop then a for loop & w/o
	using external library functions.
*/
	cout << "Task 3" << endl;
	cout << "********************************" << endl;
	cout << "Enter a lowercase string (it may contain spaces and punctuation): ";
	getline(cin, userStr);

	// Part 1 While loop solution
	cout << "While loop solution:" << endl;
	while(i < userStr.length()) {
		if(userStr.at(i) >= 97 && userStr.at(i) <= 122) {
			userStr.at(i) -= 32;
		}
		i++;
	}

	// prints the uppercase version of the user's string
	cout << "Your string converted to uppercase: " << userStr << endl;
	
	// Part 2 For loop solution
	cout << "For loop solution:" << endl;
	for(i = 0; i < userStr.size(); i++) {
		if(userStr.at(i) >= 97 && userStr.at(i) <= 122) {
			userStr.at(i) -= 32;
		}
	}
	
	// prints the uppercase version of the user's string
	cout << "Your string converted to uppercase: " << userStr
		<< "\n" << endl;	

	// prompt to separate tasks
	cout << "Press enter to continue..." << endl;
	getline(cin, task);
	
/*
	Task 4: Ask the user for a number & then print each number from 1 to
	the given number, printing each number as many times as its value.
*/
	cout << "Task 4" << endl;
	cout << "********************************" << endl;
	cout << "Please enter a number: ";
	cin >> num;
	
	// Part 1: just the numbers
	cout << "Part 1:" << endl;
	for(int n = 1; n <= num; n++) {   // outer for loop for new lines
		for(int c = 1; c <= n; c++) { // inner for loop for row contents
			cout << n;
		}
		cout << "\n";
	}
	cout << "\n" << endl;
	
	// Part 2: numbers + sum of the line
	cout << "Part 2:" << endl;
	for(int n = 1; n <= num; n++) {
		for(int c = 1; c <= n; c++) {
			cout << n;
			lineSum = lineSum + n;
		}
		cout << " " << lineSum <<"\n";
		lineSum = 0;
	}
	cout << "\n" << endl;
	
	// prompt to separate tasks
	cout << "Press enter to continue..." << endl;
	getline(cin, task);
	getline(cin, task);	
	
/*
	Task 5: Print a game menu; where choosing options 1-4 link
	back to the menu & option 5 ends the loop (else it loops forever).
*/
	cout << "Task 5" << endl;
	cout << "********************************" << endl;
	
	// do-while loop to produce said menu indefinitely
	do {
		// actual Game menu - prints after each decision
		cout << "Please choose from the following menu (1-5)" << endl;
		cout << "1) Display Game Rules & Description" << endl;
		cout << "2) Display General Game Commands" << endl;
		cout << "3) See High Scores" << endl;
		cout << "4) Play a New Game" << endl;
		cout << "5) Quit" << endl;
		cin >> multiChoice;
		
		// if statements for when an option is chosen
		if(multiChoice == 1) {
			cout << "\nDisplay Game Rules & Description\n" << endl;
		}
		if(multiChoice == 2) {
			cout << "\nDisplay General Game Commands\n" << endl;
		}
		if(multiChoice == 3) {
			cout << "\nSee High Scores\n" << endl;
		}
		if(multiChoice == 4) {
			cout << "\nPlay a New Game\n" << endl;
		}	
		if(multiChoice == 5) {
			cout << "\nQuit\n" << endl;
			break; // exits loop immediately
		}
	}
	while(multiChoice < 6);
	
	return 0;
}
