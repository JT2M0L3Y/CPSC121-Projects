/**********************************************************
Jonathan Smoley
CPSC121 - Spring 2021
PA9 Function Definitions
Stores all functions (besides main()) that are used within
the PA9 main file.
**********************************************************/

#include "PA9_Header.h"

/**************************************************************
Function: readStudentRecords()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: reads 1 student record at a time from a file
Inputs: ifstream value to access input file, type-specific 
	variables for each type of data read in from the file
Returns: logical state of system after data is read
**************************************************************/
bool readStudentRecord(ifstream& infile, string& studentId, double& GPA, int& classStanding, double& age)
{
	string trashBin = "";
	
	// format of input file recreated to read in data properly
	getline(infile, studentId);
	infile >> GPA;
	infile >> classStanding;
	infile >> age;
	getline(infile, trashBin);
	getline(infile, trashBin);
	
	// return true if data is read successfully
	if(!infile.fail())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**************************************************************
Function: storeDataSets()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: sorts student records into vectors for later use
Inputs: ifstream value to access input file, type-specific 
	vectors for each type of data read in from the file
Returns: count of stuent records read in from the file
**************************************************************/
int storeDataSets(ifstream& infile, vector<string>& studentIdVector, vector<double>& gpaVector, vector<int>& standingVector, vector<double>& ageVector)
{
	int count = 0, classStanding = 0;
	double GPA = 0.0, age = 0.0;
	string studentId = "";
	
	while(!infile.eof())
	{
		// function call to read new values for each iteration
		readStudentRecord(infile, studentId, GPA, classStanding, age);
		
		// allocate memory for a new value in each vector
		studentIdVector.push_back(studentId);
		gpaVector.push_back(GPA);
		standingVector.push_back(classStanding);
		ageVector.push_back(age);
		
		count++;
	}
	
	// check if data was readin full sets & return -1 if not
	if(count == studentIdVector.size() && count == gpaVector.size() && count == standingVector.size() && count == ageVector.size())
	{
		return count;
	}
	else
	{
		cout << "A full set of data was not read!" << endl;
		return -1;
	}
}

/**************************************************************
Function: calculateSum()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: adds values each index of populated vector
Inputs: vector of values read in from the file
Returns: sum as a double value
**************************************************************/
double calculateSum(vector<double> doubleVector)
{
	double sum = 0.0;
	
	// sum values of vector passed in the call
	for(double value:doubleVector)
	{
		sum += value;
	}
	
	return sum;
}

/**************************************************************
Function: calculateSum()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: adds values at each index of populated vector
Inputs: vector of double values read in from the file
Returns: sum as an int value
**************************************************************/
int calculateSum(vector<int> intVector)
{
	int sum = 0;
	
	// sum values of vector passed in the call
	for(int value:intVector)
	{
		sum += value;
	}
	
	return sum;
}

/**************************************************************
Function: calculateMean()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: uses sum and count of records to find average gpa
Inputs: sum of gpa values, number of gpa values
Returns: mean as a double value
**************************************************************/
double calculateMean(double sum, int number)
{
	// return -1.0 if count of student records is passed as a 0
	if(number == 0)
	{
		return -1;
	}
	else
	{
		return sum / number;
	}
}

/**************************************************************
Function: calculateCountAboveMean()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: counts number of gpa values above the mean
Inputs: mean gpa value and vector of student gpas
Returns: count of gpas above mean
**************************************************************/
int calculateCountAboveMean(double mean, vector<double> GPAs)
{
	int count = 0;
	
	// loop through vector passed in function call
	for(double GPA:GPAs)
	{
		if(GPA > mean)
		{
			count++;
		}
	}
	
	return count;
}

/**************************************************************
Function: calculateCountBelowMean()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: counts number of gpa values below the mean
Inputs: mean gpa value, vector of student gpas
Returns: count of gpas below mean
**************************************************************/
int calculateCountBelowMean(double mean, vector<double> GPAs)
{
	int count = 0;
	
	// loop through vector passed in function call
	for(double GPA:GPAs)
	{
		if(GPA < mean)
		{
			count++;
		}
	}
	
	return count;
}

/**************************************************************
Function: calculateDeviations()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: find the deviation of each gpa from the mean
Inputs: vector of student gpas, mean gpa, vector for deviations
Returns: N/A
**************************************************************/
void calculateDeviations(vector<double> GPAs, double mean, vector<double>& deviations)
{
	double deviation = 0.0;
	
	// loop through passed vector to populate a new one
	for(int i = 0; i < GPAs.size(); i++)
	{
		deviation = abs(GPAs.at(i) - mean);
		deviations.push_back(deviation);
	}
	
	return;
}

/**************************************************************
Function: calculateVariance()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: find variance between deviation values
Inputs: vector for deviations, number of student records in file
Returns: variance value as a double
**************************************************************/
double calculateVariance(vector<double>& deviations, int number)
{
	double totalDeviation = 0.0;
	
	// adds square of each value in deviations vector
	for(int i = 0; i < number; i++)
	{
		totalDeviation += pow(deviations.at(i), 2);
	}
	
	// returns sum once divided by number of deviations
	return totalDeviation / number;
}

/**************************************************************
Function: calculateStandardDeviation()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: computes a standard deviation value of gpa values
Inputs: variance double value
Returns: square rooted variance as a standard deviation
**************************************************************/
double calculateStandardDeviation(double variance)
{
	// returns square root of value passed in
	return sqrt(variance);
}

/**************************************************************
Function: findMax()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: searchs for the max gpa value & returns the index
Inputs: vector of student gpas, referenced maxGPA variable
Returns: N/A
**************************************************************/
void findMax(vector<double> GPAs, double& maxGPA, int& maxIndex, int number)
{
	maxGPA = GPAs.at(0);
	
	// loop through vector passed to find max value & at what index
	for(int i = 1; i < number; i++)
	{
		if(GPAs.at(i) > GPAs.at(i - 1))
		{
			maxGPA = GPAs.at(i);
			maxIndex = i;
		}
	}
	
	return;
}

/**************************************************************
Function: findMin()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: searches for the min gpa value & returns the index
Inputs: vector of student gpas, referenced minGPA variable
Returns: N/A
**************************************************************/
void findMin(vector<double> GPAs, double& minGPA, int& minIndex, int number)
{
	minGPA = GPAs.at(0);
	
	// loop through vector passed to find min value & at what index
	for(int i = 1; i < number; i++)
	{
		if(GPAs.at(i) < GPAs.at(i - 1))
		{
			minGPA = GPAs.at(i);
			minIndex = i;
		}
	}
	
	return;
}

/**************************************************************
Function: printFormattedDouble()
Date Created: 4/19/21
Date Last Modified: 4/19/21
Description: formats a double value to hundredths place, then
	prints said value to an output file
Inputs: ofstream variable, a double value, a formatting number
Returns: N/A
**************************************************************/
void printFormattedDouble(ofstream& outfile, double number, int precision)
{
	// only works for double values passed, other output file writing in main()
	outfile << fixed << setprecision(precision) << number << endl;
	
	return;
}
