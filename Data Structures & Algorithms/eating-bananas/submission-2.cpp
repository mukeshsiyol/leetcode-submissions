class Solution {
public:
    int isvalid(vector<int>& piles, int h,int k){
        int hours = 0;
        for(int nums : piles){
            if(nums%k==0){
                hours+=nums/k;
            }else{
                hours+=nums/k + 1;
            }
        }
        if(hours<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans;
        int maximum=0;
        for(int nums:piles){
            maximum = max(maximum,nums);
        }
        int start=1;
        int end = maximum;
        while(start<=end){
            int k = start + (end - start)/2;
            if(isvalid(piles,h,k)){
                ans = k;
                end = k-1;
            }else{
                start = k+1;
            }
        }
        return ans;
        
    }
};
