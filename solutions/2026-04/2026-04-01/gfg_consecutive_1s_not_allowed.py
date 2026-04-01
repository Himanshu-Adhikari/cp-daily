class Solution:
	def countStrings(self,n):
    	if n == 1:
            return 2
        if n == 2:
            return 3
        a, b = 2, 3
        for _ in range(3, n + 1):
            a, b = b, a + b
            
        return b
