/*
        Write a function template for selection sort that inputs,
        sorts and outputs an integer array and a float array.
*/

#include<iostream>
using namespace std;

template<class T>
class SortHub{
private:
    int size;
    T arr[];
public:
    SortHub(){
        cout<<"Enter the size of the array: ";
        cin>>size;
        arr[size];
    }
    // function to create the array with respective data-type.
    void createArr(){
        for(int x=0; x<size; x++){
            cout<<"Enter element "<<x<<": ";
            cin>>arr[x];
        }
        cout<<"Array created successfully!"<<endl;
    }
    // function to print the array.
    void printArr(){
        if(size==0){
            cout<<"Array is empty!"<<endl;
        }
        else{
            for(int x=0; x<size; x++){
                cout<<arr[x]<<" ";
            }
            cout<<endl;
        }
    }
    // function to sort the array in ascending order.
    void selectionSort(){
        if(size==0){
            cout<<"Array is empty!"<<endl;
        }
        else{
            for(int x=0; x<size-1; x++){
                int min=x;
                for(int y=x+1; y<size; y++){
                    if(arr[min]>arr[y]){
                        min=y;
                    }
                }
                // swapping the elements.
                T temp=arr[min];
                arr[min]=arr[x];
                arr[x]=temp;
            }
        }
    }
};

int main(){

    int res=1;
    while(res==1) {
        cout<<"Integer array section!"<<endl;
        // object for the int array.
        SortHub<int> intSb;
        // creating the array.
        intSb.createArr();
        cout<<"The integer array before sorting: ";
        intSb.printArr();
        // sorting the integer array.
        intSb.selectionSort();
        // printing the sorted array.
        cout<<"The integer array after sorting: ";
        intSb.printArr();

        cout<<"Float array section!"<<endl;
        // object for the float array.
        SortHub<float> floatSb;
        // creating the array.
        floatSb.createArr();
        cout<<"The float array before sorting: ";
        floatSb.printArr();
        // sorting the float array.
        floatSb.selectionSort();
        // printing the sorted array.
        cout<<"The float array after sorting: ";
        floatSb.printArr();

        cout<<"Do you want to continue the program?(Yes - 1, No - 2)"<<endl;
        cout<<"Your response(1 or 2): ";
        cin>>res;
    }







}


