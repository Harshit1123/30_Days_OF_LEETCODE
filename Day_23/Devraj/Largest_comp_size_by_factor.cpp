class DSU
{
    private:
    vector<int> parent;
    
    public:
    DSU(int n)
    {
        for(int i = 0; i < n; i++)
        {
            parent.push_back(i);
        }
    }
    
    int findParent(int node)
    {
        if(parent[node] == node)
            return node;
        
        return parent[node] = findParent(parent[node]);
    }
    
    void _union(int u, int v)
    {
        int uParent = findParent(u);
        int vParent = findParent(v);
        
        if(uParent != vParent)
            parent[uParent] = parent[vParent];
    }
};

class Solution {
  
public:
    int largestComponentSize(vector<int>& nums) {
        
        int n = *max_element(nums.begin(), nums.end());
         
        DSU dsu(n+1);
        
        // do union for each element with all of the element's factors
        for(auto &val : nums)
        {
            for(int i = 2; i * i <= val; i++)
            {
                if(val % i == 0)
                {
                    dsu._union(val, i);
                    dsu._union(val, val/i);
                    
                }
            }
        }
        
        
        unordered_map<int,int> mp;
        int res = 1;
        
        // count the number of parent for each value
        for(auto val : nums)
        {
            res = max(res, ++mp[dsu.findParent(val)]);
        }
        
        return res;
    }
};
