void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void aux(vector<vector<int> > &v, vector<int> &arr, int l, int r)
{
    if(l==r)v.push_back(arr);
    else
    {
        for(int i=l;i<r;i++)    
        {
            swap(arr[l],arr[i]);
            aux(v,arr,l+1,r);
            swap(arr[l],arr[i]);
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &a) {
    vector<vector<int> >v;
    sort(a.begin(),a.end());
    int n=a.size();
    aux(v, a, 0, n);//sub-array
    return v;
}