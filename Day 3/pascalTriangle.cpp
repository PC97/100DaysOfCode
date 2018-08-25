vector<vector<int> > Solution::solve(int a) {
    vector<vector<int> >v;
    for(int i=0;i<a;i++)
    {
        vector<int>small;
        for(int j=0;j<=i;j++)
        {
            if(i==j)small.push_back(1);
            else if(j==0)small.push_back(1);
            else
            {
                small.push_back(v[i-1][j]+v[i-1][j-1]);
            }
        }
        v.push_back(small);
    }
    return v;
}