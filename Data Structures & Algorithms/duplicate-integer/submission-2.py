class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        for i in range(len(nums)):
            val = nums[i]
            nums[i] = None
            if val in nums:
                return True
        return False
            
         