class Solution {
public:
   
    int mask_string(string s)
    {
        int mask = 0 ;
        for(int i=0;i<s.size();i++)
        {
            char c = s[i] ;
            mask = mask | (1<<(c-'a')) ;
        }
        
        return mask ;
    }
    
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
    {
        unordered_map<int,int> mask_freq ; 
     
        
        for(int i=0;i<words.size();i++)
        {
            string curr_word = words[i] ;
            int curr_mask = mask_string(curr_word) ;
            
            mask_freq[curr_mask] ++ ; 
        }
        
        
        vector<int> ans ; 
        
        for(int i=0;i<puzzles.size();i++)
        {
            string curr_puzzle = puzzles[i] ;
            
            int mask = mask_string(curr_puzzle) ; 
            int submask = mask ;
            int first = 1<<(curr_puzzle[0]-'a') ; 
            int count = 0 ;
            
           
            while(submask)
            {
                if(submask&first) 
                {
                    count += mask_freq[submask] ;
                }
                
                submask = submask - 1 ;
                
             
                submask = submask & mask ;
                
              
            }
            
            ans.push_back(count) ;
            
        }
        
        return ans ;
        
        
    }
};
