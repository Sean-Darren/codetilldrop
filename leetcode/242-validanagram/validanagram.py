class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        length = len(s)

        p = {}
        q = {}

        if length != len(t):
            return False
        
        for i in s:
            p[i] = p.get(i, 0) + 1
        
        for j in t:
            q[j] = q.get(j, 0) + 1

        for k in t:
            if q.get(k) != p.get(k):
                return False
        

        return True
        