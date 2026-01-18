# 📘 GFG DSA160 – Array Problems

This repository contains my solutions to **GeeksforGeeks DSA160 Array problems**.
Each problem includes a short explanation, intuition, approach, and the **exact code submitted on GFG**.

---

## 1. Second Largest Element in an Array

### Problem Explanation

Given an array of positive integers, return the **second largest distinct element**.
If it does not exist, return `-1`.

### Intuition

Track the largest and second largest elements while iterating once through the array.

### Approach

* Initialize two variables: `largest` and `secondLargest`
* Update them during a single traversal
* Ignore duplicate largest values
* If `secondLargest` is never updated, return `-1`

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int largest=INT_MIN, secondLargest=INT_MIN;
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            }
            else if(arr[i] > secondLargest && arr[i]!=largest) {
                secondLargest = arr[i];
            }
        }
        
        if(secondLargest == INT_MIN)
            return -1;
            
        return secondLargest;
    }
};
```

---

## 2. Move All Zeros to End

### Problem Explanation

Move all zeros to the end of the array while maintaining the relative order of non-zero elements.
The operation must be done **in-place**.

### Intuition

Use a pointer to keep track of where the next non-zero element should be placed.

### Approach

* Maintain `zeroPos` index
* Traverse the array
* Swap non-zero elements with `zeroPos`
* Increment `zeroPos`

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int zeroPos=0;
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]!=0) {
                swap(arr[i],arr[zeroPos]);
                zeroPos++;
            }
        }
    }
};
```

---

## 3. Reverse an Array

### Problem Explanation

Reverse the given array **in-place**.

### Intuition

Swap elements from both ends moving towards the center.

### Approach

* Use two pointers (`start`, `end`)
* Swap and move inward until they meet

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;    

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n = arr.size();
        
        for(int i=0, j=n-1; i<j; i++,j--)
            swap(arr[i], arr[j]);
    }
};
```

---

## 4. Rotate Array Left by D Positions

### Problem Explanation

Rotate the array to the left by `d` steps considering the array as circular.

### Intuition

Rotation can be done efficiently using the **reverse technique**.

### Approach

* Reduce `d` using modulo
* Reverse first `d` elements
* Reverse remaining elements
* Reverse the entire array

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n; 
        
        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};
```

---

## 5. Next Permutation

### Problem Explanation

Generate the **next lexicographically greater permutation** of the array.
If it does not exist, return the smallest permutation.

### Intuition

Find the first decreasing element from the right and rearrange the suffix.

### Approach

1. Find the pivot
2. Find next greater element
3. Swap them
4. Reverse the suffix

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
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
```

---

## 6. Majority Element II (More than ⌊n/3⌋ Times)

### Problem Explanation

Find all elements that appear more than ⌊n/3⌋ times.

### Intuition

At most **two elements** can satisfy the condition.

### Approach

* Use Extended Boyer–Moore Voting Algorithm
* First pass selects candidates
* Second pass verifies frequency

### Code

```cpp
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
```

---

## 7. Stock Buy and Sell (Multiple Transactions)

### Problem Explanation

Maximize profit when multiple buy-sell transactions are allowed.

### Intuition

Profit is earned whenever prices increase from one day to the next.

### Approach

* Add all positive differences between consecutive days

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int totalProfit = 0;
        
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > prices[i-1])
                totalProfit += prices[i]-prices[i-1];
        }
        return totalProfit;
    }
};
```

---

## 8. Stock Buy and Sell (Single Transaction)

### Problem Explanation

Find the maximum profit with **only one buy and one sell** allowed.

### Intuition

Track the minimum price so far and maximize profit.

### Approach

* Update minimum price
* Update maximum profit at each step

### Code

```java
package Array;

class Solution {
    public int maximumProfit(int prices[]) {
        int minValue = Integer.MAX_VALUE;
        int maxProfit = Integer.MIN_VALUE;
        
        for(int i=0; i<prices.length; i++) {
            minValue = Math.min(minValue, prices[i]);
            maxProfit = Math.max(maxProfit, prices[i]-minValue);
        }
        
        return maxProfit;
    }
}
```

---

## 10. Maximum Subarray Sum (Kadane’s Algorithm)

### Problem Explanation
Given an integer array, find the **maximum sum of any contiguous subarray** containing at least one element.

### Intuition
At each element, decide:
- Start a new subarray from this element, or
- Extend the previous subarray by adding this element  

Choose whichever gives a larger sum.

### Approach
- Maintain `currSum` to store the maximum subarray sum ending at the current index
- Maintain `maxSum` to store the overall maximum
- For each element:
  - `currSum = max(arr[i], arr[i] + currSum)`
  - Update `maxSum`
- Return `maxSum`

### Code
```java
package Array;

class Solution {
    int maxSubarraySum(int[] arr) {
        int currSum = 0;
        int maxSum = Integer.MIN_VALUE;
        
        for(int i = 0; i < arr.length; i++) {
            currSum = Math.max(arr[i], arr[i] + currSum); 
            maxSum = Math.max(maxSum, currSum);
        }
        
        return maxSum;
    }
}

```

---

## 11. Maximum Product Subarray

### Problem Explanation
Given an array containing positive, negative, and zero values, find the **maximum product of any contiguous subarray**.

### Intuition
Negative numbers can flip the sign of the product, and zeros break subarrays.  
To handle this, we consider products from **both directions**.

### Approach
- Traverse from **left to right**, keeping a running product
- Reset the product when it becomes zero
- Traverse again from **right to left** to handle cases with odd negative counts
- Track the maximum product seen in both traversals

### Code
```java
package Array;

class Solution {
    int maxProduct(int[] arr) {
        int maxProduct = Integer.MIN_VALUE;
        int currProduct = 1;
        
        for(int i = 0; i < arr.length; i++) {
            currProduct *= arr[i];
            maxProduct = Math.max(currProduct, maxProduct);
            if(currProduct == 0) currProduct = 1;
        }
        
        currProduct = 1;
        for(int i = arr.length - 1; i >= 0; i--) {
            currProduct *= arr[i];
            maxProduct = Math.max(currProduct, maxProduct);
            if(currProduct == 0) currProduct = 1;
        }
        
        return maxProduct;
    }
}

```

---

## 12. Maximum Circular Subarray Sum

### Problem Explanation  
Given a **circular array**, find the maximum sum of a **non-empty contiguous subarray**, where the subarray is allowed to wrap from the end of the array to the beginning.

### Intuition  
The answer is the maximum of two cases:  
1. **Non-circular maximum subarray sum** (normal Kadane’s algorithm).  
2. **Circular maximum subarray sum** = `totalSum - minimum subarray sum`.

If the entire array is the minimum subarray, then wrapping gives no benefit, so we return the normal maximum subarray sum.

### Approach  
- Use Kadane’s algorithm to find:
  - `maxSum` → maximum subarray sum  
  - `minSum` → minimum subarray sum  
- Compute `totalSum` of the array  
- If `totalSum == minSum`, return `maxSum` (all elements are negative case)  
- Otherwise, return `max(totalSum - minSum, maxSum)`

### Code
```java
class Solution {
    public int maxCircularSum(int arr[]) {
        int minSum = Integer.MAX_VALUE, 
            maxSum = Integer.MIN_VALUE, 
            totalSum = 0;
        int currMaxSum = 0, currMinSum = 0;
        
        for(int i = 0; i < arr.length; i++) {
            currMaxSum = Math.max(arr[i], arr[i] + currMaxSum);
            maxSum = Math.max(maxSum, currMaxSum);
            
            currMinSum = Math.min(arr[i], arr[i] + currMinSum);
            minSum = Math.min(minSum, currMinSum);
            
            totalSum += arr[i];
        }
        
        if(totalSum == minSum) return maxSum;
        return Math.max(totalSum - minSum, maxSum);
    }
}

```

---

## 13. Smallest Missing Positive Number

### Problem Explanation  
Given an integer array that may contain negative numbers and zero, find the **smallest missing positive integer**.  
Positive numbers start from **1**.

### Intuition  
The answer must lie in the range **[1, n+1]**, where `n` is the array size.  
We can use the array itself as a frequency map by marking indices corresponding to values.

### Approach  
1. Replace all negative numbers and numbers greater than `n` with `0`.  
2. For each value `x` in the array (where `1 ≤ x ≤ n`), mark its presence by adding `(n+1)` to index `x-1`.  
3. The first index whose value is still less than `n+1` corresponds to the missing number.  
4. If all positions are marked, return `n+1`.

### Code
```java
class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] < 0 || arr[i] > n) 
                arr[i] = 0;
        }
        
        for(int i = 0; i < n; i++) {
            int value = arr[i] % (n + 1);
            if(value != 0) {
                arr[value - 1] += n + 1;
            }
        }
        
        for(int i = 0; i < n; i++) 
            if(arr[i] / (n + 1) == 0)
                return i + 1;
        
        return n + 1;
    }
}
```