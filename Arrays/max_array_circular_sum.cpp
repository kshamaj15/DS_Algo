// https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum/0/?category[]=Arrays&difficulty[]=2&page=1&query=category[]Arraysdifficulty[]2page1
// most optimal solution for this proble
// has O(n) time complexity
// hard

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    bool allNeg = true;
	    for(int i=0; i<n; i++) {
	        cin>>v[i];
	        if(v[i] >= 0)
	        allNeg = false;
	    }
	    if(allNeg) {
	        int mi = v[0];
	        for(int i=0; i<n; i++)
	        mi = max(mi, v[i]);
	        cout<<mi<<endl;
	    } else {
	        int sum = 0; // temp max sum
	        int arrSum = 0; // total array sum
	        int fsum = 0; // final max sum
	        int rsum = 0; // temp min sum (inverted)
	        int frsum = 0; // final min sum (inverted)
            for(int i=0; i<n; i++) {
                sum += v[i];
                arrSum += v[i];
                if(sum < 0) {
                    sum = 0;
                }
                fsum = max(fsum, sum);
                v[i] = -v[i];
                rsum += v[i];
                if(rsum < 0)
                rsum = 0;
                frsum = max(frsum, rsum);
	    }
	    cout<<max(fsum, arrSum + frsum)<<endl;
	    }
	}
}