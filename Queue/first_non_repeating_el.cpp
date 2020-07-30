#include<bits/stdc++.h>
using namespace std;

string solve(string A) {
    // queue<char> qu;
    // string ans = "";
    // ans += A[0];
    // qu.push(A[0]);
    // for(int i=1; i<A.size(); i++) {
    //     if(qu.empty()) {
    //         ans += '#';
    //     }
    //     else if(qu.front() == A[i]) {
    //         qu.pop();
    //         if(qu.empty())
    //         ans += '#';
    //         else
    //         ans += qu.front();
    //     } else if (qu.front() != A[i]) {
    //         qu.push(A[i]);
    //         ans += qu.front();
    //     }
        
    // }
    // return ans;
    queue<char> qu;
    string ans = "";
    ans += A[0];
    char prev = A[0];
    qu.push(A[0]);
    vector<int> charCount(26);
    charCount[A[0] - 'a']++;
    for(int i=1; i<A.size(); i++) {
        charCount[A[i] - 'a']++;
        
        prev = A[i];
        if(qu.empty()) {
            qu.push(A[i]);
            if(charCount[qu.front()-'a'] != 1)
            ans += '#';
            else 
            ans += A[i];
        }
        else if(qu.front() == A[i]) {
            qu.push(A[i]);
            qu.pop();
            if(qu.empty())
            ans += '#';
            else {
                while(charCount[qu.front()-'a'] != 1 && !qu.empty())
            qu.pop();
            if(!qu.empty())
            ans += qu.front();
            else
            ans += '#';
            }
        } else if (qu.front() != A[i]) {
            // qu.push(prev);
            qu.push(A[i]);
            while(charCount[qu.front()-'a'] != 1 && !qu.empty())
            qu.pop();
            if(!qu.empty())
            ans += qu.front();
            else
            ans += '#';
        }
        
    }
    return ans;
}


int main (){
    //code
    cout<<solve("xyzxyz");
    return 0;
}
