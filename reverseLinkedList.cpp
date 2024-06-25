#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
}*ptr,*start;

void push(int n){
    Node *newnode = new Node;
    newnode->data=n;
    newnode->next=NULL;
    if(start==NULL)
        start=newnode;
    else{
        ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}

void display(){
    Node *ptr = new Node;
    ptr=start;
    while(ptr->next!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<ptr->data<<"->null";
}

Node* reverse(Node *head, int count){
    Node *prev=NULL;
    Node *curr=head;
    Node *temp=curr->next;
    while(count>0){
        --count;
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

void reverseNode(int m, int n){
    Node *leftNode=start;
    Node *beforeLeftNode=NULL;
    Node *afterRightNode=start;

    if (m >= n || start == NULL) return;

    for(int i=1;i<m && leftNode!=NULL ;i++){
        beforeLeftNode=leftNode;
        leftNode=leftNode->next;
    }

    if(leftNode==NULL) return;

    Node *rightNode = leftNode;
    for (int i = m; i <= n && rightNode != NULL; ++i) {
        rightNode = rightNode->next;
    }
    afterRightNode = rightNode;

    Node *reversedHead = reverse(leftNode, n - m + 1);

    if (beforeLeftNode != NULL) {
        beforeLeftNode->next = reversedHead;
    } 
    else {
        start = reversedHead;
    }

    leftNode->next = afterRightNode;
}

int main(){
    int n,d;
    int left, right;
    cout<<"Enter the number of values: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>d;
        push(d);
    }
    display();
    cout<<"\nEnter form which left and right position: ";
    cin>>left>>right;
    reverseNode(left,right);
    display();
}