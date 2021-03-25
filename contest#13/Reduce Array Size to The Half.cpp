class Solution {
public:
    int minSetSize(vector<int>& arr) {        
        vector<int> occ;
        unordered_map<int, int> um;
        
        int hf = arr.size()/2;
        int sz = arr.size();
        int count = 0;
        int flag = 0;
        
        for(int &i : arr) {
            um[i]+=1;
        }
        
        for(auto &a: um) {
            occ.push_back(a.second);
        }
        
        sort(occ.begin(), occ.end());
        
        for(int i = occ.size()-1; i >= 0; i--) {
                if(sz - occ[i] > hf) {
                    sz-=occ[i];
                    count++;
                    flag = 1;
                } else if(sz - occ[i]) return count + 1;
                   
                
        }
        
        if(flag)  return count + 1;
        else return 1;
        
    }
};
