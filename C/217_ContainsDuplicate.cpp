#include <vector>
#include <unordered_map>

class Solution {
    public:
        bool containsDuplicate(std::vector<int>& nums) {
            std::unordered_map<int, int> seen;
            for(auto x:nums){
                if(seen[x]>=1){
                    return true;
                }
                seen[x]++;
            }
            return false;
        }
    };