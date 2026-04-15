# 📅 Daily CP Solutions — 2026-04-15

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Urlify-A-Given-String
**Platform:** GeeksforGeeks

Problem Insight:
The task is to replace all spaces in a given string with '%20'. This problem often implies in-place modification of a character array in other programming languages.

Approach:
The solution leverages Python's built-in string.replace() method. This method creates a new string by replacing all occurrences of a specified substring (' ') with another substring ('%20').

Time Complexity:
O(N) where N is the length of the input string. Python's string.replace effectively iterates through the string once to construct the new result.

Space Complexity:
O(N) where N is the length of the input string. A new string is created to store the result, which can be up to three times the length of the original string.

Optimization Notes:
This solution is optimal for Python's immutable strings and is highly Pythonic. However, if the problem constraints require in-place modification of a character array (common in this type of problem for languages like C/Java), then this solution is not space-optimal as it creates a new string. An in-place solution would typically use a two-pointer approach.

### 💻 Implementation
```py
class Solution:
    def URLify(self, s): 
        return s.replace(' ','%20')
        

```

## 🔹 Leetcode Shortest-Distance-To-Target-String-In-A-Circular-Array
**Platform:** LeetCode

Problem Insight:
The problem asks for the minimum circular distance from a given start index to any occurrence of a target string in a circular array of words.

Approach:
The solution iterates linearly through the entire words array. For each word matching the target, it calculates two candidate distances: the direct absolute difference of indices and a specific expression (n - current index + start index) intended to cover a circular path. It keeps track of the minimum distance found.

Time Complexity:
O(N) - The solution performs a single pass over all N words in the array.

Space Complexity:
O(1) - It uses a constant amount of extra space for a few integer variables.

Optimization Notes:
The solution is not optimal in its correctness. The calculation of the circular distance `n - i + startIndex` is flawed and does not correctly represent the wrap-around distance in all cases. The correct circular distance between two indices i and startIndex should be min(abs(i - startIndex), n - abs(i - startIndex)). While a linear scan (O(N)) is generally required to find all occurrences, the current logic might return an incorrect minimum distance for some inputs due to this calculation error.

### 💻 Implementation
```cpp
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int res=INT_MAX,n=words.size(),i=0;
        while(i<n){
            if(words[i]==target){
                res=min(res,abs(i-startIndex));
                res=min(res,n-i+startIndex);
            }
            i++;
        }
       
        return res==INT_MAX?-1:res;
    }
};
```
