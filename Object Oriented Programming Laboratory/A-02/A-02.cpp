// Problem Statement:
// Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). The
// program should take two operands from user and performs the operation on those two
// operands depending upon the operator entered by user. Use a switch statement to select
// the operation. Finally, display the result.

#include <iostream>
using namespace std;

class Calculator {
    float num1, num2;
    public:
    Calculator() {
        cout << "Enter num1: ";
        cin >> num1;
        cout << "Enter num2: ";
        cin >> num2;
    }
    void addition() {
        cout << "Addition: " << num1 + num2 << "\n";
    }
    void subtraction() {
        cout << "Subtraction: " << num1 - num2 << "\n";
    }
    void multiplication() {
        cout << "Multiplication: " << num1 * num2 << "\n";
    }
    void division() {
        cout << "Division: " << num1 / num2 << "\n";
    }
};

int main() {
    Calculator Obj;
    char choice;
    do {
        cout << "Enter Operator(+, -, *, /): ";
        cin >> choice;

        switch (choice) {
            case '+':
                Obj.addition();
                break;
            case '-':
                Obj.subtraction();
                break;
            case '*':
                Obj.multiplication();
                break;
            case '/':
                Obj.division();
                break;
            default:
                cout << "Invalid Choice\n";
                break;
        }
    } while (choice != '0');
    return 0;
}