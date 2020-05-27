#include<iostream>
#include<unordered_set>
using namespace std;
int main () {
    int arr[10] = {2,5,5,2,6,8,1,4,0,6};
    unordered_set<int> unique;
    unordered_set<int> dupli;

    for(auto i: arr) {
        if (unique.find(i) == unique.end())
        unique.insert(i);
        else 
        dupli.insert(i);
    }

    // iterator
    unordered_set<int>:: iterator itr1;
    cout << "Unique elements are as follows: ";
    for(itr1 = unique.begin(); itr1 != unique.end(); itr1++) {
        cout << *itr1 << " ";
    }
    cout << endl;

    unordered_set<int>:: iterator itr2;
    cout << "Duplicate elements are as follows: ";
    for(itr2 = dupli.begin(); itr2 != dupli.end(); itr2++) {
        cout << *itr2 << " ";
    }
    cout << endl;

    return 0;
}