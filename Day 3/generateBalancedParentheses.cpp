void aux(vector<string> &v,int pos, int open, int close, int n, string &str)
{
    //static string str;
    if(close==n)
    {
        v.push_back(str);
        return;
    }
    else
    {
        if(open<n)
        {
            str[pos]='(';
            aux(v, pos+1, open+1, close, n, str);
        }
        if(open>close)
        {
            str[pos]=')';
            aux(v, pos+1, open, close+1, n, str);
        }
        
    }
}
vector<string> Solution::generateParenthesis(int n) {
    vector<string>v;
    string str(2*n,'.');
    aux(v,0,0,0,n,str);
    return v;
}