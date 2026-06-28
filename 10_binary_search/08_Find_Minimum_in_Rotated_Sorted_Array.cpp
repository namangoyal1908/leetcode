// Problem: Find Minimum in Rotated Sorted Array
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Difficulty: Medium
// Pattern: Binary Search
//
// Approach:
// - Array is sorted but ROTATED at some unknown pivot → can't use plain
//   binary search comparing against a target, instead compare guess
//   against the LAST element (nums[n-1]) to figure out which "half"
//   of the rotation we're in
// - If nums[guess] > nums[n-1] → guess is in the LEFT (larger) rotated
//   segment → minimum must be somewhere to the RIGHT → low = guess+1
// - If nums[guess] <= nums[n-1] → guess is already in the smaller/sorted
//   right segment → guess itself COULD be the minimum → record res=guess,
//   but keep searching LEFT (high = guess-1) for a possibly smaller value
//
// Why compare against nums[n-1] specifically (not nums[0] or nums[low])?
// - The LAST element is a stable reference point regardless of where
//   the rotation pivot is — it always tells us whether guess lies in
//   the "still high" segment (before pivot) or "already low" segment
//   (after pivot, where the minimum actually lives)
//
// Why edge case high==low → return nums[0]?
// - If array has only ONE element, there's nothing to compare or rotate
//   → that single element is trivially the minimum
//
// Time: O(log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int res=0;
        if(high==low){return nums[0];}
        while(high>=low){
            int guess = low + ((high - low) / 2);
            if(nums[guess]>nums[n-1]){
                low=guess+1;
             }
            else if(nums[guess]<=nums[n-1]){
                res=guess;
                high=guess-1;
                }
                }return nums[res];
    }
};