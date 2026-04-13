//User function template for C++
class Solution{
public:
	vector<int> nextPalindrome(vector<int>&num) {
	    // code here
        bool ch=false;
        int n=num.size();
        
        for(int i=0,j=n-1;i<n&&j>=0; i++,j--)
        {
            if(num[i]<num[j] )
            {
                num[j]=num[i];
                ch=false;
            }
            else if(num[i]>num[j])
            {
                num[j]=num[i];
                ch=true;
            }
        }
          if(ch==false)
        {
            int s,e;
            if(n%2==0)
            {
                 s=n/2-1;
                 e=n/2;
            }
            else
            {
                 s=n/2;
                 e=n/2;
            }
        while( s>=0 && e<n && num[s]==9 && num[e]==9 )
            {
                num[s]=0;
                num[e]=0;
                s--;
                e++;
            }
            
            if(s>=0 && e<n)
            {
                if(s!=e)
                {
                    num[s]=num[s]+1;
                    num[e]=num[e]+1;
                }
                else
                {
                    num[s]++;
                }
            }
            else
            {
                vector<int> ans;
                ans.push_back(1);
                for(int i=1;i<n;i++)ans.push_back(0);
                
                ans.push_back(1);
                return ans;
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++)ans.push_back(num[i]);
        
        return ans;
            
	}

};