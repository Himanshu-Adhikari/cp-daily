class Solution:
    def findWays(self, n):
        if(n%2==1):
            return 0
        def rec(o,c):
            if(not o and not c):return 1
            cs=0
            if(o==c):
                an=rec(o-1,c)
                cs+=an
            else:
                if(c>o):
                    an=rec(o,c-1)
                    cs+=an
                if(o):
                    an=rec(o-1,c)
                    cs+=an
            return cs
        res=rec(n//2,n//2)
        return res    