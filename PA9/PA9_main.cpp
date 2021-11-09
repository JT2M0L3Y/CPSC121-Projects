/**********************************************************
Jonathan Smoley
CPSC121 - Spring 2021
PA9
Read in student data and process it for later output by
utilizing file input/output, functions, and vectors to 
organize tasks into a program designed top-down.
**********************************************************/

#include "PA9_Header.h"

int main()
{
	// variable declaration block
	int recordCount = 0, sumStandings = 0, aboveGPAs = 0, belowGPAs = 0;
	int maxIndex = 0, minIndex = 0;
	double sumGPAs = 0.0, sumAges = 0.0, variance = 0.0, stdDev = 0.0;
	double gpaMean = 0.0, standingsMean = 0.0, ageMean = 0.0;
	double maxGPA = 0.0, minGPA = 0.0;
	vector<string> studentIdVector;
	vector<double> gpaVector;
	vector<int> standingVector;
	vector<double> ageVector;
	vector<double> deviations;
	
	// file IO stream variable declarations
	ifstream infile;
	ofstream outfile;
	string inName = "input.dat", outName = "output.dat";
	
	// open files
	infile.open(inName);
	outfile.open(outName);
	
	// check if files are open
	if(!infile.is_open() || !outfile.is_open())
	{
		cout << "Unable to open file(s)." << endl;
		return -1;
	}
	
	// read in student records, count how many there are, write to the output file
	recordCount = storeDataSets(infile, studentIdVector, gpaVector, standingVector, ageVector);
	outfile << recordCount << "\n" << endl;
	
	// compute needed sums of value in each numeric-value vector
	sumGPAs = calculateSum(gpaVector);
	sumStandings = calculateSum(standingVector); // overloaded int function used
	sumAges = calculateSum(ageVector);
	
	// compute mean of student gpa values, write to output file
	gpaMean = calculateMean(sumGPAs, recordCount);
	printFormattedDouble(outfile, gpaMean, 2);
	
	// count number of student gpas above mean, write to output file
	aboveGPAs = calculateCountAboveMean(gpaMean, gpaVector);
	outfile << aboveGPAs << endl;
	
	// count number of student gpas below mean, write to output file
	belowGPAs = calculateCountBelowMean(gpaMean, gpaVector);
	outfile << belowGPAs << endl;
	
	// compute mean class rank of students in set, write to output file
	standingsMean = calculateMean(sumStandings, recordCount);
	printFormattedDouble(outfile, standingsMean, 2);
	
	// compute mean age of students in set, write to output file
	ageMean = calculateMean(sumAges, recordCount);
	printFormattedDouble(outfile, ageMean, 2);
	
	// add space between sections of output info
	outfile << endl;
	
	// compute each gpa's stray from the mean gpa
	calculateDeviations(gpaVector, gpaMean, deviations);
	
	// compute the variance between values in the input file
	variance = calculateVariance(deviations, recordCount);
	
	// compute standard deviation between gpa values, write to output file
	stdDev = calculateStandardDeviation(variance);
	printFormattedDouble(outfile, stdDev, 2);
	
	// find min GPA of those inputted
	findMin(gpaVector, minGPA, minIndex, recordCount);
	printFormattedDouble(outfile, minGPA, 2);
	
	// find student ID matching min GPA
	outfile << studentIdVector.at(minIndex) << endl;
	
	// find max GPA of those inputted
	findMax(gpaVector, maxGPA, maxIndex, recordCount);
	printFormattedDouble(outfile, maxGPA, 2);
	
	// find student ID matching max GPA
	outfile << studentIdVector.at(maxIndex) << endl;
	
	// close files
	infile.close();
	outfile.close();
	
	return 0;
}
