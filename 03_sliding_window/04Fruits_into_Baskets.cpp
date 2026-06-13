// Problem: Fruits into Baskets
// Link: https://leetcode.com/problems/fruit-into-baskets/
// Difficulty: Medium
// Pattern: Sliding Window (Variable Size) + HashMap
//
// Problem in simple terms:
// - You have 2 baskets → each basket holds only 1 TYPE of fruit
// - Pick maximum fruits from a subarray with at most 2 distinct types
//
// How is it different from previous problem (K Distinct)?
// - Previous: exactly K distinct chars → res updated only when f.size()==k
// - This: at MOST 2 distinct fruits → res updated ALWAYS (any valid window)
// - K is hardcoded as 2 here
// - No -1 case → always a valid answer exists (single fruit is valid)
// - That's why res = INT_MIN not -1 (we always update res)
//
// Why res updates outside the if condition here?
// - Previous problem: f.size() must be EXACTLY k → conditional update
// - This problem: any window with <= 2 types is valid → always update
// - After while loop shrinks window to valid state → current window is valid
// - So we record length every iteration
//
// HashMap used same way:
// unordered_map<int, int> f  → {fruit_type : count_in_window}
// f.size() > 2               → more than 2 fruit types → shrink
// f.erase()                  → remove fruit type with 0 count
//
// Time: O(n) | Space: O(1) → map holds at most 3 entries at any time

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int high = 0;
        int low = 0;
        int res = INT_MIN;
        int n = fruits.size();

        unordered_map<int, int> f;  // {fruit_type → count in window}

        for (high = 0; high < n; high++) {
            f[fruits[high]]++;  // EXPAND → pick new fruit

            // SHRINK → more than 2 fruit types in basket
            while (f.size() > 2) {
                f[fruits[low]]--;
                if (f[fruits[low]] == 0) {
                    f.erase(fruits[low]);  // remove type with 0 count
                }
                low++;
            }

            // Any valid window → update result (at most 2 types)
            int len = high - low + 1;
            res = max(len, res);
        }

        return res;
    }
};