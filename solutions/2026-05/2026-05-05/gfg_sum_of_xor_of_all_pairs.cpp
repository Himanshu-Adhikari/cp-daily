

class Solution{
    public:
    long long int sumXOR(vector<int>&arr)
    {
        int n=arr.size();
    	long long int sum=0;
        for(int i=0;i<32;i++)
        {   long long int zero=0;
             long long  int one=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j]&(1<<i))
                {
                    ++zero;
                }
                else
                {
                    ++one;
                }
            }
            sum+=zero*one*(pow(2,i));
        }
        return sum;
    }
};
