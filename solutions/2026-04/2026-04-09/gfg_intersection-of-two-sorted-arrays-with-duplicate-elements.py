class Solution:
    def intersection(self,a, b):
        res=[]
        a1=set(a)
        a2=set(b)
        for i in a1:
            if( i in a2):res.append(i)
        res.sort()
        return res
        