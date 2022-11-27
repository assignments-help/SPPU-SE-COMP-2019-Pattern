// Problem Statement
// Implement a class Complex which represents the Complex Number data type. Implement
// the following
// 1. Constructor (including a default constructor which creates the complex number 0+0i).
// 2. Overloaded operator+ to add two complex numbers.
// 3. Overloaded operator* to multiply two complex numbers.
// 4. Overloaded << and >> to
// print and read Complex Numbers.

#include<iostream>
using namespace std;

class Complex {
    int real, imag;
    public:
    Complex() {
        real = 0;
        imag = 0;
    }
    friend Complex operator + (Complex, Complex);
    friend Complex operator * (Complex, Complex);
    friend istream & operator >> (istream &, Complex &);
    friend ostream & operator << (ostream &, Complex &);
};

Complex operator + (Complex num1, Complex num2) {
    Complex res;
    res.real = num1.real + num2.real;
    res.imag = num1.imag + num2.imag;
    return res;
}

Complex operator * (Complex num1, Complex num2) {
    Complex res;
    res.real = num1.real * num2.real - num1.imag * num2.imag;
    res.imag = num1.real * num2.imag + num1.imag * num2.real;
    return res;
}

istream & operator >> (istream &in, Complex &num) {
    cout << "Enter Real Part: ";
    in >> num.real;
    cout << "Enter Imaginary Part: ";
    in >> num.imag;
    return in;
}

ostream & operator << (ostream &out, Complex &num) {
    if(num.imag >= 0) {
        out << num.real << " + " << num.imag << "i\n"; 
    } else {
        out << num.real << " " << num.imag << "i\n";
    }
    return out;
}

int main() {
    Complex num1, num2, num3;

    cout << "Initialized num1: \n";
    cout << num1;
    cout << "Initialized num2: \n";
    cout << num1;

    int choice;

    do
    {
        cout << "Menu\n0: Exit\n1: Input\n2: Addition\n3: Multiplication\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "For num1: \n";
            cin >> num1;
            cout << "For num2: \n";
            cin >> num2;
            break;
        case 2:
            cout << "Addition: \n";
            num3 = num1 + num2;
            cout << num3;
            break;
        case 3:
            cout << "Multiplication: \n";
            num3 = num1 * num2;
            cout << num3;
            break;
        default:
            cout<<"Invalid Choice\n"; 
            break;
        }
    } while (choice != 0);
    
    return 0;
}