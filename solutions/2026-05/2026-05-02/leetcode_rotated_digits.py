class Solution:
    def rotatedDigits(self, n: int) -> int:
        res=0
        d={"1":"1","2":"5","5":"2","6":"9" ,"9":"6","0":"0","8":"8"}
        def rec(n:int)->bool:
            s=str(n)
            vl=0
            for i in s:
                if(i not in d):return False
                vl=vl*10+int(d[i])
            return vl!=n
        for i in range(1,n+1):
            if(rec(i)):
                res+=1
        return res