#include<bits/stdc++.h>
using namespace std;

vector<int> maxset(vector<int> &A) {
    long long int sum = 0;
    long long int maxSum = 0;
    int count = 0;
    int maxCount = 0;
    vector<int> ans;
    for(int i=0; i<A.size(); i++) {
        if(A[i] >= 0) {
            // cout<<A[i]<<" ";
            sum += A[i];
            if(sum>maxSum) {
                cout<<maxCount<<" "<<count<<" "<<sum<<endl;
                maxSum = sum;
                maxCount = count;
            }
        } else {
            count++;
            sum = 0;
        }
    }
    
    for(int i=0; i<A.size(); i++) {
        if(A[i] < 0) {
            maxCount--;
        }
        if(A[i] >= 0 && maxCount == 0) {
            ans.push_back(A[i]);
        }
        if(maxCount < 0) {
            break;
        }
    }
    return ans;
}


int main (){
    //code
    vector<int> v{336465782, -278722862, -2145174067, 1101513929, 1315634022, -1369133069, 1059961393, 628175011, -1131176229, -859484421};
    // vector<int> v{1, 2, 5, -7, 2, 3};
    // vector<int> v{-846930886, -1714636915, 424238335, -1649760492};
    vector<int> ans;
    ans = maxset(v);
    for(auto el: ans) {
        cout<<el<<" ";
    }
    return 0;
}
