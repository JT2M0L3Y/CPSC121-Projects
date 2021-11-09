/*
Name: Jonathan Smoley
Class: CPSC 121, Spring 2021
Date: February 7, 20121
Programming Assignment: PA2
Description: This program runs a quiz to see 
	if the user is a fan of the content area.
Notes: I utilized this source url: Coding Standard.pdf,
	PA2.pdf
*/

#include <iostream>
#include <string>

using namespace std;

int main () {

	int score = 0;
	int numAnswer = 0;
	int intLogicAnswer = 0;
	bool boolLogicAnswer = false;
	string multiAnswer;
	
	cout << "Welcome to the General Knowledge Quiz!!" << endl;
	
	cout << "1) How many Olympic gold medals does Michael Phelps have?"
	 << "Give a number." << endl;
	cin >> numAnswer;
	
	/*
		The if-else function for each question evaluates the user input
		of the answer variable and produces a response on whether the
		user got the answer correct/incorrect. If correct, score is
		incremented upwards by 1.
	*/
	
	if (numAnswer == 23) {
		cout << "That is correct!\n" << endl;
		score += 1;
	}
	else {
		cout << "That is incorrect, Phelps has 23 Olympic gold medals.\n" << endl;
	}
	
	cout << "2) How many elements are there in the periodic table?\n"
		<< "Give a number." << endl;
	cin >> numAnswer;
	
	if (numAnswer == 118) {
		cout << "That is correct!\n" << endl;
		score += 1;
	}
	else {
		cout << "That is incorrect, there are 118 elements.\n" << endl;
	}
	
	cout << "3) True or False? Spaghetto is the singular form of Spagetti.\n"
		<< "Give your answer as a 1 for true or a 0 for false." << endl;
	cin >> intLogicAnswer;
	
	if (static_cast<bool>(intLogicAnswer) == 1) {
		cout << "That is correct!\n" << endl;
		score += 1;
	}
	else {
		cout << "That is incorrect, the statement is actually True.\n" << endl;
	}
	
	cout << "4) True or False? There are 219 episodes of the tv show Friends.\n"
		<< "Give your answer as a 1 for true or a 0 for false." << endl;
	cin >> intLogicAnswer;
	
	if (static_cast<bool>(intLogicAnswer) == 0) {
		cout << "That is correct!\n" << endl;
		score += 1;
	}
	else {
		cout << "That is incorrect, the statement is false"
		<< " as are 236 episodes of Friends.\n" << endl;
	}
	
	cout << "5) What is the 100th digit of Pi?\n"
		<< "Give your answer as A, B, C, or D.\n" << "A) 9\nB) 4\nC) 7\nD) 2"
		<< endl;
	cin >> multiAnswer;
	
	if (multiAnswer == "C") {
		cout << "That is correct!\n" << endl;
		score += 1;
	}
	else {
		cout << "That is incorrect, the answer is C) 7.\n" << endl;
	}
	
	cout << "6) What is considered the rarest form of color Blindness?\n"
		<< "Give your answer as A, B, C, or D.\n" 
		<< "A) Blue\nB) Red\nC) Green\nD) Purple" << endl;
	cin >> multiAnswer;
	
	if (multiAnswer == "A") {
		cout << "That is correct!\n" << endl;
		score += 1;
	}
	else {
		cout << "That is incorrect, the answer is A) Blue.\n" << endl;
	}
	
	cout << "7) In The Little Mermaid, how many sisters does Ariel have?\n"
		<< "Give your answer as a number." << endl;
	cin >> numAnswer;
	
	if (numAnswer == 6) {
		cout << "That is correct!\n" << endl;
		score += 1;
	}
	else {
		cout << "That is incorrect, Ariel has 6 sisters in The Little Mermaid.\n"
			<< endl;
	}
	
	cout << "8) True or False? Broccoli was once banned from the White House.\n"
		<< "Give your answer as a 1 for true or a 0 for false." << endl;
	cin >> intLogicAnswer;
	
	if (static_cast<bool>(intLogicAnswer) == 1) {
		cout << "That is correct!\n" << endl;
		score += 1;
	}
	else {
		cout << "That is incorrect. The answer is false"
			<< " as Broccoli was banned in 1990 by George H.W. Bush.\n"
			<< endl;
	}
	
	cout << "9) How many seeds does an average strawberry have?\n"
		<< "Give your answer as A, B, C, D.\n"
		<< "A) 500\nB) 200\nC) 100\nD) 85" << endl;
	cin >> multiAnswer;
	
	if (multiAnswer == "B") {
		cout << "That is correct!\n" << endl;
		score += 1;
	}
	else {
		cout << "That is incorrect, the answer is B) 200.\n" << endl;
	}
	
	cout << "10) How many men did Jesus Christ appoint to be his apostles?\n"
		<< "Give your answer as a number." << endl;
	cin >> numAnswer;
	
	if (numAnswer == 12) {
		cout << "That is correct!\n" << endl;
		score += 1;
	}
	else {
		cout << "That is incorrect, Jesus appointed 12 apostles originally.\n" << endl;
	}
	
	cout << "Thank you for participating, your score is: " << score << "/10.\n" 
		<< endl;
	
	/*
		The if-else if-else statement takes in the overall score,
		after all the questions have been answered, and presents 
		the user with a comment on their level of knowledge about
		the content of the quiz.
	*/
	
	if (score > 5) {
		cout << "You have quite a bit of general knowledge.\n" << endl;
	}
	else if ((score <= 5) && (score > 0)) {
		cout << "You know some stuff, but not enough for this quiz.\n" << endl;
	}
	else {
		cout << "You need to study up on general knowledge.\n" << endl;
	}
}
