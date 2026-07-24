class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int> arr = colors;
        arr.insert(arr.end(),colors.begin(),colors.begin()+k-1);
        int n = arr.size();
        int i=0,j=0 ; 
        int ans = 0;
        while( i<n && j<n){
            j = i+1;
            if(arr[j] == arr[j-1]){
                i++;
            }
            else{
                while(j < n && arr[j] != arr[j-1] && (j-i+1) <= k){

                    if((j-i+1) == k){
                        ans++;
                        i++;
                    }
                        j++;
                }
                i=j;
            }
        }
        return ans;
    }
};