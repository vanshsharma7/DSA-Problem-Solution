class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=0,n=nums.size();
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            arr[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(arr[i]>=2){
                ans=i;
                break;
            }
        }
        return ans;
    }
};