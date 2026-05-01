class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        priority_queue<int>q;
        vector<int>res;
        for(int i:arr){
            q.push(-i);
            if(q.size()>k)q.pop();
            if(q.size()==k)res.push_back(-q.top());
            else res.push_back(-1);
        }
        return res;
    }
};