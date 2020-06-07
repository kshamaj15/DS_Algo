#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v;
    stack<int> stk;
    int count = 0;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        if(temp > 0) {
            stk.push(temp);
        } else {
            if(temp + stk.top() == 0) {
                count = count + 2;
            } else {
                count = 0;
            }
        }
    }
    cout << count;
    return 0;
}