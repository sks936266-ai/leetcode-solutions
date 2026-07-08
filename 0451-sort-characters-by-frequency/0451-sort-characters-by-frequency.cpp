class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> countMap;
        for(char c:s){
            countMap[c]++;
        }
        priority_queue<pair<int,char>>maxHeap;
        for(auto& entry:countMap){
            maxHeap.push({entry.second,entry.first});
        }
        string result="";
        while(!maxHeap.empty()){
            int freq=maxHeap.top().first;
            int ch=maxHeap.top().second;
            maxHeap.pop();
            result.append(freq,ch);
        }
        return result;
    }
};