// Problem Statement:
// Imagine a publishing company which does marketing for book and audio cassette
// versions. Create a class publication that stores the title (a string) and price (type float) of
// a publication.
// From this class derive two classes: book, which adds a page count (type int), and tape,
// which adds a playing time in minutes (type float).
// Write a program that instantiates the book and tape classes, allows user to enter data
// and displays the data members. If an exception is caught, replace all the data member
// values with zero values.

#include<iostream>
using namespace std;

class Publication {
    string title;
    float price;

    public:
    Publication() {
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Price: ";
        cin >> price;
    }

    Publication(string t, float p) {
        title = t;
        price = p;
    }

    void display() {
        try {
            if(title.length() <= 3) {
                throw title;
            }
        } catch(string t) {
            title = "";
        }

        try {
            if(price < 0) {
                throw price;
            }
        } catch(float p) {
            price = 0;
        }

        cout << "Title: " << title << "\n";
        cout << "Price: " << price << "\n";
    }
};

class Book : public Publication {
    int pageCount;
    public:

    Book() {
        cout << "Enter Page Count: ";
        cin >> pageCount;
    }

    Book(string t, float p, int pc) : Publication(t, p) {
        pageCount = pc;
    }

    void display() {
        Publication::display();
        try {
            if(pageCount < 0) {
                throw pageCount;
            }
        } catch(int pc) {
            pageCount = 0;
        }
        cout << "Page Count: " << pageCount << "\n";
    }
};

class Tape : public Publication {
    float playingTime;
    public:

    Tape() {
        cout << "Enter Playing Time (in mins): ";
        cin >> playingTime;
    }

    Tape(string t, float p, float pt) : Publication(t, p) {
        playingTime = pt;
    }

    void display() {
        Publication::display();
        try {
            if(playingTime < 0) {
                throw playingTime;
            }
        } catch(float pt) {
            playingTime = 0;
        }
        cout << "Playing Time: " << playingTime << "\n";
    }
};

int main() {
    cout << "For Book:  \n"; 
    Book b;
    b.display();

    cout << "For Tape:  \n";
    Tape t;
    t.display();
    
    return 0;
}