// Problem: Search 2D Matrix II
// Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
// Difficulty: Hard
// Pattern: Binary Search / Two Pointers
//
// How is it different from Search 2D Matrix (I)?
// - Matrix I: each row's first element > last element of previous row
//   → entire matrix is ONE fully sorted sequence → plain binary search
// - Matrix II: each row sorted, each COLUMN sorted, BUT first element
//   of next row is NOT necessarily > last element of current row
//   → can't flatten to 1D → different approach needed
//
// Key Insight - Start from BOTTOM LEFT corner:
// - Bottom left gives a unique property:
//   → moving UP   decreases the value (column is sorted top to bottom)
//   → moving RIGHT increases the value (row is sorted left to right)
// - This means at every step we can ELIMINATE either an entire row
//   or an entire column with one comparison → no wasted moves
//
// Approach:
// - Start at row = n-1 (bottom), col = 0 (leftmost)
// - If matrix[row][col] == target → found → return true
// - If matrix[row][col] > target → current value too big →
//   entire remaining column below is also too big (column sorted) →
//   eliminate this row → row--
// - If matrix[row][col] < target → current value too small →
//   entire remaining row to the left is also too small (row sorted) →
//   eliminate this column → col++
// - Continue until out of bounds → return false
//
// Why not start from top-right instead?
// - Top right works too (same logic mirrored) — moving LEFT decreases,
//   moving DOWN increases → equally valid starting corner
// - Top-left or bottom-right DON'T work → both moves go same direction
//
// Time: O(n + m) → at most n rows + m cols traversed | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row=n-1;
        int col=0;
        while (row>=0&&col<m){
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                row--;
            }
            else{col++;}
         }return false;
    }
};