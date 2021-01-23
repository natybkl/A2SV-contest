vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    vector<int> result; 
    int len1 = strings.size();
    int len2 = queries.size();
    for(int i=0; i<len2; i++) 
    {
        int count =0;
        for(int j=0; j<len1; j++) 
        {
            if(strings[j]==queries[i])
            {
                count++; 
            }
        
       }
       result.push_back(count);
   }
    return result;
}
