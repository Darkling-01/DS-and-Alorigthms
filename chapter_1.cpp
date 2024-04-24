#include <iostream>
#include <string>
#include <climits>
#include <cmath>



// Question 1

/*
Write a program to solve the selection problem.
Let k = N/2. Draw a table showing the running time

NOTES: Here N represents total number of elements in the array.
k is the position of the element you're trying to find.
K = N/2 is finding the element in the middle(median) of the list or array.

*/


// rearrange the elements of an array smaller to greater..
int partition(int arr[], int l, int r){
   int x = arr[r];    // pivot element just holds value not index
   int L = 1; 

   for(int i = L; i <= r; i++){   // use '<=' to include element index r-1
      if(arr[i] < x){
	  std::swap(arr[L], arr[i]); 
	  L++;	// increment element
	}
    }
  
    std::swap(arr[L], arr[r]);  // move pivot to final place
    return L;
}

// left <= k <= right
int select(int arr[], int l, int r, int k){
    if(l == r){   // if array has only one element
      return arr[l];
    }
   
    int index = partition(arr, l, r);
    // in the final sorting postion
    if(k == index){
       return arr[k];
    } 
    else if(k < index){
       return select(arr, l, index - 1, k);
    }
    else{
       return select(arr, index + 1, r, k);
    }

}


int main(){
   double processing;
   int arr[] = {10, 4, 5, 8, 6, 11, 26};
   int n = sizeof(arr) / sizeof(arr[0]);
   int k = 3;

   std::cout << select(arr, 0, n - 1, k) << std::endl;

   return 0;
}


