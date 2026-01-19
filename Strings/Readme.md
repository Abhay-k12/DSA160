# 📘 GFG DSA160 – Strings Problems

This repository contains my solutions to **GeeksforGeeks DSA160 Strings problems**.
Each problem includes a short explanation, intuition, approach, and the **exact code submitted on GFG**.

---

---

## 16. Check if Two Strings are Anagrams  

### Problem Explanation  
Given two non-empty lowercase strings `s1` and `s2`, determine whether they are **anagrams** — i.e., whether both contain exactly the same characters with the same frequencies, just in a different order.

### Intuition  
If two strings are anagrams, the count of every character (`a` to `z`) must be identical in both.  
We can verify this efficiently using a frequency array of size 26.

### Approach  
1. If lengths are different → return `false`.  
2. Create a frequency array of size 26.  
3. Increment counts for characters in `s1`.  
4. Decrement counts for characters in `s2`.  
5. If any frequency is non-zero → not an anagram.  

### Code
```java
package Strings;

import java.util.Arrays;

class Solution {
    public static boolean areAnagrams(String s1, String s2) {
        int l1 = s1.length(), l2 = s2.length();
        
        if(l1 != l2) return false;
        
        int freqMap[] = new int[26];
        Arrays.fill(freqMap, 0);
        
        for(int i = 0; i < l1; i++)
            freqMap[s1.charAt(i) - 'a'] += 1;
        
        for(int i = 0; i < l2; i++)
            freqMap[s2.charAt(i) - 'a'] -= 1;
            
        for(int i = 0; i < 26; i++)
            if(freqMap[i] != 0)
                return false;
        
        return true;
    }
}
```