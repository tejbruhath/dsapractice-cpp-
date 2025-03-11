#include <iostream>
using namespace std;

bool checkPalindrome(int num){
    int reverse = 0;
    int n = num;
    while(n!=0){
        reverse = (reverse*10) + (n%10);
        n /= 10;
    }
    return(reverse==num);
};

int main() {
   int num;
   cin >> num;
   cout<<(checkPalindrome(num)? "true": "false");
    return 0;
}