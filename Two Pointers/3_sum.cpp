#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    
    // int minDiff = abs(A[0]+A[0]+A[0]-(B));
    // int ans = A[0]+A[1]+A[2];
    // int i = 0;
    // int j = 0;
    // int k = 0;
    // int cycle = 0;
    // int aprev = A[0];
    // int bprev = A[0];
    // int cprev = A[0];
    // while(i<A.size() && j<A.size() && k<A.size()) {
    //     int sum = A[i] + A[j] + A[k];
    //     bool dupli = false;
    //     if(abs(B-sum) < minDiff) {
    //         minDiff = abs(sum - B);
    //         ans = sum;
    //     };
    //     if(cycle%3 == 0) {
    //         i++;
    //         dupli = true;
    //         cycle++;
    //     } else if (cycle%3 == 1) {
    //         j++;
    //         cycle++;
    //     } else {
    //         k++;
    //         cycle++;
    //     }
    //     if(dupli)
    //     while(A[j] == A[i]) {
    //         i++;
    //         dupli = false;
    //     }
    // }
    // return ans;
}


int main (){
    //code
    vector<int> v{2147483647, -2147483648, -2147483648, 0, 1};
    // vector<int> v{-5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3};
    sort(v.begin(), v.end());
    for(auto el: v) {
        cout<<el<<" ";
    }
    cout<<endl;
    cout<<threeSumClosest(v, -1);
    return 0;
}
