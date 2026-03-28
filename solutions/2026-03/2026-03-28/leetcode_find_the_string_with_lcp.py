class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n=len(lcp)
        s:str=[""]*n
        cur=ord('a')
        for i in range(n):
            print("".join(s))
            print(s)
            if(not s[i]):
                if(cur>ord('z')):return ""
                s[i]=chr(cur)
                for j in range(i+1,n):
                    if(lcp[i][j]):
                        s[j]=s[i]
                cur+=1
        for i in range(n-1,-1,-1):
            for j in range(n-1,-1,-1):
                if(s[i]!=s[j]):
                    if(lcp[i][j]):return ""
                else:
                    if i == n - 1 or j == n - 1:
                        if lcp[i][j] != 1:
                            return ""
                    else:
                        if lcp[i][j] != lcp[i + 1][j + 1] + 1:
                            return ""
        return "".join(s)