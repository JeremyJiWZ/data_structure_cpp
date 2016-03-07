#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int N,M;
map<string,vector<int> > titleMap;
map<string,vector<int> > authorMap;
map<string,vector<int> > keywordMap;
map<string,vector<int> > publisherMap;
map<int,vector<int> > yearMap;
vector<string> splitWords(string words);
void printIds(vector<int> ids);
int main(){
    int id,year;
    string title,keywords,author,publisher;
    scanf("%d",&N);
    for (int i=0;i<N;i++){
        scanf("%d",&id);
        getline(cin, title);
        getline(cin, title);
        getline(cin, author);
        getline(cin, keywords);
        getline(cin, publisher);
        scanf("%d",&year);
        vector<string> words=splitWords(keywords);
        titleMap[title].push_back(id);
        authorMap[author].push_back(id);
        for(int i=0;i<words.size();i++) keywordMap[words[i]].push_back(id);
        publisherMap[publisher].push_back(id);
        yearMap[year].push_back(id);
    }
    cin>>M;
    int cmd;
    string query;
    vector<int> ids;
    getline(cin, query);
    for(int i=0;i<M;i++)
    {
        getline(cin, query);
        cout<<query<<endl;
        cmd=query[0]-'0';
        query=query.substr(3,query.length());
        switch (cmd) {
            case 1:
                ids=titleMap[query];
                printIds(ids);
                break;
            case 2:
                ids=authorMap[query];
                printIds(ids);
                break;
            case 3:
                ids=keywordMap[query];
                printIds(ids);
                break;
            case 4:
                ids=publisherMap[query];
                printIds(ids);
                break;
            case 5:
                ids=yearMap[atoi(query.c_str())];
                printIds(ids);
                break;
            default:
                break;
        }
    }
    
    return 0;
}
vector<string> splitWords(string words){
    vector<string> result;
    string word;
    string::size_type pos1=0;
    int length=0;
    for (int i=0; i<words.length(); i++) {
        if(words[i]==' '){
            if(length!=0){
                result.push_back(words.substr(pos1,length));
                pos1=i+1;
                length=0;
            }
        }
        else{
            length++;
        }
    }
    if(words[words.length()-1]!=' ')
        result.push_back(words.substr(pos1,length));
    return result;
}
void printIds(vector<int> ids){
    sort(ids.begin(), ids.end());
    for (int i=0;i<ids.size();i++)
        cout<<ids[i]<<endl;
    if(ids.size()==0)
        cout<<"Not Found"<<endl;
}








