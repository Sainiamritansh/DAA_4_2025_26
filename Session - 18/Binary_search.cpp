#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int LowerBound(vector<int> arr, int target, int n)
{
    int low = 0;
    int high = n-1;
    
    int ans = -1;
    while(low<= high)
    {
        int mid = low + (high-low)/2;
        
        if(arr[mid] == target)
        {
            ans = mid;
            high = mid-1;
        }
        
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else 
            low = mid+1;
    }
    
    return ans;
}

int UpperBound(vector<int> arr, int target, int n)
{
    int low = 0;
    int high = n-1;
    
    int ans = -1;
    while(low<=high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == target)
        {
            ans = mid;
            low = mid+1;
        }
        
        else if(arr[mid] > target)
        {
            high = mid -1;
        }
        else
            low = mid+1;
    }
    return ans;
}

int main() {
    vector<int> arr = {0,1};
    vector<int> anotherarr = {1,1,1,2,3};
    sort(anotherarr.begin(), anotherarr.end());
    int target = 2;
    int ans = 0;
    int m = arr.size();
    int n = anotherarr.size();

    for(int i = 0; i<m; i++)
    {
        int val = target - arr[i];
        ans = ans + UpperBound(anotherarr, val, n) - LowerBound(anotherarr, val, n) + 1;
    }
    
    cout<<ans;
    return 0;
}
