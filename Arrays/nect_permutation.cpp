#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &A) {
    int n = A.size()-1;
    int prev = A[n];
    bool notDec = false;
    int minIndex = n;
    for(int i=n-1; i>=0; i--) {
        minIndex = A[minIndex] > A[i] ? minIndex : i;
        if(A[i+1] < A[i]) {
            int ind = i+1;
            int nxtMinInd = ind;
            while(ind<=n) {
                if(A[i] > A[ind]) {
                    nxtMinInd = A[nxtMinInd] > A[ind] ? nxtMinInd : ind;
                }
                cout<<nxtMinInd<<" "<<n<<endl;
                ind++;
            }
            cout<<A[i-1]<<" "<<A[nxtMinInd]<<"a"<<endl;
            swap(A[i-1], A[nxtMinInd]);
            sort(A.begin()+i+1, A.end());
            notDec = true;
            break;
        } else {
            prev = A[i];
        }
        // if(notDec)
        // break;
    }
    if(!notDec) {
        for(int i=0; i<=n/2; i++) {
            int temp = A[n-i];
            A[n-i] = A[i];
            A[i] = temp;
        }
    }
    return A;
}


int main (){
    //code
    // vector<int> v{5,6,7,9,4,3,7,9,8};
    vector<int> v{444, 994, 508, 72, 125, 299, 181, 238, 354, 223, 691, 249, 838, 890, 758, 675, 424, 199, 201, 788, 609, 582, 979, 259, 901, 371, 766, 759, 983, 728, 220, 16, 158, 822, 515, 488, 846, 321, 908, 469, 84, 460, 961, 285, 417, 142, 952, 626, 916, 247, 116, 975, 202, 734, 128, 312, 499, 274, 213, 208, 472, 265, 315, 335, 205, 784, 708, 681, 160, 448, 365, 165, 190, 693, 606, 226, 351, 241, 526, 311, 164, 98, 422, 363, 103, 747, 507, 669, 153, 856, 701, 319, 695, 52};
    // vector<int> v{626, 436, 819, 100, 382, 173, 817, 581, 220, 95, 814, 660, 397, 852, 15, 532, 564, 715, 179, 872, 236, 790, 223, 379, 83, 924, 454, 846, 742, 730, 689, 112, 110, 516, 85, 149, 228, 202, 988, 212, 69, 602, 887, 445, 327, 527, 347, 906, 54, 460, 517, 376, 395, 494, 827, 448, 919, 799, 133, 879, 709, 184, 812, 514, 976, 700, 156, 568, 453, 267, 547, 8, 951, 326, 652, 772, 213, 714, 706, 972, 318, 768, 506, 59, 854, 422};
    // vector<int> v{120, 110, 103};
    vector<int> ans;
    ans = nextPermutation(v);
    for(auto el:ans) {
        cout<<el<<" ";
    }
    return 0;
}
