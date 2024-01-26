class Solution
{
    public:
    static bool cmp(Item& a,Item& b)
    {
        double pro1=((double)a.value)/a.weight;
        double pro2=((double)b.value)/b.weight;
        
        return pro1>pro2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,cmp);
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            int val=arr[i].value;
            int wei=arr[i].weight;
            
            if(wei<=W)
            {
                ans+=val;
                W-=wei;
            }
            else
            {
                double last=((double)W/wei)*val;
                ans+=last;
                W=0;
            }
        }
        return ans;
    }
};
