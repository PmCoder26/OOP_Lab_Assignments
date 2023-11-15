#include<iostream>
using namespace std;

/*
        Assignment-2

        Develop an object-oriented program in C++ to create a database of student information
        system containing the following information: Name, Roll number, Class, division, Date of
        Birth, Blood group, Contact address, telephone number, driving license no. and other.
        Construct the database with suitable member functions for initializing and destroying the
        data viz constructor, default constructor, Copy constructor, destructor, static member
        functions, friend class, this pointer, inline code and dynamic memory allocation
        operators-new and delete.
*/

//-------------------------------------------------------------------------------------------------------------->
class Student{
    private:
        string name="-";    // name of class.
        int rollno=0;     // roll number.
        string cl="-";      // class.
        string dob="-";     // date of birth.
        string bg="-";      // blood group.
        string dlno="-";    // driving licence no.
        string address="-";
    public:
        void set_data(){
            cout<<"Enter name: ";
            string s="";
            getline(cin,s);
            getline(cin, this->name);
            cout<<"Enter roll number: ";
            cin>>this->rollno;
            cout<<"Enter class: ";
            cin>>this->cl;
            cout<<"Enter date of birth: ";
            cin>>this->dob;
            cout<<"Enter blood group: ";
            cin>>this->bg;
            cout<<"Enter driving licence number: ";
            cin>>this->dlno;
            cout<<"Enter contact address: ";
            string s1="";
            getline(cin, s1);
            getline(cin, this->address);
        }
        void get_data(){
            cout<<"Student name: "<<this->name<<endl;
            cout<<"Student roll number: "<<this->rollno<<endl;
            cout<<"Student class: "<<this->cl<<endl;
            cout<<"Student date of birth: "<<this->dob<<endl;
            cout<<"Student blood group: "<<this->bg<<endl;
            cout<<"Student driving licence number: "<<this->dlno<<endl;
            cout<<"Student contact address: "<<this->address<<endl;
        }
};
//-------------------------------------------------------------------------------------------------------------->


//-------------------------------------------------------------------------------------------------------------->
class Faculty{
    string div="";
    int id=0;
    Student stdArr[100];
    public:
        friend void createDataSet(Faculty &obj);
        friend int getFltId(Faculty &obj);
        friend Student getStdArr(Faculty &obj, int i);
    int n;
};
void createDataSet(Faculty &obj){
    cout<<"Enter division: ";
    cin>>obj.div;
    cout<<"Enter id: ";
    cin>>obj.id;
    cout<<"Enter the no.of students in class: ";
    cin>>obj.n;
    obj.stdArr[obj.n];
    int flag=1;
    int x=0;
    while(flag==1){
        int choice=0;
        cout<<"Menu: "<<endl;
        cout<<"What would you like to perform-"<<endl;
        cout<<"     1.Set student data."<<endl;
        cout<<"     2.Get student data."<<endl;
        cout<<"Enter your choice - ";
        cin>>choice;
        switch(choice){
            case 1:
                obj.stdArr[x].set_data();
                x++;
                break;
            case 2:
                cout<<"Enter the roll number of student: ";
                int r;
                cin>>r;
                obj.stdArr[r-1].get_data();
                break;
            default:
                break;
        }
        cout<<"Do you want to continue manipulating student's data??"<<endl;
        cout<<"\tYes-1\n\tNo-2."<<endl;
        cout<<"     Your Response - ";
        cin>>flag;
    }
}
int getFltId(Faculty &obj){
   return obj.id;
}
Student getStdArr(Faculty &obj, int i){
    return obj.stdArr[i];
}
//-------------------------------------------------------------------------------------------------------------->


//-------------------------------------------------------------------------------------------------------------->
int main() {
    int m = 0;
    int x = 0;
    cout << "Enter the no.of faculties: ";
    cin >> m;
    Faculty ftyArr[m];
    int cnt = 1;
    while (cnt == 1) {
        cout << "What would you like to perform?" << endl;
        cout << "     1.Create Faculty.\n      2.Access database." << endl;
        cout << "Your Response: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                createDataSet(ftyArr[x++]);
                break;
            case 2:
                cout << "Enter the id of faculty: ";
                int id;
                Faculty curr;
                cin >> id;
                for (int i = 0; i < m; i++) {
                    Faculty f = ftyArr[i];
                    if (getFltId(f) == id) {
                        curr = f;
                        break;
                    }
                }
                cout << "The students are: " << endl;
                for (int i = 0; i < curr.n; i++) {
                    cout << "-------------------------------------------------------------------" << endl;
                    getStdArr(curr, i).get_data();
                    cout << "-------------------------------------------------------------------" << endl;
                }
                break;
        }
        cout << "Do you want to continue the program?\n\tYes-1\n\tNo-2" << endl;
        cout << "Your Response-";
        cin >> cnt;
    }
    return 0;
}
//-------------------------------------------------------------------------------------------------------------->

