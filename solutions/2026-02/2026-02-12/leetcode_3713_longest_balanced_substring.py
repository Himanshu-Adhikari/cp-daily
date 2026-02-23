class Solution:
    def longestBalanced(self, s: str) -> int:
        res = 0
        n = len(s)
        for i in range(n):
            v = [0] * 26
            aux = {}
            for j in range(i, n):
                c = ord(s[j]) - ord('a')
                if v[c] > 0:
                    aux[v[c]] -= 1
                    if aux[v[c]] == 0:
                        del aux[v[c]]
                v[c] += 1
                aux[v[c]] = aux.get(v[c], 0) + 1
                if len(aux) == 1:
                    res = max(res, j - i + 1)
        return res
