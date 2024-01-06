// time complexity-> O(N*sqrt(N)),  using sieve it canbe solve in O(N*logN), [Note: O(logN) is preffered over O(sqrt(n))]
    int primePower(int n){
        int numberOfPowers = 0;
        for(int i=2; i<=sqrt(n); i++){      // normal prime Number Logic
            while(n%i == 0){
                numberOfPowers++;        // incrrease the power , for 2^3 will increament 3..
                n /= i;
            }
        }
        
        if(n != 1) numberOfPowers++;     // if the rest number is prime, like n=11 the sqrt(11) ~~ 3
        
        return numberOfPowers;
    }
    
	int sumOfPowers(int a, int b){
	    // Code here
	    int ans = 0;
	    for(int i=a; i<=b; i++){
	        ans += primePower(i);
	    }
	    return ans;
	}