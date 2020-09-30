// https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum/0/?category[]=Arrays&difficulty[]=2&page=1&query=category[]Arraysdifficulty[]2page1
// there is one better solution also exist
// this has O(n^2) time complexity in worst case
// most optimal solution has O(n) time complexity
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
	    for(int i=0; i<n; i++) {
	        cin>>v[i];
	    }
	    int sum = 0;
	    int fsum = 0;
	    int index = 0;
        queue<int> qu;
        qu.push(0);
        for(int i=1; i<n; i++) {
            if(v[i-1] < 0 && v[i] > 0) {
                // cout<<i<<" ";
                qu.push(i);
            }
        }
        // cout<<endl;
        while(!qu.empty()) {
            int s = qu.front();
            // cout<<"s"<<" "<<s<<endl;
            int e = n;
            sum = 0;
            for(int i=s; i<e; i++) {
	        sum += v[i];
	        if(sum < 0) {
	            sum = 0;
	        }
            if(v[i] < 0)
            index = i+1;
            // cout<<i<<" "<<sum<<" "<<fsum<<endl;
	        fsum = max(fsum, sum);
	        if(i==n-1){
	            i = -1;
	            e = s - 1;
                // cout<<i<<" "<<n<<endl;
	        }
	    }
        qu.pop();
        }
	    cout<<fsum<<endl;
	}
}