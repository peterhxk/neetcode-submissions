class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs)==0:
            return "0"
        elif strs == [""]:
            return ""
        ret = ""
        for string in strs:
            ret = ret + string + ";"
        ret = ret[:len(ret)-1]
        return ret
    def decode(self, s: str) -> List[str]:
        if s == "0":
            return []
        elif s == "":
            return [""]
        return s.split(";")