# 📅 Daily CP Solutions — 2026-02-06

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Happiest-Triplet
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks to find three numbers, one from each of three arrays, such that the difference between the maximum and minimum of these three chosen numbers is minimized. This is a variation of the k-pointers technique on sorted arrays.

Approach:
Sort all three input arrays. Initialize three pointers, one for each array. In a loop, identify the maximum and minimum among the three elements pointed to, calculate their difference, and update the minimum difference found. To progress, increment the pointer of the currently smallest element to potentially reduce the overall range.

Time Complexity:
O(N log N + M log M + K log K) where N, M, K are sizes of arrays a, b, c respectively.
Sorting each array takes N log N, M log M, K log K time. The three-pointer scan takes O(N+M+K) time.

Space Complexity:
O(1)
The solution uses constant extra space for pointers and storing the result triplet, not including the input arrays themselves.

Optimization Notes:
The solution is optimal. Sorting the arrays is a prerequisite for the efficient three-pointer approach. Without sorted arrays, a significantly less efficient solution would be required. The three-pointer scan visits each element at most once, making it the most efficient way to find the triplet after sorting. The final sort of the result vector might be an output format requirement and does not impact the core algorithm's optimality.

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
         sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        int i,j,k;
        i=0;
        j=0;
        k=0;
        int mini=INT_MAX;
        vector<int>ans;
        while(i<a.size() && j<b.size() && k<c.size()){
            if(a[i]>=b[j] && a[i]>=c[k]){
                if(b[j]>=c[k]){
                    int diff=a[i]-c[k];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    k++;
                }
                else{
                    int diff=a[i]-b[j];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    j++;
                }
            }
            else if(b[j]>=a[i] && b[j]>=c[k]){
                if(a[i]>=c[k]){
                    int diff=b[j]-c[k];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    k++;
                }
                else{
                    int diff=b[j]-a[i];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    i++;
                }
            }
            else{
                if(b[j]>=a[i]){
                    int diff=c[k]-a[i];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    i++;
                }
                else{
                    int diff=c[k]-b[j];
                    if(diff<mini){
                        mini=diff;
                        ans={a[i],b[j],c[k]};
                    }
                    j++;
                }
            }
        }
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};
```

## 🔹 Leetcode Minimum-Removals-To-Balance-Array
**Platform:** LeetCode

Problem Insight:
To minimize removals, find the longest continuous subarray where the maximum element is at most k times the minimum element. Sorting the array allows for efficient determination of the minimum and maximum within any continuous subarray.

Approach:
Sort the input array. Use a two-pointer sliding window (j for left, i for right). Expand the window by incrementing i as long as nums[i] <= nums[j] * k, updating the result with the current window's length (n - length_of_window) as potential minimum removals. If the condition fails, shrink the window from the left by incrementing j until the condition might hold again for the current i.

Time Complexity:
O(N log N) because sorting the array takes O(N log N) time, and the two-pointer sliding window takes O(N) time.

Space Complexity:
O(1) if in-place sorting is used, or O(N) if the sorting algorithm requires auxiliary space (e.g., Python's Timsort). No additional significant data structures are used.

Optimization Notes:
The solution is optimal. Sorting is a necessary step to simplify the max-min condition within a subarray. The two-pointer sliding window approach is the most efficient way to find the longest valid subarray in a sorted array, achieving O(N) time after sorting.

### 💻 Implementation
```py
class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        n=len(nums)
        i,j=0,0
        res=n-1
        nums.sort()
        while(i<n):
            while(i<n and  nums[i]<=(nums[j]*k)):
                if((n-(i-j+1))<res):
                    res=n-(i-j+1)
                i+=1
            while(i<n and nums[i]>(nums[j]*k)):
                j+=1
        return res
```
