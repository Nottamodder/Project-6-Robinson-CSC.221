#include <iostream>
#include <limits>
#include <string>
using namespace std;

const int NUM_REGIONS = 4;
void getRegionData(string& name, int& accidents);
int getValidatedAccidents();
void findSafestRegion(string& safestName, int& lowestAccidents);
void displayResult(const string& safestName, int lowestAccidents);

int main() {
    string safestRegion;
    int lowestAccidents;

    findSafestRegion(safestRegion, lowestAccidents);
    displayResult(safestRegion, lowestAccidents);
    return 0;
}
 /* Prompts the user to enter the name of a region and the number of accidents.
  Ensures that the accident count is valid before returning values. */

void getRegionData(string& name, int& accidents) {
    cout << "\nEnter the name of the region: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    accidents = getValidatedAccidents();
}
  /* Prompts the user to enter the number of accidents.
  Ensures the value is greater than 0 and rejects invalid input. */

int getValidatedAccidents() {
    int accidents;

    while (true) {
        cout << "Enter the number of accidents: ";
        cin >> accidents;

        if (cin.fail() || accidents <= 0) {
            cout << "Invalid input. Please enter a number greater than 0.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return accidents;
        }
    }
}
  /* Collects data for all regions and determines which region
  has the lowest number of accidents. */

void findSafestRegion(string& safestName, int& lowestAccidents) {
    string name;
    int accidents;

    // Get first region to initialize minimum
    cout << "Region 1:";
    getRegionData(name, accidents);
    safestName = name;
    lowestAccidents = accidents;

    // Process remaining regions
    for (int i = 2; i <= NUM_REGIONS; i++) {
        cout << "\nRegion " << i << ":";
        getRegionData(name, accidents);
        if (accidents < lowestAccidents) {
            lowestAccidents = accidents;
            safestName = name;
        }
    }
}
 /* Displays the region with the lowest number of accidents. */
void displayResult(const string& safestName, int lowestAccidents) {
    cout << "\n--- Safest Region ---\n";
    cout << "Region: " << safestName << endl;
    cout << "Number of Accidents: " << lowestAccidents << endl;
}