# 📘 GFG DSA160 – Sorting Problems

This repository contains my solutions to **GeeksforGeeks DSA160 Sorting problems**.
Each problem includes a short explanation, intuition, approach, and the **exact code submitted on GFG**.

---

---

## 22. H-Index of a Researcher  

### Problem Explanation  
Given an array where each element represents the number of citations of a paper, compute the **H-index**.  
The H-index is the maximum value `H` such that the researcher has **at least `H` papers with citations ≥ `H`**.

### Intuition  
After sorting the citations, for any index `i`, the number of papers having citations ≥ `citations[i]` is `n - i`.  
We need the largest value where `citations[i] ≥ (n - i)`.

### Approach  
1. Sort the citations array.  
2. Use binary search on the sorted array.  
3. At index `mid`, calculate `nop = n - mid` (number of papers).  
4. If `citations[mid] ≥ nop`, it is a valid H-index candidate.  
5. Try to maximize it by searching the left half.  

### Code
```java
package Sorting;
import java.util.Arrays;

class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int ans = 0;
        int low = 0, high = citations.length - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int nop = citations.length - mid;
            
            if(nop <= citations[mid]) {
                ans = nop;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
}

```

