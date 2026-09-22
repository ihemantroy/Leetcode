class Solution {
public:
    int n,k;
    vector<int> p,a;
    vector<array<int,25>> c;
    void mg(int nd){
        int l=2*nd,r=2*nd+1;
        p[nd]=p[l]*p[r]%k;
        for(int i=0;i<k;i++){
            int t=i*p[l]%k;
            for(int j=0;j<k;j++) c[nd][i*k+j]=c[l][i*k+j]+c[r][t*k+j];
        }
    }
    void leaf(int nd,int v){
        for(int i=0;i<k*k;i++) c[nd][i]=0;
        p[nd]=v%k;
        for(int i=0;i<k;i++) c[nd][i*k+i*p[nd]%k]=1;
    }
    void bld(int nd,int l,int r){
        if(l==r){ leaf(nd,a[l]); return; }
        int m=(l+r)/2;
        bld(2*nd,l,m); bld(2*nd+1,m+1,r);
        mg(nd);
    }
    void upd(int nd,int l,int r,int i,int v){
        if(l==r){ leaf(nd,v); return; }
        int m=(l+r)/2;
        if(i<=m) upd(2*nd,l,m,i,v); else upd(2*nd+1,m+1,r,i,v);
        mg(nd);
    }
    void qry(int nd,int l,int r,int ql,int &st,vector<int>& res){
        if(r<ql) return;
        if(l>=ql){
            for(int j=0;j<k;j++) res[j]+=c[nd][st*k+j];
            st=st*p[nd]%k;
            return;
        }
        int m=(l+r)/2;
        qry(2*nd,l,m,ql,st,res);
        qry(2*nd+1,m+1,r,ql,st,res);
    }
    vector<int> resultArray(vector<int>& nums, int kk, vector<vector<int>>& queries) {
        n=nums.size(); k=kk; a=nums;
        p.assign(4*n,0); c.assign(4*n,{});
        bld(1,0,n-1);
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int id=queries[i][0],v=queries[i][1],s=queries[i][2],x=queries[i][3];
            upd(1,0,n-1,id,v);
            int st=1%k;
            vector<int> res(k,0);
            qry(1,0,n-1,s,st,res);
            ans.push_back(res[x]);
        }
        return ans;
    }
};