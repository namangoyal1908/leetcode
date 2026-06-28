// Problem: Peak Index in Mountain Array
// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Difficulty: Easy
// Pattern: Binary Search
//
// Approach:
// - Array increases then decreases (mountain shape) → binary search
//   can find the peak by checking the SLOPE at guess, not the value itself
// - Compare arr[guess] with arr[guess+1]:
//   → if arr[guess] < arr[guess+1] → still on the ASCENDING side →
//     peak must be to the RIGHT → low = guess+1
//   → if arr[guess] > arr[guess+1] → already past the peak, on the
//     DESCENDING side → peak is at guess OR to the LEFT →
//     record res = guess, then high = guess-1 to keep searching left
//     for a possibly even higher peak index
//
// Why does this correctly converge to the true peak?
// - Every iteration either moves further into ascending territory (low++)
//   or records a valid "could be peak" candidate while shrinking right
//   boundary (high--) — search space keeps shrinking either way
// - Since there's exactly ONE peak in a mountain array, this binary
//   search naturally homes in on it without ever needing to compare
//   against a fixed target value
//
// Time: O(log n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxi=arr.size();
        int low=0;
        int high=maxi;
        int res=0;
        while(high>=low){
            int guess = low + ((high - low) / 2);
            if(arr[guess]<arr[guess+1]){
                low = guess + 1;
             }
            if( arr[guess]>arr[guess+1]){
               res=guess;
                high = guess - 1;
             }
        }return res;
    }
};