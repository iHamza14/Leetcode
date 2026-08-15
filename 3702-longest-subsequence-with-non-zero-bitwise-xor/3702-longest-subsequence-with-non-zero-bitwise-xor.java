class Solution {
    public int longestSubsequence(int[] nums) 
    {
        boolean zero = false;
        int x = 0;
        for(int i =0; i<nums.length; i++)
        {
            if(nums[i] != 0) zero = true;
            x^=nums[i];
        }
        if(!zero) return 0;
        if(x==0) return nums.length-1;
        else return nums.length;
    }
}