// https://practice.geeksforgeeks.org/problems/save-your-life/0/?category[]=Kadane&page=1&query=category[]Kadanepage1
// run time error in this code gfg on submission
// medium

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    string s;
	    int x;
	    vector<char> a(x);
	    vector<int> b(x);
	    cin>>s>>x;
	    for(int i=0; i<x; i++) {
	        cin>>a[i];
	    }
	    for(int i=0; i<x; i++) {
	        cin>>b[i];
            // cout<<b[i];
	    }
	    unordered_map<char, int> mp;
	    for(int i=0; i<x; i++) {
	        mp[a[i]] = b[i];
            cout<<a[i] << " "<< mp[a[i]]<<endl;
	    }
	    vector<int> arr;
	    int n = s.size();
	    for(int i=0; i<n; i++) {
	        if(mp.find(s[i]) == mp.end())
	        arr.push_back((int)s[i]);
	        else
	        arr.push_back(mp[s[i]]);

            cout<<arr[i]<<" ";
	    }
        cout<<endl;
	    
	    int ans = 0;
	    int fans = 0;
	    int si = 0, ei = 0;
	    int st = 0, e = 0;
	    for(int i=0; i<n; i++) {
	        ans += arr[i];
	        if(ans < 0) {
	            si = i+1;
	            ans = 0;
	        }
	        if(fans < ans) {
	            e = ei;
	            st = si;
	        }
	        ei++;
	    }
        cout<<endl;
	    cout<<s.substr(st, e-st+1)<<endl;
        cout<<endl;
	} 
	return 0;
}