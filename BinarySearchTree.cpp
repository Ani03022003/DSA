#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int val;
    Node *left;
    Node *right;
};
Node *root = NULL;
Node* Getnewnode(int data){
    Node* newnode=new Node();
    newnode->val=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
Node* Insert(Node* root, int data){
    if(root==NULL)
    {
        root=Getnewnode(data);
    }
    else if(data<=root->val){
        root->left=Insert(root->left,data);
    }
    else{
        root->right=Insert(root->right,data);
    }
    return root;
}
void LevelOrder(Node* root){
    if(root==NULL)
        return;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node* current=Q.front();
        cout<<current->val<<" ";
        if(current->left!=NULL)
            Q.push(current->left);
        if(current->right!=NULL)
            Q.push(current->right);
        Q.pop();
    }    
}
void preorder(Node* root){
    if(root==NULL)
        return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
}
int main(){
    int choice;
    char ans;
    do
    {
        cout<<"1.Insert element"<<endl;
        cout<<"2.Display as Level Order(BFS)"<<endl;
        cout<<"3.Display as preorder(DFS)"<<endl;
        cout<<"4.Display as inorder(DFS)"<<endl;
        cout<<"5.Display as postorder(DFS)"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                int data;
                cout<<"Enter the element to be inserted: ";
                cin>>data;
                root = Insert(root,data);
                break;
            case 2:
                LevelOrder(root);
                cout<<"\n";
                break;
            case 3:
                preorder(root);
                cout<<"\n";
                break;
            case 4:
                inorder(root);
                cout<<"\n";
                break;
            case 5:
                postorder(root);
                cout<<"\n";
                break;
            default:cout<<"Wrong choice"<<endl;
        }
        cout<<"Do you want to continue?(y/n): ";
        cin>>ans;
    } while (ans=='y'||ans=='Y');
    return 0;
}