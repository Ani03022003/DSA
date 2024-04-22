#include <iostream>
using namespace std;
const int SIZE=100;
int arr[SIZE];
int top=-1;

void push(int ele)
{
    if(top==SIZE-1)
    {
        cout<<"Overflow";
    }
    else{
        arr[++top]=ele;
    }
}

void pop()
{
    if(top==-1)
    {
        cout<<"Underflow";
    }
    else{
        top--;
    }
}

void display()
{
    for(int i=top;i>=0;i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main() {
    // Write C++ code here
    char ans;
    int choice;
    do{
        cout<<"1.Add element"<<endl;
        cout<<"2.Delete element"<<endl;
        cout<<"3.Display element"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1: int num;
                    cin>>num;
                    push(num);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            default: cout<<"Enter choice between 1 and 3"<<endl;
        }
        cout<<"Do you wish to continue: ";
        cin>>ans;
    }while(ans=='Y'||ans=='y');
}