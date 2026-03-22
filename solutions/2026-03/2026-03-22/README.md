# 📅 Daily CP Solutions — 2026-03-22

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Rotten Oranges
**Platform:** GeeksforGeeks

Problem Insight:
This problem asks for the minimum time required for all fresh oranges to rot, which is a classic shortest path problem on an unweighted grid, solvable with Breadth-First Search (BFS).

Approach:
The solution uses a multi-source BFS. All initially rotten oranges are added to a queue, and the BFS proceeds level by level. Each level represents one minute, and newly rotten oranges are added to the queue for the next level. After the BFS, a final scan checks for any remaining fresh oranges.

Time Complexity:
O(N*M)
Each cell in the N*M grid is visited and processed at most a constant number of times (initial scan, pushed to queue, popped from queue, checking neighbors).

Space Complexity:
O(N*M)
In the worst case, the queue could store all cells in the grid, for example, if all oranges are initially rotten.

Optimization Notes:
The solution is optimal. BFS is the correct algorithm for finding minimum time in an unweighted grid, and its time and space complexities are the best possible given that all cells might need to be visited. Modifying the grid to mark rotten oranges serves as an implicit visited set.

### 💻 Implementation
```cpp
class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2)q.push({i,j});
            }
        }
        vector<pair<int,int>>d={{0,1},{1,0},{-1,0},{0,-1}};
        int res=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto[x,y]=q.front();q.pop();
                for(auto [i,j]:d){
                    int nx=i+x,ny=y+j;
                    if(nx<0 or nx>=n or ny<0 or ny>=m or mat[nx][ny]!=1)continue;
                    mat[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if(q.size())res+=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)return -1;
            }
        }
        return res;
    }
};
```

## 🔹 Leetcode Determine-Whether-Matrix-Can-Be-Obtained-By-Rotation
**Platform:** LeetCode

Problem Insight:
The problem checks if a matrix can be transformed into a target matrix by one of four possible clockwise rotations (0, 90, 180, 270 degrees). It requires accurate matrix rotation logic and repeated comparison.

Approach:
The solution first checks if the matrices are equal without rotation. It then iteratively performs three 90-degree clockwise rotations on the matrix, checking for equality with the target after each rotation. If any rotation matches, it returns true.

Time Complexity:
O(N^2)
Each rotation operation creates a new N*N matrix, and each comparison takes O(N^2) time. This is repeated a constant number of times.

Space Complexity:
O(N^2)
A new N*N matrix is constructed and assigned to 'mat' during each rotation step, consuming temporary space proportional to the matrix size.

Optimization Notes:
The solution is time-optimal as checking all N*N elements for rotation and comparison is necessary. Space complexity can be improved to O(1) by performing in-place matrix rotations through element swaps, avoiding the creation of new matrices in each step.

### 💻 Implementation
```py
class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        n=len(mat)
        if(mat==target):return True
        for i in range(3):
            mat=[[mat[i][j] for i in range(n-1,-1,-1)] for j in range(n)]
            if(mat==target):
                return True
        return False
```
