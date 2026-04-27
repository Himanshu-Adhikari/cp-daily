// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        // int ans=1e9;
     vector<int> A(3, 0);
        int hi=0, lo=0, n=s.size(), ans=1e9;
        while(hi<n) {
            A[s[hi]-'0']++;
            while(A[0]&&A[1]&&A[2]) {
                ans=min(ans, hi-lo+1);
                A[s[lo++]-'0']--;
            }
            hi++;
        }
        return ans==1e9?-1:ans;
    }
};

