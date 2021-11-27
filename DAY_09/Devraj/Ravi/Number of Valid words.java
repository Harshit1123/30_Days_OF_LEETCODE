class Solution {
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Map<Integer, Integer> wordMap = new HashMap<>();
        for(String w:words) {
            int mainMask = 0;
            for(char c:w.toCharArray()) {
                mainMask |= 1 << (c - 'a');
            }
            wordMap.put(mainMask, wordMap.getOrDefault(mainMask, 0) + 1);
        }
        
        List<Integer> answerList = new ArrayList<>();
        for(String p:puzzles) {
            int first = 1 << (p.charAt(0) - 'a');
            int mainMask = 0;
            for(char c:p.substring(1).toCharArray()) {
                mainMask |= 1 << (c - 'a');
            }
            int count = 0;
            count += combination(wordMap, -1, 0, mainMask, first);
            answerList.add(count);
        }
        return answerList;
    }
    
    int combination(Map<Integer, Integer> wordMap, int index, int mask, int mainMask, int first) { 
        if(index == 27) {
            return wordMap.getOrDefault(first|mask, 0);
        }
        
        int sum = 0;
        for(int i=index; i<27; i++) {
            int bit = 1<<i;
            if((bit&mainMask) != 0 || i==26){ // need to include i=26 i.e. did not pick any bit this round
                sum += combination(wordMap, i + 1, mask|(bit&mainMask), mainMask, first);
            }
        }
        return sum;
    }
}
