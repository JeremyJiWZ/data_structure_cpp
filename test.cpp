#include <cstdio>

using namespace std;
const int INFI = 0x7FFFFFFF;
struct node
{
    int length;
    int cost;
    int path;
    bool know;
    bool operator < (const node &b)const
    {
        if(length < b.length)
            return true;
        if(length == b.length && cost < b.cost)
            return true;
        return false;
    }
};
node city[500];
int N,M,S,D;
int map[500][500];
int cost[500][500];

int findmin()
{
    node min;
    int mincity = -1;
    min.cost = min.length = INFI;
    for(int i = 0 ; i < N ; i++)
    {
        if(!city[i].know && city[i] < min)
        {
            min.cost = city[i].cost;
            min.length = city[i].length;
            mincity = i;
        }
    }
    return mincity;
}

void printpath(int path)
{
    if( path != S)
        printpath(city[path].path);
    printf("%d ",path);
}

int main()
{
    int i;
    scanf("%d%d%d%d",&N,&M,&S,&D);
    for(i = 0 ; i< N ; i++)
        for(int j = 0; j < N ; j++)
        {
            map[i][j] = cost[i][j] = -1;
        }
    while(M--)
    {
        int ca,cb;
        scanf("%d%d",&ca,&cb);
        scanf("%d%d",&map[ca][cb],&cost[ca][cb]);
        map[cb][ca] = map[ca][cb];
        cost[cb][ca] = cost[ca][cb];
    }
    for( i = 0 ; i < N ; i++)
    {
        if( i != S)
            city[i].cost = city[i].length = INFI;
        else
            city[i].cost = city[i].length = 0;
        city[i].know = false;
        city[i].path = -1;
    }
    while(true)
    {
        int w = findmin();
        if( w == D || w == -1)
            break;
        city[w].know = true;
        for( i = 0; i < N ; i++)
        {
            if( map[w][i] != -1 )
            {
                if(!city[i].know)
                {
                    if(city[i].length > city[w].length + map[w][i])
                    {
                        city[i].length = city[w].length + map[w][i];
                        city[i].cost = city[w].cost + cost[w][i];
                        city[i].path = w;
                    }
                    else if( city[i].length == city[w].length + map[w][i])
                    {
                        if(city[i].cost > city[w].cost + cost[w][i])
                        {
                            city[i].cost = city[w].cost + cost[w][i];
                            city[i].path = w;
                        }
                    }
                }
            }
        }
    }
    printpath(D);
    printf("%d %d",city[D].length,city[D].cost);
}