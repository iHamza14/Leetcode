class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr1 = [nums[0]]
        arr2 = [nums[1]]
        
        for j in range (2,len(nums)):
            if(arr1[-1] > arr2[-1]):
                arr1.append(nums[j])
            else:
                arr2.append(nums[j])

        return arr1+arr2
