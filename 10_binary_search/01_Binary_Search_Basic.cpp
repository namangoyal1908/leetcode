// Problem: Binary Search (Basic)
// Link: https://leetcode.com/problems/binary-search/
// Difficulty: Easy
// Pattern: Binary Search
//
// Approach:
// - Standard binary search on a sorted array
// - low/high pointers bound the current search space
// - guess = midpoint between low and high → check if it's the target
// - if nums[guess] < target → target is in the RIGHT half → low = guess+1
// - if nums[guess] > target → target is in the LEFT half → high = guess-1
// - Loop continues while low <= high, narrowing search space each time
// - If never found → return -1
//
// Why guess = low + (high-low)/2 instead of (low+high)/2?
// - (low+high) can OVERFLOW if both low and high are large (close to INT_MAX)
// - low + (high-low)/2 avoids this because (high-low) is always a SMALLER
//   value than either low or high individually, so the addition stays
//   within safe integer bounds
//
// Time: O(log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high =n-1;
        while(low<=high){
            int guess=(low+((high-low)/2));
            if(nums[guess]==target){
                return guess;
            }
            else if(nums[guess]<target){
                low=guess+1;
            }
            else if(nums[guess]>target){
                high=guess-1;
            }
        }
        return -1;
    }
};