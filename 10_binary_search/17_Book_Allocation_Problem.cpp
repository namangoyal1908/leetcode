// Problem: Book Allocation Problem
// Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// Difficulty: Hard
// Pattern: Binary Search on Answer
//
// Problem in simple terms:
// - Allocate books to k students such that the MAXIMUM pages assigned
//   to any student is MINIMIZED
// - Each student gets a contiguous chunk of books
//
// How is it similar to Aggressive Cows and Koko?
// - All three use Binary Search on Answer with a helper() feasibility check
// - Koko:  minimize eating speed → helper checks hours <= h
// - Cows:  maximize min distance → helper checks cows placed >= k
// - Books: minimize max pages → helper checks partitions needed <= k
//
// helper() function:
// - Given a page 'limit', checks if we can assign books to k or fewer
//   students such that no student reads more than 'limit' pages
// - Walk through books greedily → keep adding to current student's load
// - If adding next book exceeds limit → assign to NEXT student (a++)
//   and reset books count to just that book
// - If students needed (a) > k → this limit is too small → false
// - Otherwise → feasible → true
//
// Search space:
// - low = max(arr) → minimum possible limit (one student can't read less
//   than the biggest book — each student gets at least one book)
// - high = sum(arr) → maximum possible limit (one student reads ALL books)
// - Binary search between them → minimize limit while keeping helper true
//
// Edge case:
// - If n < k → more students than books → impossible to allocate
//   (each student must get at least one book) → return -1
//
// Time: O(n log(sum)) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  bool helper (vector<int>&arr,int n,int k,long long limit){
      
      int a=1;
      long long books =0;
      
      for(int i=0;i<n;i++){
          if(books+arr[i]<=limit){
              books = books + arr[i];
              
          }
          else{a++;
          books=arr[i];
      }
      }
      if(a>k){
          return false ;
      }
      else{ return true;}
  }
    int findPages(vector<int> &arr, int k) {
        int n= arr.size();
        if(n<k){
            return -1;
        }
        long long  low=arr[0];
        long long high=0;
        long long res;
        for(int i=0;i<n;i++){
            if(arr[i]>low){
                low=arr[i];
            }
            high=high+arr[i];
        }
        while(high>=low){
        long long limit = (high +low)/2;
        if(!helper(arr,n,k,limit)){
            low = limit+1;
        }
        else {
            res=limit;
            high=limit-1;
        }}return res;
        
    }
};