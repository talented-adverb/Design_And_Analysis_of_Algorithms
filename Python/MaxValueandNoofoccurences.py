#Input nums: [2,7,11,8,11,8,3,11]
#Output: [11,3]

class Solution:
    def MaxValueAndOfOccurences(self,nums:list[int])->list[int]:
        maxVal=nums[0]
        counter=0
        for num in nums: # O(n) / O(1)
            if maxVal<num:
                maxVal=num
                counter=1
            elif num==maxVal: #instead of using 2 for loop we solve the problem in one loop
                counter+=1
        return [maxVal, counter]

solution=Solution()
Numbers=[2,7,11,8,11,8,3,11]
print(solution.MaxValueAndOfOccurences(Numbers))