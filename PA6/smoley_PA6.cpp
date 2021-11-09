/*
	Jonathan Smoley
	CPSC121 - Spring 2021
	PA6
	Purpose: Read in student data and process it for later output by
		utilizing file input/output and functions to organize tasks.
*/

#include <iostream> // for IO
#include <fstream> // for file IO
#include <string> // for getline()
#include <sstream> // for string streams
#include <iomanip> // to formulate ouput text
#include <cmath> // for pow()

using namespace std;

/**************************************************************
Function: readDouble()
Date Created: 3/15/21
Date Last Modified: 3/17/21
Description: Reads a double value from the input file.
Input parameters: ifstream& infile
Returns: double doubleValue
**************************************************************/
double readDouble(ifstream& infile);

/**************************************************************
Function: readInteger()
Date Created: 3/15/21
Date Last Modified: 3/17/21
Description: Reads a integer value from the input file.
Input parameters: ifstream& infile
Returns: int intValue
**************************************************************/
int readInteger(ifstream& infile);

/**************************************************************
Function: calculateSum()
Date Created: 3/15/21
Date Last Modified: 3/17/21
Description: Sums all students' GPA, standing, and age values
Input parameters: double number1, number2, number3, number4, number5
Returns: double sum
**************************************************************/
double calculateSum(double number1, double number2, double number3, double number4, double number5);

/**************************************************************
Function: calculateMean()
Date Created: 3/15/21
Date Last Modified: 3/17/21
Description: averages the GPA, standing, and age values
Input parameters: double sum, int number
Returns: double mean
**************************************************************/
double calculateMean(double sum, int number);

/**************************************************************
Function: calculateDeviation()
Date Created: 3/15/21
Date Last Modified: 3/17/21
Description: find the normal deviation (to be used in stdev's numerator)
Input parameters: double number, mean
Returns: double deviation
**************************************************************/
double calculateDeviation(double number, double mean);

/**************************************************************
Function: calcuateVariance()
Date Created: 3/15/21
Date Last Modified: 3/17/21
Description: utilizes deviation values for each student to find
	part of standard deviation calculation inside the square root
Input parameters: double deviation1, deviation2, deviation3, devation4,
	deviation5; int number
Returns: double variance
**************************************************************/
double calculateVariance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);

/**************************************************************
Function: calculateStandardDeviation()
Date Created: 3/15/21
Date Last Modified: 3/17/21
Description: take sqaure root of variance value
Input parameters: double variance
Returns: double stdev
**************************************************************/
double calculateStandardDeviation(double variance);

/**************************************************************
Function: findMax()
Date Created: 3/15/21
Date Last Modified: 3/17/21
Description: utilizes an if-else system to test for best GPA
Input parameters: double number1, number2, number3, number4, number5
Returns: double max
**************************************************************/
double findMax(double number1, double number2, double number3, double number4, double number5);

/**************************************************************
Function: findMin()
Date Created: 3/15/21
Date Last Modified: 3/17/21
Description: utilizes an if-else system to test for worst GPA
Input parameters: double number1, number2, number3, number4, number5
Returns: double min
**************************************************************/
double findMin(double number1, double number2, double number3, double number4, double number5);

/**************************************************************
Function: printDouble()
Date Created: 3/15/21
Date Last Modified: 3/17/21
Description: throws outputs into sstream to print strings into
	an output file
Input parameters: ofstream& outfile; double number
Returns: N/A
**************************************************************/
void printDouble(ofstream& outfile, double number);

// main() to call functions
int main(void)
{
	// variable declaration block
	double number1 = 0.0, number2 = 0.0, number3 = 0.0, number4 = 0.0, number5 = 0.0, gpaSum = 0.0, ageSum = 0.0, gpaMean = 0.0, standingMean = 0.0, ageMean = 0.0, deviation1 = 0.0, deviation2 = 0.0, deviation3 = 0.0, deviation4 = 0.0, deviation5 = 0.0, variance = 0.0, age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0, stdDev = 0.0, gpaMax = 0.0, gpaMin = 0.0;
	int number = 0, standing1 = 0, standing2 = 0, standing3 = 0, standing4 = 0, standing5 = 0, standingSum = 0, studentID = 0;
	
	// file IO stream variable declarations
	ifstream infile;
	ofstream outfile;
	string inName = "input.dat", outName = "output.dat", trashbin = "";
	
	// open files
	infile.open(inName);
	outfile.open(outName);
	
	// check if files are open
	if(!infile.is_open() || !outfile.is_open())
	{
		cout << "Unable to open file(s)." << endl;
		return -1;
	}
	
	// first set of data
	studentID = readInteger(infile);
	number1 = readDouble(infile);
	standing1 = readInteger(infile);
	age1 = readDouble(infile);
	getline(infile, trashbin);
	number++;
	
	// second set of data
	studentID = readInteger(infile);
	number2 = readDouble(infile);
	standing2 = readInteger(infile);
	age2 = readDouble(infile);
	getline(infile, trashbin);
	number++;
	
	// third set of data
	studentID = readInteger(infile);
	number3 = readDouble(infile);
	standing3 = readInteger(infile);
	age3 = readDouble(infile);
	getline(infile, trashbin);
	number++;
	
	// fourth set of data
	studentID = readInteger(infile);
	number4 = readDouble(infile);
	standing4 = readInteger(infile);
	age4 = readDouble(infile);
	getline(infile, trashbin);
	number++;
	
	// fifth set of data
	studentID = readInteger(infile);
	number5 = readDouble(infile);
	standing5 = readInteger(infile);
	age5 = readDouble(infile);
	getline(infile, trashbin);
	number++;
	
	// sums sets of data
	gpaSum = calculateSum(number1, number2, number3, number4, number5);
	standingSum = calculateSum(standing1, standing2, standing3, standing4, standing5);
	ageSum = calculateSum(age1, age2, age3, age4, age5);
	
	// averages sets of data
	gpaMean = calculateMean(gpaSum, number);
	standingMean = calculateMean(standingSum, number);
	ageMean = calculateMean(ageSum, number);
	
	// finds deviation of gpa data
	deviation1 = calculateDeviation(number1, gpaMean);
	deviation2 = calculateDeviation(number2, gpaMean);
	deviation3 = calculateDeviation(number3, gpaMean);
	deviation4 = calculateDeviation(number4, gpaMean);
	deviation5 = calculateDeviation(number5, gpaMean);
	
	// finds variance of deviations
	variance = calculateVariance(deviation1, deviation2, deviation3, deviation4, deviation5, number);
	
	// finds standard devation of variance
	stdDev = calculateStandardDeviation(variance);
	
	// finds the maximum gpa
	gpaMax = findMax(number1, number2, number3, number4, number5);
	
	// finds the minimum gpa
	gpaMin = findMin(number1, number2, number3, number4, number5);
	
	// writes output data to output file in proper format
	printDouble(outfile, gpaMean);
	printDouble(outfile, standingMean);
	printDouble(outfile, ageMean);
	outfile << endl;
	printDouble(outfile, stdDev);
	printDouble(outfile, gpaMin);
	printDouble(outfile, gpaMax);
	
	// close files
	infile.close();
	outfile.close();
	
	return 0;
}

// function definitions
double readDouble(ifstream& infile)
{
	double doubleValue;
	infile >> doubleValue;
	return doubleValue;
}

int readInteger(ifstream& infile)
{
	int intValue;
	infile >> intValue;
	return intValue;
}

double calculateSum(double number1, double number2, double number3, double number4, double number5)
{
	double sum = 0.0;
	sum = number1 + number2 + number3 + number4 + number5;
	return sum;
}

double calculateMean(double sum, int number)
{
	double mean = 0.0;
	mean = sum / number;
	
	if(mean == 0)
	{
		return -1;
	}
	else
	{
		return mean;
	}
}

double calculateDeviation(double number, double mean)
{
	double deviation = 0.0;
	deviation = number - mean;
	return deviation;
}

double calculateVariance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
	double variance = 0.0;
	variance = (pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2)) / number;
	return variance;
}

double calculateStandardDeviation(double variance)
{
	double stdDev = 0.0;
	stdDev = sqrt(variance);
	return stdDev;
}

double findMax(double number1, double number2, double number3, double number4, double number5)
{
	double max = 0.0, firstMax = 0.0, secondMax = 0.0, thirdMax = 0.0;
	if(number1 > number2)
	{
		firstMax = number1;
	}
	else
	{
		firstMax = number2;
	}
	if(number3 > number4)
	{
		secondMax = number3;
	}
	else
	{
		secondMax = number4;
	}
	if(firstMax > secondMax)
	{
		thirdMax = firstMax;
	}
	else
	{
		thirdMax = secondMax;
	}
	if(thirdMax > number5)
	{
		max = thirdMax;
	}
	else
	{
		max = number5;
	}
	
	return max;
}

double findMin(double number1, double number2, double number3, double number4, double number5)
{
	double min = 0.0, firstMin = 0.0, secondMin = 0.0, thirdMin = 0.0;
	if(number1 > number2)
	{
		firstMin = number2;
	}
	else
	{
		firstMin = number1;
	}
	if(number3 > number4)
	{
		secondMin = number4;
	}
	else
	{
		secondMin = number3;
	}
	if(firstMin > secondMin)
	{
		thirdMin = secondMin;
	}
	else
	{
		thirdMin = firstMin;
	}
	if(thirdMin > number5)
	{
		min = number5;
	}
	else
	{
		min = thirdMin;
	}
	return min;
}

void printDouble(ofstream& outfile, double number)
{
	string output = "";
	stringstream ss;
	ss << fixed << setprecision(2) << number;
	output = ss.str();
	outfile << output << endl;
}