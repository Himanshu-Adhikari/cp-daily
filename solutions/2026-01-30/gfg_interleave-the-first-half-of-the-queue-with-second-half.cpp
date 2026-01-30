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