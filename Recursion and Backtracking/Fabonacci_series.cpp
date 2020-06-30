#include<bits/stdc++.h>
using namespace std; 
  

  long long int fib2(long long int n) 
{ 
      
    // Declare an array to store  
    // Fibonacci numbers. 
    // 1 extra to handle  
    // case, n = 0  
    long long int f[n + 2];  
    long long int i; 
  
    // 0th and 1st number of the  
    // series are 0 and 1 
    f[0] = 0; 
    f[1] = 1; 
  
    for(i = 2; i <= n; i++) 
    { 
          
       //Add the previous 2 numbers  
       // in the series and store it 
       f[i] = f[i - 1] + f[i - 2]; 
    } 
    return f[n]; 
    } 

long long int fib1(long long int n) 
{ 
    long long int a = 0, b = 1, c, i; 
    if( n == 0) 
        return a; 
    for(i = 2; i <= n; i++) 
    { 
       c = a + b; 
       a = b; 
       b = c; 
    } 
    return b; 
} 
  
// Driver code 
int main() 
{ 
    long long int n = 1000; 
      
    cout << fib2(n); 
    return 0; 
} 