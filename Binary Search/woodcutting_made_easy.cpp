#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int min = A[0];
    int max = A[0];
    for(int i=1; i<A.size(); i++) {
        min = min < A[i] ? min : A[i];
        max = max > A[i] ? max : A[i];
    }
    // cout<<max<<min<<" ";
    while(min<=max) {
        int mid = min + (max-min)/2;
        int mid0 = min + (max-min)/2 + 1;
        cout<<mid<<" ";
        int sum = 0;
        int sum0 = 0;
        for(int i=0; i<A.size(); i++) {
            if(A[i]-mid > 0)
            sum += A[i] - mid;
            cout<<sum<<" ";
            if(A[i]-mid0 > 0)
            sum0 += A[i] - mid0;
        }
        cout<<endl;
        if(sum == B)
        return mid;
        else if(sum < B)
        max = mid-1;
        else if(sum > B) {
            if(sum0 < B)
            return mid;
            else
            min = mid+1;
        }
    }
}


int main (){
    //code

    vector<int> v{20,15,10,17};
    cout<<solve(v, 8);
    return 0;
}
