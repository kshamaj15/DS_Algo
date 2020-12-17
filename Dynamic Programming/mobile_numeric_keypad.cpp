#include<bits/stdc++.h>
using namespace std;

long long getCount(int remainingDigits, int possibilities) {
	    if(possibilities == 0 || remainingDigits == 0)
	    return 0;
	    
	    return 1 + getCount(remainingDigits-1, possibilities) 
	    + getCount(remainingDigits-1, possibilities-1);
	    
	}
	
	long long getCount(int N)
	{
		vector<int> v{2, 3, 4, 3, 4, 5, 4, 3, 5, 3};
		long long int ans = 0;
		for(auto el: v) {
            int x = 1 + getCount(N-1, el);
		    ans += x;
            cout<<el<<" "<<x<<endl;
		}
		return ans;
	}

int main() {
    cout<<endl;
    cout<<getCount(2);
    cout<<endl;
}