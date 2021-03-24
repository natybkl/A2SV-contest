class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        unordered_map<int,int> um;
        map<int, set<int>> m;
        vector<int> res;
        
        for(int i=0; i < mat.size(); i++) {
            int count = 0;
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 0) break;
                count++;
            }
            um[i] = count;
        }
        
        for(auto &a: um) {
            m[a.second].insert(a.first); 
        }
        
        auto a = m.begin();
        
        while(k!=0 && a != m.end()) {
            auto b = a->second;
            for(auto c = b.begin(); c != b.end() && k!=0; c++) {
                res.push_back(*c);
                k--;
            }
            a++;
            
        }
        
        return res;
    }
};
