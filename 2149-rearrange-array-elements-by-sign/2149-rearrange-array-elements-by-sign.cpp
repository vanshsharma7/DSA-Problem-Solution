class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> num1;
        vector<int> num2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                num1.push_back(nums[i]);
            }
            else if(nums[i]<0){
                num2.push_back(nums[i]);
            }
        }
        nums.clear();
        for(int i=0;i<num1.size();i++){
            nums.push_back(num1[i]);
            nums.push_back(num2[i]);
        }
        return nums;
    }
};