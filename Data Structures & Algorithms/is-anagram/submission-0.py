class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        d1 = {}
        d2 = {}
        for ch in s:
            if ch in d1:
                d1[ch] += 1
            else:
                d1[ch] = 0
        for ch in t:
            if ch in d2:
                d2[ch] += 1
            else:
                d2[ch] = 0
        for i in d1.keys():
            if i not in d2.keys() or d1[i] != d2[i]:
                print(i)
                return False
        for i in d2.keys():
            if i not in d1.keys() or d2[i] != d1[i]:
                return False
        return True
        