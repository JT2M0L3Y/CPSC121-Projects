/*
	Name: Jonathan Smoley
	Class: CPSC 121, Spring 2021
	Programming Assignment 5 - Pet Store
	Notes: I utilized the given starter code.
*/

#include <iostream> // for IO
#include <fstream> // for file IO
#include <string> // for string data type/functions
#include <cmath> // to round the average days on site

using namespace std;

int main(void)
{
	// variable declaration block
	string storeName = "", petName = "", trashBin = "", animalType = "";
	string dateUpdated = "";
	int numDaysAtStore = 0, mostDaysAtStore = 0, fewestDaysAtStore = 1;
	int countCats = 0, countDogs = 0, countPigs = 0, countOther = 0;
	int numPets = 0, totalDays = 0;
	double averageDaysOnSite = 0.0;

	ifstream infile;
	ofstream outfile;
	string inName = "petstore.txt", outName = "summaryreport.txt";
	
	// opens input and output files for use
	infile.open(inName);
	outfile.open(outName);
	
	// to check of input or output file was opened correctly
	if (!infile.is_open() || !outfile.is_open())
	{
		cout << "Unable to open the input file" << endl;
		return -1;
	}
	
	getline(infile, storeName);
	getline(infile, trashBin); // to grab the following newline
	
	cout << "Reading in pet list from store: " << storeName << "...\n" << endl;
	
	// input animal data & adjust calculations with new data
	while (!infile.fail())
	{
		getline(infile, petName);
		// allows the differing final input line to be parsed & stored correctly
		if(petName.find("Last updated: ") == 0)
		{
			dateUpdated = petName.substr(14, petName.size() - 14);
			break;
		}
		if(infile.fail())
		{
			cout << "Invalid format for Pet Name" << endl;
			return -1;
		}
		
		getline(infile, animalType);
		if(infile.fail())
		{
			cout << "Invalid format for Animal Type" << endl;
			return -1;
		}
		
		infile >> numDaysAtStore;
		if(infile.fail())
		{
			cout << "Invalid format for Days at Store" << endl;
			return -1;
		}
		
		// accounts for newlines in input file
		getline(infile, trashBin);
		getline(infile, trashBin);
		
		// organizes data read from input file
		cout << "Processing " << animalType << " \"" << petName << "\" ... "
			<< numDaysAtStore << " day(s) on site." << endl;
		
		// to organize the greatest and least days on site for summary report
		if(numDaysAtStore >= mostDaysAtStore)
		{
			mostDaysAtStore = numDaysAtStore;
		}
		else if(numDaysAtStore <= fewestDaysAtStore)
		{
			fewestDaysAtStore = numDaysAtStore;
		}
		
		// to count the number of each type of animal
		if(animalType == "cat")
		{
			countCats++;
		}
		else if(animalType == "dog")
		{
			countDogs++;
		}
		else if(animalType == "pig")
		{
			countPigs++;
		}
		else if(animalType == "other")
		{
			countOther++;
		}
			
		totalDays += numDaysAtStore; // sum the number of days stayed
	}

	// calculations for summary report data
	numPets = countCats + countDogs + countPigs + countOther;
	averageDaysOnSite = ceil(static_cast<double>(totalDays) / numPets);
	
	cout << "\nPet store data processed!\n" << endl;
	cout << "Generating summary report...\n" << endl;
	
	// writes summary report to the output file
	outfile << "Store: " << storeName << "\nNumber of Pets: " << numPets << endl;
	outfile << "\nPet Information Summary Statistics:" << endl;
	outfile << "___________________________________" << endl;
	outfile << "Count of each animal:" << endl;
	outfile << "Cat - " << countCats << ", Dog - " << countDogs << ", Pig - "
		<< countPigs << ", Other - " << countOther << endl;
	outfile << "Most days on site: " << mostDaysAtStore << endl;
	outfile << "Fewest days on site: " << fewestDaysAtStore << endl;
	outfile << "Average days on site: " << averageDaysOnSite << endl;
	outfile << "\nPet store list was last modified on " << dateUpdated;
	
	cout << "Done!" << endl; // tells user when summary report is generated
	
	infile.close(); // closes input file
	outfile.close(); // closes output file

	return 0;
}
