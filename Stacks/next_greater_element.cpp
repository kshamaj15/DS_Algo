#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 10;
    int arr[10] = {0,0,0,0,0,0,0,0,70,0};
    stack<int> stk;
    vector<int> nge(n, -1);
    stk.push(0);
    for (int i = 1; i < n; i++) {
        if(arr[stk.top()] >= arr[i]) {
            stk.push(i);
        } else {
            while(arr[stk.top()] < arr[i]) {
                nge[stk.top()] = arr[i];
                stk.pop();
                if(stk.empty())
                break;
            }
            stk.push(i);
        }
    }

    for (int i = 0; i < n; i++) {;
        cout<<nge[i]<<" ";
    }
    
    return 0;
}