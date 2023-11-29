/*
                                Assignment-3.
        Imagine a publishing company which does marketingfor book and
        audio cassette versions.Create a class publication that stores
        the title (a string) and price (type float) of publications.
        From this class derive two classes: book which adds a page count
        (type int) and tape which adds a playing time in minutes (type float).
        Write a program that instantiates the book and tape class, allows user
        to enter data and displays the data members. If an exception is caught,
        replace all the data member values with zero values.

 */

#include<iostream>
using namespace std;

class Publication{
    protected:
        string title="";
        float price=0;

};

class Book:public Publication{
    int count=0;
    public:
        void setData(){
            cout<<"Enter the title: ";
            string temp;
            cin>>temp;  // for successful reading the title.
            getline(cin, title);
            cout<<"Enter the no.of pages: ";
            cin>>this->count;
            cout<<"Enter the price of book: ";
            cin>>this->price;
        }
        void getData(){
            cout<<"The details of the book are: "<<endl;
            cout<<"*****************************************************"<<endl;
            cout<<"Title: "<<this->title<<endl;
            cout<<"Total pages: "<<this->count<<endl;
            cout<<"Price: "<<this->price<<endl;
            cout<<"*****************************************************"<<endl;
        }
};

class Tape:public Publication{
    float playTime=0;
    public:
        void setData(){
            cout<<"Enter the title: ";
            string temp;
            cin>>temp;  // for successful reading the title.
            getline(cin, title);
            cout<<"Enter the play time of audio in minutes: ";
            cin>>this->playTime;
            cout<<"Enter the price of tape: ";
            cin>>this->price;
        }
        void getData(){
            cout<<"The details of the tape are: "<<endl;
            cout<<"***************************************************"<<endl;
            cout<<"Title: "<<this->title<<endl;
            cout<<"Total pages: "<<this->playTime<<endl;
            cout<<"Price: "<<this->price<<endl;
            cout<<"***************************************************"<<endl;
        }
};

class Market{
        Book bookArr[1000];
        Tape tapeArr[1000];
        void bookSection(){
            int choice;
            cout<<"What operation would you like to perform?"<<endl;
            cout<<"1. Add a Book.\n2. Access Information.\n3. Exit."<<endl;
            cout<<"Your Response: ";
            cin>>choice;
            if (choice == 1) {
                int n = -1;
                cout << "Enter the book number: ";
                cin >> n;
                bookArr[n - 1].setData();
                return;
            } else if (choice == 2) {
                int n = -1;
                cout << "Enter the book number: ";
                cin >> n;
                bookArr[n - 1].getData();
                return;
            } else if (choice == 3) {
                cout << "Thank-you!!" << endl;
                return;
            }
            else{
                cout<<"Invalid choice!"<<endl;
            }
        }
        void tapeSection(){
            int choice;
            cout<<"What operation would you like to perform?"<<endl;
            cout<<"1. Add a cassette.\n2. Access Information.\n3. Exit."<<endl;
            cout<<"Your Response: ";
            cin>>choice;
                if (choice == 1) {
                    int n = -1;
                    cout << "Enter the cassette number: ";
                    cin >> n;
                    tapeArr[n - 1].setData();
                }
                else if (choice == 2) {
                    int n = -1;
                    cout << "Enter the cassette number: ";
                    cin >> n;
                    tapeArr[n - 1].getData();
                }
                else if (choice == 3) {
                    cout << "Thank-you!!" << endl;
                }
                else{
                    cout<<"Invalid choice!";
                }
        }
    public:
        void start() {
            int res = 1;
            try {
                while (res == 1) {
                    int choice = -1;
                    cout << "Which section would you like to access?" << endl;
                    cout << "1. Books\n2. Tapes.\nYour Response: ";
                    cin >> choice;
                    try {
                        if (choice == 1) {
                            int c1 = 1;
                            while (c1 == 1) {
                                bookSection();
                                cout << "Do you want to continue book section?"
                                        "\nYes-1.\nNo-2.\nYour Response: ";
                                cin >> c1;
                            }
                        } else if (choice == 2) {
                            int c1 = 1;
                            while (c1 == 1) {
                                tapeSection();
                                cout << "Do you want to continue tape section?"
                                        "\nYes-1.\nNo-2.\nYour Response: ";
                                cin >> c1;
                            }
                        }
                        if (choice != 1 && choice != 2) {
                            throw (choice);
                        }
                    }
                    catch(int x){
                        cout<<"Invalid choice entered!"<<endl;
                        break;
                    }
                    cout << "Do you want to continue program?"
                            "\nYes-1.\nNo-2.\nYour Response: ";
                    cin >> res;
                }
            }
            catch(int x){
                cout<<"Invalid choice entered!"<<endl;
            }
        }
};


int main(){
    Market m;
    m.start();
    return 0;
}
