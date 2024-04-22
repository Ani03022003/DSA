#include<iostream>
#define MAX 100
using namespace std;
int arr[MAX];
int Linearsearch(int ele,int n){
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            return 1;
        }
    }
    return 0;
}

int BinarySearch(int ele, int n){
    int mid;
    int beg=0,end=n;
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==ele){
            return 1;
        }
        if(arr[mid]<ele){
            beg=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result1=Linearsearch(10,n);
    int result2=BinarySearch(6,n);
    if(result1==1){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    if(result2==1){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
}