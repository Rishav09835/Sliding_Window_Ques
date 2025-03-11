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
    unordered_set<char>st;
    while(j<n){
        if(st.count(s[j])>0){
            //shrink window
            while(s[i]!=s[j]){
                st.erase(s[i]);
                i++;
            }
            st.erase(s[i]);
            i++;
        }
        else{
            st.insert(s[j]);
            l=j-i+1;
            maxl = max(maxl,l);
            j++;
        }

    }
    return maxl;
}

int main(){
    string s;
    cin>>s;
    cout<<"the longest string without repeating character is of size: "<<\
    LSWRC(s);
}