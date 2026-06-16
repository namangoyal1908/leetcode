// Problem: Subarray Sum Equals K
// Link: https://leetcode.com/problems/subarray-sum-equals-k/
// Difficulty: Easy
// Pattern: Prefix Sum + HashMap
//
// Brute Force: O(n²)
// - Two loops → fix start, expand end, track sum == k
//
// Why Prefix Sum + HashMap?
// - prefixSum[i] = sum of elements from index 0 to i
// - Sum of subarray [j+1, i] = prefixSum[i] - prefixSum[j]
// - We want prefixSum[i] - prefixSum[j] == k
// - → prefixSum[j] == prefixSum[i] - k
// - So at every index ask: how many previous prefix sums equal (currentSum - k)?
// - HashMap stores {prefixSum → frequency} for O(1) lookup
//
// Why freq[0] = 1?
// - Handles case where subarray starts from index 0
// - If prefixSum == k → prefixSum - k == 0 → needs freq[0] to exist
// - Without this → subarrays starting at index 0 are missed
//
// Why count += freq[prefixSum - k] before updating freq?
// - Must check BEFORE adding current prefix sum to map
// - Otherwise current index could match itself → wrong count
//
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;  // empty prefix sum → handles subarrays from index 0

        int prefixSum = 0;
        int count = 0;

        for (int num : nums) {
            prefixSum += num;

            // how many previous prefix sums make current subarray sum == k
            if (freq.count(prefixSum - k)) {
                count += freq[prefixSum - k];
            }

            freq[prefixSum]++;  // add current prefix sum to map
        }

        return count;
    }
};