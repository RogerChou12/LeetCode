#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto calculateGain=[](int pass, int total){
            return (double)(pass+1)/(total+1)-(double)pass/total;
        };
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        for(const auto& singleClass:classes){
            double gain=calculateGain(singleClass[0], singleClass[1]);
            maxHeap.push({gain, {singleClass[0], singleClass[1]}});
        }
        while(extraStudents--){
            auto [currentGain, classInfo]=maxHeap.top();
            maxHeap.pop();
            int pass=classInfo.first;
            int total=classInfo.second;
            double gain=calculateGain(pass+1, total+1);
            maxHeap.push({gain, {pass+1, total+1}});
        }
        double totalRatio=0;
        while(!maxHeap.empty()){
            auto [gain, classInfo]=maxHeap.top();
            maxHeap.pop();
            totalRatio += (double)classInfo.first/classInfo.second;
        }
        return totalRatio/classes.size();
    }
};