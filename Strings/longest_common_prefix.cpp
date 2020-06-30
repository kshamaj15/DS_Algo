#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &A) {
    int n;
    vector<string> strList;
    string ans = "";
    cin >> n;
    int index = 0;
    bool matched = true;
    for(int i=1; i<n; i++) {
        string temp;
        cin >> temp;
        strList.push_back(temp);
    }
    while(1) {
        int val = strList[0][index];
        for(int i=1; i<n; i++) {
            if(val != strList[i][index]) {
                matched = false;
                break;
            }
        }
        // ans = ans + val;
        if(!matched) {
            break;
        }
        index++;
    }
    return ans;
}

int main() {
    vector<string> strList;

    // cout<<longestCommonPrefix({"abcdefgh", "aefghijk", "abcefgh"});
    return 0;
}