#include<bits/stdc++.h>
using namespace std;

int colorful(int a) {
    unordered_map<int, int> map;
    int copy = a;
    int digitCount = 0;
    vector<int> digits;
    while(copy != 0) {
        int digit = copy%10;
        map[digit]++;
        digits.push_back(digit);
        copy = copy/10;
        digitCount++;
    }
    for(int i=2; i<digitCount; i++) {
        for(int j=0; j<digitCount-i-1; j++) {
            int prod = 1;
            int k = j;
            for(int count = i; count>0; count--) {
                prod *= digits[k];
                k++;
            }
            map[prod]++;    
        }     
    }
    for(auto k: map) {
        cout<<k.first<< " ";
    }
    return 0;
}

int main(){
    cout<<colorful(3245);
    return 0;
}
