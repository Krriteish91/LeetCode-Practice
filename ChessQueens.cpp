#include <bits/stdc++.h>
using namespace std;

bool isSafe(int r, int c, vector<string>& board){
    int i = r, j = c;
    if(board[i][j] == '*') return false;
    while(i>=0 && j>=0){
        if(board[i][j] == 'Q') return false;
        i--;
        j--;
    }
    i=r,j=c;

    while( j>=0){
        if(board[i][j] == 'Q') return false;
        j--;
    }
    i=r,j=c;

    while(i<8 && j>=0){
        if(board[i][j] == 'Q') return false;
        i++;
        j--;
    }
    return true;
}

static int ans = 0;
void solve(int col,vector<string>& board){
    if(col == 8){
        ans++;
        return;
    }

    for(int i=0 ; i<8 ; i++){
        if(board[i][col] == '.'){
            if(isSafe(i,col,board)){
                board[i][col] = 'Q';
                solve(col+1, board);
                board[i][col] = '.';
            }
        }
    }
}

int main(){
    int n = 8;
    vector<string> board(n);

    for(int i=0 ; i<n ; i++){
        string s;
        cin >> s;
        board[i] = s;
    }
    solve(0,board);
    cout << ans << endl;
    return 0;
}