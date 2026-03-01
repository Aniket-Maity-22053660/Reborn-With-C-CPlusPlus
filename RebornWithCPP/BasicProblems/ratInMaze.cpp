#include<iostream>
#include<vector>
#define x 4
#define y 4

using namespace std;

void ratInMaze(vector<vector<char>> &maze, int i, int j, int goal, vector<vector<char>> &ans, vector<vector<char>> &visited, vector<vector<vector<char>>> &res){
 
    if(i == goal && j == goal){
      ans[i][j] = '*';
      res.push_back(ans);
      return;
    }
    
    visited.at(i).at(j) = '1';
    if((i + 1 >= 0 && i + 1 <= goal) && (j >= 0 && j <= goal) && (visited.at(i + 1).at(j) != '1') && maze.at(i + 1).at(j) != 'O'){
    ans.at(i + 1).at(j) = '*';
    ratInMaze(maze, i + 1, j, goal, ans, visited, res);
    visited.at(i + 1).at(j) = '0';
    ans.at(i + 1).at(j) = 'O';
    }

    if((i - 1 >= 0 && i - 1 <= goal) && (j >= 0 && j <= goal) && (visited.at(i - 1).at(j) != '1') && maze.at(i - 1).at(j) != 'O'){
    ans.at(i - 1).at(j) = '*';
    ratInMaze(maze, i - 1, j, goal, ans, visited, res);
    visited.at(i - 1).at(j) = '0';
    ans.at(i - 1).at(j) = 'O';
    }

    if((i >= 0 && i <= goal) && (j - 1 >= 0 && j - 1 <= goal) && (visited.at(i).at(j - 1) != '1') && maze.at(i).at(j - 1) != 'O'){
    ans.at(i).at(j - 1) = '*';
    ratInMaze(maze, i, j - 1, goal, ans, visited, res);
    visited.at(i).at(j - 1) = '0';
    ans.at(i).at(j - 1) = 'O';
    }

    if((i >= 0 && i <= goal) && (j + 1 >= 0 && j + 1 <= goal) && (visited.at(i).at(j + 1) != '1') && maze.at(i).at(j + 1) != 'O'){
    ans.at(i).at(j + 1) = '*';
    ratInMaze(maze, i, j + 1, goal, ans, visited, res);
    visited.at(i).at(j + 1) = '0';
    ans.at(i).at(j + 1) = 'O';
    }
   
    visited[i][j] = '0';  
  return;
}

int main(){

  vector<vector<char>> maze = {
    {'*', '*', 'O', '*'},
    {'*', 'O', 'O', '*'},
    {'*', '*', '*', '*'},
    {'*', 'O', '*', '*'}
  };
  int start = 0, end = 3;
  vector<vector<char>> ans(4, vector<char>(4, 'O'));
  vector<vector<vector<char>>> res;
  vector<vector<char>> visited(4, vector<char>(4, '0'));
  //visited.at(0).at(0) = '1';
  ans.at(0).at(0) = '*';
  ratInMaze(maze, start, start, end, ans, visited, res);
  cout<<"Given maze:- "<<endl;
  for(int i = 0 ; i < maze.size() ; i++){
    for(char j: maze.at(i)){
      printf("%2c", j);
    }
    putchar('\n');
  }
  cout<<"Possible paths to reach in the destination:- "<<endl;
  for(vector<vector<char>> i: res){
    for(vector<char> j: i){
      for(char ch: j){
	if(1){
	  printf("%2c", ch);
	}
      }
      putchar('\n');
    }
    putchar('\n');
  }
  
  return 0;
}
