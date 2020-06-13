//
// Created by 张承元 on 2020/6/13.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 60

using namespace std;
int G[N][N];//城市距离邻接矩阵
int main()
{
    freopen("testin2.txt","w",stdout);
    srand(time(NULL));
    int n=12;
    cout<<n<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=i;j<n;++j)
        {
            if(i==j)G[i][j]=0;
            else G[i][j]=G[j][i]=rand()%16-1;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            printf("%-4d",G[i][j]);
        cout<<endl;
    }
}
