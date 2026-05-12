# 📅 Daily CP Solutions — 2026-05-12

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Range Lcm Queries
**Platform:** GeeksforGeeks

Problem Insight:
This problem requires efficient range LCM queries and point updates on an array.
A segment tree is well-suited to handle these operations effectively.

Approach:
A segment tree is used where each node stores the LCM of its corresponding range.
Build involves computing LCMs bottom-up. Queries traverse the tree, combining LCMs of relevant segments.
Updates modify a leaf and recompute LCMs up to the root.

Time Complexity:
O(N log(MAX_VAL) + Q log N log(MAX_VAL)). Building takes O(N log(MAX_VAL)); each query/update takes O(log N log(MAX_VAL)).

Space Complexity:
O(N). The segment tree uses an auxiliary array of size proportional to N.

Optimization Notes:
Yes, it is optimal for range LCM queries with point updates. The logarithmic factors for segment tree operations and LCM computation are inherent.

### 💻 Implementation
```cpp
class Solution {
  public:
    #define ll long long 
    ll lc(ll a,ll b){
        return (1LL * a / __gcd(1ll*a, 1ll*b)) * b;
    }
    vector<ll>aux;
    void build(int si,vector<int>&arr,int l,int r){
        if(l==r){
            aux[si]=arr[l];
            return;
        }
        int md=l+(r-l)/2;
        build(2*si+1,arr,l,md);
        build(2*si+2,arr,md+1,r);
        aux[si]=lc(aux[2*si+1],aux[2*si+2]);
    }
    ll rec(int si,int sl,int sr,int l,int r){
        if(sl>r or sr<l)return 1ll;
        if(sl>=l && sr<=r)return aux[si];
        int md=sl+(sr-sl)/2;
        return lc(rec(2*si+1,sl,md,l,r),rec(2*si+2,md+1,sr,l,r));
    }
    void upd(int si,int sl,int sr,int id,int val,vector<int>&arr){
        if(sl==id and sl==sr){
            arr[id]=val;
            aux[si]=val;
            return;
        }
        int md=sl+(sr-sl)/2;
        if(id<=md){
            upd(2*si+1,sl,md,id,val,arr);
        }
        else{
            upd(2*si+2,md+1,sr,id,val,arr);
        }
        aux[si]=lc(aux[2*si+1],aux[2*si+2]);
    }
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        int n=arr.size();
        aux=vector<ll>(4*n+1,1);
        build(0,arr,0,n-1);
        vector<ll>res;
        for(auto c:queries){
            if(c[0]==1){
                upd(0,0,n-1,c[1],c[2],arr);
            }
            else{
                res.push_back(rec(0,0,n-1,c[1],c[2]));
            }
        }
        return res;
    }
};
```

## 🔹 Leetcode Minimum Initial Energy To Finish Tasks
**Platform:** LeetCode

Problem Insight:
This problem asks for the minimum starting energy to complete a series of tasks, where each task has an actual cost and a minimum energy required to start it. The order of tasks significantly impacts the total energy needed.

Approach:
The solution first sorts the tasks using a greedy strategy: tasks with a larger difference between minimum required energy and actual cost (x[1] - x[0]) are prioritized. If differences are equal, tasks with larger actual cost (x[0]) come first. After sorting, binary search is performed on the possible range of the minimum starting effort. For each candidate effort, a helper function simulates task completion to check if it's sufficient for the sorted tasks.

Time Complexity:
O(N log N + N log(SUM_M)) where N is the number of tasks and SUM_M is the sum of all minimum requirements. Sorting takes O(N log N) and the binary search performs log(SUM_M) checks, each taking O(N).

Space Complexity:
O(N)
This is primarily due to the space required for storing the tasks and the sorting algorithm.

Optimization Notes:
The solution is not optimal in its time complexity. While the greedy sorting criterion is correct and takes O(N log N), the subsequent binary search on the answer space is unnecessary. After sorting, the minimum required starting effort can be found in a single O(N) pass by iterating through the sorted tasks and maintaining a running sum of actual costs and tracking the maximum needed energy. This would reduce the overall time complexity to O(N log N).

### 💻 Implementation
```py
class Solution:
    
    def rec(self, md, tasks):
        for actual, minimum in tasks:
            if md >= minimum:
                md -= actual
            else:
                return False
        return True

    def minimumEffort(self, tasks):
        
        tasks.sort(
            key=lambda x: (-(x[1] - x[0]), -x[0])
        )

        l = 0
        r = sum(task[1] for task in tasks)

        while l <= r:

            md = l + (r - l) // 2

            if self.rec(md, tasks):
                r = md - 1
            else:
                l = md + 1

        return l
```
