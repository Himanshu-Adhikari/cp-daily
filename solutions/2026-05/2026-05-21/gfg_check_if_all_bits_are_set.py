class Solution:
    def isBitSet(self, n):
        s=bin(n)[2::]
        for i in s:
            if(i=='0'):return False
        return True