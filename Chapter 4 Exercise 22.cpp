#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    const double PLAN_A_BASE = 39.99, PLAN_A_GB = 2.0, EXTRA_RATE = 8.00;
    const double PLAN_B_BASE = 59.99, PLAN_B_GB = 8.0;
    const double PLAN_C_BASE = 79.99;

    string customerName;
    char planChoice;
    double gigabytesUsed;

    cout << "Enter customer name: ";
    getline(cin, customerName);
    cout << "Enter the plan purchased (A, B, or C): ";
    cin >> planChoice;
    cout << "Enter the number of gigabytes used: ";
    cin >> gigabytesUsed;

    if (gigabytesUsed < 0) {
        cout << "Error: Gigabytes used cannot be negative." << endl;
        return 1;
    }

    double costA = PLAN_A_BASE + (gigabytesUsed > PLAN_A_GB ? (gigabytesUsed - PLAN_A_GB) * EXTRA_RATE : 0);
    double costB = PLAN_B_BASE + (gigabytesUsed > PLAN_B_GB ? (gigabytesUsed - PLAN_B_GB) * EXTRA_RATE : 0);
    double costC = PLAN_C_BASE;

    planChoice = toupper(planChoice);

    cout << fixed << setprecision(2);
    cout << "Customer Name : " << customerName << endl;
    cout << "Plan Purchased: Plan " << planChoice << endl;
    cout << "Gigabytes Used: " << gigabytesUsed << " GB" << endl;

    if (planChoice == 'A') {
        cout << "Total Due: $" << costA << endl;
        if (costB < costA) cout << "Savings with Plan B: $" << (costA - costB) << endl;
        if (costC < costA) cout << "Savings with Plan C: $" << (costA - costC) << endl;
    }
    else if (planChoice == 'B') {
        cout << "Total Due: $" << costB << endl;
        if (costC < costB) cout << "Savings with Plan C: $" << (costB - costC) << endl;
    }
    else if (planChoice == 'C') {
        cout << "Total Due: $" << costC << endl;
    }
    else {
        cout << "Error: Invalid plan selected." << endl;
        return 1;
    }

    return 0;
}