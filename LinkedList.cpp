#include<bits/stdc++.h>
using namespace std;

struct Node{
        int val;
        Node *next;
        
    }*start,*ptr,*save;
    
void push(int x){
    Node *newptr=new Node;
    newptr->val=x;
    if(start==NULL){
        start=newptr;
    }
    else{
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newptr;
    }
}
void deleteval(int key){
    Node *temp=start;
    Node *prev=NULL;
    if(temp!=NULL && temp->val==key){
        start=temp->next;
        delete temp;
        return;
    }
    while(temp!=NULL && temp->val!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL) return;
    prev->next=temp->next;
    delete temp;
}
void rev(){
    stack<int>s;
    save=start;
    while(save!=NULL){
        s.push(save->val);
        save=save->next;
    }
     cout<<"Rev"<<endl;
     while(!s.empty()){
         cout<<s.top()<<" ";
         s.pop();
     }
}
void display(){
    save=start;
    while(save!=NULL){
        cout<<save->val<<" ";
        save=save->next;
    }
}
int main(){
    int n;
    int count;
    cout<<"Enter the no. of elements you want to add";
    cin>>count;
    for(int i=1;i<=count;i++){
        cin>>n;
        push(n);
    }
    cout<<"original"<<endl;
    display();
    return 0;
}