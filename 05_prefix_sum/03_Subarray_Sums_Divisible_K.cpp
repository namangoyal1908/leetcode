// Problem: Subarray Sums Divisible by K
// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Difficulty: Medium
// Pattern: Prefix Sum + HashMap
//
// How is it different from Subarray Sum Equals K?
// - Equals K: find prefixSum - k in map (exact difference)
// - Divisible by K: find matching REMAINDER in map, not actual sum
//
// Key Insight:
// - If two prefix sums have SAME remainder when divided by k
// - Their difference (subarray sum) is divisible by k
// - prefixSum[i] % k == prefixSum[j] % k → subarray [j+1, i] divisible by k
// - So instead of storing prefixSum → store prefixSum % k in map
//
// Why handle negative remainder?
// - In C++, negative % positive can give negative result (e.g. -1 % 3 = -1)
// - Mathematically remainder should always be 0 to k-1
// - rem += k fixes this → converts negative remainder to positive equivalent
//
// Why freq[0] = 1?
// - Handles subarrays from index 0 with remainder 0
// - Same logic as Equals K problem but for remainder instead of sum
//
// Why count += freq[rem] BEFORE freq[rem]++?
// - Check existing matches before adding current remainder
// - Avoids counting current index against itself
//
// Time: O(n) | Space: O(min(n, k))

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;  // empty prefix sum → remainder 0

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            int rem = prefixSum % k;
            if (rem < 0)
                rem += k;  // normalize negative remainder

            count += freq[rem];  // how many previous prefix sums share this remainder
            freq[rem]++;         // add current remainder to map
        }

        return count;
    }
};