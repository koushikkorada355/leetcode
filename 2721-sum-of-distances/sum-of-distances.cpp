class Solution {
public:
    vector<long long> distance(vector<int>& arr) {
        int n = arr.size();

        unordered_map<long,long> list;
        unordered_map<long,long> freq;

        vector<long long> intervals(n,0);
        for(int i = 0;i < n;i++){
          intervals[i] = intervals[i] + (i * freq[arr[i]]) - list[arr[i]]; 
          freq[arr[i]]++;         
          list[arr[i]] += i;
        }
        list.clear();
        freq.clear();
        for(int i = n - 1;i >= 0;i--){
          intervals[i] = intervals[i] + (list[arr[i]] - (i * freq[arr[i]]));    
          freq[arr[i]]++;           
          list[arr[i]] += i;
        }
        return intervals;
    }
};