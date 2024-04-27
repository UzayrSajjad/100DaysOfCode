class Solution {
public:
    int countSteps(int ringIndex, int i, int n) {
        int dist       = abs(i - ringIndex);
        int wrapAround =  n - dist;
        
        return min(dist, wrapAround);
    }
    
    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        int m = key.length();
        
        unordered_map<char, vector<int>> adj; // char --> {indices in ring where char is present}
        for (int i = 0; i < n; i++) {
            char ch = ring[i];
            adj[ch].push_back(i);
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        set<pair<int, int>> visited;
        
        int totalSteps = 0;
        while (!pq.empty()) {
            vector<int> vec = pq.top();
            pq.pop();
            
            totalSteps    = vec[0];
            int ringIndex = vec[1];
            int keyIndex  = vec[2];
            
            if (keyIndex == m) {
                break;
            }
            
            if (visited.count({ringIndex, keyIndex})) {
                continue;
            }

            visited.insert({ringIndex, keyIndex});
            
            for (int nextIndex : adj[key[keyIndex]]) {
                pq.push({totalSteps + countSteps(ringIndex, nextIndex, n), 
                            nextIndex, keyIndex + 1});
            }
        }
        
        return totalSteps + m; //Note : totalSteps is for bringing each character to 12:00 position and then printing each of them will take m steps
    }
};
