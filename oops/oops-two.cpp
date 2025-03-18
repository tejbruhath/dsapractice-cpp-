//this file will be on constructor and destructor
//comeback and learn baout ctime header and its functions
#include <iostream>
#include <string>
using namespace std;

class Consclass{//constructors init objects when they are to be created
    private:
    string name;
    int data;

    public:
    Consclass(){//default constructor, no arguments 
        name = "Tej";
        data = 19;

        cout<<"Default Constructor values!"<<endl;
    }
    Consclass(string name,int data){ // Parameterized constructor to initialize `name` and `data` with provided values
        this->name = name; //this keyword is used to distinguish between the class attributes and the parameters passed.
        this->data = data;
    }
    void display(){
        cout<<"Name: "<< name << ", data: "<<data<<endl;
    }
    ~Consclass(){//destructor, no arguments
        cout<<"Destructor called! for Consclass"<<endl;
    }

};
 /*destructor: 
    1. Resource Deallocation
    2.Resource Cleanup
    3.Automatically called: function para are destroyed when exec leaves the block
    3, local objects are destroyed after exec leaves the block
    4.Memory Leak Prevention
┌─────────────────────────────────────────┐
│            OBJECT CREATION              │
├─────────────────────────────────────────┤
│ 1. Memory Allocation                    │
│ 2. Base Class Constructors (if any)     │
│    - Called in order of declaration     │
│ 3. Member Object Constructors           │
│    - Called in order of declaration     │
│ 4. Class Constructor Body Execution     │
│    - Object Lifetime STARTS             │
└───────────────┬─────────────────────────┘
                │
                ▼
┌─────────────────────────────────────────┐
│             OBJECT USE                  │
│                                         │
│ - Object's methods are called           │
│ - Object's data is accessed/modified    │
└───────────────┬─────────────────────────┘
                │
                ▼
┌─────────────────────────────────────────┐
│          EXECUTION LEAVES BLOCK         │
├─────────────────────────────────────────┤
│ For automatic objects:                  │
│ - When function returns                 │
│ - When scope (block) ends               │
│ - When program terminates               │
│                                         │
│ For dynamic objects:                    │
│ - When delete or delete[] is called     │
└───────────────┬─────────────────────────┘
                │
                ▼
┌─────────────────────────────────────────┐
│           OBJECT DESTRUCTION            │
├─────────────────────────────────────────┤
│ 1. Class Destructor Body Execution      │
│ 2. Member Object Destructors            │
│    - Called in REVERSE order of         │
│      declaration                        │
│ 3. Non-virtual Base Class Destructors   │
│    - Called in REVERSE order of         │
│      declaration                        │
│ 4. Virtual Base Class Destructors       │
│    - Called in REVERSE order of         │
│      declaration                        │
│ 5. Memory Deallocation                  │
│    - Object Lifetime ENDS               │
└─────────────────────────────────────────┘

    */

//Basic Destructor
class Bdes{
    public:
    Bdes(){
        cout<<"constructor called."<<endl;
    }
    ~Bdes(){
        cout<<"destructor called."<<endl;
    }
};
//Resource Cleanup
class Rcdes{
    private:
    int* array;
    int size;

    public:
    Rcdes(int size){//if we use size the member variable will be hidden by the parameter?
        this->size = size;
        array = new int[size];//why we use new keyword?
        cout<<"Dynamic array of size: "<<size <<" is created."<<endl;
    }
    ~Rcdes(){
        delete[] array;
        array = nullptr;//to counter undefined behaviour of destructor
        cout<<"array deleted!"<<endl;
    }
};
int main(){
    // Testing Consclass
    Consclass c1;
    Consclass c2("Tej", 19);
    c1.display();
    c2.display();

    // Testing Bdes
    Bdes obj;

    // Testing Rcdes
    Rcdes arr(5);

    
}
