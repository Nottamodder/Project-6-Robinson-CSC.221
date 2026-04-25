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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    findSafestRegion(safestRegion, lowestAccidents);
    displayResult(safestRegion, lowestAccidents);
        return 0;
}
void getRegionData(string& name, int& accidents)
{
    cout << "\nEnter the name of the region: ";
    getline(cin, name);
    accidents = getValidatedAccidents();
}
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
            }
        else
        {
            return accidents;
        }
    }
}
bool isLower(int value1, int value2)
{
    return value1 <= value2;
}
void findSafestRegion(string& safestName, int& lowestAccidents)
    {
    string name;
    int accidents;
    cout << "Region 1\n";
    getRegionData(name, accidents);
    safestName = name;
    lowestAccidents = accidents;
        for (int i = 2; i <= NUM_REGIONS; i++)
        {
        cout << "\nRegion " << i << "\n";
        getRegionData(name, accidents);

        if (isLower(accidents, lowestAccidents))
            {
            lowestAccidents = accidents;
            safestName = name;
            }
        }
    }
void displayResult(const string& safestName, int lowestAccidents)
{
    cout << "\n--- Safest Region ---\n";
    cout << "Region: " << safestName << endl;
    cout << "Number of Accidents: " << lowestAccidents << endl;
}