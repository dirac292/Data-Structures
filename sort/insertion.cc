#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


// Consider the first element to be sorted sequence of length one
 // Insert the second element into existing sequence into correct position
 // first i elemnts are sorted we then insert a[i] into correct pos

// Auxilary Space: theta(1)
// Worst case : theta(n^2) 
// Best case: theta(n) // when array is sorted
void insertion_sort(std::vector<int>& a) {
  for(int i = 1 ; i < a.size(); i ++) {
   int j = i;
   while (j > 0 && a[j] < a[j - 1])
   {
    int temp = a[j];
    a[j] = a[j-1];
    a[j-1] = temp;
    //  std::swap(&a[j],&a[j-1]);
    j = j - 1;
   }; 
   std:: cout << "Pass " << i << " : " ;
   for(auto k: a) {
    std::cout << k << " " ;
  }
  std::cout << std::endl;
  }
   
}


// Merge sort

// Split A into 2 subarrays: A_L consists of the first [n/2] elements
// in A and A_R consists of the last [n/2] elements in A.

//Recursively run mergesort on A_L and A_R

// after A_L and A_r have been sorted merge them to a single sorted array

//  

void merge(std::vector<int>& A, int l, int m, int r,std::vector<int>& S){
 for(int j = l; j<=r ; j++) {
  S[j] = A[j];
  // S.push_back(A[j]);
  // std::cout<< A[j] << std::endl;
 }
 int i_l = l;
 int i_r = m+1;
 for(int k = l; k <=r ; k++) {
  if (i_l > m) A[k] = S[i_r++];
  else if(i_r > r) A[k] = S[i_l++];
  else if (S[i_l] <= S[i_r]) A[k] = S[i_l++];
  else A[k] = S[i_r++];
 }
 std:: cout << "Pass " << " : " ;
   for(auto k: A) {
    std::cout << k << " " ;
  }
  std::cout << std::endl;

}

void mergesort(std::vector<int>& A, int n, int l, int r,std::vector<int>& S) {
  // if (S.size() == 0) {
  //   std::cout <<"Triggered" << std::endl;
  //   for(int i = 0; i < A.size(); i++) {
  //     S.push_back(0);
  //   }
  // } 
  if(r <= l) {
    return;
  } else{
    int m = (r + l)/2;
    mergesort(A,n,l,m,S);
    mergesort(A,n,m+1,r,S);
    merge(A,l,m,r,S);
  }
}



int main() {

  std::vector<int> b = {8,2,7};
  std::vector<int> S(b.size());
  std::cout<< "Given array : " ;
  for(auto i: b) {
    std:: cout << i << " " ;
  }
  std::cout<< std::endl;
  mergesort(b,b.size(),0,b.size()-1,S);
  std::cout << "Sorted Array : ";
  for(auto i: b) {
    std:: cout << i << " ";
  }

}