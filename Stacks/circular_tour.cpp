#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 6;
    int distance[6] = {5,6,7,8, 6,4};
    int petrol[6] = {6,7,4,10,6,5};
    stack<int> stk;
    int sum = 0;
    int top = 0;
    stk.push(0);
    for (int i = 0; i < n; i++) {
        sum += petrol[i] - distance[i];
        if(sum < 0) {
            stk.push(i);
            top = i;
        } else {
            continue;
        }
    }
    cout<<stk.top();
    cout<<top;
    return 0;
}