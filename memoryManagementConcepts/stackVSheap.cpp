#include <bits/stdc++.h>
using namespace std;

//stack Memory
//Only upto few MBs
//LIFO
void fun(){
    int x = 10; // Stack Allocation
    double arr[100];
    arr[0] = 10;
    cout<<x<<arr[0]<<endl;
    //Also stack (fixed array)
}//after the completion of the function, the memory is deallocated
//Memory is automatically reclaimed when variables go out of scope

//Heap Memory
//Larger than stack
//Objects that need to persist beyond the scope of the function
//Dynamic Memory Allocation
//Slower allocation and dealloc
//You have to alloc and dealloc manually(memoryLeaks)

void funHeap(){
    int* ptr = new int;
    *ptr = 10;//changes the value in the memory location
    //Using a pointer for any work
    cout<<*ptr<<endl;
    delete ptr;//deallocating the memory
    int* array = new int[5];
    for(int i = 0; i<5; i++)
         array[i] = i;
    cout<<array[2]<<endl;
    delete[] array;//deallocate memory dont forget to use [] for arrays
}

/*Why array[i] = i Works(Very Important)

When you declare int* array = new int, you're creating a pointer to the first element of a contiguous block of memory that can hold 5 integers. The array indexing syntax array[i] is actually syntactic sugar for *(array + i), which means:

    Take the pointer array

    Add i to it (with pointer arithmetic, this advances i * sizeof(int) bytes)

    Dereference that location to access the value
*/
class MyClass{
    private:
        string name;
        int age;
    public:
        MyClass(string name, int age) : name(name), age(age) {}//Intializer List
        void displayProfile(){
            cout<<name<<","<<age<<endl;
        }
    ~MyClass(){
        cout<<"Destructor Called"<<endl;
    }
};
/*                                                 
┌───────────────────┐                           
│ Stack Memory      │                           
│ ┌─────────────┐   │                           
│ │ obj pointer │───┼───┐                       
│ └─────────────┘   │   │                       
└───────────────────┘   │                       
                        ▼                       
┌───────────────────────────────────────┐       
│ Heap Memory                           │       
│ ┌─────────────────────────────────┐   │       
│ │ MyClass Object                  │   │       
│ │ ┌───────────────┐ ┌───────────┐ │   │       
│ │ │ name: "Tej"   │ │ age: 19   │ │   │       
│ │ └───────────────┘ └───────────┘ │   │       
│ │ ┌─────────────────────────────┐ │   │       
│ │ │ Method table pointer        │ │   │       
│ │ └─────────────────────────────┘ │   │       
│ └─────────────────────────────────┘   │       
└───────────────────────────────────────┘       
                │                               
                │ When obj->displayProfile()    
                ▼                               
┌─────────────────────────────────────────────┐ 
│ Class Method Table                           │ 
│ ┌─────────────────────────────────────────┐ │ 
│ │ displayProfile() implementation         │ │ 
│ └─────────────────────────────────────────┘ │ 
│ ┌─────────────────────────────────────────┐ │ 
│ │ ~MyClass() destructor implementation    │ │ 
│ └─────────────────────────────────────────┘ │ 
└─────────────────────────────────────────────┘ 
                │                               
                │ Only if delete obj; is called 
                ▼                               
┌─────────────────────────────────────────────┐ 
│ Destructor Execution                         │ 
│ 1. Prints "Destructor Called"                │ 
│ 2. Releases memory for string name           │ 
│ 3. Releases memory for MyClass object        │ 
└─────────────────────────────────────────────┘ 
*/
int main(){
    funHeap();
    fun();
    int a = 5;
    int* pA = &a;
    cout<<*pA<<endl;
    MyClass* obj = new MyClass("Tej",19);
    obj->displayProfile();
    delete obj;
    return 0;
}
/*Common Pitfalls:

    Memory leaks (forgetting to call delete)

    Double deletion (calling delete twice on the same pointer)

    Dangling pointers (using a pointer after deletion)

    Using delete instead of delete[] for arrays
*/