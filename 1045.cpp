#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    fstream file("fin.txt");
    // 读入数据
    int N, M, L; file >> N >> M;
    vector<int> fc(M+1);
    for(int i=1; i<=M; i++) file >> fc[i];
    file >> L; vector<int> stripe(L+1);
    for(int i=1; i<=L; i++) file >> stripe[i];
    
    // 动态规划处理
    vector<vector<int> > dp(M+1, vector<int>(L+1, 0));
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=L; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i][j-1]);
            if(stripe[j] == fc[i]) {
                dp[i][j]++;
            }
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    cout << dp[M][L] << endl;
    return 0;
}