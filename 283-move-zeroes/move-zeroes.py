class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        
        i=0

        for j in range(1 , len(nums)):

            if(nums[i] == 0 and nums[j] != 0):
                nums[i] , nums[j] = nums[j] , nums[i]

            if(nums[i] != 0):
                i += 1