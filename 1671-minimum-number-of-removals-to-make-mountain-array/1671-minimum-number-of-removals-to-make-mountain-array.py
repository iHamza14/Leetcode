class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        n = len(nums)
        inc = [1]*n
        dec = [1]*n

        for i in range(n):
            for j in range(i):
                if(nums[i] > nums[j]):
                    inc[i] = max(inc[i], 1 + inc[j])

        for i in range(n-1, -1 , -1):
            for j in range(i+1 , n , 1):
                if(nums[i] > nums[j]):
                    dec[i] = max(dec[i], 1 + dec[j])

        ans =0
        for i in range(n):
            if(inc[i]>1 and dec[i]>1):
                ans = max(ans , inc[i]+dec[i]-1)

        return n-ans
