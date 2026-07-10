class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        clone = strs.copy()
        ans = []
        for i in range(len(strs)):
            clone[i] = ''.join(sorted(clone[i]))
        for i in range(len(strs)):
            if clone[i] == None:
                continue
            val = clone[i]
            clone[i] = None
            l = [strs[i]]
            while val in clone:
                ind = clone.index(val)
                clone[ind] = None
                l.append(strs[ind])
            ans.append(l)
        return ans

        