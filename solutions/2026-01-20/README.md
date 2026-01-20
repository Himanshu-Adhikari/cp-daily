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

Problem Insight:
This problem requires finding two numbers in an array that sum to a specific target value. Efficiently identifying the complement for each number is key.

Approach:
Iterate through the array, storing each number and its index in a hash map. For each current number, calculate the required complement to reach the target and check if this complement already exists in the map.

Time Complexity:
O(N)
Each number is processed once, with hash map operations (insertion, lookup) taking average O(1) time.

Space Complexity:
O(N)
In the worst case, the hash map stores up to N entries before the pair is found.

Optimization Notes:
This approach is optimal. It achieves linear time complexity, which is the fastest possible as every element must be examined at least once.

CODE:

### 💻 Implementation
```cpp

```
