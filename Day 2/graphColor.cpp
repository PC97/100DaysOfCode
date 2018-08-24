bool isSafe(int g[][MAX],int color[],int v,int c)
{
    for(int i=0;i<v;i++)
    {
        if(g[v][i] && color[i]==c)
        return false;
    }
    return true;
}
bool aux(int g[][MAX],int V,int i,int m,int small[])
{
    if(i==V)return true;
    for(int m=1;m<=2;m++)
    {
        if(isSafe(g,small,V,m))
        {
            small[i]=m;
            if(aux(g,V,i+1,m,small))
                return true;
            small[i]=0;
        }
    }
    return false;
}
bool isBipartite(int G[][MAX],int V)
{
    bool visited[V];
    for(int i=0;i<V;i++)
    visited[i]=false;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            int small[V];
            for(int i=0;i<V;i++)
            small[i]=0;
            bool ans=aux(G,V,0,2,small);
            if(!ans)return false;
        }
    }
    return true;
}