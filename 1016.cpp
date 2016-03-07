#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

class Record{
public:
    string name;
    int month,day,hour,min;
    int onOrOff;
};

int Rate[24];
Record records[1000];
double computeCharge(const Record &a,const Record &b);
int cmp(const Record &a, const Record &b);
int computeMin(const Record &a,const Record &b);
double computeTimeAndCharge(const Record &a,const Record &b,int &time);
int main(){
    int N;
    for (int i=0; i<24; i++) {
        cin>>Rate[i];
    }
    cin>>N;
    string name,onOrOff;
    int month,day,hour,min;
    for(int i=0;i<N;i++){
        cin>>name;
        scanf("%d:%d:%d:%d",&month,&day,&hour,&min);
        cin>>onOrOff;
        records[i].name=name;
        records[i].month = month;
        records[i].day=day;
        records[i].hour=hour;
        records[i].min=min;
        if(onOrOff=="on-line") records[i].onOrOff =1;
        else records[i].onOrOff=0;
    }
    sort(records, records+N, cmp);
    int i=0;
    double totalCharge,thisCharge;
    int firstName=1;
    string thisName = records[0].name;
    while (i<N) {
        totalCharge=0;
        thisCharge=0;
        thisName=records[i].name;
        firstName=1;
        while (i<N-1&&records[i+1].name==thisName) {
            if(records[i].onOrOff&&!records[i+1].onOrOff){
                //                thisCharge=computeCharge(records[i], records[i+1])/100;
                int minute = computeMin(records[i],records[i+1]);
                thisCharge=computeTimeAndCharge(records[i], records[i+1], minute)/100;
                totalCharge+=thisCharge;
                if(firstName) printf("%s %02d\n",records[i].name.c_str(),records[i].month);
                firstName=0;
                printf("%02d:%02d:%02d ",records[i].day,records[i].hour,records[i].min);
                printf("%02d:%02d:%02d %d $%.2f\n",records[i+1].day,records[i+1].hour,records[i+1].min,minute,thisCharge);
                
            }
            i++;
        }
        if(totalCharge!=0) printf("Total amount: $%.2f\n",totalCharge);
        i++;
    }
    return 0;
}
int cmp(const Record &a,const Record &b){
    if(a.name < b.name)
        return 1;
    else if(a.name > b.name)
        return 0;
    else{
        int aTime = a.day*60*24+a.hour*60+a.min;
        int bTime = b.day*60*24+b.hour*60+b.min;
        return aTime<bTime;
    }
}
double computeCharge(const Record &a, const Record &b){
    int result=0;
    int aHour = a.hour;
    int aDay = a.day;
    int aMin = a.min;
    if(aDay<b.day||aHour<b.hour){
        result += (60-aMin)*Rate[aHour];
        aHour++;
        aMin=0;
    }
    while (aDay<b.day||(aDay==b.day&&aHour<=b.hour)) {
        if(aDay==b.day&&aHour==b.hour)
            result += Rate[aHour]*(b.min-aMin);
        else
            result += Rate[aHour]*60;
        aHour++;
        if(aHour>=24){
            aHour=0;
            aDay++;
        }
        //        cout<<result<<endl;
    }
    //    cout<<"+++++++++"<<endl;
    return result;
}
double computeTimeAndCharge(const Record &a,const Record &b,int &time)
{
    int aTime = 60 * 24 * a.day + 60 * a.hour + a.min;
    int bTime = 60 * 24 * b.day + 60 * b.hour + b.min;
    time = bTime - aTime;
    int i;
    double charge = 0.0;
    for(i = aTime;i<bTime;++i){
        charge += Rate[(i%(60 * 24))/60];
    }
    return charge;
}
int computeMin(const Record& a, const Record& b){
    return -a.day*60*24-a.hour*60-a.min+
    b.day*60*24+b.hour*60+b.min;
}