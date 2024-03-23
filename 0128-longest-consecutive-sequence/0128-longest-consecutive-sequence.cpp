class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> st;
        for(auto x:nums)
        st.insert(x);

        for(auto x:nums){
            if(st.find(x-1)==st.end()){
                int num=x;
                int l=1;
                while(st.find(num+1)!=st.end()){
                    l++;
                    num++;
                }
                ans=max(ans,l);
            }
        }
        return ans;
    }
};