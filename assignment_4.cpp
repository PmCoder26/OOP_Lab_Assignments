/*
        Assignment_4.

        Write a C++ program that creates an output file, writes information to it, closes the file, open
        it again as an input file and read the information from the file.

 */

#include<iostream>
#include<fstream>
using namespace std;


static string fileName="";

// function to set the name of the file.
void setName(){
    cout<<"Enter the name of the file: ";
    cin>>fileName;
}

// function to write text in the file.
void writeFile(ofstream &outputFile){
    if(!outputFile.is_open()){
        cout<<"File is closed!"<<endl;
        return;
    }
    else{
        int choice=1;
        string text = "";
        cout<<"Writing the data in the file."<<endl;
        while(choice==1) {
            cout << "Enter a line in the file:";
            string subText1="";
            string subText2="";
            cin>>subText2;
            getline(cin, subText1);
            cout<<"Do you want to write another line in the file?"<<endl;
            cout<<"1.Yes\n2.No"<<endl;
            cout<<"Your response-";
            cin>>choice;
            text+=subText2+subText1;
            if(choice==1){
                text+="\n";
            }
        }
        outputFile<<text;
        outputFile.close();
    }
}

// function to read the information from the file
void readFile(ifstream &inputFile){
    if(!inputFile.is_open()){
        cout<<"File is closed!"<<endl;
    }
    else{
        cout<<"Reading the information from the file:"<<endl;
        string line="";
        while(getline(inputFile, line)){
            cout<<line<<endl;
        }
        inputFile.close();
    }
}



int main(){

   int choice=1;
   while(choice==1){
       // setting the name of the file.
    setName();
    int ans=-1;
    cout<<"What would you like to perform?"<<endl;
    cout<<"1.Write File\n2.Read File"<<"\nYour Response-";
    cin>>ans;
    if(ans==1) {
        // creating the file to write the data.
        ofstream outputFile;

        // opening the output file.
        outputFile.open(fileName, ios::out);

        // writing in the file.
        writeFile(outputFile);
    }
    else if(ans==2) {
        // creating the input file to read the information.
        ifstream inputFile;

        // opening the input file.
        inputFile.open(fileName, ios::in);

        // reading the information from the file.
        readFile(inputFile);
    }
    cout<<"Do you want to continue program?"<<"\n1.Yes\n2.No"<<endl;
    cout<<"Your response-";
    cin>>choice;
   }











    return 0;
}