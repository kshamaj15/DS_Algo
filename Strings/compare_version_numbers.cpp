#include<bits/stdc++.h>
using namespace std;

int compareVersion(string A, string B) {
    int i = 0;
    int j = 0;
    int x=5;
    while(i<A.size() || j<B.size()) {
        string a = ""; 
        string b = "";
        bool zeroA = true;
        bool zeroB = true;
        while(i<A.size() && A[i] != '.') {
            if(A[i] == '0' && !zeroA)
            a += A[i];
            else if(A[i] != '0') {
                a += A[i];
                zeroA = false;
            }
            i++;
        }
        while(j<B.size() && B[j] != '.') {
            if(B[j] == '0' && !zeroB)
            b += B[j];
            else if(B[j] != '0') {
                b += B[j];
                zeroB = false;
            }
            j++;
        }
        i++;
        j++;
        if(a == "")
        a = "0";
        if(b == "")
        b = "0";

        if(a.size() > b.size())
        return 1;
        else if(a.size() < b.size())
        return -1;
        else {
            if(a>b)
            return 1;
            if(a<b)
            return -1;
        }
    }
}


int main (){
    //code
    cout<<compareVersion("01","1");
    return 0;
}
