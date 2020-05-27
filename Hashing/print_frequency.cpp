#include<iostream>
#include<unordered_map>
using namespace std;
int main () {
    int arr[10] = {2,5,5,2,6,8,1,4,0,6};
    unordered_map<int, int> map;
    for(auto i: arr) {
        map[i]++;
    }

    // iterator
    unordered_map<int, int>:: iterator itr;
    for(itr = map.begin(); itr != map.end(); itr++) {
        cout << itr->first << ": " << itr->second << endl;
    }
    return 0;
}