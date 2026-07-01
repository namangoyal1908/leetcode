// Problem: Koko Eating Bananas
// Link: https://leetcode.com/problems/koko-eating-bananas/
// Difficulty: Medium
// Pattern: Binary Search (on Answer)
//
// How is this different from standard Binary Search on a sorted array?
// - There's no actual sorted array being searched here at all
// - Instead we binary search over the ANSWER itself (possible eating speeds)
// - This is "Binary Search on Answer" → search space is [1, max(piles)]
//   instead of array indices
//
// fun() helper:
// - Given a candidate eating speed, calculates total hours needed to
//   finish ALL piles at that speed
// - piles[i]/speed → full hours needed for that pile
// - if there's a remainder (piles[i]%speed != 0) → needs ONE extra hour
//   to finish the leftover bananas in that pile (can't eat partial pile
//   in the same hour as a different pile)
//
// Approach:
// - low = 1 (slowest possible valid speed)
// - high = max value in piles (no need to eat faster than the biggest
//   pile, since you can only eat from one pile per hour anyway)
// - At each guess speed: calculate hours needed via fun()
// - If hours needed > h (allowed hours) → speed is TOO SLOW →
//   need to go faster → low = guess+1
// - Otherwise (hours <= h) → this speed WORKS → record res=gues
//   but try to go SLOWER (high = guess-1) to find the minimum valid speed
//
// Why does minimizing speed work via binary search here?
// - As speed increases, hours needed strictly DECREASES (monotonic
//   relationship) → this monotonicity is exactly what makes binary
//   search on the answer space valid
//
// Time: O(n log m) where n = piles.size(), m = max(piles)
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// making function to check whether coco can eat at my guess speed 
    long long fun(vector<int> &piles ,int n,long long speed ){
        long long  hw =0;
        for (int i =0 ;i<n;i++)
    {
        hw=hw+piles[i]/speed;
        if(piles[i]%speed){
            hw++;
        }
    }return hw;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;  
        int high = piles[0];
        for (int i = 1; i < piles.size(); i++) {
            if (piles[i] > high) {
        high = piles[i];
    }
}
        int n= piles.size();
        int res=-1;
        while(low<=high){
            long long guess = low + ((high - low)) / 2;
            long long  hour=fun(piles,n,guess);
            if(hour>h){
                low=guess+1;
            }
            else{res=guess;
            high=guess-1;}
        }return res;
    }
};