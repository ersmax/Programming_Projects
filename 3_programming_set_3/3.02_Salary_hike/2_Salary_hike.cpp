/*
Write a program to gauge the rate of an employee’s raise from the previous year.
The program asks for their annual salary in this year and the previous year. It estimates
the hike percentage as the difference in their salary from the previous year
divided by the previous year’s salary. Your program should allow the user to repeat
this calculation as often as the user wishes. Define a function to compute the hike
percentage for an employee. The hike rate should be a value of type double giving
the rate as a percentage, for example 5.3 for 5.3%.
*/
#include <iostream>
using namespace std;

double raise(double currentSalary, double priorSalary);
// Precondition: priorSalary is not zero
// Postcondition: returns the hike percentage

void displayHike(double hike);
// Precondition: hike is the percentage or -1 if prior salary is zero
// Postcondition: Displays the hike or an error message

int main( ) {
    char answer;
    double currentYearSalary, lastYearSalary, salaryHike;

    do {
        cout << "Enter current and last year salary "
             << "(separated by space):";
        cin >> currentYearSalary >> lastYearSalary;

        if (currentYearSalary < 0 || lastYearSalary < 0) {
            cerr << "Error: Salaries cannot be negative.\n";
        } else {
            salaryHike = raise(currentYearSalary, lastYearSalary);
            displayHike(salaryHike);
        }

        cout << "Repeat? (y/Y):";
        cin >> answer;
    } while (answer == 'y' || answer == 'Y');

    return 0;
}

double raise(double currentSalary, double priorSalary) {
    if (priorSalary == 0)
        return -1;
    return ((currentSalary - priorSalary) / priorSalary) * 100;
}

void displayHike(double hike) {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if (hike == -1)
        cerr << "Error: prior salary cannot be zero.\n";
    else
        cout << "The salary hike is: " << hike << "%.\n";
}