class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        a=bin(n)[2::]
        if(sum(1 if a[i]==a[i-1] else 0 for i in range(1,len(a)))):
            return False
        return True