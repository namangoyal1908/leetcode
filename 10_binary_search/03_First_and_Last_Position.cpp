// Problem: First and Last Position of Element in Sorted Array
// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Difficulty: Medium
// Pattern: Binary Search
//
// Helper functions:
// - first() → moves high pointer LEFT past the current guess (high = guess-1)
// - last()  → moves low pointer RIGHT past the current guess (low = guess+1)
//
// Approach (TWO separate binary searches):
// - First binary search: finds the FIRST (leftmost) occurrence of target
//   → when nums[guess] == target, record it in resi[0], but DON'T stop —
//     keep searching LEFT (high = first(...)) for an even earlier occurrence
// - Second binary search: finds the LAST (rightmost) occurrence of target
//   → when nums[guess] == target, record it in resi[1], but DON'T stop —
//     keep searching RIGHT (low = last(...)) for an even later occurrence
// - Both searches reset low/high back to 0/n-1 before running independently
//
// Why run 2 SEPARATE binary searches instead of using a single
// while loop to expand left/right from one found match? (your question)
// - If we found target once and then used a while loop to manually walk
//   left/right from that index to find the boundaries, in the WORST CASE
//   (e.g., array is all the same value, or target appears very frequently)
//   that walk could visit O(n) elements → degrades to O(n) time complexity
// - Running a SEPARATE binary search for first and for last guarantees
//   O(log n) for EACH search, so total stays O(log n) + O(log n) = O(log n)
// - This is the whole point of doing it via binary search "shrinking"
//   instead of a linear scan — it preserves the logarithmic guarantee
//
// Time: O(log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int last(int low, int guess) {
        low = guess + 1;
        return low;
    }
    int first(int high, int guess) {
        high = guess - 1;
        return high;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> resi = {-1, -1}; 
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (high >= low) {
            int guess = low + ((high - low) / 2);
            if (nums[guess] > target) {
                high = first(high, guess);
            } 
            else if (nums[guess] < target) {
                low = last(low, guess);
            } 
            else if (nums[guess] == target) {
                resi[0] = guess; 
                high = first(high, guess); 
            }
        }
        low = 0;
        high = n - 1;
        while (high >= low) {
            int guess = low + ((high - low) / 2);
            if (nums[guess] > target) {
                high = first(high, guess);
            } 
            else if (nums[guess] < target) {
                low = last(low, guess);
            } 
            else if (nums[guess] == target) {
                resi[1] = guess; 
                low = last(low, guess); 
            }
        }
        return resi;
    }
};