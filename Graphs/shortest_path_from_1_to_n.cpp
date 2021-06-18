// https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1/?category[]=Graph&category[]=Graph&difficulty[]=-1&page=1&query=category[]Graphdifficulty[]-1page1category[]Graph
// v-easy

#include<bits/stdc++.h>
using namespace std;

int minimumStep(int n){
        //complete the function here
        int ans = 0;
        while(n > 2) {
            int rem = n%3;
            ans += rem;
            ans++;
            n = n/3;
        }
        if(n==2) ans++;
        return ans;
    }

int main() {
    int n;
    cin>>n;
    cout<<minimumStep(n);
}
