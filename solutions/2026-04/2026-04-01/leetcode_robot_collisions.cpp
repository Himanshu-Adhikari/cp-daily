class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& ps, vector<int>& h,
                                      string d) {
        stack<int> st;
        int n = ps.size();
        vector<int> v(n), res;
        iota(begin(v), end(v), 0);
        sort(begin(v), end(v), [&](int a, int b) { return ps[a] < ps[b]; });
        for (int i : v) {
            if (d[i] != 'L')
                st.push(i);
            else {
                while (!st.empty() && h[i]) {
                    if (h[st.top()] > h[i])
                        h[i] = 0, h[st.top()]--;
                    else if (h[st.top()] < h[i])
                        h[i]--, h[st.top()] = 0, st.pop();
                    else
                        h[i] = h[st.top()] = 0,st.pop();
                }
            }
        }
        for (auto c : h)
            if (c)
                res.push_back(c);
        return res;
    }
};