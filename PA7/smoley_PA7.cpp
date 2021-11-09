/* 
	Name: Jonathan Smoley
	Class: CPSC 121, Spring 2021
	Programming Assignment 7 - Pet Store Follow-up
	Description: Utilizes same content as the previous pet store
		assignment, but implements 1D arrays and functions for
		greater organization of individual instructions.
*/

#include "PA7Header.h"

int main()
{
	// variable declaration block
	PetType petType, petTypes[100];
	string petStoreName = "", petName = "", dateUpdated = "", trashBin = "";
	string petNames[100], petString = "", petTypeStrings[100], petStrings[5];
	string petStr = "", aboveAveragePets[100];
	int i, sumDays = 0, numPets = 0, daysAtStore[100], petTypeCounts[5];
	int numPetsAbove = 0, mostFrequentAnimalTypeIndex = 0;
	int numDaysAtStoreMinIndex = 0, numDaysAtStoreMaxIndex = 0;
	int numPetsAboveAverageStay = 0, storeDays = 0, maxValue = 0, minValue = 0;
	bool aboveAverageDaysAtStore[100];
	double averageDays;
	
	// file stream variable declarations
	ifstream infile;
	ofstream outfile;
	string inName = "petstore.txt"; 
	string outName = "petstats.txt";
	
	// function call to open files
	fileOpen(infile, outfile, inName, outName);

	// read in store name from input file
	cout << "\nReading in pet list from store: ";
	getline(infile, petStoreName); // grabs store name
	getline(infile, trashBin); // to grab the following newline
	cout << "\"" << petStoreName << "\"...\n" << endl;

	// function call to collect remaining pet store info into arrays
	
	// loop to iterate through initialized arrays of pet info
	while(!infile.eof())
	{
		// function call to read in input file data
		getPetStoreInfo(infile, dateUpdated, petName, petStr, storeDays);
		
		// check for last line of input file
		if(petName.find("Last updated: ") == 0)
		{
			dateUpdated = petName.substr(14, petName.size() - 14);
			break;
		}
		
		// check for pet types not listed as accepatable
		if((petStr != "bird" && petStr != "cat" && petStr != "dog" && petStr != "fish"))
		{
			petStr = "other";
		}
		
		// assign array indicies with proper values
		petNames[i] = petName;
		petTypeStrings[i] = petStr;
		daysAtStore[i] = storeDays;
		
		// organizes data read from input file
		cout << "Processing " << petTypeStrings[i] << " \"" << petNames[i]
			<< "\" ... " << daysAtStore[i] << " day(s) on site." << endl;
		
		numPets++;
		i++;
	}
	
	// console output for when reading in file data is completed
	cout << "\nPet store data processed!\n" << endl;
	cout << "Generating summary report...\n" << endl;
	
	// loop to iterate through function that fills string array
	for(i = 0; i < numPets; i++)
	{
		petType = static_cast<PetType>(i);
		petStrings[i] = getPetTypeString(petType);
	}
	
	// loop to iterate through function that fills enum array
	for(i = 0; i < numPets; i++)
	{
		petString = petTypeStrings[i];
		petTypes[i] = getPetTypeCode(petString);
	}
	
	// function call to collect number of each pet type allowed
	setPetTypeCounts(petTypes, petTypeCounts, numPets);
	
	// function call to determine most occuring pet type
	mostFrequentAnimalTypeIndex = findMostFrequentPetType(petTypeCounts, numPetTypes);
	
	// determine min and max days stayed in the store
	for(i = 0; i < numPets; i++)
	{
		if(daysAtStore[i] > maxValue)
		{
			maxValue = daysAtStore[i];
			numDaysAtStoreMaxIndex = i;
		}
		else if(daysAtStore[i] < minValue)
		{
			minValue = daysAtStore[i];
			numDaysAtStoreMinIndex = i;
		}
	}
	
	// loop to sum iterations through array of days at store
	for(i = 0; i < numPets; i++)
	{
		sumDays += daysAtStore[i];
	}
	// average calculation
	averageDays = ceil(static_cast<double>(sumDays) / numPets);

	// function call to fill an array of pet stays above the average length
	setAboveAverageDaysAtStore(daysAtStore, numPets, aboveAverageDaysAtStore, averageDays);
	
	// function call to create array of pets that have above average stays
	numPetsAboveAverageStay = findPetsWithAboveAverageStay(petNames, aboveAverageDaysAtStore, numPets, aboveAveragePets);
	
	// writes to the output file with header of store name and number of pets
	writePetSummaryHeader(outfile, petStoreName, numPets);
	
	// writes to the output file with amount of each animal in the list
	writeAnimalTypeSummary(outfile, petTypeCounts, numPetTypes);
	
	// converts lowercase string array to capital case string array
	for(i = 0; i < numPets; i++)
	{
		petString = petTypes[i];
		toCapitalCase(petString);
	}
	
	// writes to output file most/least lengthy stay & most frequent pet type
	writePetFrequencyStats(outfile, petNames, daysAtStore, petTypes, mostFrequentAnimalTypeIndex, numDaysAtStoreMinIndex, numDaysAtStoreMaxIndex);
	
	// writes to output file average days on site & animals with a longer stay
	writePetAveragesStats(outfile, averageDays, aboveAveragePets, numPetsAboveAverageStay);
	
	// last line in output file
	outfile << "Pet store list was last modified on " << dateUpdated << endl;

	// tells user when summary report is generated
	cout << "Done!" << endl;
	
	// closes files in use
	infile.close();
	outfile.close();

	return 0;
}
