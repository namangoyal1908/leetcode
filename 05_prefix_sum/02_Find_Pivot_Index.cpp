// Problem: Find Pivot Index
// Link: https://leetcode.com/problems/find-pivot-index/
// Difficulty: Easy
// Pattern: Prefix Sum
//
// What is Pivot Index?
// - Index where sum of left elements == sum of right elements
// - Pivot element itself is not included in either side
//
// Approach:
// - Calculate total sum first
// - At every index i:
//   left  = sum of elements before i
//   right = totalSum - nums[i] - left
// - If left == right → pivot found
//
// Why check index 0 separately?
// - Loop starts at i=1 → left starts accumulating from nums[0]
// - If pivot is at index 0 → left = 0, right = sum - nums[0]
// - Need to check if sum - nums[0] == 0 before loop
//
// Why right = sum - nums[i] - left?
// - sum = left + nums[i] + right
// - → right = sum - nums[i] - left
// - No need to maintain separate right prefix array
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        // Step 1: calculate total sum
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Step 2: check index 0 separately
        if (sum - nums[0] == 0)
            return 0;

        // Step 3: check remaining indices
        int left = 0;
        for (int i = 1; i < n; i++) {
            left += nums[i - 1];               // sum of elements before i
            int right = sum - nums[i] - left;  // sum of elements after i

            if (left == right)
                return i;
        }

        return -1;  // no pivot found
    }
};