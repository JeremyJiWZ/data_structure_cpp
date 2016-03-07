#include <iostream>
#include <string>
using namespace std;
int N;
string str1,str2;
int countExp(string str){
   int res;
   if (str.size()==1&&str[0]=='0') return 0;
   if (str[0]=='0') {// <1
      int i;
      for (i=2; i<str.length(); i++) {
         if (str[i]=='0') res--;
         else break;
      }
      if (i==str.length()) {
         res=0;
      }
   }
   else{// >1
      for (int i=0; i<str.length(); i++) {
         if (str[i]!='.') res++;
         else break;
      }
   }
   return res;
}
void printNum(string num,int exp){
   int d;
   if(exp>0) d=0;
   else d=2-exp;
   cout<<"0.";
   for (int i=0; i<N&&i<num.length(); i++) {
      if (num[i]!='.') {
         cout<<num[i];
      }
   }
   cout<<"*10^"<<exp;
}
bool isEqual(string num1,string num2,int exp){
   if (exp>0) {
      int i;
      for (i=0; i<N&&i<num1.length()&&i<num2.length(); i++) {
         if (num1[i]!=num2[i]) {
            return false;
         }
      }
      if (i<N) return false;
   }
   else{
      int i;
      for (i=2-exp; i<N&&i<num1.length()&&i<num2.length(); i++) {
         if (num2[i]!=num2[i]) {
            return false;
         }
      }
      if (i<N) {
         return false;
      }
   }
   return true;
}
int main(){
   cin>>N>>str1>>str2;
   int exp1,exp2;
   exp1=countExp(str1);
   exp2=countExp(str2);
   if (exp1!=exp2) {
      cout<<"NO ";
      printNum(str1, exp1);
      cout<<' ';
      printNum(str2, exp2);
      cout<<endl;
   }
   else{
      if (isEqual(str1, str2, exp1)) {
         cout<<"YES ";
         printNum(str1, exp1);
         cout<<endl;
      }
      else{
         cout<<"NO ";
         printNum(str1, exp1);
         cout<<' ';
         printNum(str2, exp2);
         cout<<endl;
      }
   }
   return 0;
}