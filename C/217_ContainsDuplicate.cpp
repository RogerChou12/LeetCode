class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_map<int, int> seen;
            for(auto x:nums){
                if(seen[x]>=1){
                    return true;
                }
                seen[x]++;
            }
            return false;
        }
    };