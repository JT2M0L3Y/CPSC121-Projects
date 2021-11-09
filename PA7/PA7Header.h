/*
	Jonathan Smoley
	PA7: Header file
	CPSC121 Spring 2021
	Description: Stores necessary libraries and
		function prototypes as well as holds 
		header guard code to allow access from
		other files in PA7.
*/

#ifndef PA7Header
#define PA7Header

#include <iostream> // for IO
#include <iomanip> // for manipulators
#include <fstream>  // for file IO
#include <string>   // for string data type/functions
#include <cmath>    // to round the average days on site

using namespace std;

enum PetType {BIRD = 0, CAT, DOG, FISH, OTHER};
const int numPetTypes = 5;

bool fileOpen(ifstream& infile, ofstream& outfile, string inName, string outName);

void getPetStoreInfo(ifstream& infile, string& dateUpdated, string& petName, string& petStr, int& storeDays);

string getPetTypeString(PetType petType);

PetType getPetTypeCode(string petTypeString);

void setPetTypeCounts(const PetType petTypes[], int petTypeCounts[], int numPets);

int findMostFrequentPetType(const int petTypeCounts[], int numPetTypes);

void setAboveAverageDaysAtStore(const int daysAtStore[], int numPets, bool aboveAverageDaysAtStore[], int averageDays);

int findPetsWithAboveAverageStay(const string petNames[], const bool aboveAverageDaysAtStore[], int numPets, string aboveAveragePets[]);

void writePetSummaryHeader(ofstream& outfile, string petStoreName, int numPets);

void writeAnimalTypeSummary(ofstream& outfile, const int petTypeCounts[], int numPetTypes);

void writePetFrequencyStats(ofstream& outfile, const string petNames[], const int daysAtStore[], const PetType petTypes[], int mostFrequentAnimalTypeIndex, int numDaysAtStoreMinIndex, int numDaysAtStoreMaxIndex);

void writePetAveragesStats(ofstream& outfile, double averageDays, const string aboveAveragePets[], int numPetsAboveAverageStay);

string toCapitalCase(string inputString);

#endif
