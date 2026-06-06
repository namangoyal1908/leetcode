// Problem: Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Difficulty: Easy
// Pattern: Two Pointers
//
// Why this approach?
// - Array is sorted so duplicates are always adjacent
// - Used two pointers via raw pointer arithmetic (practice purpose)
// - p1 tracks where to place next unique element (write pointer)
// - p2 used as base for traversal with index i
// - If current element == previous → skip (duplicate)
// - If current element != previous → write it at position j and move j
// - j at the end = count of unique elements
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int* p1 = &nums[0];  // write pointer
        int* p2 = &nums[1];  // read pointer base

        int i = 0;  // traversal index
        int j = 1;  // position for next unique element

        while (i < n - 1) {
            if (*(p2 + i) == *(p2 + i - 1)) {
                // duplicate found → skip
                i++;
                continue;
            }
            else if (*(p2 + i) != *(p2 + i - 1)) {
                // unique element → write it at j
                *(p1 + j) = *(p2 + i);
                j++;
                i++;
            }
        }

        return j;  // number of unique elements
    }
};