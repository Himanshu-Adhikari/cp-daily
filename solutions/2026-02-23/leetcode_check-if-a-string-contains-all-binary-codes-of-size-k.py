class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        res=0
        st=set()
        n=len(s)
        for i in range(n-k+1):
            t=""
            for j in range(i,i+k):
                t+=s[j]
            st.add(t)
        return len(st)==(1<<k)