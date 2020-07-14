#include <bits/stdc++.h> 
using namespace std;  
 
bool compareInterval(int a, int b) 
{ 
    // cout<<a<<" "<<b<<endl;
    vector<int> digiA;
    vector<int> digiB;
    while(a != 0) {
        // cout<<a%10<<" ";
        digiA.push_back(a%10);
        a=a/10;
    }
    while(b != 0) {
        // cout<<b%10<<" ";
        digiB.push_back(b%10);
        b=b/10;
    }
    int asiz = digiA.size()-1;
    int bsiz = digiB.size()-1;
    // cout<<asiz<<" "<<bsiz<<endl;
    while(asiz >= 0 && bsiz >= 0) {
        if(digiA[asiz] != digiB[bsiz]) {
            // cout<<asiz<<" "<<bsiz<<endl;
            // cout<<digiA[asiz]<<" "<<digiB[bsiz]<<endl;
            return digiA[asiz] > digiB[bsiz];
        } else {
            if(asiz > 0 && bsiz > 0) {
                asiz--;
                bsiz--;
            } else {
                if(asiz > 0) {
                    // cout<<"a";
                    asiz--;
                    bsiz = digiB.size()-1;
                }
                else if(bsiz > 0) {
                    // cout<<"b";
                    bsiz--;
                    asiz = digiA.size()-1;
                }
            }
        }
        if(bsiz == 0 && asiz == 0 && digiA[asiz] == digiB[bsiz]) {
            return true;
        }
    }
    return true;
} 
  
int main() 
{ 
    vector<int> A{3, 30, 34, 5, 9, 9};
    sort(A.begin(), A.end(), compareInterval);
    string ans = "";
    bool leadingZero = A[0] == 0;
    for(auto el: A) {
        cout<<el<<endl;
        if(el != 0 && leadingZero) { 
            leadingZero = false;
            ans = ans + to_string(el);
        } else if (!leadingZero) {
            ans = ans + to_string(el);
        }
    }
    cout<< ans;
    return 0; 
} 
