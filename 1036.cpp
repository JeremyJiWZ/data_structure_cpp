#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
struct Student{
    string name;
    char gender;
    string id;
    int grade;
};
bool hasGirl=0,hasBoy=0;
int N,maxGirl,minBoy,maxGirlGrade=-1,minBoyGrade=101;
Student stus[10000];
int main(){
    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>stus[i].name>>stus[i].gender>>stus[i].id>>stus[i].grade;
        if (stus[i].gender=='M'){
            hasBoy=1;
            if (stus[i].grade<minBoyGrade){
                minBoyGrade=stus[i].grade;
                minBoy=i;
            }
                
        }
        else {
            hasGirl =1;
            if(stus[i].grade>maxGirlGrade){
                maxGirlGrade=stus[i].grade;
                maxGirl=i;
            }
        }
    }
   
    if(hasGirl)
        cout<<stus[maxGirl].name<<' '<<stus[maxGirl].id<<endl;
    else
        cout<<"Absent"<<endl;
    if (hasBoy) {
        cout<<stus[minBoy].name<<' '<<stus[minBoy].id<<endl;
    }
    else cout<<"Absent"<<endl;
    if(!hasGirl||!hasBoy)
        cout<<"NA"<<endl;
    else
        cout<<stus[maxGirl].grade-stus[minBoy].grade<<endl;
    return 0;
}
