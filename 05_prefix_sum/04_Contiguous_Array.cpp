// Problem: Contiguous Array
// Link: https://leetcode.com/problems/contiguous-array/
// Difficulty: Medium
// Pattern: Prefix Sum + HashMap
//
// Problem in simple terms:
// - Find longest subarray with equal number of 0s and 1s
//
// Key Trick:
// - Treat 0 as -1 and 1 as +1
// - If subarray has equal 0s and 1s → sum of that subarray = 0
// - So we need two indices i, j where prefixSum[i] == prefixSum[j]
// - Subarray between them has sum 0 → equal 0s and 1s
//
// Why mp[0] = -1?
// - If prefixSum becomes 0 at index i → subarray [0, i] is valid
// - length = i - (-1) = i + 1 → correct length using imaginary index -1
// - Without this → we'd miss subarrays starting from index 0
//
// Why store FIRST occurrence only?
// - We want LONGEST subarray → need earliest index with same sum
// - If sum repeats → don't update map → keep earliest index
// - This guarantees maximum possible length when match found
//
// Why different from Subarray Sum == K?
// - That problem: COUNT all subarrays with sum == k → uses frequency
// - This problem: LONGEST subarray with sum == 0 → uses first index only
//
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        int maxi = 0;
        mp[0] = -1;  // important: handles subarray starting from index 0

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                sum += -1;
            else
                sum += 1;

            if (mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]);
            } else {
                mp[sum] = i;  // store first occurrence only
            }
        }

        return maxi;
    }
};