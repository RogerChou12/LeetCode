#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class TaskManager {
    priority_queue<pair<int, int>>PriorityandTask;
    unordered_map<int, int> TasktoPriority;
    unordered_map<int, int>TasktoUser;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(const auto task:tasks){
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        PriorityandTask.push({priority, taskId});
        TasktoPriority[taskId]=priority;
        TasktoUser[taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
        PriorityandTask.push({newPriority, taskId});
        TasktoPriority[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
        TasktoPriority[taskId]=-1;
    }
    
    int execTop() {
        while(!PriorityandTask.empty()){
            const auto task=PriorityandTask.top();
            PriorityandTask.pop();
            if(task.first==TasktoPriority[task.second]){
                TasktoPriority[task.second]=-1;
                return TasktoUser[task.second];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */