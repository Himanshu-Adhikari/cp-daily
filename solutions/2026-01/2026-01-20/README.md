# 📅 Daily CP Solutions — 2026-01-20

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Implement Undo Redo
**Platform:** GeeksforGeeks

Problem Insight:
This problem simulates a text editor's core functionality, specifically managing text content with undo and redo operations. It requires maintaining a document's current state and its historical changes.

Approach:
The solution uses a dynamic array to store all characters ever appended, representing the full history. An integer index tracks the current visible end of the document. Undo and redo manipulate this index, while append adds characters and prunes any "future" history if executed after an undo.

Time Complexity:
append: O(N) in the worst case, where N is the total number of characters in doc, due to repeated pop_back calls when pruning history.
undo: O(1), as it's a simple decrement of an integer pointer.
redo: O(1), as it's a simple increment of an integer pointer.
read: O(C), where C is the length of the current document (curr + 1), for iterating and concatenating characters.

Space Complexity:
O(N), where N is the maximum number of characters ever stored in the 'doc' vector, representing the longest history.

Optimization Notes:
The solution is not optimal for the append operation. The while loop to prune history can result in O(N) complexity for a single append if many elements need to be removed. This can be optimized to O(1) amortized by using 'doc.resize(curr + 1)' to truncate the vector, making the append operation amortized O(1).

### 💻 Implementation
```cpp
class Solution {
  public:
   int curr = -1;
    vector<char>doc;
    
  public:
    void append(char x) {
        while(curr < (int)doc.size()-1){
            doc.pop_back();
        }
        
        doc.push_back(x);
        curr++;
        
    }

    void undo() {
        if(curr >= 0){
            curr--;
        }
    }

    void redo() {
        if(curr < (int)doc.size()-1){
            curr++;
        }
    }

    string read() {
        string res = "";
        for(int i=0;i<=curr;i++){
            res += doc[i];
        }
        return res;
    }
};
```

## 🔹 Leetcode 3314 Construct The Minimum Bitwise Array I
**Platform:** LeetCode
# 3314. Construct the Minimum Bitwise Array I

## 🧠 Problem Insight

This problem requires constructing an array `ans` such that for every index `i`:

ans[i] | (ans[i] + 1) = nums[i]


Among all possible valid values, we must choose the **minimum** `ans[i]`.  
If no such value exists, return `-1` for that index.

---

## 🔍 Key Observations

- The expression `x | (x + 1)` is **always odd**.
  - Therefore, if `nums[i]` is **even**, it is **impossible** to form such an `ans[i]`.
- If `nums[i]` is **odd**, a valid solution exists.

### Bitwise Insight
- Adding `1` to a number flips the **rightmost `0` bit** to `1` and clears all trailing `1`s.
- To minimize `ans[i]`, we reverse the smallest possible bit change.
- The expression  
((n + 1) & ~n)

isolates the **lowest zero bit** in `n`.
- Shifting it right by one gives the exact bit to clear in `n`.

---

## 🚀 Approach

1. Iterate through the array `nums`.
2. If the current number is even, append `-1` to the result.
3. If the number is odd:
 - Identify the lowest zero bit.
 - Clear that bit to construct the minimum valid `ans[i]`.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(N)`  
Each element is processed once with constant-time bit operations.
- **Space Complexity:** `O(N)`  
Extra space is used for the result array.

---

## 💡 Optimization Notes

- Uses pure bit manipulation — no brute force.
- Optimal solution since every element must be examined at least once.

---

## 💻 Code (C++)

```cpp
class Solution {
public:
  vector<int> minBitwiseArray(vector<int>& nums) {
      vector<int> res;
      for (auto& n : nums) {
          if (n & 1) {
              auto z = ((n + 1) & ~n) >> 1;
              res.push_back(n & ~z);
          } else {
              res.push_back(-1);
          }
      }
      return res;
  }
};
```
