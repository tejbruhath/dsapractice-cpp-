//this file will be on constructor and destructor
//comeback and learn baout ctime header and its functions
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Consclass{//constructors init objects when they are to be created
    private:
    string name;
    int data;

    public:
    Consclass(){//default constructor, no arguments passed
        data = 18 + rand() % 8;
        cout<<"Default Constructor values!"<<endl;
    }
    Consclass(string name,int data){ //parameterized constructor , passing arguments
        this->name = name; //this keyword is used to distinguish between the class attributes and the parameters passed.
        this->data = data;
    }
    void display(){
        cout<<"Name: "<< name << ", data: "<<data<<endl;
    }

};

int main(){
    srand(time(0));
    Consclass c1;
    Consclass c2("Tej", 19);
    c1.display();
    c2.display();
    return 0;

}