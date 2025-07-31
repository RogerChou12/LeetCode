#include<vector>
#include<unordered_set>

class Solution {
public:
    int subarrayBitwiseORs(std::vector<int>& arr) {
        std::unordered_set<int> result, current;

        for(int x:arr){
            std::unordered_set<int> next;
            next.insert(x);

            for(int y:current){
                next.insert(x|y);
            }
            result.insert(next.begin(), next.end());
            current=next;
        }

        return result.size();
    }
};