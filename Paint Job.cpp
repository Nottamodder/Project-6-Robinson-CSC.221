#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

const double GALLONS_PER_SQFT = 1.0 / 110.0;
const double HOURS_PER_SQFT = 8.0 / 110.0;
const double LABOR_RATE = 25.0;
int getNumRooms();
double getPricePerGallon();
double getSqFt(int roomNumber);
int gallonsForRoom(double sqFt);
double laborHoursForRoom(double sqFt);
void displayEstimate(int totalGallons, double totalHours,
    double paintCost, double laborCost, double totalCost);

int main() {
    int numRooms = getNumRooms();
    double pricePerGallon = getPricePerGallon();
    int totalGallons = 0;
    double totalHours = 0.0;

    for (int i = 1; i <= numRooms; i++) {
        double sqFt = getSqFt(i);
        int gallons = gallonsForRoom(sqFt);
        double hours = laborHoursForRoom(sqFt);
            totalGallons += gallons;
            totalHours += hours;
    }
    double paintCost = totalGallons * pricePerGallon;
    double laborCost = totalHours * LABOR_RATE;
    double totalCost = paintCost + laborCost;
        displayEstimate(totalGallons, totalHours, paintCost, laborCost, totalCost);
    return 0;
}

/* Prompts the user for the number of rooms and validates input. */
int getNumRooms() {
    int rooms;
        while (true) {
            cout << "Enter number of rooms: ";
            cin >> rooms;

        if (cin.fail() || rooms < 1) {
            cout << "Invalid input. Must be at least 1 room.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return rooms;
        }
    }
}

/* Prompts for paint price per gallon and validates input. */
double getPricePerGallon() {
    double price;
        while (true) {
            cout << "Enter price per gallon of paint: ";
            cin >> price;

        if (cin.fail() || price < 10.0) {
            cout << "Invalid input. Must be at least $10.00.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return price;
        }
    }
}

/* Prompts for square footage of a room and validates input. */
double getSqFt(int roomNumber) {
    double sqFt;
        while (true) {
            cout << "Enter square feet for room " << roomNumber << ": ";
            cin >> sqFt;

        if (cin.fail() || sqFt < 0) {
            cout << "Invalid input. Must be 0 or greater.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return sqFt;
        }
    }
}
/* Calculates gallons of paint required for a room. */
int gallonsForRoom(double sqFt) {
    return ceil(sqFt * GALLONS_PER_SQFT);
}

/* Calculates labor hours required for a room. */
double laborHoursForRoom(double sqFt) {
    return sqFt * HOURS_PER_SQFT;
}

/* Displays the full cost estimate for the paint job. */
void displayEstimate(int totalGallons, double totalHours,
    double paintCost, double laborCost, double totalCost) {
   cout << fixed << setprecision(2);
    cout << "\n--- Paint Job Estimate ---\n";
    cout << "Total gallons required: " << totalGallons << endl;
    cout << "Total labor hours: " << totalHours << endl;
    cout << "Cost of paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCost << endl;
    cout << "Total cost: $" << totalCost << endl;
}