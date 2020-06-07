#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[7] = {1, 1, 2, 3, 4, 2, 1};
    vector<int> v;
    unordered_map<int, int> map;
    stack<int> stk;
    v.push_back(-1);
    stk.push(arr[0]);
    for(int i=0; i<7; i++) {
        map[arr[i]]++;
    }
    for(int i=1; i<7; i++) {
        if(map[stk.top()] > map[arr[i]]) {
            v.push_back(stk.top());
        } else {
            while (!stk.empty() && map[stk.top()] < map[arr[i]]) {
                stk.pop();
                if(stk.empty())
                break;
            }
            cout<< "i: "<<i<<" :"<<stk.top()<<endl;
            if(stk.empty()) {
                v.push_back(-1);
            } else {
                v.push_back(stk.top());
            }
        }
        stk.push(arr[i]); 
    }

    for (int k=0; k<v.size(); k++) {
        cout<<v[k]<<" ";
    }
    
    return 0;
}