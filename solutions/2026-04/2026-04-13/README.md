# 📅 Daily CP Solutions — 2026-04-13

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Next Smallest Palindrome
**Platform:** GeeksforGeeks

Problem Insight:
The task is to find the smallest palindrome strictly greater than a given number represented as a digit vector. This involves two main scenarios: either mirroring the first half already yields a larger number, or we must increment the middle of the number to form the next palindrome.

Approach:
First, the number is transformed into a palindrome by mirroring its left half to the right. A flag indicates if this mirroring made the number strictly greater than the original. If so, this is the answer. Otherwise, the middle digit(s) are incremented, propagating carries, to generate the next palindrome. A special case handles numbers consisting entirely of nines, resulting in a palindrome with an additional digit.

Time Complexity:
O(N)
The solution involves a single pass over the digits for mirroring, followed by at most another pass for incrementing, and a final pass for constructing the result vector. Each pass is proportional to the number of digits, N.

Space Complexity:
O(N)
The input vector is modified in place. The resulting palindrome is stored and returned in a new vector of size N or N+1 in the all-nines case, which constitutes O(N) space.

Optimization Notes:
The solution is optimal. It processes each digit at most a constant number of times (mirroring, incrementing, copying), resulting in linear time complexity. The space complexity is also optimal, as generating a new number as output inherently requires O(N) space. Further significant improvements are not possible.

### 💻 Implementation
```cpp
//User function template for C++
class Solution{
public:
	vector<int> nextPalindrome(vector<int>&num) {
	    // code here
        bool ch=false;
        int n=num.size();
        
        for(int i=0,j=n-1;i<n&&j>=0; i++,j--)
        {
            if(num[i]<num[j] )
            {
                num[j]=num[i];
                ch=false;
            }
            else if(num[i]>num[j])
            {
                num[j]=num[i];
                ch=true;
            }
        }
          if(ch==false)
        {
            int s,e;
            if(n%2==0)
            {
                 s=n/2-1;
                 e=n/2;
            }
            else
            {
                 s=n/2;
                 e=n/2;
            }
        while( s>=0 && e<n && num[s]==9 && num[e]==9 )
            {
                num[s]=0;
                num[e]=0;
                s--;
                e++;
            }
            
            if(s>=0 && e<n)
            {
                if(s!=e)
                {
                    num[s]=num[s]+1;
                    num[e]=num[e]+1;
                }
                else
                {
                    num[s]++;
                }
            }
            else
            {
                vector<int> ans;
                ans.push_back(1);
                for(int i=1;i<n;i++)ans.push_back(0);
                
                ans.push_back(1);
                return ans;
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++)ans.push_back(num[i]);
        
        return ans;
            
	}

};
```

## 🔹 Leetcode Minimum-Distance-To-The-Target-Element
**Platform:** LeetCode

Problem Insight:
The problem asks to find the minimum absolute difference between the index of any target element and a given start index.

Approach:
The solution iterates through the array, identifying all indices where the element equals the target. For each such index, it calculates the absolute difference to the start index, and then returns the minimum of these differences.

Time Complexity:
O(N)
The code iterates through the entire 'nums' array once to find all occurrences of the target.

Space Complexity:
O(1)
It uses a generator expression, which processes elements one by one without storing intermediate lists.

Optimization Notes:
This solution is optimal. A full scan of the array is necessary in the worst case to locate all possible target positions and determine the closest one, so O(N) time complexity cannot be improved.

### 💻 Implementation
```py
class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        return min(abs(i-start) for i,val in enumerate(nums) if val==target)
```
