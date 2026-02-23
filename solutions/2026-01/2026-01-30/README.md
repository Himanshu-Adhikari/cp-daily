# 📅 Daily CP Solutions — 2026-01-30

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Interleave-The-First-Half-Of-The-Queue-With-Second-Half
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires rearranging a queue by interleaving its first half with its second half. This involves splitting the queue and then merging the two halves alternately.

Approach:
The solution divides the original queue into two auxiliary queues: one for the first half ('f') and one for the second half ('s'). It then reconstructs the original queue by repeatedly pushing an element from 'f' followed by an element from 's' until both auxiliary queues are empty.

Time Complexity:
O(N)
Every element in the queue is processed and moved a constant number of times through the three loops.

Space Complexity:
O(N)
Two auxiliary queues, 'f' and 's', are used to store elements, each holding approximately N/2 elements.

Optimization Notes:
The time complexity of O(N) is optimal because every element must be touched at least once. The space complexity is O(N) due to the use of two auxiliary queues. While some advanced approaches or specific data structures (like a deque or using a stack) could potentially achieve O(1) auxiliary space, this O(N) space solution is a straightforward and common method for standard queue operations.

### 💻 Implementation
```cpp
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        queue<int>f,s;
        int sz=q.size()/2;
        while(sz--){
            f.push(q.front());q.pop();
        }
        while(!q.empty()){
            s.push(q.front());q.pop();
        }
        while(!f.empty()){
            q.push(f.front());f.pop();
            q.push(s.front());s.pop();
        }
    }
};
```

## 🔹 Leetcode 2977 Minimum-Cost-To-Convert-String-Ii
**Platform:** LeetCode

Problem Insight:
This problem requires finding the minimum cost to transform a source string into a target string. Transformations are defined as converting one word to another, can be chained, and apply to substrings.

Approach:
A Trie is used to map all distinct words (from original and changed lists) to unique integer IDs. These IDs form nodes in a graph where direct transformation costs are edge weights. Floyd-Warshall algorithm then computes all-pairs shortest paths in this graph, representing minimum costs to transform any registered word into any other. Finally, dynamic programming is used on the strings: dp[i] is the minimum cost to convert source[0...i] to target[0...i], calculated by either a direct character match or by finding a substring source[j...i] transformable to target[j...i] using precomputed word costs.

Time Complexity:
O(P^3 + N^2 * L_max)
Where N is source string length, P is number of unique words (at most 2 * M where M is count of original/changed pairs), and L_max is max word length. P^3 for Floyd-Warshall dominates if P is large. N^2 * L_max for the DP part.

Space Complexity:
O(P^2 + Sum_Lengths_of_All_Words_Trie + N)
P^2 for the adjacency matrix, Sum_Lengths_of_All_Words_Trie for Trie nodes, and N for the DP array.

Optimization Notes:
The O(P^3) complexity from the Floyd-Warshall algorithm is likely the dominant bottleneck. If P (the number of unique words) is large (e.g., 2000-4000 based on typical competitive programming constraints for M), this step would result in a Time Limit Exceeded (TLE). For example, 4000^3 operations is prohibitively slow.

### 💻 Implementation
```cpp
struct Trie {
    Trie* child[26];
    int id;

    Trie() {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
        id = -1;
    }
};

int add(Trie* node, const string& word, int& index) {
    for (char ch : word) {
        int i = ch - 'a';
        if (!node->child[i]) {
            node->child[i] = new Trie();
        }
        node = node->child[i];
    }
    if (node->id == -1) {
        node->id = ++index;
    }
    return node->id;
}

void update(long long& x, long long y) {
    if (x == -1 || y < x) {
        x = y;
    }
}

class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {
        int n = source.size();
        int m = original.size();
        Trie* root = new Trie();

        int p = -1;
        vector<vector<int>> G(m * 2, vector<int>(m * 2, inf));
        for (int i = 0; i < m * 2; ++i) {
            G[i][i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int x = add(root, original[i], p);
            int y = add(root, changed[i], p);
            G[x][y] = min(G[x][y], cost[i]);
        }

        for (int k = 0; k <= p; ++k) {
            for (int i = 0; i <= p; ++i) {
                for (int j = 0; j <= p; ++j) {
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }

        vector<long long> f(n, -1);
        for (int j = 0; j < n; ++j) {
            if (j > 0 && f[j - 1] == -1) {
                continue;
            }
            long long base = (j == 0 ? 0 : f[j - 1]);
            if (source[j] == target[j]) {
                update(f[j], base);
            }
            Trie* u = root;
            Trie* v = root;
            for (int i = j; i < n; ++i) {
                u = u->child[source[i] - 'a'];
                v = v->child[target[i] - 'a'];
                if (!u || !v) {
                    break;
                }
                if (u->id != -1 && v->id != -1 && G[u->id][v->id] != inf) {
                    update(f[i], base + G[u->id][v->id]);
                }
            }
        }
        return f[n - 1];
    }

private:
    static constexpr int inf = INT_MAX / 2;
};
```
