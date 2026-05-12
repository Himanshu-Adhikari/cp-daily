# 📅 Daily CP Solutions — 2026-05-12

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Range Lcm Queries
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires supporting range LCM queries and point updates on an array of integers.
A segment tree is suitable as LCM is an associative operation.

Approach:
A segment tree is constructed where each node stores the LCM of its range. Range LCM queries traverse the tree to combine relevant node values, and point updates propagate changes up the tree.

Time Complexity:
O( (N + Q log N) * log(max_val) )
Building the tree takes O(N) LCMs, and each query/update takes O(log N) LCMs; each LCM involves a GCD operation taking O(log(max_val)) time.

Space Complexity:
O(N)
The segment tree uses an auxiliary array of size O(4N) to store node values.

Optimization Notes:
The solution is optimal for this problem type. Segment trees provide logarithmic time complexity for range queries and point updates, which is the best possible for general associative operations.

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
This problem asks for the minimum initial effort required to complete a series of tasks, where each task has an actual cost and a minimum effort needed to start it. The key challenge is finding the optimal order to complete tasks and the minimum initial effort.

Approach:
The solution uses binary search on the possible range of the initial effort. For a given initial effort, a greedy approach determines if all tasks can be completed. Tasks are sorted by (actual_cost - minimum_required) in descending order (or equivalently, (minimum_required - actual_cost) in ascending order), with a tie-breaker by actual_cost ascending. This greedy order ensures that tasks with smaller 'buffer' (minimum_required - actual_cost) are attempted first.

Time Complexity:
O(N log N + N log R) where N is the number of tasks and R is the sum of maximum minimum requirements. Sorting takes O(N log N), and the binary search performs O(log R) calls to the O(N) verification function.

Space Complexity:
O(N) for storing the tasks and the auxiliary space used by Python's Timsort algorithm.

Optimization Notes:
The solution is optimal. It correctly employs a greedy sorting strategy for task order, which is provably optimal for minimizing the initial resource. Binary searching over the answer range for the minimum initial effort, coupled with this greedy check, is the standard and most efficient approach for this type of problem.

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
