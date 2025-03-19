//everything about pointers
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int a = 5;
    int* ptr = &a;
    cout<< a << endl<<"print pointer value: "<<*ptr<<endl<<"print pointer address: "<<ptr<<endl;
    *ptr = 6;//*ptr is called dereferencing to access the value
    cout<< "changing a value after dereferencing: "<<a <<endl;
    ptr = nullptr;//points to null dont call ptr , it gives segementation fault
    cout<< "ptr is now null "<<ptr<<endl;
    //pointers in arrays
    int arr[] = {1,2,3,4,5};
    int *ptrarr = arr;

    //pointer arthmetic
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
        cout<<"printing the "<<i<<"th element using arthmetic pointer: ";
        cout<<*(ptrarr + i)<<endl;
    }
    cout<< "use arr[] or *(ptr+i)"<<endl;

    //container to store raw pointers using stl's
    vector<int*> pointerVector;

}