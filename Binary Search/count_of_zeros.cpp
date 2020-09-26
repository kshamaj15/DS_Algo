#include <bits/stdc++.h>
using namespace std;

int countZeroes(vector<int> &arr, int n) {
        int s = 0, e = n-1;
        int ans = 0;
        while(s<=e) {
            int m = s + (e-s)/2;
            if(m == n && arr[m] == 1) {
                ans = 0;
                break;
            } else if(m != n && arr[m] == 1 && arr[m+1] == 1) {
                s = m+1;
            } else if(m==0 && arr[m] == 0) {
                ans = n;
                break;
            } else if(m!=0 && arr[m] == 0 && arr[m-1] == 0) {
                e = m-1;
            } else {
                if(arr[m] == 0)
                ans = n-m;
                else
                ans = n-m-1;
                break;
            }
        }
        return ans;
    }

    int main() {
        vector<int> arr{1,1,1,1,1,1,1,0,0,0,0,0};
        cout<<countZeroes(arr,12)<<endl;
    }