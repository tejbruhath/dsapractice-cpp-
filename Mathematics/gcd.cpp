#include <iostream>
using namespace std;

int gcd(int a, int b){

    if (a == b)
        return a;
    if(a==0)
        return b;
    if (b==0)
        return a;        
    if (a>b)
        return gcd(a-b,b);
    return gcd(a,b-a)  ;  

}

int main(){
    int a ,b;
    cin>>a;
    cin >> b;
    cout<<gcd(a,b)<<endl;
    return 0;
}