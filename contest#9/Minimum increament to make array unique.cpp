class Solution {
public:
    int res=0;
    
    int minIncrementForUnique(vector<int>& A) {
        map<int,int> um;
        for(int i : A)
            um[i]+=1;
    
        return helper(um);
    }
    
    int helper(map<int,int> &um) {
        bool allunique=true;
        for(auto &a : um) {
            if(a.second > 1) {
                allunique=false;
                int fix = a.second;
                for(int j = 1; j < fix; j++) {
                    res+=j;
                    um[a.first + j]+=1;
                    a.second--;
                }
            }
        }
        
        
        if(!allunique) return helper(um);
        return res;
    }
};
