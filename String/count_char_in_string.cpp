#include <iostream>
#include <string>
using namespace std;

int countChar(char  a,string b){
    int n = b.length();
    int count;
    for (int i=0;i<n;i++){
        if(a==b[i])
            count++;
    }
    return count;
};

int main (){
    string sample;
    char scar;
    getline(cin,sample);
    cin>>scar;
    cout<<countChar(scar,sample);
}