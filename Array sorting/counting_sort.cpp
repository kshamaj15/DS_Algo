// Counting sort is a sorting technique based on keys between a specific range. 
// It works by counting the number of objects having distinct key values (kind of hashing). 
// Then doing some arithmetic to calculate the position of each object in the output sequence.
// for more theory ---- SCROLL DOWN

// { Driver Code Starts
// C Program for counting sort
#include<bits/stdc++.h>
using namespace std;

// The main function that sort the given string arr[] in
// alphabatical order
char* countSort(char arr[]);

// Driver program to test above function
int main()
{
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        long int n;
        scanf("%ld",&n);
        char arr[n+1];
        scanf("%s",arr);
        printf("%s\n", countSort(arr));
    }
    return 0;
}

// } Driver Code Ends

char* countSort(char arr[])
{
    int a[26];
    memset(a, 0, sizeof(a));
    int i=0;
    while(arr[i] != '\0') {
        int index = arr[i] - 'a';
        a[index]++;
        i++;
    }
    for(int i=1; i<26; i++) {
        a[i] = a[i] + a[i-1];
    }
    int k = 0;
    i=0;
    while(i<26) {
        while(k < a[i]) {
            arr[k] = (char)(i+97);
            k++;
        }
        i++;
    }
    return arr;
}

// For simplicity, consider the data in the range 0 to 9. 
// Input data: 1, 4, 1, 2, 7, 5, 2
//   1) Take a count array to store the count of each unique object.
//   Index:     0  1  2  3  4  5  6  7  8  9
//   Count:     0  2  2  0   1  1  0  1  0  0

//   2) Modify the count array such that each element at each index 
//   stores the sum of previous counts. 
//   Index:     0  1  2  3  4  5  6  7  8  9
//   Count:     0  2  4  4  5  6  6  7  7  7

// The modified count array indicates the position of each object in 
// the output sequence. (1 based indexing)
 
//   3) Output each object from the input sequence followed by 
//   decreasing its count by 1.
//   Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
//   Put data 1 at index 2 in output. Decrease count by 1 to place 
//   next data 1 at an index 1 smaller than this index.