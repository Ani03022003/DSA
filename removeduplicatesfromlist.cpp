#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[]={0,0,0,1,1,2,2,3,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int j=0;

    for(int i=1;i<n;i++)
    {
        if(arr[i]^arr[j])
        {
            j++;
            arr[j]=arr[i];
        }
    }

    for(int i=0;i<=j;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}