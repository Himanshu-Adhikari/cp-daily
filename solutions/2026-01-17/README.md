# 📅 Daily CP Solutions — 2026-01-17

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Expression Contrain Redundant Brackets Or Not
**Platform:** GeeksforGeeks

Problem Insight:
The problem aims to identify if an arithmetic expression contains redundant parentheses, specifically if a pair of parentheses encloses an expression that does not contain any operator or is empty.

Approach:
The solution uses a stack to keep track of opening parentheses and operators. When a closing parenthesis is encountered, it checks if the top of the stack is an opening parenthesis, indicating redundancy (e.g., "()", or "(expression)" where "expression" itself contains no operator at the outermost level). If not, it pops operators until the matching opening parenthesis is found, then pops that parenthesis.

Time Complexity:
O(N)
The solution iterates through the input string once, and each character results in constant-time stack operations (push, pop, peek).

Space Complexity:
O(N)
In the worst case (e.g., an expression with many nested opening parentheses and operators before any closing ones), the stack can store up to N characters.

Optimization Notes:
The solution is optimal. We must traverse the entire string at least once to check all parentheses, making O(N) time unavoidable. The use of a stack for parenthesis matching and operator tracking typically requires O(N) space in the worst case for nested structures, which is also generally optimal for this type of problem.

### 💻 Implementation
```py
class Solution():
    def checkRedundancy(self, s):
        st,aux=[],"+-/*"
        i,n=0,len(s)
        while(i<n):
            if(s[i]=='(' or s[i] in aux):
                st.append(s[i])
            elif(s[i]==')'):
                if(st[-1]=='('):
                    return True
                while(st and st[-1]!='('):
                    st.pop()
                st.pop()
            i+=1
        return False

## 🔹 Leetcode 3047 Find The Largest Area Of Square Inside Two Rectangles
**Platform:** LeetCode

Problem Insight:
To find the largest square area from the intersection of any two rectangles, we must iterate through all possible pairs of rectangles. For each pair, calculate the dimensions of their intersection and find the maximum possible square side within it.

Approach:
The solution iterates through all unique pairs of rectangles. For each pair, it calculates the width and height of their intersection using min/max coordinate comparisons. If an intersection exists, the side of the largest possible inscribed square is the minimum of the intersection's width and height, and the maximum area is updated accordingly.

Time Complexity:
O(N^2)
The solution uses two nested loops to iterate through all N*(N-1)/2 distinct pairs of rectangles, with constant time operations inside the loops.

Space Complexity:
O(1)
A few variables are used to store intermediate calculations and the result, none of which scale with the input size N.

Optimization Notes:
The solution is optimal for the typical constraints of this problem (e.g., N <= 50). It directly computes the answer by checking all N^2 pairs, which is efficient enough for small N. More complex algorithms like sweep-line methods would be significantly harder to implement and likely unnecessary for the given constraints, offering little or no practical advantage for the stated problem size.

### 💻 Implementation
```cpp
class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        #define ll long long
        ll res=0;
        int n=bottomLeft.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wdth=min(topRight[i][0],topRight[j][0])-
                max(bottomLeft[i][0],bottomLeft[j][0]);
                int hgth=min(topRight[i][1],topRight[j][1])-
                max(bottomLeft[i][1],bottomLeft[j][1]);
                int sd=min(wdth,hgth);
                res=max(res,sd>0?1ll*sd*sd:0);
            }
        }
        return res;
    }
};
