class Solution {
  public:
    bool isPower(int x, int y) {
        if(x==1 and y!=1)return false;
        while(y!=1){
            if(y%x)return false;
            y/=x;
        }
        return true;
    }
};