// https://practice.geeksforgeeks.org/problems/next-larger-element/0#
// https://www.youtube.com/watch?v=sDKpIO2HGq0&list=PLEJXowNB4kPzEvxN8ed6T13Meet7HP3h0

#include<bits/stdc++.h>
using namespace std;

vector<int> nge(vector<int>& v, int n) {
    stack<int> s;
    vector<int> ans(n);
	for(int i=0; i<n; i++) {
	    if(s.empty() || v[i] <= v[s.top()])
	    s.push(i);
	    else {
	        while(!s.empty() && v[i] > v[s.top()]) {
	            int index = s.top();
	            ans[index] = v[i];
	            s.pop();
	        }
	        s.push(i);
	    }
	}
	while(!s.empty()) {
	    int index = s.top();
	    ans[index] = -1;
	    s.pop();
	}
    return ans;
}

int main() {
    int n = 10;
    vector<int> v{3,4,5,6,7,2,4,0, 8,3};
    vector<int> ans = nge(v, n);
    for(auto el: ans) {
	    cout<<el<<" ";
	}
    cout<<endl;
}