#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A) {
    vector<int> ans;
    int pIndex, nIndex;
    
    int n = A.size();
    int s = 0, e = n-1;
    while(s<=e) {
        int m = s+(e-s)/2;
        if(A[m] >= 0 && m == 0) {
            pIndex = 0;
            nIndex = -1;
            break;
        } else if(A[m] < 0 && m == n-1) {
            pIndex = -1;
            nIndex = n-1;
            break;
        } else if(A[m] >= 0 && A[m-1] < 0) {
            pIndex = m;
            nIndex = m-1;
            break;
        } else if(A[m] < 0 && A[m+1] >= 0) {
            pIndex = m+1;
            nIndex = m;
            break;
        } else if(A[m] >= 0 && A[m-1] >= 0 && A[m+1] >= 0) {
            e = m-1;
        } else if(A[m] < 0 && A[m-1] < 0 && A[m+1] < 0) {
            s = m+1;
        }
    }
    while(nIndex >= 0 && pIndex < n) {
        if(abs(A[pIndex]) <= abs(A[nIndex])) {
            ans.push_back(A[pIndex]*A[pIndex]);
            pIndex++;
        } else {
            ans.push_back(A[nIndex]*A[nIndex]);
            nIndex--;
        }
    }
    while(nIndex >= 0) {
        ans.push_back(A[nIndex]*A[nIndex]);
        nIndex--;
    }
    while(pIndex < n) {
        ans.push_back(A[pIndex]*A[pIndex]);
        pIndex++;
    }
    return ans;
}


int main (){
    //code
    vector<int> v{-10000, -9999, -822, -811, -799, -732, -711, -699, -632, -532, -93, -43, -32, -29, -18, -2, -1, 0, 7, 7, 31, 67};
    vector<int> ans;
    ans = solve(v);
    for(auto el: ans) {
        cout<<el<<" ";
    }
    return 0;
}
// vector<int> solve(vector<int> &A) {
//     vector<int> ans;
//     int index = 0;
//     for(int i=1; i<A.size(); i++) {
//         if(A[i-1]<0 && A[i] >=0) {
//             index = i;
//             break;
//         }
//     }
//     int left = index-1;
//     int right = index;
//     while(left >=0 && right < A.size()) {
//         cout<<left<<" "<<right<<endl;
//         if(abs(A[left]) >= abs(A[right])) {
//             ans.push_back(A[right]*A[right]);
//             right++;
//         } else {
//             ans.push_back(A[left]*A[left]);
//             left--;
//         }
//     }
//     if(left <= 0) {
//         while(right < A.size()) {
//             ans.push_back(A[right]*A[right]);
//             right++;
//         }
//     } else if (right >= A.size()-1) {
//         while (left >= 0) {
//             ans.push_back(A[left]*A[left]);
//             left--;
//         }
        
//     }
//     return ans;
// }



