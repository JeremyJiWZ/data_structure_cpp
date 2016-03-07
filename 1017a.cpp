#include<set>
#include<map>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
#define open 28800
#define close 61200
struct custom{
    int come,cost,finish;
};
void swap(custom &a,custom &b){
    custom c=a;
    a=b;
    b=c;
}
void BuildHeap(custom *cc,int m){
    int fa,child=m-1,i;
    for(i=(child-1)/2;i>=0;i--){
        child=i*2+1;//左儿子
        for(fa=i;child<m;child=fa*2+1){
            if(child+1<m&&cc[child].finish>cc[child+1].finish){
                child++;
            }
            if(cc[child].finish<cc[fa].finish){
                swap(cc[fa],cc[child]);
                fa=child;
            }
            else{
                break;
            }
        }
    }
}
void Insertion(custom *cc,custom cur,int &m){
    int i=m++;
    for(;i>0&&cc[(i-1)/2].finish>cur.finish;i=(i-1)/2){
        cc[i]=cc[(i-1)/2];
    }
    cc[i]=cur;
}
custom DeleteMin(custom *cc,int &m){
    custom cur=cc[0];
    custom temp=cc[--m];
    int fa,child=1;
    for(fa=0;child<m;child=fa*2+1){
        if(child<m-1&&cc[child].finish>cc[child+1].finish){
            child++;
        }
        if(cc[child].finish<temp.finish){
            cc[fa]=cc[child];
            fa=child;//保证fa指向当前要比较的节点
        }
        else{
            break;
        }
    }
    cc[fa]=temp;
    return cur;
}
bool cmp(custom a,custom b){
    return a.come<b.come;
}
int main(){
    //freopen("D:\\input.txt","r",stdin);
    int n,nn;
    int i,j;
    scanf("%d %d",&n,&nn);
    
    //cout<<n<<" "<<nn<<endl;
    
    custom *c=new custom[n+5],*cc=new custom[nn+5];
    int h,m,s,cost;
    for(i=0;i<n;i++){
        scanf("%d:%d:%d %d",&h,&m,&s,&cost);
        c[i].come=h*3600+m*60+s;
        c[i].cost=cost*60;
    }
    int totaltime=0,count=0;
    sort(c,c+n,cmp);
    
    
    j=1;
    for(i=0;i<nn&&i<n;i++){
        if(c[i].come<open){
            totaltime+=open-c[i].come;
            c[i].come=open;
        }
        if(c[i].come>close){
            break;
        }
        c[i].finish=c[i].come+c[i].cost;
        cc[i]=c[i];
        count++;
    }
    
    //cout<<count<<endl;
    
    if(count<nn){//人数不够
        printf("%.1lf\n",totaltime*1.0/60/count);//不经意间看到，让我找了将近一小时！！
        return 0;
    }
    
    BuildHeap(cc,count);//建堆
    
    
    custom cur;
    for(;i<n;i++){
        cur=DeleteMin(cc,nn);
        if(c[i].come<=close){//cur.finish<=close&&
            if(cur.finish<c[i].come){
                c[i].finish=c[i].come+c[i].cost;
            }
            else{
                c[i].finish=cur.finish+c[i].cost;
                totaltime+=cur.finish-c[i].come;
            }
            cur=c[i];
            Insertion(cc,cur,nn);
            count++;
        }
        else{
            break;
        }
    }
    //    for(int j=0;j<n;j++)
    //        cout<<c[j].finish-c[j].come<<endl;
    cout<<count<<endl;
    cout<<totaltime<<endl;
    printf("%.1lf\n",totaltime*1.0/count/60);
    return 0;
}