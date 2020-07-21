#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<=r) {
            int m = l+(r-l)/2;
            cout<<l<<" "<<m<<" "<<r<<endl;
            if((m > 0 && m < nums.size()-1 && nums[m] > nums[m-1] && nums[m] > nums[m+1])
              || (m > 0 && m == nums.size()-1 && nums[m] > nums[m-1])
              || (m == 0 && m < nums.size()-1 && nums[m] > nums[m+1])) {
             return m;   
            } else if(m > 0 && m < nums.size()-1 && nums[m]<nums[m+1]) {
                l = m+1;
            } else if(m > 0 && m < nums.size()-1 && nums[m]>nums[m+1]) {
                r = m-1;
            } else if(m==0 || nums.size() == 2) {
                return nums[m] > nums[m+1] ? m : m+1;
            } else if(m==0 || m==nums.size()-1) {
                return m;
            }
        } 
        return -1;
}


int main (){
    //code
    vector<int> v{13};
    cout<<findPeakElement(v);
    return 0;
}
