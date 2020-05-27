#include<iostream>
#include<vector>
using namespace std;
void swap(int *a, int *b);
int main() {
    //  vector<int> unSortedList = {4,7,2,6,2,0,1,9}; //avg case
    //  vector<int> unSortedList = {0, 1, 2, 2, 4, 6, 7, 9}; //best case
     vector<int> unSortedList = {9,7,6,4,2,2,1,0}; // worst case

     int start = 0; 
     int end = unSortedList.size() - 1;

     quickSort(unSortedList, start, end);

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

 void quickSort(vector<int> arr, int s, int e) {
     while (/* condition */)
     {
         /* code */
     }
     
 }