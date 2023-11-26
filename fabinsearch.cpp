#include <iostream> 
using namespace std;   

int fibonacciSearch(int arr[], int n, int x) { 
if (n == 0) { 
return -1; 
} 
int fib1 = 0, fib2 = 1, fib3 = fib1 + fib2; 
while (fib3 < n)
 { 
    fib1 = fib2; 
    fib2 = fib3; 
    fib3 = fib1 + fib2; 
} 
int offset = -1; 
while (fib3 > 1) 
{ 
    int i = min(offset + fib2, n-1);
    if (arr[i] < x) { 
        fib3 = fib2; 
        fib2 = fib1; 
        fib1 = fib3 - fib2; 
        offset = i; 
    } 
    else if (arr[i] > x) { 
        fib3 = fib1; 
        fib2 = fib2 - fib1; 
        fib1 = fib3 - fib2; 
    } 
    else { 
        return i; 
    } 
} 
if (fib2 == 1 && arr[offset+1] == x) { 
    return offset + 1; 
} else { 
    return -1; 
} 
} 
int main() { 

int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100, 235}; 
int n = sizeof(arr)/sizeof(arr[0]); 
int x = 50; 
int ind = fibonacciSearch(arr, n, x); 
if (ind >= 0) { 
cout << "Found at index: " << ind << endl; 
} else { 
cout << x << " isn't present in the array" << endl; 
} 
return 0; 
}
