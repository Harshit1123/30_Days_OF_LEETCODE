class CombinationIterator {

    List<String> li = new ArrayList<>();
    int len;
    int ind[];
    String s;
    boolean hasRemItems = true;
    
    public CombinationIterator(String characters, int combinationLength) {
        len = combinationLength;
        s = characters;
        ind = new int[combinationLength];
        for (int i = 0; i < len; i++)
            ind[i] = i;
    }
    
    public String next() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < ind.length; i++) {
            sb.append(s.charAt(ind[i]));
        }
        int j = 0;
        for (; j < len; j++) {
            if (ind[len-1-j] != s.length()-1-j) {
                ind[len-1-j]++;
                for (int k = len-j; k < len; k++) {
                    ind[k] = ind[k-1]+1;
                }
                break;
            }
        }
      
        if (j == len) hasRemItems = false;
        return sb.toString();
    }
    
    public boolean hasNext() {
        return hasRemItems;
    }
}
