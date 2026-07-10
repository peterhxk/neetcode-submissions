class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        m = {}
        for string in strs:
            sorted_str = str(sorted(string))
            if sorted_str in m:
                m[sorted_str].append(string)
            else:
                m[sorted_str] = [string]
        ret = []
        for val in m.values():
            ret.append(val)
        print(ret)
        return ret
