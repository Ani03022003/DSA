#include<bits/stdc++.h>
using namespace std;
string smallestWindow (string s, string p)
    {
        vector<int> map(128,0);
        for(auto c : p)
            map[c]++;
        int counter=p.size(), end=0, begin=0, head=0, d=INT_MAX;
        while(end<s.size())
        {
            if(map[s[end++]]-- > 0)
                counter--;
            while(counter==0)
            {
                if(end-begin<d)
                    d=end-(head=begin);
                if(map[s[begin++]]++ == 0)
                    counter++;
            }
        }
        return d==INT_MAX? "-1":s.substr(head,d);
    }

int main(){
    string s="timetopractice", p="toc";
    cout<<smallestWindow(s, p);
    return 0;
}