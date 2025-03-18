//oops uses objects and classes as central concepts
//this file has classes , public and private , methods and attributes
#include <iostream>
#include <string>
using namespace std;

class Student {//class start with Capital letter
    public: 
    string name;//Attributes of a class
    int roll_no;
    int age;
    int year;

    void displayInfo(){//Method
        cout<<"Name: "<<name<<" ,Reg No: "<<roll_no<<" ,Age: "<<age<<" ,Year of Graduation: "<<year<<endl;
        
    }
};

class BankAccount{
    private:  
    string accountNumber;
    double balance;

    //constructor
    public:
    BankAccount(string accNum,double initBal){
        accountNumber = accNum;
        balance = initBal;
    }
    string getAccountNumber(){//getter method
        return accountNumber;
    }
    double getBalance(){
        return balance;
    }
    void deposit(double amount){
        if(amount>=0){
        balance += amount;
        cout<< "Deposit: "<<amount<<endl;
        }
    };
    void withdraw(double amount){
        if(amount >0 && amount <= balance){
            balance -= amount;
            cout<<"Withdraw: "<<amount<<endl;
        }else{
            cout<<"Insufficient Funds or Invalid Amount"<<endl;
        }
    };
};

int main(){
    cout<< "hello,world!"<<endl;
    Student tej;//object
    tej.name = "Tej Bruhath";
    tej.roll_no = 494;
    tej.age = 19;
    tej.year = 2026;
    tej.displayInfo();
    BankAccount tejAccount("tej123",5000);
    cout<<"Account Number: "<<tejAccount.getAccountNumber()<<endl;
    cout<<"Balance: "<<tejAccount.getBalance()<<endl;
    tejAccount.deposit(1000);
    tejAccount.withdraw(1500);
    cout<<"Gross Balance after Transactions: "<<tejAccount.getBalance()<<endl;
    return 0;

}