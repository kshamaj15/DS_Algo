#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<=r) {

            int m = l+(r-l)/2;
            cout<<l<<" "<<m<<" "<<r<<endl;
            if(m > 0 && nums[m]<nums[m-1]) {
                return nums[m];
            } else if (nums[m] > nums[nums.size()-1]) {
                l = m+1;
            } else if (nums[m] < nums[nums.size()-1]) {
                r = m-1;
            } else if(m==0) {
                return nums[0];
            }
            
        }
        return nums[0];
    }

int main (){
    //code
    vector<int> v{4,5,6,7,0,1,2};
    cout<<findMin(v);
    return 0;
}
