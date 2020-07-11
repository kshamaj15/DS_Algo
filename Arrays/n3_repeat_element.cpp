#include<iostream>
#include<vector>
using namespace std;

int repeatedNumber(const vector<int> &A) {
    int num1, num2;
    int count1=0, count2=0;
    for(auto el:A) {
        if(el == num1) {
            count1++;
        } else if (el == num2){
            count2++;
        } else if(count1 == 0) {
            count1++;
            num1 = el;
        } else if(count2 == 0) {
            count2++;
            num2 = el;
        } else {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(auto el:A) {
        if(el == num1)
        count1++;
        if(el == num2)
        count2++;
    }
    if(count1 > A.size()/3)
    return num1;
    else if(count2 > A.size()/3)
    return num2;
    else
    return -1;
}

int main() {
    vector<int> a({1,9,9,9,9,6});
    cout<<repeatedNumber(a);
    return 0;
}
