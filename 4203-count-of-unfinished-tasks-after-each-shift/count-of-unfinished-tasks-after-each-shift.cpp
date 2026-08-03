class Solution {
public:

    int ub (vector<long long>&prefix , long long target){

        int task_done = upper_bound(prefix.begin(),prefix.end(),target) - prefix.begin();
        return task_done; 
    }
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();
        int m = shifts.size();

        vector<int> ans(m);
        vector<long long> prefix(n,0);
        for(int i=0 ; i<n ; i++){
            prefix[i] = (i==0 ? 0 : prefix[i-1]) + tasks[i];
        }

        long long sh = 0;
        for(int i=0 ; i<m ; i++){
            sh += shifts[i];

            ans[i] = n-ub(prefix, sh);

            if(ans[i] == 0){
                sh = 0;
            }
        }
        return ans;
    }
};