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
int factorial (int n){
    if (n==0)
        return 1;
    else 
        return n*factorial(n-1);
}
vector<int> v;
vector<int> v1 = {1,2,3,4,5};//Initializer list
vector<int> vUniform_initilization{1,2,3,4,5};//Uniform initialization
vector<int> v1copy(v1);
vector<int> v1copy2(v1.front(),v1.back());
vector<int> v1copy3(v1.begin()+1,v1.end());//Find the differences

int main(){

    displayVector(v1); // pass vector by reference
    displayVector(v1copy2);
    reverseVector(v1);
    displayVector(v1);
    v1.push_back(6);
    cout<<"print value at 5: "<<v1.at(4)<<endl;//checks for bounds
    cout<<v1[6]<<endl;//does not check for bounds you can call v1[100] and it will give you garbage value
    cout<<"Out of Bound Value for vector: "<<v1[100]<<endl;
    int arr[5] = {1,2,3,4,5};
    cout<<"Out of Bound value for arr: "<< arr[6]<<endl;//gives garbage value
    
    //Inserting elements
    v1.at(0) = 10;
    cout<<"After changing the value of 0th element: "<<v1.at(0)<<endl;
    v1.insert(v1.begin()+1,20);
    cout<<"After inserting 20 at 2nd position: "<<v1.at(1)<<endl;
    v1.insert(v1.begin()+1,3,30);//Insert multiple copies of 30 in 2,3,4th index
    displayVector(v1);

    //Delete elements
    v1.erase(v1.begin(),v1.begin()+4);//erase 0th to 3rd element
    v1.pop_back();//delete the last element
    cout<<factorial(5)<<endl;

    //size and capacity
    cout<<"size of vector v1: "<<v1.size()<<endl;
    cout<<"capacity of vector v1: "<<v1.capacity()<<endl;
    v1.shrink_to_fit();//shrink the capacity to the size
    cout<<"capacity of vector v1 after shrink: "<<v1.capacity()<<endl;
    v1.clear();//clear the vector
    cout<<"size of vector v1 after clear: "<<v1.size()<<endl;
    cout<<"capacity of vector v1 after clear: "<<v1.capacity()<<endl;
    //.clear() does not change the capacity of the vector , call shrink_to_fit() to do that
    v1.shrink_to_fit();
    cout<<"capacity of vector v1 after clear and shrink: "<<v1.capacity()<<endl;
    cout<<"check if v is empty: "<< (v.empty()? "true": "false") <<endl;
    //visual difference in capacity
    vector<int> vec;
    for(int i = 0; i < 10; i++){
        vec.push_back(i);
        cout<<"size: "<<vec.capacity()<<endl;
    }


}