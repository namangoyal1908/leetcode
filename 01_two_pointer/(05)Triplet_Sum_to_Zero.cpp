// Problem: Three Sum
// Link: https://leetcode.com/problems/3sum/
// Difficulty: Medium
// Pattern: Two Pointers
//
// Why this approach?
// - Brute force: 3 nested loops checking all triplets → O(n³)
// - Optimised: Sort + fix one element + Two Pointers for remaining two → O(n²)
//
// Key Idea:
// - Sort the array first
// - Fix nums[i] as the first element using outer loop
// - Problem reduces to: find two numbers in remaining array that sum to -nums[i]
// - Use two pointers (p1 from left, p2 from right) to find the pair → O(n)
// - Skip duplicates at both outer loop and inner pointers to avoid duplicate triplets
//
// Duplicate handling:
// - Outer loop: if nums[i] == nums[i-1] → skip (same fixed element)
// - After finding triplet: skip duplicate p1 values (*(p1)==*(p1-1))
// - After finding triplet: skip duplicate p2 values (*(p2)==*(p2+1))
//
// Time: O(n²) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int l = nums.size();
        vector<vector<int>> result;

        for (int i = 0; i < l - 2; i++) {

            // Skip duplicate fixed elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Two pointers for remaining subarray
            int* p1 = &nums[i + 1];  // left pointer
            int* p2 = &nums[l - 1];  // right pointer

            while (p1 < p2) {
                if (*p1 + *p2 == -nums[i]) {
                    // Found a valid triplet
                    result.push_back({*p1, *p2, nums[i]});
                    p1++;
                    p2--;

                    // Skip duplicates from left
                    while (p1 < p2 && *p1 == *(p1 - 1))
                        p1++;

                    // Skip duplicates from right
                    while (p2 > p1 && *p2 == *(p2 + 1))
                        p2--;
                }
                else if (*p1 + *p2 > -nums[i]) {
                    p2--;  // sum too big → move right pointer left
                }
                else {
                    p1++;  // sum too small → move left pointer right
                }
            }
        }

        return result;
    }
};