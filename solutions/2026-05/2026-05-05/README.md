# 📅 Daily CP Solutions — 2026-05-05

This document contains concise, interview-ready explanations for the problems solved today.
Each solution includes the core idea, complexity analysis, and optimization insight.

---

## 🔹 Gfg Sum Of Xor Of All Pairs
**Platform:** GeeksforGeeks

Problem Insight:
The problem asks for the sum of XORs of all unique pairs (arr[i], arr[j]) where i < j. It can be efficiently solved by considering the contribution of each bit position to the total sum.

Approach:
For each bit position from 0 to 31, count how many numbers in the array have that bit set and how many have it unset. The product of these two counts determines how many pairs will have that specific bit set in their XOR sum. Multiply this product by the bit's value (2^bit_position) and accumulate the result for all bit positions.

Time Complexity:
O(N * B)
The outer loop runs B (number of bits, typically 32) times. The inner loop iterates N (array size) times for each bit.

Space Complexity:
O(1)
Only a few constant variables are used to store counts and the running sum, independent of array size.

Optimization Notes:
This solution is optimal in terms of time complexity as it processes each bit for each number. The use of pow(2,i) should be replaced with (1LL << i) to ensure integer arithmetic, prevent potential floating-point precision errors, and improve performance slightly.

### 💻 Implementation
```cpp


class Solution{
    public:
    long long int sumXOR(vector<int>&arr)
    {
        int n=arr.size();
    	long long int sum=0;
        for(int i=0;i<32;i++)
        {   long long int zero=0;
             long long  int one=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j]&(1<<i))
                {
                    ++zero;
                }
                else
                {
                    ++one;
                }
            }
            sum+=zero*one*(pow(2,i));
        }
        return sum;
    }
};

```

## 🔹 Leetcode Rotate List K Times
**Platform:** LeetCode

Problem Insight:
To rotate a linked list right by k positions, effectively we need to move the last k nodes to the front. This can be simplified by forming a circle and then breaking it at the new tail.

Approach:
First, determine the list's length and normalize k to be within the list's bounds. Form a circular list by connecting the tail to the head. Then, traverse (length - k) steps from the original head to locate the new tail, and break the circle at that point.

Time Complexity:
O(n)
Two passes are made over the list: one to find its length, and another to find the split point.

Space Complexity:
O(1)
Only a fixed number of pointer variables are used, independent of the list's size.

Optimization Notes:
This solution is optimal. It requires at least one full pass to determine the list's length and another pass to restructure it, making O(n) time complexity unavoidable. It also uses minimal O(1) extra space.

### 💻 Implementation
```cpp

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode*a=head;
        if(!head)return head;
        ListNode* pr=NULL;
        while(a){
            n++;
            pr=a;
            a=a->next;
        }
        k=k%n;
        if(k==0)return head;
        pr->next=head;
        k=n-k;
        a=head;
        pr=NULL;
        while(k--){
            pr=a;
            a=a->next;
        }
        pr->next=NULL;
        return a;
    }
};
```
