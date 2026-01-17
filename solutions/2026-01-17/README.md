# 📅 Daily CP Solutions — 2026-01-17

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Expression Contrain Redundant Brackets Or Not
**Platform:** GeeksforGeeks

Problem Insight:
The problem checks if an arithmetic expression contains any redundant parentheses. Redundant parentheses are those that do not change the order of evaluation (e.g., `((a+b))` or `(a)`).

Approach:
The solution uses a stack. It pushes opening parentheses and operators onto the stack. When a closing parenthesis is encountered, it checks if the top of the stack is an opening parenthesis; if so, redundancy is found and it returns `True`. Otherwise, it pops elements from the stack until the matching opening parenthesis is found, ensuring at least one operator was enclosed.

Time Complexity:
O(N) because each character in the input string `s` is processed once, and stack operations take O(1) time.

Space Complexity:
O(N) in the worst case, as the stack `st` can store up to N characters for deeply nested expressions (e.g., `((((...))))`).

Optimization Notes:
This approach is optimal. Any algorithm must examine each character of the expression at least once (O(N) time), and storing intermediate parenthesis states often requires O(N) space.

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
The problem asks to find the maximum area of a square that can be inscribed within the intersection of any two axis-aligned rectangles from a given set.

Approach:
The solution iterates through all unique pairs of rectangles. For each pair, it calculates the dimensions of their intersection. The side length of the largest square that can fit within this intersection is the minimum of the intersection's width and height. The maximum square area found across all pairs is maintained and returned.

Time Complexity:
`O(N^2)`, because it involves nested loops iterating through all `N * (N-1) / 2` unique pairs of rectangles, with constant time operations inside the loops.

Space Complexity:
`O(1)`, as only a few constant extra variables are used regardless of the input size `N`.

Optimization Notes:
Yes, this approach is generally optimal. To guarantee finding the largest square among *any* pair, one must inspect all possible pairs of rectangles. There isn't a known faster general algorithm for this specific problem than iterating through all `O(N^2)` pairs.

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
