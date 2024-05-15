#include<iostream>
using namespace std;
int main()
{
    string str ="geeksforgeeks";
    int len = str.size();
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(i==j||i+j==len-1)
            {
                cout<<str[j];
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    } 
}