//Inheritance code
//allows a classs to inherit methods and properties from another class
//Single,Multiple,Multilevel,Heirarchical,Hybrid
//Code Reusability, Modularity, *polymorphism*

#include <iostream>
using namespace std;

class A {
    public: 
    void callA(){
        cout<<"Parent A Method Called."<<endl;
    }
};
//Single Inheritance
class SA : public A{
    public:
    void callSA(){
        cout<<"Single Inheritance"<<endl;
    }
};
//Multiple Inheritance 
class B {
public:
    void callB(){
        cout<<"Parent B Method Called."<<endl;
    }
};
class MAB : public A, public B {

};
//Multilevel Inheritance 
// class B : public A , class C : public B ; u can use all methods

//Hybrid Inheritance combination of multi and multiple
// class B : public A, class C , class D : public B public C

int main (){
    SA single;
    single.callA();
    single.callSA();
    MAB multiple;
    multiple.callA();
    multiple.callB();

}