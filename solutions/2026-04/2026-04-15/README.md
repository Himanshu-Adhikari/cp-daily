# 📅 Daily CP Solutions — 2026-04-15

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Urlify-A-Given-String
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires replacing all single space characters in an input string with the "%20" sequence. This is a common string manipulation task.

Approach:
The solution uses Python's native string.replace() method. This method efficiently scans the string for target characters and constructs a new string with the specified substitutions.

Time Complexity:
O(N) where N is the length of the input string. Python's string.replace() method internally iterates through the string once to perform replacements.

Space Complexity:
O(N) where N is the length of the input string. A new string is created to hold the result, which can be up to three times the length of the original string.

Optimization Notes:
It is optimal for Python. Given that Python strings are immutable, creating a new string is necessary. The built-in replace method is highly optimized, making this the most efficient and Pythonic approach.

### 💻 Implementation
```py
class Solution:
    def URLify(self, s): 
        return s.replace(' ','%20')
        

```

## 🔹 Leetcode Shortest-Distance-To-Target-String-In-A-Circular-Array
**Platform:** LeetCode

Problem Insight:
The problem asks for the minimum circular distance from a given starting index to any occurrence of a target string within an array.

Approach:
The solution iterates through all words in the array. For each word that matches the target, it calculates a direct linear distance and attempts to calculate a wrap-around distance. It then updates the overall minimum distance found.

Time Complexity: O(N * L)
Justification: The code iterates through N words. Each string comparison takes O(L) time, where L is the maximum length of a word.

Space Complexity: O(1)
Justification: The solution uses a constant amount of extra space for variables, independent of the input size.

Optimization Notes:
The overall approach of scanning through the array is optimal in terms of worst-case time complexity. However, the calculation of the circular distance is incorrect in the line 'res=min(res,n-i+startIndex);'. The proper way to calculate the minimum circular distance between two indices 'a' and 'b' in an array of size 'N' is 'min(abs(a-b), N - abs(a-b))'. Correcting this calculation is necessary for the solution to be logically sound.

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
