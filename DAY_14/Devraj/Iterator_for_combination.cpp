class CombinationIterator {
public:
    string s;
    bool combs[15];
    int k;
    bool hasMoreCombs = true;
    void advanceCombs() {
        //move the first availabile and rightmost 1 left one step, sort from there
        for (int i = s.size() - 1; i; i--) {
            if (!combs[i] && combs[i - 1]) {
                swap(combs[i], combs[i - 1]);
                sort(begin(combs) + i + 1, begin(combs) + s.size(), greater<>());
                return;
            }
        }
        hasMoreCombs = false;
    }
    
    CombinationIterator(string &characters, int combinationLength) {
        s = characters;
        k = combinationLength;
        // initialising combs for our very first string
        for (int i = 0; i < 15; i++) combs[i] = i <  k;
    }
    
    string next() {
        // generating the current next string
        string res;
        for (int i = 0; i < s.size(); i++) if (combs[i]) res.push_back(s[i]);
        // preparing the next combinations
        advanceCombs();
        return res;
    }
    
    bool hasNext() {
     
        return hasMoreCombs;
    }
};
