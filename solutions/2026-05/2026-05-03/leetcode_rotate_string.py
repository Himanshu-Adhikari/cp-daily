class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        s=s+s
        return True if len(s)==len(goal)*2 and goal in s else False