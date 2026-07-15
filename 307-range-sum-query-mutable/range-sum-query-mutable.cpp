class NumArray {
public:
    vector<int> segTree;
    int n ;
    void BuildSegTree(int l , int r, vector<int>& nums, int idx){
        if(l==r) {
            segTree[idx] = nums[l];
            return;
        }
        int mid = l + (r-l)/2 ;
        BuildSegTree(l,mid,nums,2*idx+1);
        BuildSegTree(mid+1,r,nums,2*idx+2);

        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];

    }
    void UpdateSegTree(int idx , int val, int i, int l, int r){
        if(l==r){
            segTree[i] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if(idx <= mid){
            UpdateSegTree(idx,val,2*i+1 ,l,mid);
        }
        else{
            UpdateSegTree(idx,val,2*i+2 ,mid+1,r);
        }
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    int query(int start, int end, int idx, int l, int r){
        if(start > r || end < l) return 0;

        if( l >= start && r<= end){
            return segTree[idx];
        }
        int mid = l+(r-l)/2;
        return query(start,end, 2*idx+1 , l ,mid) + query(start,end, 2*idx+2 , mid+1 ,r);
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.assign(4*nums.size(),0);
        BuildSegTree(0, nums.size()-1, nums, 0);
    }
    
    void update(int index, int val) {
        UpdateSegTree(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return query(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */