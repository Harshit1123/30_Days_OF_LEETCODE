class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
      if(n == 0){
           return {};
          }
    
	   //sort to take all the divisors of the current number before that.
       sort(nums.begin(), nums.end());
    
	  //ct[i] counts the number of elements in the subsequence finishing at position i with the given condition.
      vector<int> ct(n,1); //initializes with 1(element itself)
        
     //prev[i] represents the element before the current element in the resultant subsequence.
      vector<int> prev(n,-1);
    
	 //maximum size of the subsequence
     int maxSize = 1;
	
    //the index where the subsequence is ending or the index of the largest element of the subsequence.
    int idx = 0;
    
    for(int i=0; i<n; i++){
        
		//iterate from start to the ith index and if there's a divisor present at jth index then check is adding that increases the number of elements in out subsequence or not.
        for(int j=0; j<i; j++){
		//just like provisional LIS approach
            if(nums[i] % nums[j] == 0){
                if(ct[i] < ct[j] + 1){
                    ct[i] = ct[j] + 1;
                    prev[i] = j; //store the index j as the previous element to the ith element
                }
            }
        }
		//if the number of elements in the subsequence finishing at ith index is more than max then update max and the finishing index.
        if(ct[i] > maxSize){
            maxSize = ct[i];
            idx = i;
        }
    }
    
    vector<int> ans;
    
	//now out prev array will act like a parent array and we'll keep storing the elements according to that.
	//starting with the index idx(where the last element of the largest subsequence is located)
    while(idx != -1){
        ans.push_back(nums[idx]);
        idx = prev[idx]; //update index to ites parent for the next iteration
    }
    
	//optional step....if not done then it'll return the reverse of the answer (descending order)
	//either way it is correct
    reverse(ans.begin(), ans.end());
    
    return ans;
}
};
