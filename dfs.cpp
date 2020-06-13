#include <iostream>
#include <vector>
#define N 20

using namespace std;

int G[N][N];//邻接矩阵，相邻城市的距离作为边的长度，不相邻则为-1
int is_marked[N];
int minS=-1;

void find(int k,int s,int n);
int sum(const int a[],int n);
void input(int n);

vector<int> tmp;
vector<int> res;
int main()
{
    freopen("testin2.txt","r",stdin);
    int n;
    cin>>n;
    input(n);

    tmp.push_back(0);
    is_marked[0]=1;
    find(0,0,n);
    res.push_back(0);
    cout<<minS<<endl;
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}
void find(int k,int s,int n)//默认起点为0
{
    if(sum(is_marked,n)==n && G[k][0]!=-1)
    {
        if(minS==-1){minS=s+G[k][0];res=tmp;}
        else
        {
            if(minS>s+G[k][0]){res=tmp;minS=s+G[k][0];}
        }
        return;
    }
    for(int i=1;i<n;++i)
    {
        if(i==k)continue;
        if(G[k][i]!=-1&&is_marked[i]==0)
        {
            tmp.push_back(i);
            is_marked[i]=1;
            find(i,s+G[k][i],n);
            tmp.pop_back();
            is_marked[i]=0;
        }
    }
}
int sum(const int a[],int n)
{
    int s=0;
    for(int i=0;i<n;++i)s+=a[i];
    return s;
}
void input(int n)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>G[i][j];
        }
    }
}