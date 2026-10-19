class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        curr_sum = 0
        max_sum = -1e9

        for num in nums:
            curr_sum += num

            max_sum = max(max_sum, curr_sum)
            if(curr_sum < 0 ):
                curr_sum = 0
        return max_sum