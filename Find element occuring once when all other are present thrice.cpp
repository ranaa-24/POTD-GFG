class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        vector<int> freq(32, 0);
        int num = 0;
        for(int bit=0; bit<32; bit++){      // for traversing the 32 bit
            for(int i=0; i<N; i++){         //in each row of all numbers
                if(arr[i] & (1<<bit)){      // if set bit
                    freq[bit]++;
                }
            }
            
            if(freq[bit]%3 != 0){
                num += (1<<bit);
            }
        }
        
        return num;
    }
};