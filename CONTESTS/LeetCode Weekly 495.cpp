//EASY
/*
PROBLEM:
You are given a string s of length n consisting of lowercase English letters.
Return the smallest index i such that s[i] == s[n - i - 1].
If no such index exists, return -1.
Example 1:
Input: s = "abcacbd"
Output: 1

Explanation:
At index i = 1, s[1] and s[5] are both 'b'.
No smaller index satisfies the condition, so the answer is 1.

Example 2:
Input: s = "abc"
Output: 1

Explanation:
​​​​​​​At index i = 1, the two compared positions coincide, so both characters are 'b'.
No smaller index satisfies the condition, so the answer is 1.

Example 3:
Input: s = "abcdab"
Output: -1

Explanation:
​​​​​​​For every index i, the characters at positions i and n - i - 1 are different.
Therefore, no valid index exists, so the answer is -1.
*/
#include <iostream>
#include <string>
class Solution {
public:
    int firstMatchingIndex(std::string s) {
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s[i] == s[n - i - 1]) {
                return i; 
            }
        }
        return -1;
    }
};

/*
You are given an initial list of events, where each event has a unique eventId and a priority.

Implement the EventManager class:
EventManager(int[][] events) Initializes the manager with the given events, where events[i] = [eventIdi, priority​​​​​​​i].
void updatePriority(int eventId, int newPriority) Updates the priority of the active event with id eventId to newPriority.
int pollHighest() Removes and returns the eventId of the active event with the highest priority. If multiple active events have the same priority, return the smallest eventId among them. If there are no active events, return -1.
An event is called active if it has not been removed by pollHighest().

Example 1:
Input:
["EventManager", "pollHighest", "updatePriority", "pollHighest", "pollHighest"]
[[[[5, 7], [2, 7], [9, 4]]], [], [9, 7], [], []]
Output:
[null, 2, null, 5, 9]

Explanation
EventManager eventManager = new EventManager([[5,7], [2,7], [9,4]]); // Initializes the manager with three events
eventManager.pollHighest(); // both events 5 and 2 have priority 7, so return the smaller id 2
eventManager.updatePriority(9, 7); // event 9 now has priority 7
eventManager.pollHighest(); // remaining highest priority events are 5 and 9, return 5
eventManager.pollHighest(); // return 9
Example 2:

Input:
["EventManager", "pollHighest", "pollHighest", "pollHighest"]
[[[[4, 1], [7, 2]]], [], [], []]
Output:
[null, 7, 4, -1]
Explanation
EventManager eventManager = new EventManager([[4,1], [7,2]]); // Initializes the manager with two events
eventManager.pollHighest(); // return 7
eventManager.pollHighest(); // return 4
eventManager.pollHighest(); // no events remain, return -1
*/
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class EventManager {
private:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.first != b.first) {
                return a.first > b.first; 
            }
            return a.second < b.second; 
        }
    };

    set<pair<int, int>, Compare> activeEvents;
    unordered_map<int, int> idToPriority;

public:
    EventManager(vector<vector<int>>& events) {
        for (auto& event : events) {
            int id = event[0];
            int priority = event[1];
            activeEvents.insert({priority, id});
            idToPriority[id] = priority;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if (idToPriority.count(eventId)) {
            int oldPriority = idToPriority[eventId];
            activeEvents.erase({oldPriority, eventId});
        }
        idToPriority[eventId] = newPriority;
        activeEvents.insert({newPriority, eventId});
    }
    
    int pollHighest() {
        if (activeEvents.empty()) {
            return -1;
        }
        auto it = activeEvents.begin();
        int eventId = it->second;
        activeEvents.erase(it);
        idToPriority.erase(eventId);
        
        return eventId;
    }
};
