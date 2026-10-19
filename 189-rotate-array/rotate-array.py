class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        k = k % len(nums)
        nums[:] = nums[:][::-1]
        nums[:k] = nums[:k][::-1]
        nums[k:] = nums[k:][::-1]
        