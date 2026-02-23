# 📅 Daily CP Solutions — 2026-02-13

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg All-Numbers-With-Specific-Difference
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks to count numbers x up to N such that x - sum_of_digits(x) >= D. The function f(x) = x - sum_of_digits(x) is non-decreasing, allowing a binary search approach.

Approach:
The solution employs binary search to find the smallest number 'x_min' within the range [10, N] that satisfies the given condition. Once 'x_min' is identified, all subsequent numbers up to N will also satisfy the condition due to the monotonic nature of f(x), yielding a count of N - x_min + 1. Note: The provided check function has a critical bug where the parameter 'd' is shadowed.

Time Complexity:
O(log N * log N)
The binary search performs O(log N) iterations, and each call to the check function (summing digits) takes O(log N) time.

Space Complexity:
O(1)
The solution uses a constant amount of extra space for variables, independent of the input size N.

Optimization Notes:
The approach is optimal in terms of time complexity given the problem constraints and the nature of the function. Binary search on the answer is an efficient strategy for monotonic predicates. The primary improvement needed is to fix the critical variable shadowing bug in the check function to ensure correct logic.

### 💻 Implementation
```cpp
class Solution {
   int check(int& d,int num){
        int sum = 0;
        int temp = num;
        while(temp>0){
            int d = temp%10;
            sum += d;
            temp /= 10;
        }
        return d <= (num-sum);
    }
  public:
    int getCount(int n, int d) {
        // code here
        if(n < 10) return 0;
        int low = 10;
        int high = n;
        int possible = 0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(check(d,mid)){
                possible = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(!possible) return 0;
        return n-possible+1;
    }
};
```

## 🔹 Leetcode Longest-Balanced-Substring-Ii
**Platform:** LeetCode

Problem Insight:
The problem seeks the maximum length of a "balanced" substring, which is interpreted as either a monochromatic substring, a substring with equal counts of two specific characters (excluding the third), or a substring with equal counts of all three characters 'a', 'b', and 'c'.

Approach:
The solution combines three strategies. It first finds the longest substring of a single repeating character. Next, it iterates through all 3P2 pairs of distinct characters (e.g., 'a' and 'b'), finding the longest substring where their counts are equal, provided the third character ('c') is not present. Finally, it uses a 2D prefix sum difference map to find the longest substring where the counts of 'a', 'b', and 'c' are all equal. The maximum length found across these three methods is returned.

Time Complexity:
O(N log N)
The dominant part is the final loop using std::map for 2D differences, which involves N operations, each taking O(log N) due to map lookups/insertions.

Space Complexity:
O(N)
The std::map used for 2D differences can store up to O(N) distinct pairs, each taking constant space, resulting in O(N) space. The unordered_map also takes O(N) space.

Optimization Notes:
The solution is near-optimal. The O(N log N) complexity for the "all three characters equal" case, stemming from std::map, could be optimized to O(N) average time by using std::unordered_map with a custom hash function for std::pair<int, int>.

### 💻 Implementation
```cpp
class Solution {
public:
    int longestBalanced(string s) {
        vector<int>a(3,0);
        #define ll long long
        int n=s.size(); ll res=0;
        for(int i=0;i<n;i++)a[s[i]-'a']++;
        int l=0,r=*min_element(begin(a),end(a));
        a=vector<int>(3,0);
       for(int i=0;i<n;i++){
           if(s[i]=='a')a[0]++,a[1]=0,a[2]=0;
           else if(s[i]=='b')a[0]=0,a[1]+=1,a[2]=0;
           else a[0]=0,a[1]=0,a[2]++;
           res=max(res,1ll*(*max_element(begin(a),end(a))));
       }
           for(char c='a';c<='c';c++){
               for( char d='a';d<='c';d++){
                   if(d==c)continue;
                    // map<pair<ll,ll>,ll>mp;
                   unordered_map<ll,pair<ll,ll>>mp;
                    // mp[{0,0}]=-1;
                   mp[0]={-1,0};
                   int j=0;
                   int f=0,o=0;
                   for(int i=0;i<n;i++){
                       if(s[i]==c)f++;
                       else if(s[i]==d)o++;
                       else {f=0,o=0,j++;mp[0]={i,j};continue;}
                       if(mp.count(f-o) && mp[f-o].second==j){
                           res=max(res,i-mp[f-o].first);
                       }
                       else mp[f-o]={i,j};
                       
                   }
               }
           }
        map<pair<int,int>,ll>m;
        a=vector<int>(3,0);
        m[{0,0}]=-1;
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
            int f=a[0]-a[1],o=a[0]-a[2];
            // cout<<f<<" "<<o<<endl;
            if(m.count({f,o}))res=max(res,i-m[{f,o}]);
            else m[{f,o}]=i;
        }
        return res;
    }
};
```
