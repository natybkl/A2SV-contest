class Solution {
public:
    int max=0;
    
    int removeStones(vector<vector<int>>& stones) {
        map<vector<int>,vector<vector<int>>> graph;
        set<vector<int>> visited;
        
        for(int i=0; i < stones.size(); i++)  {
            count = 0;
            for (int j=i+1; j < stones.size(); j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[stones[i]].push_back(stones[j]);
                    count ++;
                }
            }
        }
        
        graph[stones[stones.size()-1]]={};
        
        for(auto itr=graph.begin(); itr < graph.end(); itr++) {
            if(visited.find(itr->first) == visisted.end())
        }
        return dfs(graph,stones[0],visited);
    /*    for(auto a : graph) {
            cout<<a.first[0]<<" "<<a.first[1]<<"   ";
            for(auto v : a.second ) {
                cout<<v[0]<<" "<<v[1]<<"  ";
            } 
            cout<<endl;
        }
        
        exit(0); */
        
    }
    
    
    int dfs(map<vector<int>,vector<vector<int>>> graph, vector<int> coord, set<vector<int>> &visited){
 
        for(itr )
        
    }
};
