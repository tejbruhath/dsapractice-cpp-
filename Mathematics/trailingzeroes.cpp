#include <iostream>
using namespace std;

int trailingzeroes(int num){
    int count = 0;
    int factorial = 1;
    for (int i = num ; i>1; i--)
       factorial *= i;
    while(factorial%10 == 0){
        count++;
        factorial /= 10;
    }
    return count;
}

int main(){
    int num ;
    cin >> num;
    cout<< trailingzeroes(num);
    return 0;
}