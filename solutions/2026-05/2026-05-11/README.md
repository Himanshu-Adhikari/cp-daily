# 📅 Daily CP Solutions — 2026-05-11

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Palindrome Pairs
**Platform:** GeeksforGeeks

Problem Insight:
The problem checks if any two strings from a given list can form a palindrome when concatenated in either order. This means one string must be the reverse of the other, or one part of a string is a palindrome and the other part's reverse exists as another string.

Approach:
The solution stores all strings in a hash map for efficient lookups. For each string, it iterates through all possible split points, creating a left and right part. If the left part is a palindrome, it checks if the reverse of the right part exists in the hash map. Similarly, if the right part is a palindrome, it checks for the reverse of the left part. Special handling is included for cases where a string is its own partner.

Time Complexity:
O(N * L^2)
N strings, each up to L length. For each string, it iterates L+1 times for splits. Inside the loop, substring creation, palindrome checks, string reversal, and hash map lookups (which involve string hashing) all take O(L) time on average.

Space Complexity:
O(N * L)
The unordered_map stores N strings, each potentially of length L, leading to O(N*L) space. Auxiliary strings for substrings and reverses also take O(L) space.

Optimization Notes:
It is not optimal. The current approach involves frequent creation of substrings and their reverses, and repeated hashing of these strings for map lookups. A more optimal solution typically uses a Trie data structure, which can achieve O(N*L) time complexity. By inserting all strings into a Trie, one can efficiently search for complementary parts (reversed prefixes/suffixes) without the overhead of string copying and re-hashing for each potential split.

### 💻 Implementation
```cpp
class Solution {
  public:
  
   bool isPal(string& s, int i, int j) {
       
       
       while (i < j) {
           if (s[i] != s[j]) return false;
           i++;
           j--;
       }
       
       return true;
   }
    bool palindromePair(vector<string>& arr) {
        // Code here
        
        unordered_map<string ,int> freq;
        
        for (string& s : arr) {
            freq[s]++;
        }
        
        for (string& str : arr) {
            
            int n = str.length();
            
            for (int i=0; i<=n; i++) {
                
                string left = str.substr(0, i);
                string right = str.substr(i);
                
                if (isPal(left, 0, left.length()-1)) {
                    
                    string rightRev = right;
                    reverse(begin(rightRev), end(rightRev));
                    
                    if (freq.count(rightRev) && (str != rightRev || freq[rightRev] > 1)) {
                        return true;
                    }
                }
                if (isPal(right, 0, right.length()-1)) {
                
                    string leftRev = left;
                    reverse(begin(leftRev), end(leftRev));
                    
                    if (freq.count(leftRev) && (str != leftRev || freq[leftRev] > 1)) {
                        return true;
                    }
                }
            }
            
        }
        
        return false;
    }
};
```

## 🔹 Leetcode Separate The Digits In An Array
**Platform:** LeetCode

Problem Insight:
The problem requires separating each integer in a list into its individual digits while maintaining the original order of digits within numbers and the order of numbers themselves. The output is a single list of all extracted digits.

Approach:
The solution iterates through each number, converts it into its string representation, and then iterates through the characters of this string. Each character is converted back to an integer digit and appended to the result list.

Time Complexity:
O(L)
The time complexity is proportional to the total number of digits (L) across all numbers in the input list, as each digit is processed once.

Space Complexity:
O(L)
The space complexity is dominated by the output list, which stores all L individual digits.

Optimization Notes:
The solution is generally optimal in terms of asymptotic time and space complexity. A minor optimization could involve a purely mathematical approach (repeated modulo 10 and integer division by 10) to extract digits, avoiding string conversions and character-to-integer operations. While this might slightly improve constant factors by avoiding string object creation overhead, it would require reversing digits or prepending to maintain order, often balancing out any performance gain and adding complexity.

CODE:
class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res=[]
        for nm in nums:
            s=str(nm)
            for j in s:
                res.append(ord(j)-ord('0'))
        return res

### 💻 Implementation
```py
class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        res=[]
        for nm in nums:
            s=str(nm)
            for j in s:
                res.append(ord(j)-ord('0'))
        return res
```
