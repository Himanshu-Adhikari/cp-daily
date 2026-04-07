# 📅 Daily CP Solutions — 2026-04-07

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Stable Marriage Problem
**Platform:** GeeksforGeeks

Problem Insight:
The problem aims to find a stable matching between N men and N women, where stability means no two unmatched individuals prefer each other over their current partners. It's a classic application of the Gale-Shapley algorithm.

Approach:
The solution uses the Gale-Shapley algorithm where men propose. It maintains a queue of free men. Each free man proposes to the next woman on his preference list. If the woman is free or prefers the new suitor over her current partner, she accepts the new suitor and rejects the less preferred one (who becomes free). This process continues until all men are matched.

Time Complexity:
O(N^2)
Each man proposes at most N times, and each proposal involves constant time operations.

Space Complexity:
O(N^2)
The 'rank' array to store women's preferences takes O(N^2) space. Other data structures take O(N) space.

Optimization Notes:
The solution implements the standard Gale-Shapley algorithm, which is known to be optimal for finding a stable marriage given the input format. The time and space complexities are inherent to needing to process potentially all preference pairs.

### 💻 Implementation
```cpp
class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        int n = men.size();

        vector<vector<int>> rank(n, vector<int>(n));

        for (int w = 0; w < n; w++) {
            for (int pos = 0; pos < n; pos++) {
                rank[w][women[w][pos]] = pos;
            }
        }

        vector<int> womanPartner(n, -1);

        vector<int> result(n, -1);

        vector<int> nextProposal(n, 0);

        queue<int> freeMen;

        for (int i = 0; i < n; i++) {
            freeMen.push(i);
        }

        while (!freeMen.empty()) {
            int man = freeMen.front();
            freeMen.pop();

            int woman = men[man][nextProposal[man]];
            nextProposal[man]++;

            if (womanPartner[woman] == -1) {
                womanPartner[woman] = man;
                result[man] = woman;
            }
            else {
                int currentMan = womanPartner[woman];

                if (rank[woman][man] < rank[woman][currentMan]) {
                    womanPartner[woman] = man;
                    result[man] = woman;

                    result[currentMan] = -1;
                    freeMen.push(currentMan);
                }
                else {
                    freeMen.push(man);
                }
            }
        }

        return result;
    }
};
```

## 🔹 Leetcode Walking Robot Simulation Ii
**Platform:** LeetCode

Problem Insight:
The problem involves simulating a robot moving along a rectangular perimeter, querying its position and direction. The main challenge is efficient cyclic movement and handling the special initial direction.

Approach:
The solution pre-computes all positions and their directions along the perimeter of the rectangle. Robot movement updates an index into these pre-computed lists using modulo arithmetic. Position and direction queries are then direct lookups based on this index.

Time Complexity:
O(W + H) for initialization, O(1) for step, getPos, getDir.
The constructor populates lists proportional to the perimeter length (width W, height H), while other methods are constant time.

Space Complexity:
O(W + H)
Two lists, pos and dirs, store data for each unique point on the perimeter, which scales with width and height.

Optimization Notes:
The solution is optimal for query operations, achieving O(1) after an O(W+H) initialization. Pre-computing the path is efficient as it avoids repeated calculations during simulation, and no further significant time or space improvements are apparent.

### 💻 Implementation
```py
class Robot:

    TO_DIR = {
        0: "East",
        1: "North",
        2: "West",
        3: "South",
    }

    def __init__(self, width: int, height: int):
        self.moved = False
        self.idx = 0
        self.pos = list()
        self.dirs = list()

        pos_, dirs_ = self.pos, self.dirs

        for i in range(width):
            pos_.append((i, 0))
            dirs_.append(0)
        for i in range(1, height):
            pos_.append((width - 1, i))
            dirs_.append(1)
        for i in range(width - 2, -1, -1):
            pos_.append((i, height - 1))
            dirs_.append(2)
        for i in range(height - 2, 0, -1):
            pos_.append((0, i))
            dirs_.append(3)

        dirs_[0] = 3

    def step(self, num: int) -> None:
        self.moved = True
        self.idx = (self.idx + num) % len(self.pos)

    def getPos(self) -> List[int]:
        return list(self.pos[self.idx])

    def getDir(self) -> str:
        if not self.moved:
            return "East"
        return Robot.TO_DIR[self.dirs[self.idx]]
```
