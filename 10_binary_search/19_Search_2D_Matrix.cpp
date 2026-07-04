// Problem: Search 2D Matrix
// Link: https://leetcode.com/problems/search-a-2d-matrix/
// Difficulty: Medium
// Pattern: Binary Search
//
// Key Insight:
// - Matrix rows are sorted AND each row's first element is greater than
//   last element of previous row → the ENTIRE matrix is one long sorted array
// - So treat the n*m matrix as a SINGLE sorted array of size n*m
//   and run standard binary search on it
//
// How to convert 1D index to 2D index?
// - guess is the 1D index in the "flattened" array
// - row = guess / m → which row (integer division)
// - col = guess % m → which column (remainder)
// - e.g. for a 3x4 matrix, index 6 → row = 6/4 = 1, col = 6%4 = 2
//   → matrix[1][2]
//
// Why does this work?
// - The flattening maps perfectly because each row has exactly m elements
// - So every 1D index maps to EXACTLY one unique (row, col) pair
// - Standard binary search logic applies identically after this mapping
//
// How is it different from standard Binary Search?
// - Standard: array[guess]
// - This: matrix[guess/m][guess%m] → same logic, just 2D index conversion
//
// Time: O(log(n*m)) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size();
        int m = matrix[0].size();
        int low=0;
        int high = (n*m)-1;
        while(high>=low){
            int guess=(low+high)/2;
            int row = guess/m;
            int col=guess%m;
            if(matrix[row][col]==target ){
                return true ;
        }
            else if(matrix[row][col]<target ){
            low=guess+1;
        }
            else if(matrix[row][col]>target ){
            high=guess-1;
        }}return false;
    }
};