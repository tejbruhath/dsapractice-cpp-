//everything about pointers
//use pointers when working with large objects where copying would be expensive
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Myclass {
    private: 
    int num;
    public:
    Myclass(int n = 0) : num(n) {}//initialization list(mandatory for const and reference variables)
    void setValue(int n){
        num = n;
    }
    int getValue() const{//const for read-only operations to not change anything
        return num;
    }
};
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
    vector<Myclass*> pointerVector;

    //create objects for Myclass and store the address in pointerVector
    for (int i = 0; i<5; i++){
        Myclass* obj = new Myclass(i);
        pointerVector.push_back(obj);
    }
    //example value in pointerVector
    cout<<"value in pointerVector(address): "<<pointerVector.at(0)<<endl;
    cout<<"value of obj pointerV is pointing too: "<<pointerVector.at(0)->getValue()<<endl;//lot of "point" in this line XD
    //set method
    pointerVector.at(0)->setValue(pointerVector.at(0)->getValue() + 5);
    cout<<"value of obj 1 after set method: "<<pointerVector.at(0)->getValue()<<endl;
    //simpler set method
    pointerVector.at(0)->setValue(10);

    //delete the objects
    for(auto ptr: pointerVector){
        delete ptr;//what happens if we dont delete the pointer?
    }



}