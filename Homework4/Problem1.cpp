#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include "StudentRecord.h"
#include <sstream>
#include <vector>

double calculate_average(std::vector<StudentRecord>* input){
  double sum=0.0, average;
  int total;
  for(StudentRecord i : *input){
    sum = sum + i.score();
  }
  total = input->size();
  average = sum / total;
  return average;
}

int main(int argc, char * argv[]){
    std::ifstream in(argv[1]);
    std::string line;
    int total, index;
    double average, sum=0.0;
    std::vector<StudentRecord> classvec;
    //Getting each line then delimiting by commas once \n's are taken care of
    while(std::getline(in, line, '\n')){
    StudentRecord a;
    std::stringstream sline(line);
    //Building each student record then adding those to a class vector
    if(a.input(sline)){ //was getting errors thrown here so looks weird
      a.input(sline);   //but it works so whatever
      classvec.push_back(a);}
    else{break;}
    }

    std::vector<StudentRecord>* pclassvec = &classvec;
    //Initialize pointer to vector like hw problem requests
    average = calculate_average(pclassvec);
    std::cout << "The average score is:" << average << std::endl;
    return 0;
}
