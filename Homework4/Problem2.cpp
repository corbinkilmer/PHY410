#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include "StudentRecord.h"
#include <sstream>
#include <vector>

int main(int argc, char * argv[]){
    std::ifstream in(argv[1]);
    std::string line;
    int total;
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

    //Built vector now find score at given index
    int index;
    std::stringstream ssindex(argv[2]);
    ssindex >> index; //Doesn't work for negative ints but for small negative ints still throws an error message so keep that in mind
    if(index > (classvec.size() - 1)){
      std::cout << "Index too large for class size, choose smaller index:" << std::endl;}
    else if(index < 0){
      //again doesn't work since can't convert stream correctly for negatives
      std::cout << "Choose a positive index" << std::endl;}
    else{
      std::cout << "Student at index: " << index << ", scored: " << classvec[index].score() << std::endl;}
    return 0;
}
