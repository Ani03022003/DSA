#include<bits/stdc++.h>
using namespace std;

int findSubString(string str)
    {
        vector<int> map(128,0);
        int counter=0;
        int begin=0, end=0, head=0;
        int d=INT_MAX;
        for(auto c : str)
        {
            if(map[c]==0)
            {
                map[c]++;
                counter++;
            }
        }
        //cout<<counter<<endl;
        while(end<str.size())
        {
            if(map[str[end++]]-- > 0 )
                counter--;
            while(counter==0)
            {
                if(end-begin<d)
                {
                    head=begin;
                    d=end-head;
                }
                if(map[str[begin++]]++ == 0)
                    counter++;
            }
        }
        return d;
    }

int main()
{
    string str="anish";
    cout<<findSubString(str);
}