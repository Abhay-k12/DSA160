/*
You are given an integer array arr[]. You need to find the 
maximum sum of a subarray (containing at least one element) in the array arr[].
Note : A subarray is a continuous part of an array.

Examples:
Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.

Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray [-2] has the largest sum -2.

Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.

Constraints:
1 ≤ arr.size() ≤ 10^5
-10^4 ≤ arr[i] ≤ 10^4
*/

//Step1: Caluculate the sum by selecting each element on asking them that "Either you are maximum os after adding you the sum is Maximum?"
//Step2: Strore the maximum of all the sum after asking question from each element.
package Array;

class Solution {
    int maxSubarraySum(int[] arr) {
        // Code here
        int currSum = 0;
        int maxSum = Integer.MIN_VALUE;
        
        for(int i=0; i<arr.length; i++) {
            currSum = Math.max(arr[i], arr[i]+currSum); 
            maxSum = Math.max(maxSum, currSum);
        }
        
        return maxSum;
            
    }
}