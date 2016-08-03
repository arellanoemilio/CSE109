#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_SIZE=100, MAX_TESTS=10; //global constants, visible from
				      //main() and all other functions

void getData(int &students,int &tests, double weight[],string id[],int grades[][MAX_TESTS]);
void computeAverage(int students, int tests, double weight[],int grades[][MAX_TESTS],double studentAvg[],double testAvg[],double &courseAvg);
void display(int students, int tests, double weight[],string id[],int grades[][MAX_TESTS],double studentAvg[],double testAvg[],double courseAvg);

int main(){
  int nStudents,nTests, grades[MAX_SIZE][MAX_TESTS];
  string id[MAX_SIZE];
  double weight[MAX_TESTS],studentAverage[MAX_SIZE],testAverage[MAX_TESTS],courseAverage;
  getData(nStudents,nTests,weight,id,grades);
  computeAverage(nStudents,nTests,weight,grades,studentAverage,testAverage,courseAverage);
  display(nStudents,nTests,weight,id,grades,studentAverage,testAverage,courseAverage);
}

void getData(int &students,int &tests, double weight[],string id[],int grades[][MAX_TESTS]){
  ifstream input;
  students = tests =0;
  int testsEntered  = 0;
  input.open("input2.data");
  if(!input.good()){
    cout<<"Error: Could not read input2.data"<<endl;
    exit(10);
  }
  input >> tests;
  if(tests > MAX_TESTS){
    cout << "Error: there are too many tests per id in this file, there can only be " << MAX_TESTS << " tests per ID"<<endl;
    exit(1);
  }
  while(input.good() && ++testsEntered <= tests)
    input >> weight[testsEntered-1];
  if(!input.good()){
    cout << "Error: Number of specified tests did not concur with number of weigthed tests" << endl;
    exit(1);
  }
  input >> id[students];
  while(input.good() && students < MAX_SIZE-1 ){
    for(int i = 0; i < tests; i++)
      input >>  grades[students][i];
    students++;
    input >> id[students];
  }
  input.close();
}

void computeAverage(int students, int tests, double weight[],int grades[][MAX_TESTS],double studentAvg[],double testAvg[],double &courseAvg){
  double weightTotal = courseAvg = 0;
  for(int i = 0; i < tests; i++)
    weightTotal += weight[i];
  for(int s = 0; s < students; s++){
    studentAvg[s] = 0;
    for(int t = 0; t < tests; t++)
      studentAvg [s] += (weight[t]*grades[s][t]);
    studentAvg[s] = studentAvg[s]/weightTotal;
  }
  for(int a = 0; a < tests;a++){
    testAvg[a] = 0;
    for(int s = 0; s < students; s++)
      testAvg[a] += grades[s][a];
    testAvg[a] = testAvg[a]/students;
  }
  for(int s = 0; s < students;s++)
    courseAvg += studentAvg[s];
  courseAvg = courseAvg/students;
}

void display(int students, int tests, double weight[],string id[],int grades[][MAX_TESTS],double studentAvg[],double testAvg[],double courseAvg){
  ofstream output;
  output.open("output2.data");
  output.precision(4);
  if(!output.good()){
    cout << "Error:output2.data could not be open";
    exit(1);
  }
  output << "Course Grades \n\t\t Weights\n\t\t";
  for(int t = 0;t < tests;t++)
    output << weight[t] <<"\t";
  output << "Average\n---------------------------------------------------" <<endl;
  for(int s = 0; s < students;s++){
    output << id[s]<<"\t\t";
    for(int t = 0;t < tests; t++)
      output << grades[s][t] << "\t";
    output << studentAvg[s] << endl;
  }
  output << "\n---------------------------------------------------\nAvereage\t";
  for (int t = 0; t < tests;t++)
    output << testAvg[t] << "\t";
  output << courseAvg;
}
