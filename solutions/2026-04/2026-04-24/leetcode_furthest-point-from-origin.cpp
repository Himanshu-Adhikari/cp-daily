class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0;for(auto c:moves)l+=(c=='_' || c=='L') -(c=='R'),r+=(c=='_' || c=='R') - (c=='L');
        return max(l,r);
    }
};