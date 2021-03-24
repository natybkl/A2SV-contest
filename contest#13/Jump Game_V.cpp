// slow traversal which takes the last index a starting point
class Solution {
public:
    
    int dfs(unordered_map<int, vector<int>> &graph, vector<int> &results, int idx, int count,int& res) {
        for(auto &a: graph[idx]) {
            int ct = 1;
            int val = 0;
            
            if(results[a] == 0) 
                val = dfs(graph, results, a, ct + 1, res);
            else 
                ct+=results[a];

            results[idx] = max(ct,results[idx]);
            results[idx] = max(val + 1, results[idx]);
        }
           res = max(res, results[idx]);
           return results[idx];
           
    }
    
    
    int maxJumps(vector<int>& arr, int d) {
        unordered_map<int, vector<int>> graph;
        vector<int> results(arr.size(), 0);
        int f1 = 0,f2 = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 1; j <= d; j++) {
                if(i + j < arr.size() && f1 == 0) {
                    if(arr[i+j] < arr[i]) {
                        graph[i].push_back(i+j);
                    } else {
                        f1 = 1;
                    }
                }
                
                if(i - j >= 0) {
                    if(arr[i-j] < arr[i] && f2 == 0) {
                        graph[i].push_back(i-j);
                    } else {
                        f2 = 1;
                    }
                }
                
                if(f1 == 1 && f2 == 1) break;
            }
            
            f1 = 0;
            f2 = 0;
        }
        
       
        for(int i = 0; i < arr.size(); i++) {
            if(graph.find(i) == graph.end())
                results[i] = 1;
        }
        
        int res = 1;
        for(auto &a: graph) {
            if(results[a.first] == 0)
                int val = dfs(graph, results, a.first, 1, res);
        }
        
        return res;
        
        
        
    }
};





// another slower traversal which takes last index as a starting point
class Solution {
public:
    
    int dfs(unordered_map<int, vector<int>> &graph, vector<int> &results, int idx, int count) {
        for(auto &a: graph[idx]) {
            int ct = 1;
            int val = 0;
            
            if(results[a] == 0) 
                val = dfs(graph, results, a, ct + 1);
            else 
                ct+=results[a];

            results[idx] = max(ct,results[idx]);
            results[idx] = max(val + 1, results[idx]);
        }
           return results[idx];
    }
    
    
    int maxJumps(vector<int>& arr, int d) {
        unordered_map<int, vector<int>> graph;
        vector<int> results(arr.size(), 0);
    
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 1; j <= d; j++) {
                if(i + j < arr.size()) {
                    if(arr[i+j] < arr[i]) {
                        graph[i].push_back(i+j);
                    } else {
                        break;
                    }
                }
            }
            
            
            for(int j = 1; j <= d; j++) {
                if(i - j >= 0) {
                    if(arr[i-j] < arr[i]) {
                        graph[i].push_back(i-j);
                    } else {
                        break;
                    }
                }
            }
        }
        
        for(int i = 0; i < arr.size(); i++) {
            if(graph.find(i) == graph.end())
                results[i] = 1;
        }
        
        
        for(auto &a: graph) {
            if(results[a.first] == 0)
                int val = dfs(graph, results, a.first, 1);
        }
        
        return *max_element(results.begin(), results.end());
        
    }
};



// a much faster version
class Solution {
public: 
    
    int dfs(vector<int>& arr, vector<int> &results, int d, int k,int& res) {
        for(int i = 1; i <= d; i++) {
            int ct = 1;
            int val = 0;
            
            if(k + i < arr.size()) {
                if(arr[k + i] < arr[k]) {
                    if(results[k+i] != 0) {
                        ct += results[k+i];
                    } else {
                        val = dfs(arr, results, d, k + i, res);
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
            
            results[k] = max(results[k], ct);
            results[k] = max(results[k], val + 1);
             
        }
        
        for(int i = 1; i <= d; i++) {
            int ct = 1;
            int val = 0;
            
            if(k - i >= 0) {
                if(arr[k - i] < arr[k]) {
                    if(results[k-i] != 0) {
                        ct += results[k-i];
                    } else {
                        val = dfs(arr, results, d, k - i, res);
                    }
                } else {
                    break;
                }
            } else {
                break;
            }
            
            results[k] = max(results[k], ct);
            results[k] = max(results[k], val + 1);
             
        }
        
        res = max(res, results[k]);
        return results[k];
    }
        
    int maxJumps(vector<int>& arr, int d) {
        vector<int> results(arr.size(), 0);
        int res = 1;
        
        if(arr.size() == 1)
            return 1;
        
        if(arr[0] < arr[1])
            results[0] = 1;
        
        if(arr[arr.size() - 1] < arr[arr.size() - 2])
            results[arr.size() - 1] = 1;
        
        for(int i = 1; i < arr.size() - 1; i++) {
            if(arr[i] <= arr[i - 1] && arr[i] <= arr[i + 1])
                results[i] = 1;
        }
        
        
        for(int i = 0; i < arr.size(); i++) {
            if(results[i] == 0) {
                int val = dfs(arr, results, d, i, res);
                cout<<i<<" ";
            }
        }
        
        return res;
    }
};

