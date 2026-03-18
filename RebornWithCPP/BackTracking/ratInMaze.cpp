#include<iostream>
#include<vector>

using namespace std;

bool checkValid(const vector<vector<int>> &maze, int i, int j, int goal, vector<vector<char>> &visited){
    if((i >= 0 && i <= goal) && (j >= 0 && j <= goal) && maze.at(i).at(j) != 0 && visited.at(i).at(j) != 'V'){
        return true;
    }
    return false;
}

void solve(vector<vector<int>> &maze, int i, int j, int goal, vector<vector<int>> &path, vector<vector<char>> &visited, vector<vector<vector<int>>> &ans){
    if(i != goal || j != goal){
        visited.at(i).at(j) = 'V';
        if(checkValid(maze, i + 1, j, goal, visited)){
            path.at(i + 1).at(j) = 1;
            solve(maze, i + 1, j, goal, path, visited, ans);
            path.at(i + 1).at(j) = 0;
        }
        if(checkValid(maze, i - 1, j, goal, visited)){
            path.at(i - 1).at(j) = 1;
            solve(maze, i - 1, j, goal, path, visited, ans);
            path.at(i - 1).at(j) = 0;
        }
        if(checkValid(maze, i, j + 1, goal, visited)){
            path.at(i).at(j + 1) = 1;
            solve(maze, i, j + 1, goal, path, visited, ans);
            path.at(i).at(j + 1) = 0;
        }
        if(checkValid(maze, i, j - 1, goal, visited)){
            path.at(i).at(j - 1) = 1;
            solve(maze, i, j - 1, goal, path, visited, ans);
            path.at(i).at(j - 1) = 0;
        }
        visited.at(i).at(j) = 'U';
        return;
    }
    ans.push_back(path);
    return;
}


void printPaths( const vector<vector<vector<int>>> &ans){
    cout<<"Possible path of rat in maze!"<<endl;
    for(vector<vector<int>> vec: ans){
        for(vector<int> arr: vec){
            for(int i: arr){
                printf("%2d", i);
            }
            putchar('\n');
        }
        putchar('\n');
    }
}

int main(){
    vector<vector<int>> maze = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {0, 0, 1, 1}
    };
    vector<vector<vector<int>>> ans;
    vector<vector<int>> path(maze.size(), vector<int>(maze.at(0).size(), 0));
    vector<vector<char>> visited(maze.size(), vector<char>(maze.at(0).size(), 'U'));
    if(maze.at(0).at(0) == 0){
        ans.push_back(path);
        printPaths(ans);
        return 0;
    }
    path.at(0).at(0) = 1;
    solve(maze, 0, 0, maze.size() - 1, path, visited, ans);
    printPaths(ans);
    return 0;
}