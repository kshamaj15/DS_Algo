#include<bits/stdc++.h>
using namespace std;

int factorial(int n) 
{ 
    // single line to find factorial 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 

int solve(vector<int> &digi, int len, int max) {
    // vector<int> numDigi;
    // int maxCopy = max;
    // int ans = 0;
    // while(max != 0) {
    //     numDigi.push_back(max%10);
    //     max = max/10;
    //     cout<<"l  ";
    // }
    // for(auto digit: digi) {
    //     if(len > numDigi.size()){
    //         cout<<"h";
    //         break;
    //     } else if(len < numDigi.size()) {
    //         cout<<"w";
    //         ans = pow(digi.size(), len);
    //     } else if(digit != 0 && digit < numDigi[numDigi.size()-1] && len > 1) {
    //         cout<<"e";
    //         ans += factorial(digi.size());
    //     } else if(digit == numDigi[numDigi.size()-1] && len > 1) {
    //         cout<<"f";
    //         int count = numDigi.size()-1;
    //         cout<<"a";
    //         while(count--) {
    //             cout<<"b";
    //             for(auto digit: digi) {
    //             cout<<"c";
    //                 if(digit < numDigi[count]) {
    //                     cout<<"d";
    //                     ans++;
    //                 } else if(digit == numDigi[count]) {
    //                     break;
    //                 }
    //             }
    //         }
    //         break;
    //     } else if (len == 1 && digit < maxCopy) {
    //         cout<<"g";
    //         ans++;
    //     } else if (len == 1 && digit == maxCopy) {
    //         cout<<"h"<<digit;
    //         break;
    //     }
    // }
    
    vector<int> numDigi;
    int maxCopy = max;
    int ans = 0;
    while(max != 0) {
        numDigi.push_back(max%10);
        max = max/10;
    }
    
    if(numDigi.size() < len)
    return ans;
    
    int index = numDigi.size() - 1;
    for(auto d: digi) {
        if(len == 1 && d<numDigi[index]) {
            ans++;
        } else if(d<numDigi[index] && d!=0){
            ans += factorial(digi.size())/factorial(digi.size()-numDigi.size()+1);
        } else if(d==numDigi[index]) {
            index;
            int x = 1;
            while(index >= 0) {
                for(auto d: digi) {
                    if(d<numDigi[index]) {
                        // if(factorial(digi.size() - x >= 0 && digi.size()-numDigi.size() + x >= 0))
                        // ans = ans + (factorial(digi.size() - x)/factorial(digi.size()-numDigi.size() + x));
                        cout<<digi.size() - x<<" ";
                        cout<<(digi.size()-numDigi.size() + x)<<endl;
                        cout<<digi.size()<<" "<<numDigi.size()<<" "<<x<<endl;
                        x++;
                    } 
                }
                cout<<endl;
                index--;
            }
            break;
        }
    }
    
    return ans;
}

int main (){
    // vector<int> v{2, 3, 5, 6, 7, 9};
    // cout<<solve(v,5,42950);
    // vector<int> v{0,1,2,5};
    // cout<<solve(v,2,21);
    vector<int> v{0, 2, 3, 4, 5, 7, 8, 9};
    cout<<solve(v,5, 86587);
    //code
    return 0;
}
