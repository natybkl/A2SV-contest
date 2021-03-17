class Solution {
public:
    int indep=0;
    
    int removeStones(vector<vector<int>>& stones) {
        map<vector<int>,vector<vector<int>>> graph;
        set<vector<int>> visited;
        
        for(int i=0; i < stones.size(); i++)  {
             vector<vector<int>> v;
            for (int j=0; j < stones.size(); j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    v.push_back(stones[j]);
                    
                }
            }
              graph[stones[i]] = v;
        }
        
       for(auto itr=graph.begin(); itr != graph.end(); itr++) {
             if(visited.find(itr->first) == visited.end()) {
                 dfs(graph,itr->first,visited);
                  indep++;
             }
                  
        } 
        
        for(auto a : stones) {
            if(visited.find(a) == visited.end())
                dfs(graph,a,visited);
        } 
        
       return stones.size()-indep;
       /* for(auto a : graph) {
            cout<<a.first[0]<<" "<<a.first[1]<<"   ";
            for(auto v : a.second ) {
                cout<<v[0]<<" "<<v[1]<<"  ";
            } 
            cout<<endl;
        }
        
        exit(0); 
         */
    }
    
    
    void dfs(map<vector<int>,vector<vector<int>>>& graph, vector<int> coord, set<vector<int>> &visited){
 
         if(visited.find(coord) != visited.end()) {
            
             return;
         }
        
         visited.insert(coord);
        
         for(auto a : graph[coord]) {
             
             dfs(graph,a,visited);
         }
         
    }
};
