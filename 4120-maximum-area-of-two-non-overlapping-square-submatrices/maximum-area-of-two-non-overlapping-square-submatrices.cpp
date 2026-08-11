class Solution {
public:
    int findSquare(int x, int y ,vector<vector<int>>& mat,vector<vector<int>>& square ){
        if(x>= mat.size() || y>= mat[0].size()){
            return 0;
        }
        if(mat[x][y] == 0 ) return square[x][y] = 0;

        if(square[x][y] != -1) return square[x][y];

        int right= 1 + findSquare(x,y+1,mat,square);
        int down = 1 + findSquare(x+1 , y , mat, square);
        int diag = 1 + findSquare(x+1 , y+1 ,mat,square);

        return square[x][y] = min(right,min(down,diag));
    }

    bool isPossible(int k,vector<vector<int>>& square ){
        int cnt = 0;
        int m = square.size();
        int n = square[0].size();
        int row_min = INT_MAX;
        int row_max = -1;
        int col_min = INT_MAX;
        int col_max = -1;

        // O(m*n);
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ;j++){
                if(square[i][j] == k){
                    row_min = min(row_min,i);
                    row_max = max(row_max,i);
                    col_min = min(col_min,j);
                    col_max = max(col_max,j);
                }
            }
        }
        if(row_min != m && row_max != -1 && row_max-row_min >= k) return true;
        if(col_min != n && col_max != -1 && col_max-col_min >= k) return true;
        return false;
    }
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size() ; 

        vector<vector<int>> square(m, vector<int>(n,-1));

        int cnt_ones = 0;
        // O(m*n)
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(square[i][j] == -1){
                    findSquare(i,j,mat,square);
                }
                if(mat[i][j] == 1) cnt_ones++;
            }
        }

        if(cnt_ones < 2) return 0;

        int low = 1 ; 
        int high = min(m,n);

        int result = 0;

        while(low<=high){
            int mid = low+(high-low)/2 ;

            if(isPossible(mid,square)){
                result = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return result*result;

    }
};