class Solution {
public:
    vector<long long> segTree;
    vector<long long> lazy;
    void buildSegTree(int idx, int l ,int r, vector<int>& charShift){
        if(l==r){
            segTree[idx] = charShift[l];
            return;
        }

        int mid = l+(r-l)/2;
        buildSegTree(2*idx+1 , l, mid, charShift);
        buildSegTree(2*idx+2 , mid+1, r, charShift);

        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }
    void updateRange(int start, int end, int val, int i, int l, int r ){
        if(lazy[i] != 0){
            segTree[i] += (r-l+1)*lazy[i];
            if(l != r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }

        if(start > r || end < l) return;

        if(start <= l && end >= r){
            segTree[i] += (r-l+1)*val;
            if( l!=r){
                lazy[2*i+1] += val;
                lazy[2*i+2] += val;
            }
            return;
        }

        int mid = l+(r-l)/2;
        updateRange(start,end,val,2*i+1,l,mid);
        updateRange(start,end,val,2*i+2,mid+1,r);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
        
    }
    long long pointQuery(int node, int l, int r,int idx ){
        if(lazy[node] != 0){
            segTree[node] += (r-l+1)*lazy[node];
            if(l != r){
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if( l == r){
            return segTree[node];
        }
        int mid = l + (r-l)/2;

        if(idx <= mid){
            return pointQuery(2*node+1 , l, mid, idx);
        }
        return pointQuery(2*node+2,mid+1 ,r,idx);
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        int m = shifts.size();
        vector<int> charShift(n,0);
        segTree.assign(4*n,0);
        lazy.assign(4*n,0);

        buildSegTree(0,0,n-1,charShift);

        for(int i=0 ; i<m ; i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int val = shifts[i][2] == 0 ? -1 : 1;

            updateRange(start,end,val,0,0,n-1);
        }
        for(int i=0 ; i<n ; i++){
            charShift[i] = pointQuery(0,0,n-1,i);
        }

        for(int i=0 ; i<n ; i++){
            char ch = s[i];
            int idx = ch-'a';

            idx += charShift[i];
            if(idx < 0){
                idx %= 26;
                idx += 26;
                idx %= 26;
            }
            else if( idx > 25){
                idx %= 26;
            }
            s[i] = 'a'+idx;
        }

        return s;
    }
};