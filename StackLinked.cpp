#include<iostream>
using namespace std;
struct StackNode{
    int val;
    StackNode* next;
}*top,*newptr,*save,*ptr;
StackNode* createNewNode(int n){
    ptr=new Node;
    ptr->val=n;
    ptr->next=NULL;
    return ptr;
}
void push(StackNode* np){
    if(top==NULL){
        top=np;
    }
    else{
        save=top;
        top=np;
        np->next=save;
    }
}
void pop(){
    if(top==NULL){
        cout<<"UNDERFLOW!!!\n";
    }
    else{
        ptr=top;
        top=top->next;
        delete(ptr);
    }
}
void display(StackNode* np){
    if(np==NULL)
        cout<<"EMPTY STACK!!!\n";
    else{
        while(np!=NULL){
            cout<<np->val<<"->";
            np=np->next;
        }
    }
}
int main()
{
    top=NULL;
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
    display(top);
    cout<<"\n";
    pop();
    pop();
    pop();
    display(top);
}