class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int ans=0;
        int maxReach=0;
        int curr=0;
        for(int i=0; i<nums.size()-1; i++){
            maxReach= max(maxReach,i+nums[i]);
            if(i==curr){
                ans++;
                curr = maxReach;
            }
            
        }
        return ans;
        
    }
};
