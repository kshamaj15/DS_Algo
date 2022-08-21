#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int> &a) { 
    vector<int> b;
    int carry = 0;
    for(int i = a.size()-1; i>=0; i--) {
        if(i==a.size()-1) {
            a[i]++;
            carry = a[i] / 10;
            a[i] = a[i] % 10;
            // cout<<a[i]<<": "<<carry<<endl;
        } else {
            if(carry) {
                a[i] = a[i] + carry;
                carry = a[i] / 10;
                a[i] = a[i] % 10;
                // cout<<a[i]<<": "<<carry<<endl;
            }
        }
    }
    int start = true;
    if(carry) {
        b.push_back(1);
        for(auto i: a) {
            b.push_back(i);
        }
    } else {
        for(auto i: a) {
            if(i!=0 || !start) {
                b.push_back(i);
                start = false;
            }
        }
    }
    return b;
}


int main() {
    vector<int> a({1,9,9,9,9});
    vector<int> b;
    b = plusOne(a);
    for(auto i: b) {
        cout<<i<<" ";
    }
    return 0;
}