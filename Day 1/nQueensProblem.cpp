#define n 100
bool isSafe(bool a[][n],int r,int m,int c)//c means current column
{
    //cout<<"aa";
    int i=r,j=c;
    while(i-- >=0)
    { //cout<<"one";
        if(a[i][j])return false;
    }
    i=r;j=c;//left diagonal
    while((i-- >=0) && (j-- >=0))
        if(a[i][j])return false;
    i=r;j=c;
    while((i-- >=0) && (j++ < m))
        if(a[i][j])return false;
    return true;
}
bool NQueens(bool a[][n],vector<vector<string> > &v,int r,int m)
{
    if(r==m)
    {
        vector<string>aux;
        for(int i=0;i<m;i++)
        {
            string s;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==true)
                s=s+'Q';
                else
                s=s+'.';
            }
        aux.push_back(s);
        }
        v.push_back(aux);
        return false;
    }
    for(int i=0;i<m;i++)
    {
        if(isSafe(a,r,m,i))
        {
            a[r][i]=true;//Anticipating that future gives us solution
            if(NQueens(a,v,r+1,m))
                return true;
            a[r][i]=false;//Future hasn't given solution , So Backtrack
        }
    }
    return false;
}
vector<vector<string> > Solution::solveNQueens(int a) {
    vector<vector<string> >v; 
    bool arr[a][n];
    for(int i=0;i<a;i++)
    for(int j=0;j<n;j++)
    arr[i][j]=false;
    NQueens(arr,v,0,a);
    return v;
}
