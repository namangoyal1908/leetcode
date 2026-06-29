// Problem: Search in Rotated Sorted Array
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Difficulty: Medium
// Pattern: Binary Search
//
// How is it different from "Find Minimum in Rotated Sorted Array"?
// - That problem only found the MINIMUM (the rotation pivot itself)
// - This problem reuses the EXACT SAME first binary search to find
//   'start' (index of the minimum / pivot), then ADDS two more
//   binary searches to actually locate the target
//
// Approach (3 binary searches total):
// - Search 1: same logic as Find Minimum → finds 'start', the index
//   where the array's second (smaller) sorted segment begins
// - This effectively splits the rotated array into TWO separate
//   sorted sub-arrays: [0, start-1] and [start, n-1]
// - Search 2: standard binary search for target within [0, start-1]
//   (the FIRST sorted segment)
// - Search 3: standard binary search for target within [start, n-1]
//   (the SECOND sorted segment)
// - If target is found in either segment → return its index immediately
// - If neither search finds it → return -1
//
// Why split into two searches instead of one clever rotated-aware search?
// - Once we know 'start' (from search 1), both remaining segments are
//   GENUINELY sorted (no rotation within them) → plain standard binary
//   search works perfectly on each, no special comparison logic needed
//
// Time: O(log n) → three binary searches, each O(log n), sum is still O(log n)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int start=0;
        //find start of 2nd part of array 2 
        while(high>=low){
            int guess=low+((high-low)/2);
            if(nums[guess]>nums[n-1]){
                low=guess+1;
            }
            else if(nums[guess]<=nums[n-1]){
                start=guess;
                high=guess-1;
            }
        }// bs in 1st part
            low=0;
            high=start-1;
        while(high>=low){
            int guess=low+((high-low)/2);
            if(nums[guess]<target){
                low=guess+1;
            }
            else if(nums[guess]>target){
                high=guess-1;
            }
            else if(nums[guess]==target){
                return guess ;
            }
        }
        // bs in second part
        low=start;
            high=n-1;
        while(high>=low){
            int guess=low+((high-low)/2);
            if(nums[guess]<target){
                low=guess+1;
            }
            else if(nums[guess]>target){
                high=guess-1;
            }
            else if(nums[guess]==target){
                return guess ;
            }}
        return -1;
    }
};