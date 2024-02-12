class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,el=0;
        for(int i:nums){
            if(count==0)
            el=i;
            if(el==i)
            count++;
            else
            count--;
        }
        return el;
    }
};