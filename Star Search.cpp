#include <iostream>
#include <limits>
using namespace std;

double getScore();
bool isLower(double value1, double value2);
bool isHigher(double value1, double value2);
double calcAverage(double total, double minScore, double maxScore);

int main() 
{
    double score, total = 0.0;
    double minScore, maxScore;
    cout << "Enter score for judge 1:\n";
    score = getScore();
    minScore = score;
    maxScore = score;
    total += score;

    for (int i = 2; i <= 5; i++) {
        cout << "Enter score for judge " << i << ":\n";
                score = getScore();
        if (isLower(score, minScore))
            minScore = score;
        if (isHigher(score, maxScore))
            maxScore = score;
                total += score;
    }
    double finalScore = calcAverage(total, minScore, maxScore);
    cout << "\nFinal Score: " << finalScore << endl;
    return 0;
}

/* Prompts the user to enter a judge's score and validates the input. */
double getScore() {
    double score;

    while (true) {
        cout << "Enter a score (0 - 10): ";
        cin >> score;
       if (cin.fail() || score < 0.0 || score > 10.0) {
            cout << "Invalid input. Enter a value between 0 and 10.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            return score;
        }
    }
}

/* Determines whether one score is less than or equal to another. */
bool isLower(double value1, double value2) {
    return value1 <= value2;
}
/* Determines whether one score is greater than or equal to another. */
bool isHigher(double value1, double value2) {
    return value1 >= value2;
}
/* Calculates the average score after removing the highest and lowest scores. */
double calcAverage(double total, double minScore, double maxScore) {
    return (total - minScore - maxScore) / 3.0;
}