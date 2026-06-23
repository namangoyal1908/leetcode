// Problem: Contiguous Array
// Link: https://leetcode.com/problems/contiguous-array/
// Difficulty: Medium
// Pattern: Prefix Sum + HashMap
//
// Brute Force: O(n²)
// - Check every subarray, count 0s and 1s
// - Track maximum length where count(0) == count(1)
// - Too slow for large inputs
//
// Prefix Sum + HashMap - The "Red and Green" Insight
//
// Split the array mentally into two parts:
// - RED part   → wrong section (unequal 0s and 1s so far)
// - GREEN part → correct section (equal 0s and 1s)
//
// To find the longest GREEN part, we need to know:
// "what prefix do I need to CUT from the left to make it balanced?"
//
// Key Trick: treat 0s and 1s as -1 and +1 implicitly via diff = zero - one
//   → diff == 0 means equal 0s and 1s from index 0 → record i+1
//   → same diff seen before at index idx means:
//       the subarray (idx+1 to i) has equal 0s and 1s
//       → the RED prefix cancelled out → what remains is GREEN
//
// HashMap stores: { diff → first index where this diff was seen }
// Once same diff appears again → the chunk between is perfectly balanced
//
// Example:
//   nums = [0, 1, 0, 0, 1, 1]
//   diff  = [1, 0, 1, 2, 1, 0]
//            ↑        ↑
//         diff=1     diff=1 again → subarray [1..4] is balanced ✅
//
// Time: O(n) | Space: O(n)
// Single pass through array, HashMap stores at most n distinct diffs

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, one = 0;
        int res = 0;
        unordered_map<int, int> f;  // { diff → first index seen }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) zero++;
            else one++;

            int diff = zero - one;

            if (diff == 0) {
                // Balanced from index 0 → i, entire prefix is GREEN
                res = max(res, i + 1);
                continue;
            }

            if (f.find(diff) == f.end()) {
                f[diff] = i;  // first time seeing this diff → store it
            } else {
                // Same diff seen before → RED prefix cancelled out
                int len = i - f[diff];  // GREEN part length
                res = max(res, len);
            }
        }

        return res;
    }
};