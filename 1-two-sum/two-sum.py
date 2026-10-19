class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mpp = {}

        found  = (-1,-1)
        for i,num in enumerate(nums):
            t = target - num

            if(t in mpp):
                found = (mpp[t] , i)
                break
            mpp[num] = i
        return found