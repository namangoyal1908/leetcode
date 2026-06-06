// Problem: Squares of a Sorted Array
// Link: https://leetcode.com/problems/squares-of-a-sorted-array/
// Difficulty: Easy
// Pattern: Two Pointers
//
// Why this approach?
// - Brute force: square all → sort → O(n log n)
// - Optimised: uses the idea of MERGING TWO SORTED ARRAYS
//
// How merge of 2 sorted arrays relates here:
// - Original array has negatives and positives (sorted)
// - After squaring: negatives squared are in DESCENDING order (e.g. -3,-2,-1 → 9,4,1)
// - Positives squared are already in ASCENDING order (e.g. 1,2,3 → 1,4,9)
// - So we split into 2 sorted arrays and merge them → classic merge of 2 sorted arrays!
// - arr1 (squared negatives) → traverse from right to left (descending → ascending)
// - arr2 (squared positives) → traverse from left to right (already ascending)
// - Pick smaller of the two at each step → merge into result
//
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> arr1, arr2, result;

        // Step 1: Separate negatives and positives, square both
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                arr1.push_back(nums[i] * nums[i]);  // descending order after squaring
            else
                arr2.push_back(nums[i] * nums[i]);  // ascending order after squaring
        }

        // Step 2: Merge two sorted arrays
        // arr1 traversed right to left (to get ascending order)
        // arr2 traversed left to right (already ascending)
        int i = arr1.size() - 1;
        int j = 0;

        while (i >= 0 && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                result.push_back(arr1[i]);
                i--;
            } else {
                result.push_back(arr2[j]);
                j++;
            }
        }

        // Step 3: Push remaining elements
        while (i >= 0) {
            result.push_back(arr1[i]);
            i--;
        }
        while (j < arr2.size()) {
            result.push_back(arr2[j]);
            j++;
        }

        return result;
    }
};