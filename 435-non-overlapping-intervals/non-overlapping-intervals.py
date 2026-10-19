class Solution:
    def eraseOverlapIntervals(self, intervals: list[list[int]]) -> int:
        
        count = 0
        intervals.sort(key = lambda x : x[1])
        end = intervals[0][1]
        size = len(intervals)

        for i in range(1,size):

            if(intervals[i][0] < end):
                count = count + 1
            else:
                end = intervals[i][1]

        return count

        