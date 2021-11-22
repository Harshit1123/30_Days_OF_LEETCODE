class Solution {
    public int[] singleNumber(int[] nums) {
        
    Set<Integer> set = new HashSet<Integer>();
    for(int i:nums){
         if(set.add(i)==false)
         set.remove(i);
    }
   	int a[]= new int [set.size()];
	int c=0;
	for(int b:set){
		a[c]=b;
		c++;
	}
	return a;

}
}
