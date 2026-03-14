# 📅 Daily CP Solutions — 2026-03-14

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Top View Of Binary Tree
**Platform:** GeeksforGeeks

Problem Insight:
The top view of a binary tree is formed by the set of nodes visible when looking from the top, prioritizing nodes with smaller depths on the same vertical line.

Approach:
The solution uses a recursive Depth First Search (DFS) traversal. It assigns a vertical index and depth to each node. Two maps store the node data and the minimum depth encountered so far for each vertical index, updating them only when a node with a smaller depth is found for an existing vertical line. Finally, it collects the stored node data from the map, which automatically sorts them by vertical index.

Time Complexity:
O(N log N)
Each of the N nodes is visited once, and each visit involves map operations (insertion, lookup, update) which take O(log K) time, where K is the number of distinct vertical lines (at most N).

Space Complexity:
O(N)
The recursion stack can go up to O(H) (tree height, O(N) in worst case). The maps store up to K entries (at most N), contributing O(N) space.

Optimization Notes:
The solution is not optimal in terms of runtime. It can be improved to an average time complexity of O(N) by using a Breadth-First Search (BFS) traversal combined with an unordered_map if sorted output by vertical index is not strictly required. If sorted output is required, a BFS with std::map will also yield O(N log N) time, but is often considered a more standard approach for this problem.

### 💻 Implementation
```cpp
class Solution {
  public:
    map<int,int>m;
    map<int,int>md;
    void rec(int i,int d,Node*r){
        if(!r)return;
        if(!m.count(i))m[i]=r->data,md[i]=d;
        else {
            if(md[i]>d){
                md[i]=d;
                m[i]=r->data;
            }
        }
        rec(i-1,d+1,r->left);
        rec(i+1,d+1,r->right);
    }
    vector<int> topView(Node *root) {
        vector<int>res;
        rec(0,0,root);
        for(auto [a,b]:m)res.push_back(b);
        return res;
    }
};

   
```

## 🔹 Leetcode The-K-Th-Lexicographical-String-Of-All-Happy-Strings-Of-Length-N
**Platform:** LeetCode

Problem Insight:
Find the k-th lexicographically smallest string of a given length n, where the string only contains 'a', 'b', 'c' and no adjacent characters are identical.

Approach:
The solution generates all possible happy strings of length n using a recursive (backtracking) function. These generated strings are stored in a vector, which is then sorted lexicographically. Finally, the (k-1)-th element of the sorted vector is returned.

Time Complexity:
O(N^2 * 2^N). There are 3 * 2^(N-1) happy strings of length N. Generating all strings takes O(N * 2^N) time, and sorting them takes O(N * (3 * 2^(N-1)) * log(3 * 2^(N-1))) which simplifies to O(N^2 * 2^N).

Space Complexity:
O(N * 2^N). The solution stores all 3 * 2^(N-1) happy strings, each of length N, in a vector.

Optimization Notes:
The solution is not optimal. Generating all happy strings and then sorting them is inefficient. An optimal solution would directly construct the k-th happy string in O(N) time by leveraging the count of happy strings that can be formed from each starting character and subsequent choices.

### 💻 Implementation
```cpp
class Solution {
public:
    vector<string>a;
    void rec(string l,int n){
        if(l.size()==n){
            a.push_back(l);
            return;
        }
        for( char c='a';c<='c';c++){
            if(l.size() && l.back()==c)continue;
            rec(l+c,n);
        }
    }
    string getHappyString(int n, int k) {
        rec("",n);
        if(a.size()<k)return "";
        sort(begin(a),end(a));
        return a[k-1];
    }
};
```
