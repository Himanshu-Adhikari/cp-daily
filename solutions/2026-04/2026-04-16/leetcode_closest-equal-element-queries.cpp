class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
     vector<int>ans;
     map<int,vector<int>>m;
     int n=nums.size();
     for(int i=0;i<n;i++)m[nums[i]].push_back(i);
     for(int &i:queries){
        int vl=nums[i];
        if(int(m[vl].size())==1)ans.push_back(-1);
        else {
            auto it = lower_bound(m[vl].begin(), m[vl].end(), i);
            int idx = it - m[vl].begin();
            int res = INT_MAX;
            int left = (idx - 1 + m[vl].size()) % m[vl].size();
            int leftDist = abs(i - m[vl][left]);
            leftDist = min(leftDist, n - leftDist);
             int right = (idx + 1) % m[vl].size();
            int rightDist = abs(m[vl][right] - i);
            rightDist = min(rightDist, n - rightDist);
            res = min(leftDist, rightDist);
            ans.push_back(res);
        }
     }
     return ans;   
    }
};