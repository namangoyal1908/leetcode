// Problem: Find Duplicate Number
// Link: https://leetcode.com/problems/find-the-duplicate-number/
// Difficulty: Medium
// Pattern: Fast & Slow Pointers
//
// Approach 1 - Brute Force: O(n²)
// - Two nested loops → check every pair → too slow
//
// Approach 2 - Sorting: O(n log n)
// - Sort array → duplicate will be adjacent → scan once
// - Modifies original array
//
// Approach 3 - HashMap/Frequency Array: O(n) time O(n) space
// - freq[i] tracks count of each number
// - First number with freq > 1 → duplicate
// - Extra space needed
//
// Approach 4 - Fast & Slow Pointers: O(n) time O(1) space
// - Treat array as LinkedList → index = node, nums[index] = next node
// - Duplicate number = two indices pointing to same next node = cycle!
// - Same as "Start of LinkedList Cycle" → Floyd's algorithm
// - l1 = nc - l2 math applies here too
// - Best approach → no extra space, no modification
//
// Time: O(n) | Space: O(1) for fast slow approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // =====================
    // Approach 3: Frequency Array (your solution)
    // =====================
    int findDuplicateHash(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] > 1)
                return nums[i];
        }
        return -1;
    }

    // =====================
    // Approach 4: Fast & Slow Pointers (optimal)
    // =====================
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: find meeting point
        do {
            slow = nums[slow];            // 1 step
            fast = nums[nums[fast]];      // 2 steps
        } while (slow != fast);

        // Phase 2: find duplicate (cycle start)
        // same math: l1 = c - l2
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;  // duplicate number = cycle start
    }
};