class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int res=INT_MAX,n=words.size(),i=0;
        while(i<n){
            if(words[i]==target){
                res=min(res,abs(i-startIndex));
                res=min(res,n-i+startIndex);
            }
            i++;
        }
       
        return res==INT_MAX?-1:res;
    }
};