/*
Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100

Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110

  Constraints:
1 ≤s1.size(), s2.size()≤ 10^6
*/
package Strings;

class Solution {
    public String addBinary(String s1, String s2) {
        // code here
        StringBuilder ans = new StringBuilder("");
        int index1 = s1.length()-1;
        int index2 = s2.length()-1;
        
        short carry = 0;
        while(index1>=0 || index2>=0) {
            int sum = carry;
            if(index1 >=0) sum += (s1.charAt(index1)-'0');
            if(index2 >=0) sum += (s2.charAt(index2)-'0');
            
            ans.append(sum%2);
            carry = (short)(sum/2);
            
            index1--; index2--;
        }
        
        if(carry==1)
            ans.append('1');
        
        ans.reverse();
        int index = 0;
        
        while(index<ans.length() && ans.charAt(index)=='0') index++;
        
        return (index == ans.length())? "0":ans.substring(index).toString();
    }
}