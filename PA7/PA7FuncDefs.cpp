/*
	Name: Jonathan Smoley
	Class: CPSC 121, Spring 2021
	Programming Assignment 7 - Function Definition file
	Description: Holds definitions as to what functions
		used in smoley_PA7.cpp actually do with regard
		to the petstore.txt input file.
*/

#include "PA7Header.h"

/**************************************************************
Function: fileOpen()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: opens the input and output files
Input parameters: ifstream& infile, ofstream& outfile,
	string inName, string outName
Returns: true or false
**************************************************************/
bool fileOpen(ifstream& infile, ofstream& outfile, string inName, string outName)
{
	// opens input and output files for use
	infile.open(inName);
	outfile.open(outName);
	
	// to check of input or output file was opened correctly
	if (!infile.is_open() || !outfile.is_open())
	{
		cout << "Unable to open one of the files." << endl;
		return false;
	}
	else
	{
		return true;
	}
}

/**************************************************************
Function: getPetStoreInfo()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: reads in the infomation written in the input file
Input parameters: ifstream& infile
Returns: arrays for pet's names, types, and days at store
**************************************************************/
void getPetStoreInfo(ifstream& infile, string& dateUpdated, string& petName, string& petStr, int& storeDays)
{	
		// input animal data
		getline(infile, petName);
		infile >> petStr;
		infile >> storeDays;
		
		// accounts for newlines in input file
		infile.ignore();
		infile.ignore();
}

/**************************************************************
Function: getPetTypeString()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: fills a string value using enum petype(s)
Input parameters: petType
Returns: petString
**************************************************************/
string getPetTypeString(PetType petType)
{	
	string petTypeString = "";
	
	switch(petType)
	{
		case BIRD:
			petTypeString = "bird";
			break;
		case CAT:
			petTypeString = "cat";
			break;
		case DOG:
			petTypeString = "dog";
			break;
		case FISH:
			petTypeString = "fish";
			break;
		case OTHER:
			petTypeString = "other";
			break;
	}

	return petTypeString;
}

/**************************************************************
Function: getPetTypeCode()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: fills petType with an enum value using string values
Input parameters: petString
Returns: petType
**************************************************************/
PetType getPetTypeCode(string petString)
{
	PetType temp;
	
	if(petString == "bird")
	{
		temp = static_cast<PetType>(0);
	}
	if(petString == "cat")
	{
		temp = static_cast<PetType>(1);
	}
	if(petString == "dog")
	{
		temp = static_cast<PetType>(2);
	}
	if(petString == "fish")
	{
		temp = static_cast<PetType>(3);
	}
	if(petString == "other")
	{
		temp = static_cast<PetType>(4);
	}
	
	return temp;
}

/**************************************************************
Function: setPetTypeCounts()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: counts number of each type of pet
Input parameters: petTypes[], petTypeCounts[], numPets
Returns: petTypeCounts[] (updated with new values)
**************************************************************/
void setPetTypeCounts(const PetType petTypes[], int petTypeCounts[], int numPets)
{
	for(int i = 0; i < numPets; i++)
	{
		if(petTypes[i] == 0)
		{
			petTypeCounts[0] = petTypeCounts[0] + 1;
		}
		if(petTypes[i] == 1)
		{
			petTypeCounts[1] = petTypeCounts[1] + 1;
		}
		if(petTypes[i] == 2)
		{
			petTypeCounts[2] = petTypeCounts[2] + 1;
		}
		if(petTypes[i] == 3)
		{
			petTypeCounts[3] = petTypeCounts[3] + 1;
		}
		if(petTypes[i] == 4)
		{
			petTypeCounts[4] = petTypeCounts[4] + 1;
		}
	}
}

/**************************************************************
Function: findMostFrequentPetType()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: determine the animal type that is found most
	int the store
Input parameters: petTypeCounts[], numPetTypes
Returns: mostFrequentAnimalTypeIndex (location of most occuring)
**************************************************************/
int findMostFrequentPetType(const int petTypeCounts[], int numPetTypes)
{
	int maxValue = 0;
	
	for(int i = 0; i < numPetTypes; i++)
	{
		if(petTypeCounts[i] > maxValue)
		{
			maxValue = petTypeCounts[i];
		}
	}
	
	return maxValue;
}

/**************************************************************
Function: setAboveAverageDaysAtStore()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: parses daysAtStore array to find animals at store
	past average days at store
Input parameters: daysAtStore[], numPets, aboveAverageDaysAtStore[]
	averageDats
Returns: aboveAverageDaysAtStore[] (updated version)
**************************************************************/

void setAboveAverageDaysAtStore(const int daysAtStore[], int numPets, bool aboveAverageDaysAtStore[], int averageDays)
{
	for(int i = 0; i < numPets; i++)
	{
		if(daysAtStore[i] > averageDays)
		{
			aboveAverageDaysAtStore[i] = true; // bool values
		}
		else
		{
			aboveAverageDaysAtStore[i] = false; // bool values
		}
	}
}

/**************************************************************
Function: findPetsWithAboveAverageStay()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: utilizes logical parallel array to determine which
	pets are above the average days at the store
Input parameters: const string petNames[], 
	const bool aboveAverageDaysAtStore[], int numPets, 
	string aboveAveragePets[]
Returns: aboveAveragePets[] (updated version)
**************************************************************/
int findPetsWithAboveAverageStay(const string petNames[], const bool aboveAverageDaysAtStore[], int numPets, string aboveAveragePets[])
{
	int numPetsAbove = 0, j = 0;
	
	for(int i = 0; i < numPets; i++)
	{
		if(aboveAverageDaysAtStore[i] == 1)
		{
			aboveAveragePets[j] = petNames[i];
			numPetsAbove++;
			j++;
		}
	}
	
	return numPetsAbove;
}

/**************************************************************
Function: writePetSummaryHeader()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: writes the name of the store to the output file
Input parameters: outfile, petStoreName, numPets
Returns: output in the ouput file
**************************************************************/
void writePetSummaryHeader(ofstream& outfile, string petStoreName, int numPets)
{
	outfile << "Store: " << petStoreName << endl;
	outfile << "Number of pets: " << numPets << endl;
	outfile << "\nPet Information Summary Statistics:" << endl;
	outfile << "___________________________________" << endl;
}

/**************************************************************
Function: writeAnimalTypeSummary()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: writes the counts of each animal type to output file
Input parameters: outfile, petTypeCounts[], numPetTypes
Returns: 2nd block of output in output file
**************************************************************/
void writeAnimalTypeSummary(ofstream& outfile, const int petTypeCounts[], int numPetTypes)
{
	outfile << "Count of each animal:" << endl;
	outfile << "		Bird  - " << petTypeCounts[0] << ",";
	outfile << "	Cat   - " << petTypeCounts[1] << endl;
	outfile << "		Dog   - " << petTypeCounts[2] << ",";
	outfile << "	Fish  - " << petTypeCounts[3] << endl;
	outfile << "		Other - " << petTypeCounts[4] << endl;
}

/**************************************************************
Function: writePetFrequencyStats()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: wrties amount of time spent for extraordinary
	circumstances of animal stays in the store
Input parameters: outfile, petNames[], daysAtStore[], petTypes[],
	mostFrequentAnimalTypeIndex[], numDaysAtStoreMinIndex,
	numDaysAtStoreMaxIndex
Returns: 3rd block of output to output file
**************************************************************/
void writePetFrequencyStats(ofstream& outfile, const string petNames[], const int daysAtStore[], const PetType petTypes[], int mostFrequentAnimalTypeIndex, int numDaysAtStoreMinIndex, int numDaysAtStoreMaxIndex)
{
	outfile << "\nMost frequent animal type: "
		<< toCapitalCase(getPetTypeString(petTypes[mostFrequentAnimalTypeIndex])) << endl;
	outfile << "\nMost days on site:" << endl;
	outfile << "		Name: " << petNames[numDaysAtStoreMaxIndex] << endl;
	outfile << "		Days: " << daysAtStore[numDaysAtStoreMaxIndex] << endl;
	outfile << "		Type: " << toCapitalCase(getPetTypeString(petTypes[numDaysAtStoreMaxIndex])) << endl;
	
	outfile << "\nFewest days on site:" << endl;
	outfile << "		Name: " << petNames[numDaysAtStoreMinIndex] << endl;
	outfile << "		Days: " << daysAtStore[numDaysAtStoreMinIndex] << endl;
	outfile << "		Type: " << toCapitalCase(getPetTypeString(petTypes[numDaysAtStoreMinIndex])) << endl;
}

/**************************************************************
Function: writePetAverageStats()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: writes the data for average amount of time that
	animals stay at the store & which animals exceed that value
Input parameters: outfile, averageDays, aboveAveragePets[],
	numPetsAboveAverageStay
Returns: 4th block of ouput to output file
**************************************************************/
void writePetAveragesStats(ofstream& outfile, double averageDays, const string aboveAveragePets[], int numPetsAboveAverageStay)
{
	outfile << "Average days on site: " << averageDays << "\n" << endl;
	outfile << "Pets on site longer than average days on site:" << endl;
	for(int i = 0; i < numPetsAboveAverageStay; i++)
	{
		outfile << "		" << aboveAveragePets[i] << endl;
	}
	outfile << endl;
}

/**************************************************************
Function: toCapitalCase()
Date Created: 4/3/21
Date Last Modified: 4/5/21
Description: converts a lowercase string to a string where
	the first letter is capitalized
Input parameters: inputString
Returns: inputString (updated version)
**************************************************************/
string toCapitalCase(string inputString)
{
	int i = 0;
	
	switch(inputString.at(i))
	{
		case 98:
			inputString.at(i) = 66;
			break;
		case 99:
			inputString.at(i) = 67;
			break;
		case 100:
			inputString.at(i) = 68;
			break;
		case 102:
			inputString.at(i) = 70;
			break;
		default:
			inputString.at(i) = 79;
			break;	
	}
	
	return inputString;
}
