class Solution {
public:
    vector<vector<int>> dirs={{0,1,0,1},{1,0,1,0},{0,0,1,-1},{0,0,-1,1}}; // {right,down,cw,ccw }
    
    bool validpos(vector<int>& cur,int idx,vector<vector<int>>& grid,int sz ) {
        if(cur[0] < 0 || cur[0] >= sz-1 || cur[1] < 0 || cur[1] >= sz-1 || cur[2] < 0 || cur[2] >= sz-1 || cur[3] < 0 || cur[3] >= sz-1 ) return false;
        
        //right
        if(idx == 0 && grid[cur[2]][cur[3] +1] == 1) return false;
        //down
        if(idx == 1 && (grid[cur[0]+1][cur[1]] == 1 || grid[cur[2]+1][cur[3]] == 1) ) return false;
        //cw
        if(idx == 2 && (cur[4] == 1 || grid[cur[0]+1][cur[1]] == 1 || grid[cur[2]+1][cur[3]] == 1)) return false;
        //ccw
        if(idx == 3 && (cur[4] == 0 || grid[cur[0]][cur[1]+1] == 1 || grid[cur[2]][cur[3]+1] == 1)) return false;
        
        return true;
     }
    
    int minimumMoves(vector<vector<int>>& grid) {
        vector<int> snakepos={0,0,0,1,0,0};  // { tx,ty,hx,hy,ver/hor,min move}
        queue<vector<int>> pos;
        set<vector<int>> visited;
        int sz = grid.size();
        
        pos.push(snakepos);
        visited.insert(snakepos);
        
        while(!pos.empty()) {
            vector<int> cur = pos.front(),newpos,dir;
            pos.pop();
            cout<<cur[0]<<" "<<cur[1]<<" "<<cur[2]<<" "<<cur[3]<<" "<<cur[4]<<" "<<cur[5]<<endl;
            visited.insert(cur);
            if(cur[0] == sz - 1 && cur[1] == sz - 2 && cur[2] == sz - 1 && cur[3] == sz -1)
                return cur[5];
            
            for(int i=0; i < dirs.size(); i++) {
                dir = dirs[i];
                newpos = {cur[0]+dir[0],cur[1]+dir[1],cur[2]+dir[2],cur[3]+dir[3],cur[4],cur[5]+1};
                
                if(validpos(newpos,i,grid,sz) && visited.find(newpos) == visited.end()) {
                    if(i == 2) newpos[4] = 1;
                    if(i == 3) newpos[4] = 0;
                    pos.push(newpos);

                }
             
            }
        }
        
         return -1;
  /*    vector<vector<int>> ht={{0,0},{0,1},{0},{0}};
        queue<vector<vector<int>>> pos;
        set<vector<vector<int>>> visited;
        int row = grid.size(), col = grid[0].size();
        pos.push(pos);
        pos.push(nullptr);
        
        while(!pos.empty()) {
            auto cur = pos.front();
            pos.pop();
            
            
            auto tail = cur[0];
            auto head = cur[1];
            int hv = cur[2];
            
            // going down
            int tx = tail[0] + 1;
            int hx = head[0] + 1;
            
            if(tx < row && tx >= 0 && hx < col && hx >= 0 && grid[tx][tail[1]]!=1 && grid[hx][head[1]]!=1 && visited.find({{tx,tail[1]},{hx,head[1]},{hv}}) == visited.end()) {
                auto newpos = {{tx,tail[1]},{hx,head[1]},{hv}};
                visited.insert(newpos);
                pos.push(newpos);
            }
            
            // going right
            int ty = tail[1] + 1;
            int hy = head[1] + 1;
            
            if(ty < col && ty >= 0 && hy < row && hy >= 0 && grid[head[0]][hy] !=1 && visisted.find({{tail[0],ty},{head[0],hy},{hv}}) == visited.end() ) {
                
                auto newpos = {{tail[0],ty},{head[0],hy},{hv}};
                visited.insert(newpos);
                pos.push(newpos);
            }
            
            // clockwise
            if(hv == 0) {
                 int hxc = head[0] + 1;
                 int hyc = head[1] - 1;
                 
                 if(hxc < row && hyc >= 0 && grid[tx][tail[1]]!=1 && grid[hx][head[1]]!=1 && visited.find({tail,{hxc,hyc},{1}}) == visited.end()) {
                       auto newpos = {tail,{hxc,hyc},{1}};
                       visited.insert(newpos);
                       pos.push(newpos);
                 } 
            } else {
            
            //counterclockwise
                 int hxcc = head[0] - 1;
                 int hycc = head[1] + 1;
            
                 if(hxcc < row && hycc >= 0 && grid[head[0]][hy] != 1 && grid[head[0]+1][hy] != 1 && visited.find({tail,{hxcc,hycc},{0}}) == visited.end() ) {
                      
                       auto newpos = {tail,{hxcc,hycc},{0}};
                       visited.insert(newpos);
                       pos.push(newpos);
                 } 
            } 
            
            
            
            
            if(pos.front() == NULL) {
                  
            }
        }
        
        */
        
        
    }
};
