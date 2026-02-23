# 📅 Daily CP Solutions — 2026-02-11

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Equalize-The-Towers
**Platform:** GeeksforGeeks

Problem Insight:
The problem seeks to find a target value X that minimizes the sum of weighted absolute differences, which is a convex function. The optimal X is the weighted median of the array elements.

Approach:
The solution employs binary search over the range of possible target values (min(arr) to max(arr)). In each iteration, it calculates the total cost for 'mid' and 'mid+1' to determine the slope of the convex function and intelligently narrow the search range towards the minimum.

Time Complexity:
O(N * log(max_val - min_val))
The binary search performs log(max_val - min_val) iterations, and each iteration involves an O(N) pass to calculate costs.

Space Complexity:
O(1)
Only a constant number of auxiliary variables are used, independent of the input size.

Optimization Notes:
This approach is effective and typically passes given competitive programming constraints. While it correctly finds the minimum of a convex function, a theoretically more optimal solution for the weighted median problem could be O(N log N) by sorting the arr values and their costs, then finding the weighted median directly. The current solution's log factor depends on the range of values rather than just N.

### 💻 Implementation
```cpp
class Solution {
  public:
    int minCost(vector<int>& arr, vector<int>& cost) {
        int n = cost.size();
        int start = INT_MAX;
        int end=INT_MIN;
        int ans = INT_MAX;
        
        for(int i=0;i<n;i++){
            if(start>arr[i])start=arr[i];
            if(end<arr[i])end=arr[i];
        }
        
        
        while(start<=end){
            
            int mid = start+((end-start)/2);
            
            int cost1 = 0;
            int cost2 = 0;
            
            for(int i=0;i<n;i++){
                cost1+=(abs(arr[i]-mid)*cost[i]);
                cost2+=(abs(arr[i]-(mid+1))*cost[i]);
            }
            
           
            
            if(cost1<cost2){
                ans = cost1;
                end=mid-1;
            }
            else{
                start = mid+1;
            }
            
        }
        
        return ans;
    }
};

```

## 🔹 Leetcode 3721 Longest Balanced Subarray Ii
**Platform:** LeetCode

Problem Insight:
This solution finds the longest subarray where the count of distinct even numbers equals the count of distinct odd numbers. It uses a dynamic "balance" prefix sum for distinct elements within a sliding window.

Approach:
A lazy segment tree stores "effective balance" values for each index, initialized with prefix sums considering only first occurrences. The left endpoint of the subarray `i` slides from `0` to `N-1`. For each `i`, it queries the segment tree for the rightmost `j` where the current subarray `nums[i...j]` has a zero balance, and then updates the segment tree to reflect `nums[i]` no longer contributing to balances from `i+1` onwards until its next occurrence.

Time Complexity:
O(N log N)
Building the segment tree takes O(N). Each of the N iterations performs a range update and a point query, both O(log N).

Space Complexity:
O(N)
The segment tree requires O(N) space for its nodes, and the occurrences map stores indices for each number, also up to O(N) in the worst case.

Optimization Notes:
The solution is optimal for its approach. The use of a lazy segment tree allows for efficient O(log N) range updates and point queries on dynamically changing prefix sums, making the overall time complexity O(N log N). This is generally the best complexity for problems involving dynamic range queries and updates on arrays.

### 💻 Implementation
```py
class LazyTag:
    def __init__(self):
        self.to_add = 0

    def add(self, other):
        self.to_add += other.to_add
        return self

    def has_tag(self):
        return self.to_add != 0

    def clear(self):
        self.to_add = 0


class SegmentTreeNode:
    def __init__(self):
        self.min_value = 0
        self.max_value = 0
        self.lazy_tag = LazyTag()


class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.tree = [SegmentTreeNode() for _ in range(self.n * 4 + 1)]
        self._build(data, 1, self.n, 1)

    def add(self, l, r, val):
        tag = LazyTag()
        tag.to_add = val
        self._update(l, r, tag, 1, self.n, 1)

    def find_last(self, start, val):
        if start > self.n:
            return -1
        return self._find(start, self.n, val, 1, self.n, 1)

    def _apply_tag(self, i, tag):
        self.tree[i].min_value += tag.to_add
        self.tree[i].max_value += tag.to_add
        self.tree[i].lazy_tag.add(tag)

    def _pushdown(self, i):
        if self.tree[i].lazy_tag.has_tag():
            tag = LazyTag()
            tag.to_add = self.tree[i].lazy_tag.to_add
            self._apply_tag(i << 1, tag)
            self._apply_tag((i << 1) | 1, tag)
            self.tree[i].lazy_tag.clear()

    def _pushup(self, i):
        self.tree[i].min_value = min(
            self.tree[i << 1].min_value, self.tree[(i << 1) | 1].min_value
        )
        self.tree[i].max_value = max(
            self.tree[i << 1].max_value, self.tree[(i << 1) | 1].max_value
        )

    def _build(self, data, l, r, i):
        if l == r:
            self.tree[i].min_value = data[l - 1]
            self.tree[i].max_value = data[l - 1]
            return

        mid = l + ((r - l) >> 1)
        self._build(data, l, mid, i << 1)
        self._build(data, mid + 1, r, (i << 1) | 1)
        self._pushup(i)

    def _update(self, target_l, target_r, tag, l, r, i):
        if target_l <= l and r <= target_r:
            self._apply_tag(i, tag)
            return

        self._pushdown(i)
        mid = l + ((r - l) >> 1)
        if target_l <= mid:
            self._update(target_l, target_r, tag, l, mid, i << 1)
        if target_r > mid:
            self._update(target_l, target_r, tag, mid + 1, r, (i << 1) | 1)
        self._pushup(i)

    def _find(self, target_l, target_r, val, l, r, i):
        if self.tree[i].min_value > val or self.tree[i].max_value < val:
            return -1

        if l == r:
            return l

        self._pushdown(i)
        mid = l + ((r - l) >> 1)

        if target_r >= mid + 1:
            res = self._find(target_l, target_r, val, mid + 1, r, (i << 1) | 1)
            if res != -1:
                return res

        if l <= target_r and mid >= target_l:
            return self._find(target_l, target_r, val, l, mid, i << 1)

        return -1


class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        occurrences = defaultdict(deque)

        def sgn(x):
            return 1 if x % 2 == 0 else -1

        length = 0
        prefix_sum = [0] * len(nums)
        prefix_sum[0] = sgn(nums[0])
        occurrences[nums[0]].append(1)

        for i in range(1, len(nums)):
            prefix_sum[i] = prefix_sum[i - 1]
            occ = occurrences[nums[i]]
            if not occ:
                prefix_sum[i] += sgn(nums[i])
            occ.append(i + 1)

        seg = SegmentTree(prefix_sum)
        for i in range(len(nums)):
            length = max(length, seg.find_last(i + length, 0) - i)
            next_pos = len(nums) + 1
            occurrences[nums[i]].popleft()
            if occurrences[nums[i]]:
                next_pos = occurrences[nums[i]][0]

            seg.add(i + 1, next_pos - 1, -sgn(nums[i]))

        return length
```
