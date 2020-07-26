#include<bits/stdc++.h>
using namespace std;

int solve(int A) {
    int target = abs(A); 
      
    // Keep moving while sum is smaller or difference 
    // is odd. 
    int sum = 0, step = 0; 
    while (sum < target || (sum - target) % 2 != 0) { 
        step++; 
        sum += step; 
    } 
    return step; 
}



int main (){
    //code
    cout<<solve(3);
    return 0;
}
