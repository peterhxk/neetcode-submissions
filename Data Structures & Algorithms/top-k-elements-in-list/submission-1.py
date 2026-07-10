class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        m = {}
        i = 1
        count = 1
        maxcount = 0
        nums.sort()
        prev = nums[0]
        while i < len(nums):
            num = nums[i]
            if prev != num:
                if count in m:
                    m[count].append(prev)
                else:
                    m[count] = [prev]
                maxcount = max(maxcount, count)
                prev = num
                count = 1
            else:
                count += 1
            i+=1
        if count in m:
            m[count].append(prev)
        else:
            m[count] = [prev]
        maxcount = max(maxcount,count)
        ret = []
        while len(ret) <= k and maxcount > 0:
            if maxcount in m:
                for i in m[maxcount]:
                    ret.append(i)
                    if len(ret) == k:
                        return ret
            maxcount -= 1
        return ret