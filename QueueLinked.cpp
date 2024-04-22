#include<iostream>
using namespace std;
struct QueueNode{
    int val;
    QueueNode* next;
}*front,*newptr,*save,*ptr,*rear;
QueueNode* createNewNode(int n){
    ptr=new Node;
    ptr->val=n;
    ptr->next=NULL;
    return ptr;
}
void push(QueueNode* np){
    if(front==NULL){
        front=rear=np;
    }
    else{
        rear->next=np;
        rear=np;
    }
}
void pop(){
    if(front==NULL){
        cout<<"UNDERFLOW!!!\n";
    }
    else{
        ptr=front;
        front=front->next;
        delete(ptr);
    }
}
void display(QueueNode* np){
    if(np==NULL)
        cout<<"EMPTY QUEUE!!!\n";
    else{
        while(np!=NULL){
            cout<<np->val<<"->";
            np=np->next;
        }
    }
}
int main()
{
    front=NULL;
    newptr=createNewNode(1);
    push(newptr);
    newptr=createNewNode(2);
    push(newptr);
    newptr=createNewNode(3);
    push(newptr);
    newptr=createNewNode(4);
    push(newptr);
    newptr=createNewNode(5);
    push(newptr);
    display(front);
    cout<<"\n";
    pop();
    pop();
    pop();
    display(front);
}