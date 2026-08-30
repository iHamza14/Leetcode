class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        int mini = min_element(nums.begin(),nums.end())-nums.begin();
        int maxi = max_element(nums.begin(),nums.end())-nums.begin();

        int x=INT_MAX;
        int y=INT_MAX;
        int z=INT_MAX;

        x= max(maxi,mini)+1;
        y= n-(min(maxi,mini));
        z= min(mini+1 + n-maxi , maxi+1+n-mini);

        return min({x,y,z});
    }
};