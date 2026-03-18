#include<iostream>
#include<vector>

using namespace std;

bool checkValid(int i, int j, vector<vector<char>> &board){
    int row = i, col = j - 1;

    while(col >= 0){
        if(board.at(i).at(col) == 'Q'){
            return false;
        }
        col--;
    }
    row = i - 1, col = j - 1;
    while(row >= 0 && col >= 0){
        if(board.at(row).at(col) == 'Q'){
            return false;
        }
        row--;
        col--;
    }
    row = i + 1, col = j - 1;
    while(row < board.size() && col >= 0){
        if(board.at(row).at(col) == 'Q'){
            return false;
        }
        row++;
        col--;
    }

    return true;
}

void solve(int col, vector<vector<char>> &board, vector<vector<char>> &path, vector<vector<vector<char>>> &ans){
    if(col < board.at(0).size()){
        for(int i = 0 ; i < board.size() ; i++){
            if(checkValid(i, col, path)){
                path.at(i).at(col) = 'Q';
                solve(col + 1, board, path, ans);
                path.at(i).at(col) = '.';
            }
        }
        return;
    }
    ans.push_back(path);
    return;
}

void printBoard(vector<vector<vector<char>>> ans){
    cout<<"Possible queens arrangement:-"<<endl<<endl;
    for(vector<vector<char>> vec: ans){
        for(vector<char> arr: vec){
            for(char ch: arr){
                printf("%2c", ch);
            }
            putchar('\n');
        }
        putchar('\n');
    }
}

int main(){

    vector<vector<char>> board(4, vector<char>(4, '.'));

    vector<vector<char>> path(board);
    vector<vector<vector<char>>> ans;

    solve(0, board, path, ans);
    printBoard(ans);
    return 0;
}