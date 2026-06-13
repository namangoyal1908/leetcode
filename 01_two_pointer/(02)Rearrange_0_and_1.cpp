// Problem: Rearrange 0s and 1s (Segregate 0s and 1s)
// Link: https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1
// Difficulty: Easy
// Pattern: Two Pointers
//
// Why this approach?
// - First approach: Sorting → O(n log n) but overkill for just 0s and 1s
// - Optimised: Count 0s first, then fill array → O(n) time, O(1) space
// - Since only 2 values exist, we don't need to sort at all
// - Just count how many 0s → fill that many 0s → rest are 1s
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void segregate0and1(vector<int>& arr) {
        int n = arr.size();
        int count0 = 0;

        // Step 1: Count total 0s
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0)
                count0++;
        }

        // Step 2: Fill first count0 positions with 0
        for (int i = 0; i < count0; i++) {
            arr[i] = 0;
        }

        // Step 3: Fill remaining positions with 1
        for (int i = count0; i < n; i++) {
            arr[i] = 1;
        }
    }
};