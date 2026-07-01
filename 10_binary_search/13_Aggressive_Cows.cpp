// Problem: Aggressive Cows
// Link: https://www.geeksforgeeks.org/problems/aggressive-cows/1
// Difficulty: Hard
// Pattern: Binary Search on Answer
//
// Problem in simple terms:
// - Place k cows in stalls such that the MINIMUM distance between
//   any two cows is MAXIMIZED
//
// How is it similar to Koko Eating Bananas?
// - Both use "Binary Search on Answer" → search space is not an array
//   but the RANGE of possible answers
// - Koko: search space = [1, max(piles)], minimize speed
// - Cows: search space = [1, max_stall - min_stall], maximize min distance
// - Both have a helper() that checks if a given "guess" is feasible
//
// helper() function:
// - Given a minimum distance 'guess', checks if we can place k cows
//   such that every adjacent pair is at least 'guess' apart
// - Start by placing first cow at stalls[0] → pos = stalls[0], cow = 1
// - Walk through sorted stalls → if current stall is less than 'guess'
//   distance from last placed cow → skip (continue)
// - Otherwise → place a cow here → cow++, update pos
// - After loop: if we managed to place k or more cows → this 'guess'
//   distance is feasible → return true
//
// Why sort stalls first?
// - To greedily place cows as early as possible in sorted order
//   → guarantees we always check the closest available stall first
// - Without sorting, the "distance from last placed cow" check breaks
//
// Binary Search on Answer:
// - low = 1 (minimum possible distance)
// - high = stalls[n-1] - stalls[0] (maximum possible distance)
// - if helper returns true → this distance is feasible → record res,
//   try LARGER distance (low = guess+1) to MAXIMIZE
// - if helper returns false → distance too large → try smaller (high = guess-1)
//
// Time: O(n log n) for sort + O(n log(max_dist)) for binary search
// Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  //helper fuction 
  bool helper(vector<int> &stalls,int n,int k,int guess){
      int cow=1;
      int pos=stalls[0];
      
      for(int i=0;i<n;i++){
          int dist=stalls[i]-pos;
          if(dist<guess){
              continue;
              
          }
          cow++;
          pos=stalls[i];
          
      }if (cow>=k){
          return true;
      }return false;
      
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int res=-1;
        int low=1;
        int high = stalls[n-1]-stalls[0];
        
        while(low<=high){
            int guess=(low+high)/2;
            if(helper(stalls,n,k,guess)){
                res=guess;
                low=guess+1;
            }
            else{high=guess-1;}
            
        }return res;
        
    }
};