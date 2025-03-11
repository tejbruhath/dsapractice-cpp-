#include<iostream>
using namespace std;

bool  checkPrime(int a ){
    if(a==2 ||a==3)
        return true;
    if(a%6==1 ||a%6 ==5){
        return true;
    }   
    return false; 
}

int main(){
    int num;
    cin >> num;
    cout<<checkPrime(num);
    return 0;
}