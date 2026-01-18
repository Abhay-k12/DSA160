/*
Given an array arr[] consisting of n integers, the task is to find all the array elements which occurs more than floor(n/3) times.
Note: The returned array of majority elements should be sorted.

Examples:
Input: arr[] = [2, 2, 3, 1, 3, 2, 1, 1]
Output: [1, 2]
Explanation: The frequency of 1 and 2 is 3, which is more than floor n/3 (8/3 = 2).

Input:  arr[] = [-5, 3, -5]
Output: [-5]
Explanation: The frequency of -5 is 2, which is more than floor n/3 (3/3 = 1).

Input:  arr[] = [3, 2, 2, 4, 1, 4]
Output: []
Explanation: There is no majority element.

Constraint:
1 ≤ arr.size() ≤ 10^6
-105 ≤ arr[i] ≤ 10^5
*/

#include <bits/stdc++.h>
using namespace std;    

class Solution {
  public:
    vector<int> majorityElementII(vector<int>& arr) {
        int n = arr.size();
        int count1=0, count2=0;
        int candidate1=-1, candidate2=-1;
        
        for(int i=0; i<n; i++) {
            
            if(count1 == 0 && arr[i] != candidate2) {
                candidate1 = arr[i];
                count1 = 1;
            }
            else if(count2 == 0 && arr[i] != candidate1) {
                candidate2 = arr[i];
                count2 = 1;
            }
            else if(arr[i] == candidate1)
                count1++;
            else if(arr[i] == candidate2)
                count2++;
            else {
                count1--;
                count2--;
            }
        }
        
        count1=0; count2=0;
        for(int i=0; i<n; i++) {
            if(arr[i] == candidate1)
                count1++;
            else if(arr[i] == candidate2)
                count2++;
        }
        
        vector<int> result;
        if(count1 > n/3)
            result.push_back(candidate1);
        if(count2 > n/3)
            result.push_back(candidate2);
        
        sort(result.begin(), result.end());
        return result;
    }
};