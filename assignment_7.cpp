/*
        Write a program in C++ to use map associative container. The keys will be the names of states
        and the values will be the populations of the states. When the program runs, the user is
        prompted to type the name of a state. The program then looks in the map, using the state
        name as an index and returns the population of the state.
 */

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class StatesInfo{
private:
    // creating the map object.
    map<string, int> states;
    // list of the states.
    vector<string> sList;
public:
    // function to check whether a state/key is present in the map.
    bool contains(string k){
        for(string st:sList){
            if(k==st){
                return true;
            }
        }
        return false;
    }
    // function to put key and value pair in the map.
    void put(string k, int v){
        states[k]=v;
        sList.push_back(k);
    }
    // function to get the population of a state.
    int get(string k){
        if(states.empty()){
            cout<<"The Map is empty!!"<<endl;
        }
        else{
            if(contains(k)) {
                cout<<"The population of the "<<k<<" is: ";
                cout << states[k] << endl;
            }
            else{
                cout<<"No such state present in the database!"<<endl;
            }
        }
    }
};

int main(){
    int res=1;
    StatesInfo si;
    while(res==1) {
        int choice;
        cout<<"What would you like to do?"<<endl;
        cout<<"1.Set information.\n2.Get information about a state."<<endl;
        cout<<"Your response(1 or 2): ";
        cin>>choice;
        if(choice==1){
            string name;    // name of state.
            int p;  // population.
            cout<<"Enter the name of the state: ";
            cin>>name;
            cout<<"Enter its population: ";
            cin>>p;
            si.put(name, p);
        }
        else if(choice==2){
            string name;
            cout<<"Enter the name of the state: ";
            cin>>name;
            si.get(name);
        }
        else{
            cout<<"Invalid choice!"<<endl;
        }
        cout<<"Do you want to continue manipulating?(Yes - 1, No - 2): ";
        cin>>res;
    }
}