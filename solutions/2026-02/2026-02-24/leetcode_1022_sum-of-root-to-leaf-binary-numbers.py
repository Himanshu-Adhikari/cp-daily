class Solution:
    
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def rec(s,r):
            if(not r):
                return 0
            if((not r.left) and (not r.right)):
                res=0
                if(r.val==1):
                    s+='1'
                else:
                    s+='0'
                n=len(s)
                for i in range(n-1,-1,-1):
                    if(s[i]=='1'):res+=(1<<(n-1-i))
                print(s,res)
                return res
            if(r.val==1):
                s+='1'
            else:
                s+='0'
            l=rec(s,r.left)
            r=rec(s,r.right)
            return l+r
        return rec("",root)