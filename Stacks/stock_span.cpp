#include<bits/stdc++.h>
using namespace std;
int main() {
    int price[7] = {100, 80, 60, 70, 60, 75, 85};
    stack<int> stk;
    int span[7];
    stk.push(0);
    span[0] = 1;
    for (int i = 1; i < 7; i++) {
        while(!stk.empty() && price[stk.top()] <= price[i]){
            stk.pop();
        }
        if(stk.empty()){
            span[i] = i+1;
        } else {
            span[i] = i - stk.top();
        }
        stk.push(i);
    } 
    for (int i = 0; i < 7; i++) {
        cout<<span[i]<<" ";
    }    
    return 0;
}