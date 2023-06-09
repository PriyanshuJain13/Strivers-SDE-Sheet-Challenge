//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    
    void findSum(vector<int> arr,int n,int index,vector<int> &ds,vector<int> &ans)
    {
        if(index == n)
        {
            int count = 0;
            for(auto it : ds)
            {
                count+=it;
            }
            ans.push_back(count);
            return;
        }
        
        ds.push_back(arr[index]);
        findSum(arr,n,index+1,ds,ans);
        ds.pop_back();
        
        findSum(arr,n,index+1,ds,ans);
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        vector<int> ds;
        findSum(arr,N,0,ds,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
