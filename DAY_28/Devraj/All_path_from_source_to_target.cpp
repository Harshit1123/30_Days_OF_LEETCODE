class Solution {
public:
    void path(vector<vector<int>>& graph, vector<bool>&vis,  vector<int>curr_path,  vector<vector<int>>&all_path,int src)
    {
         vis[src]=true;
         curr_path.push_back(src);
         if(src==(graph.size()-1))
          {  all_path.push_back(curr_path);
             vis[src]=false;
             return;
          }
        
         for(auto node:graph[src])
          { if(!vis[node])
              path(graph,vis,curr_path,all_path,node);
          }
        vis[src]=false;    
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int r=graph.size();
        vector<vector<int>>all_path;
        vector<int>curr_path;
        vector<bool>vis(r,false);
        path(graph,vis,curr_path,all_path,0);
        return all_path;
    }
};
