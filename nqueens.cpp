#include<bits/stdc++.h>
using namespace std;
void printboard(vector<vector<char>>&board, int n) {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl; cout<<endl;
}
bool validate(vector<pair<int,int>>&queens, vector<int>&rows, vector<int>&cols, int x, int y){
    for(int i=0; i<rows.size(); i++){
        if(rows[i] == x){
            return false;
        }
    }
    for(int j=0; j<cols.size(); j++){
        if(cols[j] == y){
            return false;
        }
    }
    for(int i=0; i<queens.size(); i++){
        int dif1 = abs(x-queens[i].first);
        int dif2 = abs(y-queens[i].second);
        if(dif1 == dif2){
            return false;
        }
    }
    return true;
}
void findstates(int n , vector<vector<char>>&board, int x, vector<pair<int,int>>queens, vector<int>&rows, vector<int>&col){
    for(int j=0; j<n; j++){
        if(validate(queens, rows, col, x, j)){
            board[x][j] = 'Q'; queens.push_back({x,j}); rows.push_back(x); col.push_back(j);
            if(x == (n-1)){
                printboard(board, n);
            }
            else{
                findstates(n,board,x+1,queens,rows,col);
            }
            board[x][j] = '.'; queens.pop_back(); rows.pop_back(); col.pop_back();
        }
    }
    return;
}

int main() {
    int n;
    cin>>n;
    vector<vector<char>>board(n , vector<char>(n , '.'));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = '.';
        }
    }
    vector<pair<int,int>>queens; vector<int>row,col;
    findstates(n , board, 0, queens,row,col);
    return 0;
}