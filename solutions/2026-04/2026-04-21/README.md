# 📅 Daily CP Solutions — 2026-04-21

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Two Water Jug
**Platform:** GeeksforGeeks

Problem Insight:
This is the classic water jug problem, solvable by simulating pouring operations. It finds the minimum steps to measure a target amount using two jugs of given capacities.

Approach:
The solution simulates two distinct greedy strategies: one starting by filling the first jug and pouring into the second, and the other vice versa. It iteratively performs pour, fill, and empty operations until the target amount is reached in either jug. A greatest common divisor (GCD) check handles impossible cases upfront.

Time Complexity:
O(max(M, N) + log(min(M, N))). The simulation loop runs at most a number of iterations proportional to the larger capacity, as states involving water levels eventually repeat or reach the target. GCD calculation adds a logarithmic factor.

Space Complexity:
O(1). The solution only uses a fixed number of integer variables regardless of the input jug capacities.

Optimization Notes:
This solution is optimal. The greedy simulation method employed for the water jug problem is known to find the minimum number of steps and its time complexity is efficient, matching the lower bound for this type of problem.

### 💻 Implementation
```cpp
class Solution {
  public:
    int fun( int n , int m , int d){
         int i = n ,  j =0;
          int ans =1;
          while(i!= d && j!= d){
              int temp = min(i , m-j);
               j += temp;
               i -= temp;
               ans++;
               if( i ==d || j ==d) break;
                if(i==0){
                    i = n;
                    ans++;
                }
                 if( j==m){
                      j = 0;
                       ans++;
                 }
          }
           return ans;
    }
    int minSteps(int m, int n, int d) {
        int mn=gcd(m,n);
        if(d%mn or max(m,n)<d)return -1;
        
          return min( fun( n , m ,d) , fun( m , n, d));
    }
};
```

## 🔹 Leetcode Minimize The Hamming Distance After Swaps Operations
**Platform:** LeetCode

Problem Insight:
The problem asks to find the minimum number of positions where source and target arrays differ after arbitrarily swapping elements within allowed groups. Allowed swaps define connected components where elements can be freely rearranged.

Approach:
A Disjoint Set Union (DSU) data structure identifies connected components based on the allowed swaps. Elements from the source array are then grouped into multisets corresponding to their DSU component. Finally, for each index, the target element is checked against the multiset of its component; if found, it's removed, otherwise a mismatch is counted.

Time Complexity:
O(N log N + M alpha(N)). DSU operations are O(alpha(N)). Populating and iterating multisets takes O(N log N) because each of N elements is inserted and potentially removed from a multiset, where multiset operations are O(log K) (K is component size, worst case N). M is the number of allowed swaps.

Space Complexity:
O(N). DSU arrays take O(N) space. The map of multisets stores all N elements from the source array, requiring O(N) space.

Optimization Notes:
The solution is largely optimal. DSU is the standard and most efficient way to find connected components. Using a map of multisets is an appropriate way to manage arbitrary integer values within components for matching. For problems with small integer ranges, a frequency array or hash map might offer average O(1) lookups instead of O(log K), but overall complexity would remain dominated by DSU and array traversals.

### 💻 Implementation
```cpp
class Solution {
public:
    int par(int i,vector<int>&p){
        if(p[i]==i)return i;
        return p[i]=par(p[i],p);
    }
    void un(int i,int j,vector<int>&p,vector<int>&r){
        int pi=par(i,p),pj=par(j,p);
        if(r[pi]>=r[pj]){
            p[pj]=pi;
            r[pi]+=1;
        }
        else{
            p[pi]=pj;
            r[pj]+=1;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int res=0;
        map<int,multiset<int>>m;
        int n=source.size();
        vector<int>pr(n),rnk(n,0);
        iota(begin(pr),end(pr),0);
        for(auto c:allowedSwaps){
            int p1=par(c[0],pr),p2=par(c[1],pr);
            if(p1!=p2){
                un(c[0],c[1],pr,rnk);
            }
        }
        for(int i=0;i<n;i++){
            m[par(i,pr)].insert(source[i]);
        }
        for(int i=0;i<n;i++){
            int prp=par(i,pr);
            if(m[prp].count(target[i])){
                m[prp].erase(m[prp].find(target[i]));
            }
            else{
                res++;
            }
        }
        return res;

    }
};
```
