#include <iostream>
#define MAX 100
using namespace std;

int front=-1,rear=-1;
int queue[MAX];

void push(int ele)
{
    if(rear==MAX-1)
    {
        cout<<"Overflow";
    }
    else if(rear==-1)
    {
        front=rear=0;
        queue[rear]=ele;
    }
    else{
        queue[++rear]=ele;
    }
}

void pop()
{
    if(front==-1)
    {
        cout<<"Underflow";
    }
    else if(rear==front)
    {
        rear=front=-1;
    }
    else
    {
        front++;
    }
}

void display()
{
    for(int i=front;i<=rear;i++)
    {
        cout<<queue[i]<<" ";
    }
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