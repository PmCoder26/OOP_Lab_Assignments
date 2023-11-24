/*
        Assignment-6.
         Write C++ program using STL for sorting and searching user
         defined records such as personal records (Name, DOB, Telephone
         number etc.) using vector container.
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Record{
public:
    string name, DOB;   // name and date of birth resp.
    int teleNo;    // telephone no.
    Record(){
        cout<<"Enter the name: ";
        cin>>this->name;
        cout<<"Enter the date of birth(DD/MM/YYYY): ";
        cin>>this->DOB;
        cout<<"Enter the telephone number: ";
        cin>>teleNo;
        cout<<"Record created successfully!"<<endl;
    }
    void printRecord(){
        cout<<"The details of the record are as follows:"<<endl;
        cout<<"*******************************************************"<<endl;
        cout<<"Name: "<<this->name<<endl;
        cout<<"Date of birth: "<<this->DOB<<endl;
        cout<<"Telephone number: "<<this->teleNo<<endl;
        cout<<"*******************************************************"<<endl;
    }
};

class RecordHub{
private:
    // record book.
    vector<Record> r;
public:
    // method to print all the records.
    void printAll(){
        if(r.size()==0){
            cout<<"No records to print!"<<endl;
            return;
        }
        else{
            for(int x=0; x<r.size(); x++){
                r.at(x).printRecord();
            }
        }
    }
    // method to create record.
    void newRecord(){
        Record nr;
        r.push_back(nr);
        }
    // method to search record using the name.
    void nameSearch(){
        if(r.empty()){
            cout<<"No records to search!"<<endl;
            return;
        }
        else{
            string name;
            cout<<"Enter the name: ";
            cin>>name;
            for(int x=0; x<r.size(); x++){
                Record curr=r.at(x);
                if(curr.name==name){
                    cout<<"Record found at index "<<x<<endl;
                    curr.printRecord();
                    return;
                }
            }
            // if no record found in the record book.
            cout<<"No record found!"<<endl;
        }
    }
    // method to search record using the date of birth.
    void birthDateSearch(){
        if(r.empty()){
            cout<<"No records to search!"<<endl;
            return;
        }
        else{
            string dob;
            cout<<"Enter the date of birth: ";
            cin>>dob;
            for(int x=0; x<r.size(); x++){
                Record curr=r.at(x);
                if(curr.DOB==dob){
                    cout<<"Record found at index "<<x<<endl;
                    curr.printRecord();
                    return;
                }
            }
            // if no record found in the record book.
            cout<<"No record found!"<<endl;
        }
    }
    // method to search record using the telephone number.
    void teleSearch(){
        if(r.empty()){
            cout<<"No records to search!"<<endl;
            return;
        }
        else{
            int tn;
            cout<<"Enter the telephone number: ";
            cin>>tn;
            for(int x=0; x<r.size(); x++){
                Record curr=r.at(x);
                if(curr.teleNo==tn){
                    cout<<"Record found at index "<<x<<endl;
                    curr.printRecord();
                    return;
                }
            }
            // if no record found in the record book.
            cout<<"No record found!"<<endl;
        }
    }
    // method for searching a record.
    void searchSection(){
        if(r.empty()){
            cout<<"No records to search!"<<endl;
            return;
        }
        else{
            int choice;
            cout<<"On the basis of what data would you"
                  " like to sort?"<<endl;
            cout<<"1.Name.\n2.Date of birth."
                  "\n3.Telephone No."<<endl;
            cout<<"Your response(1, 2 or 3): ";
            cin>>choice;
            if(choice==1){
                nameSearch();
            }
            else if(choice==2){
                birthDateSearch();
            }
            else if(choice==3){
                teleSearch();
            }
            else{
                cout<<"Invalid choice!"<<endl;
            }
        }
    }
    // method to sort name-wise.
    void nameSort(){
        if(r.empty()){
            cout<<"No records to sort!"<<endl;
            return;
        }
        else{
            // using the selection sort technique.
            for(int x=0; x<r.size()-1; x++){
                // index of the min element.
                int min=x;
                for(int y=x+1; y<r.size(); y++){
                    if(r.at(min).name>r.at(y).name){
                        min=y;
                    }
                }
                // swapping the records.
                Record temp=r.at(min);
                r.at(min)=r.at(x);
                r.at(x)=temp;
                // printing the sorted book.
                cout<<"The sorted record book is:"<<endl;
            }
        }
    }
    // method to sort birth date-wise.
    void birthDateSort(){
        if(r.empty()){
            cout<<"No records to sort!"<<endl;
            return;
        }
        else{
            // using the selection sort technique.
            for(int x=0; x<r.size()-1; x++){
                // index of the min element.
                int min=x;
                string minyr;
                for(int y=x+1; y<r.size(); y++){
                    // comparing the birth year of current min with others.
                    if(r.at(min).DOB.substr(6)>r.at(y).DOB.substr(6)){
                        min=y;
                    }
                }
                // swapping the records.
                Record temp=r.at(min);
                r.at(min)=r.at(x);
                r.at(x)=temp;
            }
            // printing the sorted book.
            cout<<"The sorted record book is:"<<endl;
            printAll();
        }
    }
    // method to sort telephone Number-wise.
    void teleSort(){
        if(r.empty()){
            cout<<"No records to sort!"<<endl;
            return;
        }
        else{
            // using the selection sort technique.
            for(int x=0; x<r.size()-1; x++){
                // index of the min element.
                int min=x;
                for(int y=x+1; y<r.size(); y++){
                    if(r.at(min).teleNo>r.at(y).teleNo){
                        min=y;
                    }
                }
                // swapping the records.
                Record temp=r.at(min);
                r.at(min)=r.at(x);
                r.at(x)=temp;
            }
            // printing the sorted book.
            cout<<"The sorted record book is:"<<endl;
            printAll();
        }
    }
    // method to sort the record book (r).
    void sortSection(){
        if(r.empty()){
            cout<<"No records to sort!"<<endl;
            return;
        }
        else{
            int choice;
            cout<<"On the basis of what data would you"
                  " like to sort?"<<endl;
            cout<<"1.Name.\n2.Date of birth(year wise).\n3.Telephone No."<<endl;
            cout<<"Your response(1, 2 or 3): ";
            cin>>choice;
            if(choice==1){
                nameSort();
            }
            else if(choice==2){
                birthDateSort();
            }
            else if(choice==3){
                teleSort();
            }
            else{
                cout<<"Invalid choice!"<<endl;
            }
        }

    }

};

int main(){
    int res=1;
    while(res==1){
        RecordHub rh;
        int ans=1;
        while(ans==1){
            int choice;
            cout<<"What would you like to perform?"<<endl;
            cout<<"1.Add Record.\n2.Search a record.\n3.Sort Records.\n4.Print Record Book."<<endl;
            cout<<"Your response: ";
            cin>>choice;
            if(choice==1){
                rh.newRecord();
            }
            else if(choice==2){
                rh.searchSection();
            }
            else if(choice==3){
                rh.sortSection();
            }
            else if(choice==4){
                rh.printAll();
            }
            else{
                cout<<"Invalid choice!"<<endl;
            }
            cout<<"Do you want to continue manipulating with same record book?\n";
            cout<<"Your response(Yes - 1, No - 2): ";
            cin>>ans;
        }
        cout<<"Do you want to continue the program?\n";
        cout<<"Your response(Yes - 1, No - 2):c";
        cin>>res;
    }
    return 0;
}
