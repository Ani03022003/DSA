#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void sort(vector<int> &arr, int l,int r)
{
    if(l<r)
    {
        int m = l+(r-l)/2;
        sort(arr,l,m);
        sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7,10,1,3,8};
    vector<int> odd;
    vector<int> even;
    int i=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    while(n!=0){
        if(i%2==0)
        {
            even.push_back(arr[i]);
            i++;
        }
        else
        {
            odd.push_back(arr[i]);
            i++;
        }
        n--;
    }
    sort(even, 0, even.size()-1);
    sort(odd, 0, odd.size()-1);
    for(int j=0; j<even.size(); j++)
    {
        cout<<even[j]<<" ";
    }
    for(int j=odd.size()-1; j>=0; j--)
    {
        cout<<odd[j]<<" ";
    }
    return 0;
}
    