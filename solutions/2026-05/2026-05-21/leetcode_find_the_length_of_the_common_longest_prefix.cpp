class node {
public:
    map<int, node*> m;

    void in(int c, node* t) {
        string s = to_string(c);
        for (auto d : s) {
            if (t->m.count(d - '0')) {
                t = t->m[d - '0'];
            } else {
                t->m[d - '0'] = new node();
                t = t->m[d - '0'];
            }
        }
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        node* rt = new node();
        node* t;
        for (auto c : arr1) {
            t = rt;
            t->in(c, t);
        }

        int res = 0;
        for (auto d : arr2) {
            t = rt;
            string s = to_string(d);
            int curr = 0;

            for (auto c : s) {
                if (t->m.count(c - '0')) {
                    curr++;
                    t = t->m[c - '0'];
                } else break;
            }
            res = max(res, curr);
        }

        return res;
    }
};
