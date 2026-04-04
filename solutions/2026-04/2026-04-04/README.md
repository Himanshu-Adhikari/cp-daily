# 📅 Daily CP Solutions — 2026-04-04

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Gray Code
**Platform:** GeeksforGeeks

Problem Insight:
This problem involves generating Gray codes, which are sequences of binary numbers where successive codes differ by only one bit, using a recursive construction method.

Approach:
The solution uses dynamic programming to build Gray code sequences iteratively. It constructs the N-bit Gray codes by prefixing the (N-1)-bit Gray codes with '0' and then prefixing the reverse of the (N-1)-bit Gray codes with '1'.

Time Complexity:
O(N * 2^N)
Justification: Each step 'i' generates 2^i strings of length 'i'. String concatenations and copies contribute O(i) work per string, leading to O(i * 2^i) per step. Summing this over N steps results in O(N * 2^N).

Space Complexity:
O(N * 2^N)
Justification: The map stores all intermediate Gray code lists up to N bits. The largest list is O(2^N) strings of length O(N), requiring O(N * 2^N) space for its characters. The sum of characters across all intermediate lists is also O(N * 2^N).

Optimization Notes:
The solution is optimal in terms of total characters for the final output, as it needs O(N * 2^N) space. However, the 'res' vector is redundant and can be removed. Replacing std::map with std::vector to store intermediate results, or explicitly clearing intermediate vectors once they are no longer needed, could offer minor performance/memory improvements for temporary storage but the final output space dominates.

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<string> graycode(int n) {
        vector<string>res;
        map<int,vector<string>>m;
        for(int i=0;i<n;i++){
            if(i==0){
                m[0].push_back("0");
                m[0].push_back("1");
                res.push_back("0");
                res.push_back("1");
            }
            else{
                for(auto&c:m[i-1]){
                    res.push_back("0"+c);
                    m[i].push_back("0"+c);
                }
                for(int j=m[i-1].size()-1;j>=0;j--){
                    m[i].push_back("1"+m[i-1][j]);
                    res.push_back("1"+m[i-1][j]);}
            }
        }
        return m[n-1];
    }
};
```

## 🔹 Leetcode Decode The Slanted Cipher Text
**Platform:** LeetCode

Problem Insight:
The problem involves decoding a ciphertext by conceptually arranging it into a grid of 'rows' and 'cols' then reading characters diagonally from top-left to bottom-right, starting a new diagonal from each column of the first row. Trailing spaces in the final decoded string must be removed.

Approach:
The solution first calculates the number of columns. It then iterates through each possible starting column index (c from 0 to cols-1). For each starting column, it traverses diagonally by simultaneously incrementing the row and column indices, appending each character to a result list. Finally, it joins the collected characters into a string and removes any trailing spaces.

Time Complexity:
O(N)
Each character that forms part of a collected diagonal is visited and appended exactly once. Joining the list and stripping spaces are also linear operations with respect to the length of the result string, which is at most N.

Space Complexity:
O(N)
The result list 'res' stores the decoded characters. In the worst case, it can store up to N characters, where N is the length of the input string 's'.

Optimization Notes:
The solution is optimal. It must examine characters along the relevant diagonals, making O(N) time complexity unavoidable. Storing the decoded characters in a list and then joining is the most efficient way to build strings in Python, and the space for the output string is also O(N) in the worst case.

### 💻 Implementation
```py

class Solution:
    def decodeCiphertext(self, s: str, rows: int) -> str:
        if(rows==1 or s==""):return s
        cols=len(s)//rows
        res = []
        for c in range(cols):
            r, j = 0, c
            while r < rows and j < cols:
                res.append(s[r * cols + j])
                r += 1
                j += 1

        return "".join(res).rstrip()
```
