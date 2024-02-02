//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        bool isNeg = false;
        int start=0;
        if(s[start] == '-'){
            isNeg = true;
            start++;
        }
        
        int num = 0;
        for(int i=start; i<s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9')
                num = num * 10 + (s[i] - '0');
            else
                return -1;
        }
        
        return (isNeg == true) ? -num : num;
    }
};
