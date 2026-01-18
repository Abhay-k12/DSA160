/*
Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. 
If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 
Note:  A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

Examples:
Input: arr[] = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is [2, 4, 5, 0, 1, 7].

Input: arr[] = [3, 2, 1]
Output: [1, 2, 3]
Explanation: As arr[] is the last permutation, the next permutation is the lowest one.

Input: arr[] = [3, 4, 2, 5, 1]
Output: [3, 4, 5, 1, 2]
Explanation: The next permutation of the given array is [3, 4, 5, 1, 2].

Constraints:
1 ≤ arr.size() ≤ 10^5
0 ≤ arr[i] ≤ 10^5
*/

//Step1: RightMost Element smaller then the its next element
//Step2: Rightmost elememet just greater than the element found in step1
//Step3: Swap both the elements

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int pivot=-1;
        
        for(int i= arr.size()-2; i>=0; i--) {
            if(arr[i] < arr[i+1]) {
                pivot = i;
                break;
            }
        }
            
        
        if(pivot == -1) {
            reverse(arr.begin(), arr.end());
            return;
        }
        
        int swapIndex = -1;
        for(int i=arr.size()-1; i>=0; i--) {
            if(arr[i] > arr[pivot]) {
                swapIndex = i;
                break;
            }
        }
            
        swap(arr[pivot], arr[swapIndex]);
        reverse(arr.begin()+pivot+1, arr.end());     
    }
};