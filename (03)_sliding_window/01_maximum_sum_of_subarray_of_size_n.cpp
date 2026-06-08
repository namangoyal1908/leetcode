// Problem: Maximum Sum Subarray of Size K
// Link: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
// Difficulty: Easy
// Pattern: Sliding Window (Fixed Size)
//
// Brute Force: O(n*k)
// - Two loops → fix start, sum next k elements
// - Too slow for large k
//
// Fixed Sliding Window Concept:
// - Window size is always exactly k → never changes
// - Use two raw pointers p1 (start) and p2 (end of window)
// - Calculate first window sum manually
// - Then SLIDE: remove p1-1 (leftmost) → add p2 (new right element)
// - Track maximum sum seen
//
// Mistakes caught and fixed:
// - Can't compare pointer with integer (p2 < n is wrong)
// - Must compare pointer with address → p2 < &arr[n]
// - Edge case: when p2 reaches last element → break before
//   accessing arr[n] which is out of bounds
// - Break condition placed AFTER moving pointers but BEFORE
//   updating sum to avoid out of bounds access
//
// Key difference from Variable Window:
// - Fixed: window size k never changes, just slide it forward
// - Variable: window grows/shrinks based on condition (like previous problem)
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();

        int* p1 = &arr[0];        // start of window
        int* p2 = &arr[k - 1];    // end of window

        int sum = 0;
        int maxSum = INT_MIN;

        // Step 1: Calculate first window sum
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        // Step 2: Slide the window
        while (p2 < &arr[n]) {
            if (sum > maxSum) {
                maxSum = sum;
            }

            p1++;
            p2++;

            // Edge case: p2 reached end → stop before out of bounds
            if (p2 == &arr[n]) {
                break;
            }

            // Slide: remove leftmost element, add new right element
            sum -= *(p1 - 1);
            sum += *(p2);
        }

        return maxSum;
    }
};