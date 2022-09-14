// https://leetcode.com/problems/single-element-in-a-sorted-array/

#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while(e >= s) {
            int mid = s + (e-s)/2;
            bool isOdd = (bool)(mid%2);
            cout<<mid<<" "<<isOdd<<endl;
            if((isOdd && nums[mid] == nums[mid-1]) 
               ||(!isOdd && mid < n-1 && nums[mid] == nums[mid+1])) {
                // go right
                s = mid + 1;
            } else if ((isOdd && mid < n-1 && nums[mid] == nums[mid+1])
                      || (!isOdd && mid > 0 && nums[mid] == nums[mid-1])) {
                // go left
                e = mid - 1;
            } else {
                return nums[mid];
            }
        }
        return -1;
    }

int main() {
    vector<int> arr = {1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(arr)<<endl;
}