#include <iostream>
#include <limits>
#include <string>
using namespace std;

const int NUM_REGIONS = 4;
void getRegionData(string& name, int& accidents);
int getValidatedAccidents();
bool isLower(int value1, int value2);
void findSafestRegion(string& safestName, int& lowestAccidents);
void displayResult(const string& safestName, int lowestAccidents);

int main()
{
    string safestRegion;
    int lowestAccidents;
    findSafestRegion(safestRegion, lowestAccidents);
    displayResult(safestRegion, lowestAccidents);
        return 0;
}
/* Prompts the user for a region name and number of accidents.
Accident count is validated and returned through reference parameter. */
void getRegionData(string& name, int& accidents)
{
    cout << "\nEnter the name of the region: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    accidents = getValidatedAccidents();
}
/* Validates that accident input is greater than 0. */
int getValidatedAccidents()
{
    int accidents;

        while (true)
        {
            cout << "Enter the number of accidents: ";
            cin >> accidents;

        if (cin.fail() || accidents <= 0)
        {
            cout << "Invalid input. Accidents must be greater than 0.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            return accidents;
        }
    }
}
/* Determines whether one accident count is less than or equal to another. */
bool isLower(int value1, int value2)
{
    return value1 <= value2;
}
/* Finds the region with the lowest number of accidents. */
void findSafestRegion(string& safestName, int& lowestAccidents)
{
    string name;
    int accidents;
    cout << "Region 1:";
    getRegionData(name, accidents);
    safestName = name;
    lowestAccidents = accidents;
    for (int i = 2; i <= NUM_REGIONS; i++)
    {
        cout << "\nRegion " << i << ":";
        getRegionData(name, accidents);
        if (isLower(accidents, lowestAccidents))
        {
            lowestAccidents = accidents;
            safestName = name;
        }
    }
}
/* Displays the region with the lowest number of accidents. */
void displayResult(const string& safestName, int lowestAccidents)
{
    cout << "\n--- Safest Region ---\n";
    cout << "Region: " << safestName << endl;
    cout << "Number of Accidents: " << lowestAccidents << endl;
}