#include<bits/stdc++.h>
using namespace std;

string fractionToDecimal(int a, int b) {
    long long A=a;
long long B=b;
    unordered_map<int, int> map;
    
    // A = absll(A);
    // B = absll(B);
    // int A = a;
    string ans = "";
    // int mul = 10;
    ans += to_string(A/B);
    string sign = ((A<0)^(B<0)&&ans[0] != '-') ? "-":""; 
    A = abs(A%B);
    A = A*10;
    int count = 1;
    map[A] = count++;
    string x = "";
    B = abs(B);
    while(A) {
        cout<<A<<" "<<B<<endl;
        x += to_string(A/B);
        A = A%B;
        A = A*10;
        if(map[A])
        break;
        else
        map[A] = count++;
    }
    if(x != "") {
        ans = ans + ".";
        bool repeat = false;
        for(int i=0; i<x.size(); i++) {
            if(i+1 == map[A]) {
                ans += '(';
                repeat = true;
            }
            ans += x[i];
        }
        // cout<<map[A];
        if(repeat)
        ans += ')';
    }
    return sign + ans;
}


int main (){
    //code
    cout<<fractionToDecimal(-7,-84343);
    return 0;
}
