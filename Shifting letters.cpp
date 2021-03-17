class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
         long sum = 0;
         for(auto a : shifts)
             sum+=a;
         
         for(int i=0; i < S.length(); i++) {
             
             S[i]=((S[i]-'a' + sum)%26 + 'a');
             sum-=shifts[i];
         }
          
         return S;
    }
};
