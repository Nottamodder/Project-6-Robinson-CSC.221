#include <iostream>
#include <iomanip>
using namespace std;

const int MIN_FAHRENHEIT = 0;
const int MAX_FAHRENHEIT = 20;
void displayTitle();
void displayHeadings();
double convertToCelsius(int fahrenheit);
void displayTable();

/* Displays the title of the temperature conversion table. */
void displayTitle() {
    cout << "Fahrenheit to Celsius Conversion Table\n";
    cout << "--------------------------------------\n";
}
/* Displays the column headings for Fahrenheit and Celsius values. */
void displayHeadings() {
    cout << right << setw(12) << "Fahrenheit"
        << setw(12) << "Celsius" << endl;
    cout << right << setw(12) << "----------"
        << setw(12) << "-------" << endl;
}
/* Converts a temperature from Fahrenheit to Celsius. */
double convertToCelsius(int fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}
/* Generates and displays the full temperature conversion table from the minimum to maximum Fahrenheit values. */
void displayTable() {
    for (int f = MIN_FAHRENHEIT; f <= MAX_FAHRENHEIT; f++) {
        double c = convertToCelsius(f);
        cout << right << setw(12) << f
            << setw(12) << fixed << setprecision(1) << c << endl;
    }
}
int main() {
    displayTitle();
    displayHeadings();
    displayTable();
    return 0;
}