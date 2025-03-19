//Vectors 
//Store collections of data that need to grow dynamically (arrays static)
//Automatic Memory Management
//Rich set of member funtions

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void displayVector(vector<int>& vec){
    cout<<"Printing vector"<<endl;
    for (int i = 0; i < vec.size(); i++)
        cout<<vec.at(i)<<endl;
}
void reverseVector(vector<int>& v){//or use reverse(v.begin(),v.end()), i just used it for swap
    for (int i = 0; i < v.size()/2; i++){
        swap(v.at(i),v.at(v.size()-1-i));
    }
}

vector<int> v;
vector<int> v1 = {1,2,3,4,5};
vector<int> v1copy(v1);
vector<int> v1copy2(v1.front(),v1.back());
vector<int> v1copy3(v1.begin(),v1.end());//Find the differences

int main(){

    displayVector(v1); // pass vector by reference
    displayVector(v1copy2);
    reverseVector(v1);
    displayVector(v1);
}

