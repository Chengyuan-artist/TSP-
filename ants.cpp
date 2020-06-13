//
// Created by 张承元 on 2020/6/13.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define N 60
#define MAXN 1000
#define INF 0xfffff
#define Alpha 1
#define Beta 5
#define NC_max 500
#define Rou 0.5
#define Q 100

using namespace std;

struct ant
{
    int start=0;
    int posi=0;
    vector<int> path;
    int visited[N]={0};
};

double G[N][N];//城市距离邻接矩阵
double t[N][N];//信息素浓度邻接矩阵
struct ant ants[N];


void init(int n);

int main()
{
    freopen("testin2.txt","r",stdin);

    int n, m;
    cin >> n;
    m = m;
    init(n);

    srand(time(NULL));
    //随机将m个蚂蚁放在n个城市当中
    for (int i = 0; i < m; ++i) {
//        int pos=i;
        int pos = rand() % n;
        ants[m].path.push_back((pos));
        ants[m].visited[pos] = 1;
        ants[m].posi = pos;
        ants[m].start = pos;
    }

    struct ant Best;
    vector<double> lens;
    double min_len = INF;
    int NC = 0;
    while (NC < NC_max)
    {

        for (int i = 0; i < m; ++i)//对于每一只蚂蚁
        {
            for (int j = 1; j < n; ++j)//只需再选n-1次下次到达点
            {
                //计算到其余各可访问点的概率
                vector<double> prb;
                for (int k = 0; k < n; ++k)
                {
                    if (!ants[m].visited[k])
                    {
                        double res = pow(t[ants[m].posi][k], Alpha) * pow(1.0 / G[ants[m].posi][k], Beta);
                        prb.push_back(res);
                    } else prb.push_back(0);
                }

                int final = max_element(prb.begin(), prb.end()) - prb.begin();
                ants[m].path.push_back((final));
                ants[m].visited[final] = 1;
                ants[m].posi = final;
            }
            //最后回到起点
            ants[m].path.push_back((ants[m].start));
            ants[m].visited[ants[m].start] = 1;
            ants[m].posi = ants[m].start;

            //计算路径长度
            double length = 0;
            for (int j = 0; j < ants[m].path.size() - 1; ++j)
            {
                length += G[ants[m].path[j]][ants[m].path[j + 1]];
            }
            lens.push_back(length);
            if(length<min_len)
            {
                Best=ants[m];
                min_len=length;
            }

        }//一代模拟结束
//            cout << NC << " " << min_len << "  ";

        //更新信息素
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                t[i][j] = Rou * t[i][j];
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < ants[m].path.size() - 1; ++j)
            {
                t[ants[m].path[j]][ants[m].path[j + 1]] += Q / G[ants[m].path[j]][ants[m].path[j + 1]];
                t[ants[m].path[j + 1]][ants[m].path[j]] += Q / G[ants[m].path[j]][ants[m].path[j + 1]];
            }
            //将该只蚂蚁初始化
            memset(ants[m].visited, 0, sizeof(ants[m].visited));
            ants[m].path.clear();
            ants[m].path.push_back((ants[m].start));
            ants[m].visited[ants[m].start] = 1;
            ants[m].posi = ants[m].start;
        }


        NC++;
    }

    cout << min_len << endl;
    for(int i=0;i<Best.path.size();++i)
    {
        cout<<Best.path[i]<<" ";
    }
//    cout<<endl<<Best.path.size();
    return 0;
}

void init(int n)
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            cin>>G[i][j];
            if(G[i][j]==-1)G[i][j]=INF;
            t[i][j]=1;//初始化信息素浓度
        }
}
