class Solution:
    def sortColors(self, nums: list[int]) -> None:
        one = 0
        zero = 0

        for num in nums:
            if(num==0):
                zero += 1
            elif(num==1):
                one += 1
        idx = 0
        while(one > 0 or zero > 0):

            if(zero > 0):
                for i in range(idx ,len(nums) ):
                    if(nums[i]==0):
                        nums[i] , nums[idx] = nums[idx] , nums[i]
                        idx += 1
                        zero -= 1

            else:
                for i in range(idx , len(nums)):
                    if(nums[i]==1):
                        nums[i] , nums[idx] = nums[idx] , nums[i]
                        idx += 1
                        one -= 1

        
        