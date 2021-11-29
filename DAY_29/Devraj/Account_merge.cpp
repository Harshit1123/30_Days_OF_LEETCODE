class Solution {
public:
    vector<int> parent;
    int findParent(int y) {
        while(parent[y] != y) {
            y = parent[y];
        }
        return parent[y];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        if(accounts.size() == 1) {
            sort(accounts[0].begin()+1, accounts[0].end());
            return accounts;
        }
        //maps every email to the given source id
        unordered_map<string, int> emailmap;
        parent = vector<int>(accounts.size(), -1);
        //maps every account to the given name
        vector<string> namemap(accounts.size(), "");
        int i=0;
        for(auto &x : accounts) {
            namemap[i] = x[0];
            parent[i] = i;
            for(int y=1; y<x.size(); y++) {
                if(emailmap.find(x[y]) != emailmap.end())
                    parent[findParent(i)] = findParent(emailmap[x[y]]);
                else
                    emailmap[x[y]] = i;
            }
            i++;
        }
        unordered_map<int, vector<string>> resmap;
      
        for(auto &m : emailmap) {
            int p = findParent(m.second);
            resmap[p].push_back(m.first);
        }
        vector<vector<string>> results;
      
        for(auto &r : resmap) {
            sort(r.second.begin(), r.second.end());
            r.second.insert(r.second.begin(), namemap[r.first]);
            results.push_back(r.second);
        }
        return results;
    }
};
