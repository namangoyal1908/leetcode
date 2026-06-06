// Problem: Two Sum II - Input Array Is Sorted
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Difficulty: Easy
// Pattern: Two Pointers
//
// Why this approach?
// - Array is already sorted, so we can use two pointers from both ends
// - If sum > target → move right pointer left (decrease sum)
// - If sum < target → move left pointer right (increase sum)
// - Used raw pointers instead of indexes to practice pointer arithmetic
// - Tracking count/count2 to get 1-based index positions directly
// - No need to search for indexes since unique solution is guaranteed
//
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> result;

        // p1 starts from left, p2 starts from right
        int* p1 = &numbers[0];
        int* p2 = &numbers[n - 1];

        // count tracks left index (1-based), count2 tracks right index (1-based)
        int count = 0, count2 = n;

        while (*p1 + *p2 != target) {
            if (*p1 + *p2 > target) {
                p2--;       // sum too big → move right pointer left
                count2--;
            }
            else if (*p1 + *p2 < target) {
                p1++;       // sum too small → move left pointer right
                count++;
            }
        }

        // +1 because problem expects 1-based indexing
        result.push_back(count + 1);
        result.push_back(count2);

        return result;
    }
};