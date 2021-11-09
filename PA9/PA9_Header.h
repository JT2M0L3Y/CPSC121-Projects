/**********************************************************
Jonathan Smoley
CPSC121 - Spring 2021
PA9 Header
Header file for PA9 that stores necessary libraries, guard
code, and function prototypes to link other two files.
**********************************************************/

#ifndef PA9_HEADER_H
#define PA9_HEADER_H

#include <iostream> // for IO
#include <fstream> // for file IO
#include <string> // for getline()
#include <iomanip> // for output format
#include <cmath> // for pow() & sqrt()
#include <vector> // for vectors

using namespace std;

bool readStudentRecord(ifstream& infile, string& studentId, double& GPA, int& classStanding, double& age);
int storeDataSets(ifstream& infile, vector<string>& studentIdVector, vector<double>& gpaVector, vector<int>& standingVector, vector<double>& ageVector);
double calculateSum(vector<double> doubleVector);
int calculateSum(vector<int> intVector);
double calculateMean(double sum, int number);
int calculateCountAboveMean(double mean, vector<double> GPAs);
int calculateCountBelowMean(double mean, vector<double> GPAs);
void calculateDeviations(vector<double> GPAs, double mean, vector<double>& deviations);
double calculateVariance(vector<double>& deviations, int number);
double calculateStandardDeviation(double variance);
void findMax(vector<double> GPAs, double& maxGPA, int& maxIndex, int number);
void findMin(vector<double> GPAs, double& minGPA, int& minIndex, int number);
void printFormattedDouble(ofstream& outfile, double number, int precision);

#endif
