
class Solution:
    def decodeCiphertext(self, s: str, rows: int) -> str:
        if(rows==1 or s==""):return s
        cols=len(s)//rows
        res = []
        for c in range(cols):
            r, j = 0, c
            while r < rows and j < cols:
                res.append(s[r * cols + j])
                r += 1
                j += 1

        return "".join(res).rstrip()