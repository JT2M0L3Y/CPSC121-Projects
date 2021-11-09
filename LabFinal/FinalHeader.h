/*
 Name: Jonathan Smoley
 Class: CPSC 121, Spring 2021
 Assignment: Lab Final Exam
 Notes: Header File
*/

#ifndef FINALHEADER_H
#define FINALHEADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

//enumerated data type used for menu option selections
enum MenuOptions { OPEN_INPUT_FILE = 1, OPEN_OUTPUT_FILE, READ_TRUCK_DATA, DISPLAY_PACKAGE_INFO, COMPUTE_PACKAGE_STATS, DISPLAY_PACKAGE_STATS, DISPLAY_ALL_DATA, WRITE_ALL_DATA, EXIT_PGM };

void cls(void); //function clears screen on both Linux and Windows OSes

//required function prototypes
bool openInputFile(ifstream& infile, const string filename);
bool openOutputFile(ofstream& outfile, const string filename);
void displayFileStatus(bool fileStatus, const string filename);
void processPackages(ifstream& infile, vector<int>& packageIds, vector<double>& packageWeights, vector<string>& packageDimensions, string& driverName, string& storeName);
bool packagesProcessedAreValid(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions);
void displayPackageInformation(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName, const string storeName);
void computePackageStats(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, int& heaviestId, double& heaviestWeight, double& avgWeight);
bool statsComputedAreValid(int heaviestId, double heaviestWeight, double avgWeight);
void displayPackageStats(int heaviestId, double heaviestWeight, double avgWeight);
void savePackageSummaryReport(ofstream& outfile, vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName, const string storeName, int heaviestId, double heaviestWeight, double avgWeight);

#endif