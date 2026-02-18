#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Jobs{
  string name;
  int profit;
  int deadline;
};

int findMaxDeadline(vector<Jobs> vec){
  int max = 0;
  for(int i = 0 ; i < vec.size() ; i++){
    if(vec.at(i).deadline > max){
      max = vec.at(i).deadline;
    }
  }
  return max;
}
void showTimeLine(vector<string> vec){
  cout<<"Displaying the timeline sequence: ";
  vector<string>::iterator itr;
  for(itr = vec.begin() ; itr != vec.end() ; itr++){
    cout<<*itr;
    if(next(itr) != vec.end()){
      cout<<"->";
    }
  }
  putchar('\n');
}
void displayJobs(vector<Jobs> vec){
  cout<<"Displaying jobs arranged by profits in a non-decreasing order:-"<<endl;
  for(int i = 0 ; i < vec.size() ; i++){
    cout<<vec.at(i).name<<" -> "<<"profit = "<<vec.at(i).profit<<" -> "<<"deadline = "<<vec.at(i).deadline<<endl;
  }
  putchar('\n');
}
  vector<Jobs> merge(vector<Jobs> vec1, vector<Jobs> vec2){
  int i = 0 , j = 0;
  vector<Jobs> merged(vec1.size() + vec2.size());
  int k = 0;
  while(i < vec1.size() && j < vec2.size()){
    if(vec1.at(i).profit > vec2.at(j).profit){
      merged.at(k++) = vec1.at(i++);
    }else{
      merged.at(k++) = vec2.at(j++);
    }
  }

  while(i < vec1.size()){
    merged.at(k++) = vec1.at(i++);
  }
  while(j < vec2.size()){
    merged.at(k++) = vec2.at(j++);
  }
  return merged;
}
  vector<Jobs> mergeSort(vector<Jobs> vec, int i, int j){

  if(i < j){
    int mid = i + (j - i) / 2;
    vector<Jobs> vec1 = mergeSort(vec, i, mid);
    vector<Jobs> vec2 = mergeSort(vec, mid+1, j);
    return merge(vec1, vec2);
  }else{
    return {{vec.at(i).name, vec.at(i).profit, vec.at(i).deadline}};
  }
}

vector<string> buildTimeLine(int max, vector<Jobs> sortedVec){
  vector<string> timeLine(max, "NIL");
  for(int i = 0 ; i < sortedVec.size() ; i++){
    string name = sortedVec.at(i).name;
    for(int j = sortedVec.at(i).deadline - 1 ; j >= 0 ; j--){
      if(timeLine.at(j) == "NIL"){
	timeLine.at(j) = name;
	break;
      }
    }
  }
  return timeLine;
}

int main(){

  int num;
  cout<<"Enter the number of jobs you want to allocate: ";
  cin>>num;
  vector<Jobs> vec(num);
  for(int i = 0 ; i < vec.size() ; i++){
    cout<<"Enter the profit of the "<<(i+1)<<"th job"<<":";
    cin>>vec.at(i).profit;
    cout<<"Enter the deadline of the "<<(i+1)<<"th job"<<":";
    cin>>vec.at(i).deadline;
    vec.at(i).name = "J"+to_string(i+1);
  }
  vector<Jobs> sortedVec = mergeSort(vec, 0, vec.size() - 1);
  displayJobs(sortedVec);
  int max = findMaxDeadline(sortedVec);
  vector<string> timeline = buildTimeLine(max, sortedVec);
  
  showTimeLine(timeline);
  
  return 0;
}
