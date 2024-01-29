int sumOfdigit=0;
	    for(auto it:str)
	    sumOfdigit+=(it-'0');
	    
	    vector<vector<int>> dp(str.length()+1,vector<int>(sumOfdigit+1,0));
	    
	    for(int i=str.length()-1;i>=0;i--)
	    {
	        for(int pre=0;pre<=sumOfdigit;pre++)
	        {
	            int sum=0;
	            int ans=0;
	            for(int j=i;j<str.length();j++)
	            {
	                sum+=(str[j]-'0');
	                if(sum>=pre)
	                {
	                    if(j+1>=str.length())
	                    ans++;
	                    else
	                    ans+=dp[j+1][sum];
	                }
	            }
	            dp[i][pre]=ans;
	        }
	    }
	    
	    return dp[0][0];
