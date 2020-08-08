#include<bits/stdc++.h>
using namespace std;

#define M 100000007
int factorial(unsigned int n)
{
    unsigned int ret = 1;
    for(unsigned int i = 1; i <= n; ++i)
        ret = (ret*i)%M;
    return ret;
}

int power(int x, int y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return (power(x, y / 2)%M * power(x, y / 2)%M)%M; 
    else
        return (x * ((power(x, y / 2))%M * (power(x, y / 2))%M)%M)%M; 
} 

int solve(int n, vector<int> &B) {
    sort(B.begin(), B.end());
    int ans = 1;
    vector<int> city;
    vector<int> ways;
    int prev = 0;
    for(int i=0; i<B.size(); i++) {
        city.push_back(B[i]-prev-1);
        prev = B[i];
    }
    city.push_back(n-prev);
    for(int i=0; i<city.size(); i++) {
        if(i==0 || i == city.size()-1 || city[i] == 0)
        ways.push_back(1);
        else {
            ways.push_back(power(2, city[i]-1));
        }
    }
    ans = ans*factorial(n-B.size());
    // cout<<ans<<" "<<city[2]<<" ";
    for(int i=0; i<city.size(); i++) {
        ans = (ans*ways[i]/factorial(city[i]))%M;
        // cout<<ans<<" "<<ways[i]<<" "<<city[i]<<endl;
    }
    return ans;
}

int main (){
    //code
    int n = 10;
    vector<int> v{2,3,6,9,10};
    cout<<solve(n, v);
    return 0;
}
