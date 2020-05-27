#include<iostream>
#include<unordered_map>
using namespace std;
int main () {
    int arr[10] = {2,5,5,2,6,8,1,4,0,6};
    int sum = 4;
    int twice_count = 0;
    int index = 1;
    //step 1: creat a map
    unordered_map<int, int> uom;
    for(auto i: arr) {
        uom[i]++;
    }
    for(auto i: arr) {
        twice_count = uom[sum - i] + twice_count;

        // because in this case uom[sum - i = i]
        // hence same element count is adding
        // so we need to remove it by one
        if (sum == 2*i) {
        twice_count--;

        } 
        // cout << index++ << " " << twice_count << endl;;
    }
    cout << twice_count/2;
    return 0;
}