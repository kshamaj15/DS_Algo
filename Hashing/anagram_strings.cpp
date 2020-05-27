#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    string S = "abcd", T = "sadc";
    // cin >> S >> T;
    unordered_map<char, int> s;
    unordered_map<char, int> t;
    for(int i=0; i<S.length(); i++) {
        s[S[i]]++;
    }
    for(int i=0; i<T.length(); i++) {
        t[T[i]]++;
        // cout << t[T[i]];
    }
    int count = 0;
    unordered_map<char, int>:: iterator itr;
        for(itr = t.begin(); itr!=t.end(); itr++) {
            if (s.find(itr->first) != s.end()) {
                count += abs(itr->second - s[itr->first]);
            }
            else {
                count += itr->second;
            }
    }
    unordered_map<char, int>:: iterator itr1;
        for(itr1 = s.begin(); itr1!=s.end(); itr1++) {
            if (t.find(itr1->first) == t.end()) 
            count += itr1->second;
        }
        cout << "Count: " << count << endl;
    return 0;
}