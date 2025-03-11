#include<iostream>
using namespace std;
#include<vector>
#include<string.h>
#include<unordered_set>
int LSWRC(string s){
    int n = s.size();
    int maxl = 0;
    int i = 0, j=0;
    int l=0;
    vector<int>freq(256,0);
    while(j<n){
        freq[s[j]]++;
        // if(st.count(s[j])){
        //     //shrink window
        //     while(s[i]!=s[j]){
        //         st.erase(s[i]);
        //         i++;
        //     }
        //     st.erase(s[i]);
        //     i++;
        // }
        // else{
        //     st.insert(s[j]);
        //     l=j-i+1;
        //     maxl = max(maxl,l);
        //     j++;
        // }
        while(freq[s[j]]>1){
            freq[s[i]]--;
            i++;
        }
        maxl = max(maxl, j-i+1);
        j++;
    }
    return maxl;
}

int main(){
    string s;
    cin>>s;
    cout<<"the longest string without repeating character is of size: "<<\
    LSWRC(s);
}