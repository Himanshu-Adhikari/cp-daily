# 📅 Daily CP Solutions — 2026-04-06

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Huffman Encoding
**Platform:** GeeksforGeeks

Problem Insight:
The task is to implement Huffman coding to generate optimal prefix codes for a set of characters, given their frequencies. This involves constructing a binary tree based on frequencies and then traversing it to derive the codes.

Approach:
A min-priority queue stores tree nodes, ordered by frequency then original index. Nodes with the two smallest frequencies are repeatedly extracted, merged into a new parent node with their combined frequency, and the parent is re-inserted. This process continues until one node (the Huffman tree root) remains. A Depth-First Search (DFS) from the root then generates the codes by appending '0' for left child and '1' for right child.

Time Complexity:
O(N^2)
Building the Huffman tree using the priority queue takes O(N log N) time. The DFS traversal for generating codes, using string concatenation, takes O(N^2) time in the worst case (e.g., a skewed tree) due to creating many temporary string copies.

Space Complexity:
O(N^2)
The Huffman tree and priority queue consume O(N) space. The result vector storing N strings can take O(N^2) space in the worst case if code lengths sum to O(N^2). The DFS recursion stack uses O(N) space.

Optimization Notes:
The tree construction time is optimal at O(N log N). The primary bottleneck is the string concatenation in the DFS, which can be optimized by passing a mutable character array or string reference and using append/pop_back operations. However, if the total length of all generated codes is inherently O(N^2) (due to a skewed tree), then O(N^2) time and space for storing the final vector of strings might be unavoidable for the required output format.

### 💻 Implementation
```cpp
class Solution {
  public:
    class Node{
      public:
        int f;
        int idx;
        Node *left, *right;
        
        Node(int f, int idx){
            this->f = f;
            this->idx = idx;
            left = right = NULL;
        }
    };
    
    struct cmp{
        bool operator()(Node* a, Node* b){
            if(a->f == b->f)
                return a->idx > b->idx;
            return a->f > b->f;
        }
    };
    
    void dfs(Node* root, string s, vector<string> &ans){
        
        if(!root) return;
        
        if(!root->left && !root->right){
            ans.push_back(s);
            return;
        }
        
        dfs(root->left, s + "0", ans);
        dfs(root->right, s + "1", ans);
    }

    vector<string> huffmanCodes(string &s, vector<int> f) {
        
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            pq.push(new Node(f[i], i));
        }
        
        if(n == 1) return {"0"};
        
        while(pq.size() > 1){
            
            Node* l = pq.top();
            pq.pop();
            
            Node* r = pq.top();
            pq.pop();
            
            Node* parent = new Node(l->f + r->f, min(l->idx, r->idx));
            parent->left = l;
            parent->right = r;
            
            pq.push(parent);
        }
        
        vector<string> ans;
        dfs(pq.top(), "", ans);
        
        return ans;
    }
};
```

## 🔹 Leetcode Walking-Robot-Simulation
**Platform:** LeetCode

Problem Insight:
Simulate robot movement on an infinite 2D grid, avoiding obstacles, to find the maximum squared Euclidean distance from the origin. Obstacles block movement one step at a time.

Approach:
Obstacle coordinates are stored in a set for efficient O(log M) lookup. The robot's direction is managed by an index into a fixed array of (dx, dy) pairs. For each forward command, the robot moves one step at a time, checking for obstacles before each move. If an obstacle is hit, movement stops for that command. The maximum squared distance is updated after each valid step.

Time Complexity:
O(M log M + N * K * log M) where M is the number of obstacles, N is the number of commands, and K is the maximum steps in a single forward command. Each forward step involves a set lookup.

Space Complexity:
O(M) where M is the number of obstacles. The set stores all obstacle coordinates.

Optimization Notes:
The solution is generally optimal for the given constraints. Using a set for obstacle checking provides efficient logarithmic time lookups. An unordered_set could offer average O(1) lookups but carries a risk of worst-case O(M) and usually has higher constant factors. Given the step-by-step movement requirement, the current approach is efficient.

### 💻 Implementation
```py
class Solution {
public:
    int robotSim(vector<int>& cmd, vector<vector<int>>& o) {
        int x = 0, y = 0;
        int res = 0, cnt = 0;
        set<pair<int, int>> s;
        
        for (auto& ob : o) {
            s.insert({ob[0], ob[1]});
        }

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto& c : cmd) {
            if (c == -2) {
                cnt = (cnt + 3) % 4;
            } else if (c == -1) {
                cnt = (cnt + 1) % 4;
            } else {
                for (int i = 0; i < c; ++i) {
                    int nx = x + dirs[cnt].first;
                    int ny = y + dirs[cnt].second;
                    if (s.count({nx, ny})) {
                        break;
                    }
                    x = nx;
                    y = ny;
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }
};

```
