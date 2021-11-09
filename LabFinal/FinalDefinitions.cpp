/*
 Name: Jonathan Smoley
 Class: CPSC 121, Spring 2021
 Assignment: Lab Final Exam
 Notes: Definitions File
*/

#include "FinalHeader.h"

/*************************************************************
Function: cls()
Date Created: 5/6/21
Date Last Modified: 5/6/21
Description: This function should clear the console screen
	for both Windows and Linux command prompt / terminal windows
*************************************************************/
void cls(void)
{
	system("cls||clear");
	return;
}

/**************************************************************
Function: openInputFile()
Date Created: 5/6/21
Date Last Modified: 5/6/21
Description: Opens the file passed into the function &
	returns true if operation is successful
Inputs: input file to open, input file name for reference
Returns: logical value depending on state on input file
**************************************************************/
bool openInputFile(ifstream& infile, const string filename)
{
	infile.open(filename);
	
	if(!infile.is_open())
	{
		return false;
	}
	else
	{
		return true;
	}
}

/**************************************************************
Function: openOutputFile()
Date Created: 5/6/21
Date Last Modified: 5/6/21
Description: Opens the file passed into the function &
	returns true if operation is successful
Inputs: output file to open, output file name for reference
Returns: logical value depending on state of output file
**************************************************************/
bool openOutputFile(ofstream& outfile, const string filename)
{
	outfile.open(filename);
	
	if(!outfile.is_open())
	{
		return false;
	}
	else
	{
		return true;
	}
}

/**************************************************************
Function: displayFileStatus()
Date Created: 5/6/21
Date Last Modified: 5/6/21
Description: uses file status from opening input/output file
	to print a message to the console
Inputs: state of file, name of file
Returns: N/A
**************************************************************/
void displayFileStatus(bool fileStatus, const string filename)
{
	if(fileStatus == false)
	{
		cout << "\nUnable to open " << filename << " at this time." << endl;
	}
	else
	{
		cout << "\n" << filename << " was opened successfully." << endl;
	}
}

/**************************************************************
Function: processPackages()
Date Created: 5/6/21
Date Last Modified: 5/6/21
Description: reads in data from input file into a set of
	parallel vectors referenced as output parameters
Inputs: input file, id vector, weight vector, dimension vector,
	driver name
Returns: N/A
**************************************************************/
void processPackages(ifstream& infile, vector<int>& packageIds, vector<double>& packageWeights, vector<string>& packageDimensions, string& driverName, string& storeName)
{
	int Id = 0;
	double weight = 0.0;
	string dimension = "", trashBin = "";
	getline(infile, driverName);
	getline(infile, storeName);
	
	while(!infile.eof())
	{
		infile.ignore();
		infile >> Id;
		if(Id == false)
		{
			break;
		}
		infile >> weight;
		infile.ignore();
		getline(infile, dimension);
		
		packageIds.push_back(Id);
		packageWeights.push_back(weight);
		packageDimensions.push_back(dimension);
	}
}

/**************************************************************
Function: packagesProcessedAreValid()
Date Created: 5/6/21
Date Last Modified: 5/6/21
Description: checks if all data was read in correctly from file
Inputs: parallel vectors for package data
Returns: logical value depending on state of parallel vectors
**************************************************************/
bool packagesProcessedAreValid(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions)
{
	if(packageIds.size() == packageWeights.size() && packageWeights.size() == packageDimensions.size() && packageDimensions.size() == packageIds.size())
	{
		cout << "\nPackages processed correctly." << endl;
		return true;
	}
	else
	{
		cout << "\nPackages processed incorrectly." << endl;
		return false;
	}
}

/**************************************************************
Function: displayPackageInformation()
Date Created: 5/6/21
Date Last Modified: 5/6/21
Description: prints package data to console in a specific format
Inputs: parallel vectors, driver's name
Returns: N/A
**************************************************************/
void displayPackageInformation(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName, const string storeName)
{
	cout << "Driver: " << driverName << endl;
	cout << "Store: " << storeName << endl;
	cout << "Number of packages: " << packageIds.size() << endl;
	cout << "Package Information\n___________________" << endl;
	for(int i = 0; i < packageIds.size(); ++i)
	{
		cout << "Package Id: " << packageIds.at(i) << endl;
		cout << "Package Weight: " << fixed << setprecision(2) << packageWeights.at(i) << endl;
		cout << "Package Dimensions: " << packageDimensions.at(i) << "\n" << endl;
	}
}

/**************************************************************
Function: computePackageStats()
Date Created: 5/6/21
Date Last Modified: 5/6/21
Description: parses package weights vector to find heaviest
	package & its Id and the average weight of the packages
Inputs: parallel vectors, heaviestWeight, avgWeight, heaviestId
Returns: N/A
**************************************************************/
void computePackageStats(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, int& heaviestId, double& heaviestWeight, double& avgWeight)
{
	heaviestWeight = packageWeights.at(0);
	double weightSum = packageWeights.at(0);
	
	for(int i = 1; i < packageIds.size(); ++i)
	{
		if(packageWeights.at(i) > packageWeights.at(i-1))
		{
			heaviestWeight = packageWeights.at(i);
			heaviestId = packageIds.at(i);
		}
		weightSum += packageWeights.at(i);
	}
	
	avgWeight = weightSum / packageIds.size();
}

/**************************************************************
Function: statsComputedAreValid()
Date Created: 5/6/21
Date Last Modified: 5/6/21
Description: checks calculated stats in previous function
	to make sure they are non-zero values
Inputs: heaviest Id, heaviest weight, average weight
Returns: logical value depending on state of computed results
**************************************************************/
bool statsComputedAreValid(int heaviestId, double heaviestWeight, double avgWeight)
{
	if(heaviestId != 0 && heaviestWeight != 0 && avgWeight != 0)
	{
		cout << "Computed stats are all valid values." << endl;
		return true;
	}
	else
	{
		cout << "One of the computed stats is not a valid value." << endl;
		return false;
	}
}

/**************************************************************
Function: displayPackageStats()
Date Created: 5/6/21
Date Last Modified: 5/6/21
Description: using package stats, prints another report to the 
	console for the user to view
Inputs: package stats previously computed
Returns: N/A
**************************************************************/
void displayPackageStats(int heaviestId, double heaviestWeight, double avgWeight)
{
	cout << "Package Stats\n_____________" << endl;
	cout << "Id of heaviest package: " << heaviestId << endl;
	cout << "Weight of heaviest package: " << heaviestWeight << endl;
	cout << "Average weight of packages on the truck: " << avgWeight << endl;
}

/**************************************************************
Function: savePackageSummaryReport()
Date Created: 5/6/21
Date Last Modified: 5/6/21
Description: prints a summary report to an output file that
	contains package and package stats data
Inputs: output file reference, parallel vectors, package stats
Returns: N/A
**************************************************************/
void savePackageSummaryReport(ofstream& outfile, vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName, const string storeName, int heaviestId, double heaviestWeight, double avgWeight)
{
	outfile << "Driver: " << driverName << endl;
	outfile << "Store: " << storeName << endl;
	outfile << "Number of packages: " << packageIds.size() << endl;
	outfile << "Package Information\n___________________" << endl;
	for(int i = 0; i < packageIds.size(); ++i)
	{
		outfile << "Package Id: " << packageIds.at(i) << endl;
		outfile << "Package Weight: " << fixed << setprecision(2) << packageWeights.at(i) << endl;
		outfile << "Package Dimensions: " << packageDimensions.at(i) << "\n" << endl;
	}
	
	outfile << "Package Stats\n_____________" << endl;
	outfile << "Id of heaviest package: " << heaviestId << endl;
	outfile << "Weight of heaviest package: " << heaviestWeight << endl;
	outfile << "Average weight of packages on the truck: " << avgWeight << endl;
}