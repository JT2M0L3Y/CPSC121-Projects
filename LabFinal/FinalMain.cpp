/*
 Name: Jonathan Smoley
 Class: CPSC 121, Spring 2021
 Assignment: Lab Final Exam
 Notes: Main File
*/

#include "FinalHeader.h"

//program main
int main()
{
	//Parallel Vectors
	vector<int> packageIds;
	vector<double> packageWeights;
	vector<string> packageDimensions;
	//Input and Output stream variables
	ifstream infile;
	ofstream outfile;
	//string variables
	string inputFilename = "truckload.txt", outputFilename = "truckloadstats.txt";
	string driverName = "", storeName = "";
	//stats variables
	int heaviestId = 0;
	double heaviestWeight = 0, avgWeight = 0;
	//menu choice variable
	int userMenuSelection = -1;
	//keeping track of file open status
	bool inputFileIsOpen = false, outputFileIsOpen = false;
	//keeping track of validating data
	bool packageDataAreValid = false, packageStatsAreValid = false;

	//MENU LOOP
	do
	{
		do
		{
			cout << "\nPlease choose from the following menu (1-9) to handle truck load processing.\n";
			cout << "1) Open input file for reading\n";
			cout << "2) Open output file for writing\n";
			cout << "3) Read in truck file and process data\n";
			cout << "4) Display the package information to the console\n";
			cout << "5) Compute package statistics for the current truck load\n";
			cout << "6) Display package statistics for the current truck load to the console\n";
			cout << "7) Display the package information AND package statistics to the console\n";
			cout << "8) Write the package information AND package statistics to the output file\n";
			cout << "9) Quit\n";
			cout << ">> ";
			cin >> userMenuSelection;
			if (userMenuSelection > 9)
			{
				cls(); //clears the screen
				cout << "Invalid Option\n";
			}
		} while (userMenuSelection < 1 || userMenuSelection > 9);
		cout << "\n";
		cls(); //clears the screen

		switch (static_cast<MenuOptions>(userMenuSelection))
		{
		case OPEN_INPUT_FILE: //Open input file for reading
			inputFileIsOpen = openInputFile(infile, inputFilename);
			displayFileStatus(inputFileIsOpen, inputFilename);
			break;
		case OPEN_OUTPUT_FILE: //Open output file for writing
			outputFileIsOpen = openOutputFile(outfile, outputFilename);
			displayFileStatus(outputFileIsOpen, outputFilename);
			break;
		case READ_TRUCK_DATA: //Read in truck file for processing
			if(inputFileIsOpen == 1)
			{
				processPackages(infile, packageIds, packageWeights, packageDimensions, driverName, storeName);
				packageDataAreValid = packagesProcessedAreValid(packageIds, packageWeights, packageDimensions);
			}
			break;
		case DISPLAY_PACKAGE_INFO: //Display the package information in forward order to the console
			if(packageDataAreValid == 1)
			{
				displayPackageInformation(packageIds, packageWeights, packageDimensions, driverName, storeName);
			}
			break;
		case COMPUTE_PACKAGE_STATS: //Compute package statistics for the current truck load
			if(packageDataAreValid == 1)
			{
				computePackageStats(packageIds, packageWeights, packageDimensions, heaviestId, heaviestWeight, avgWeight);
				packageStatsAreValid = statsComputedAreValid(heaviestId, heaviestWeight, avgWeight);
			}
			break;
		case DISPLAY_PACKAGE_STATS: //Display package statistics for the current truck load to the console
			if(packageStatsAreValid == 1)
			{
				displayPackageStats(heaviestId, heaviestWeight, avgWeight);
			}
			break;
		case DISPLAY_ALL_DATA: //Display the package information in forward order AND statistics about the packages to the console
			if(packageDataAreValid == 1 && packageStatsAreValid == 1)
			{
				displayPackageInformation(packageIds, packageWeights, packageDimensions, driverName, storeName);
				displayPackageStats(heaviestId, heaviestWeight, avgWeight);
			}
			break;
		case WRITE_ALL_DATA: //Write the package information in forward order AND statistics about the packages to an output file
			if(packageDataAreValid == 1 && packageStatsAreValid == 1)
			{
				savePackageSummaryReport(outfile, packageIds, packageWeights, packageDimensions, driverName, storeName, heaviestId, heaviestWeight, avgWeight);
			}
			break;
		case EXIT_PGM:
			//Do nothing, we will exit the loop
			break;
		default:
			cout << "Invalid Option\n";
			break;
		}

	} while (userMenuSelection != 9);

	//CLOSE FILES
	infile.close();
	outfile.close();

	return 0;
}