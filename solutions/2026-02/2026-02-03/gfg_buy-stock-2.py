class Solution:
    def maxProfit(self, prices):
        res,n=0,len(prices)
        pr=prices[-1]
        for i in range(n-2,-1,-1):
            res=max(res,pr-prices[i])
            pr=max(pr,prices[i])
        return res