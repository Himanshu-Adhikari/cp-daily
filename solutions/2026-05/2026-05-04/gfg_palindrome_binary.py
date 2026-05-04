class Solution:
    def isBinaryPalindrome(self, n):
        s=bin(n)[2:]
        r=s[::-1]
        return s==r
        