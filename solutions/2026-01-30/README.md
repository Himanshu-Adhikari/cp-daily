# 📅 Daily CP Solutions — 2026-01-30

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Interleave-The-First-Half-Of-The-Queue-With-Second-Half
**Platform:** GeeksforGeeks

Problem Insight:
The problem requires rearranging a queue by interleaving its first half with its second half. This necessitates temporarily storing the halves to achieve the desired interleaved order.

Approach:
The solution separates the original queue into two auxiliary queues, one for the first half and one for the second half. It then reconstructs the original queue by alternately pushing elements from the first half queue and the second half queue.

Time Complexity:
O(N)
Each element is moved between queues a constant number of times (from original to auxiliary, then from auxiliary back to original).

Space Complexity:
O(N)
Two auxiliary queues are used, each storing up to N/2 elements, where N is the total number of elements.

Optimization Notes:
The solution is optimal in terms of time complexity O(N) as every element must be processed. In terms of space complexity, it uses O(N) auxiliary space. While specific in-place algorithms or use of a recursion stack might achieve O(1) auxiliary space in other contexts, for standard queue operations and explicit temporary storage, O(N) space using auxiliary queues is a common and practical approach.

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
This problem requires transforming segments of a source string into corresponding target segments. It combines an all-pairs shortest path problem on word transformations with dynamic programming for segment-based string conversion.

Approach:
First, unique words from original and changed lists are mapped to integer IDs using a Trie. An adjacency matrix is built to store direct transformation costs between words. Floyd-Warshall algorithm is then used to compute the minimum cost to transform any word ID to another. Finally, dynamic programming determines the minimum cost to convert source to target, where dp[i] represents the cost for source[0...i] to target[0...i]. Each dp[i] considers matching source[j] to target[j] (cost 0) or transforming a substring source[j...i] to target[j...i] using the precomputed costs.

Time Complexity:
O(P^3 + N^2)
P is the number of unique words (at most 2 * M). Floyd-Warshall takes O(P^3). The dynamic programming loop is O(N^2).

Space Complexity:
O(P^2 + N + M*L_max)
O(P^2) for the adjacency matrix, O(N) for the DP array, and O(M*L_max) for the Trie (L_max is max word length).

Optimization Notes:
The solution is not optimal for the typical maximum constraints of this problem (N=1000, M=2000). P can be up to 2 * M (4000), making the O(P^3) Floyd-Warshall step around 6.4 * 10^10 operations, which is too slow. If P is much smaller in practice or the test cases are weak, it might pass.

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
