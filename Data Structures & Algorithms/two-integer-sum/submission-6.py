class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ind_map = {}
        for i in range(len(nums)):
            num = nums[i]
            if target-num in ind_map:
                return [ind_map[target-num], i]
            else:
                ind_map[num] = i 