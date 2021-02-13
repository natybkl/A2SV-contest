void topView(Node * root) {
       if(root==NULL) return;
        
     int x=0;   
     queue<pair<Node*,int>> q;
     pair<Node*,int> p={root,x};   
     q.push(p);   
     unordered_map<int,int> um={{0,root->data}}; 
    
    while(q.size())
    {   
        x=p.second;
        if(um.count(x)==0) um[x]=p.first->data;
        if(p.first->left != NULL)
        {
            q.push(make_pair(p.first->left,x-1));
        }
        if(p.first->right != NULL)
        {  
            q.push(make_pair(p.first->right,x+1));
        }
        q.pop();
        p=q.front();
       
    }
      
     vector<int> v;
     for(auto a:um)
         v.push_back(a.first);
         
     sort(v.begin(),v.end());
     for(auto a:v){
         auto val=um.find(a);
         cout<<val->second<<" ";
     }   

    }
