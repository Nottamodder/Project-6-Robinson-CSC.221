#include <iostream>
#include <limits>
using namespace std;

// Function prototypes
double getValidatedInput(const string& prompt);
void getDimensions(double& length, double& width);
double calculatePerimeter(double length, double width);
double calculateArea(double length, double width);
void displayResults(double length, double width, double perimeter, double area);
bool processAgain();

int main() 
{
    do {
        double length, width;

        // Get and validate inputs
        getDimensions(length, width);

        // Perform calculations
        double perimeter = calculatePerimeter(length, width);
        double area = calculateArea(length, width);

        // Display results
        displayResults(length, width, perimeter, area);

    } while (processAgain());

    cout << "Program ended.\n";
    return 0;
}

// Function to get a validated positive number
double getValidatedInput(const string& prompt) {
    double value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0) {
            cout << "Invalid input. Please enter a number greater than 0.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return value;
        }
    }
}

// Function to get both dimensions
void getDimensions(double& length, double& width) {
    length = getValidatedInput("Enter the length: ");
    width = getValidatedInput("Enter the width: ");
}

// Function to calculate perimeter
double calculatePerimeter(double length, double width) {
    return 2 * (length + width);
}

// Function to calculate area
double calculateArea(double length, double width) {
    return length * width;
}

// Function to display results
void displayResults(double length, double width, double perimeter, double area) {
    cout << "\n--- Rectangle Results ---\n";
    cout << "Length: " << length << endl;
    cout << "Width: " << width << endl;
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;
}

// Function to ask user to repeat
bool processAgain() {
    char choice;

    while (true) {
        cout << "\nProcess another rectangle? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
            return true;
        else if (choice == 'n' || choice == 'N')
            return false;
        else
            cout << "Invalid choice. Please enter y or n.\n";
    }
}