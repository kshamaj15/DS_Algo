// https://practice.geeksforgeeks.org/problems/maximum-sub-array5443/1
// medium

#include <bits/stdc++.h>
using namespace std;

vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<int> sarr;
	    long long sum = 0;
	    long long fsum = 0;
	    int si = 0, ei = 0;
	    int s = 0, e = 0;
	    for(int i=0; i<n; i++) {
	        sum += a[i];
	        if(a[i] < 0) {
	            sum = 0;
	            si = i+1;
	        }
	        if(sum > fsum || (sum == fsum && e-s < ei-si)) {
	            s = si;
	            e = ei;
	            fsum = sum;
	        }
	        ei++;
	    }
	    for(int i=s; i<=e; i++) {
	        if(a[i] < 0)
	        return {-1};
	        else
	        sarr.push_back(a[i]);
	    }
	    return sarr;
	}

    int main() {
        int a[] = {1, 2, 3, -1, 4, 5};
        vector<int> ans = findSubarray(a, 6);
        for(auto el: ans)
        cout<<el<<" ";
        cout<<endl;
    }