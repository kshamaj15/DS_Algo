#include<iostream>
#include<vector>
using namespace std;
void swap(int *a, int *b);
 
 int main() {
     vector<int> unSortedList = {4,7,2,6,2,0,1,9}; //avg case
    //  vector<int> unSortedList = {0, 1, 2, 2, 4, 6, 7, 9}; //best case
    //  vector<int> unSortedList = {9,7,6,4,2,2,1,0}; // worst case
     for(int i=0; i < unSortedList.size()-2; i++) {
         for(int j=0; j < unSortedList.size()-1; j++) {
             if(unSortedList[j] > unSortedList[j+1])
             swap(&unSortedList[j], &unSortedList[j+1]);
         }
     }

     for(int i=0; i < unSortedList.size(); i++) {
         cout << unSortedList[i] << " ";
     }
     return 0;
 }

 void swap(int *a, int *b) {
     *a = *a + *b;
     *b = *a - *b;
     *a = *a - *b;
 }