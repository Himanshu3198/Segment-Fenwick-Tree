class NumArray {
public:
    vector<int>seg;
    int n;
    void build(int idx,int low,int high,vector<int>&nums){
        
        if(low==high){
            seg[idx]=nums[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*idx+1,low,mid,nums);
        build(2*idx+2,mid+1,high,nums);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    
    int query(int idx,int l,int r,int low,int high){
        if(low>=l && high<=r)
            return seg[idx];
        
        if(high<l || low>r) return 0;
            
        int mid=(low+high)/2;
        int left=query(2*idx+1,l,r,low,mid);
        int right=query(2*idx+2,l,r,mid+1,high);
        return left+right;
    }
    void updateUntill(int ind, int low,int high,int idx,int val){
        
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid=(low+high)/2;
        if(idx<=mid) updateUntill(2*ind+1,low,mid,idx,val);
        else updateUntill(2*ind+2,mid+1,high,idx,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }
    
    NumArray(vector<int>& nums) {
        
        n=nums.size();
        if(n<=0) return;
        seg.resize(4*n);
        build(0,0,n-1,nums);
    }
    
    
    void update(int index, int val) {
        
        updateUntill(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        
        return query(0,left,right,0,n-1);
        
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
