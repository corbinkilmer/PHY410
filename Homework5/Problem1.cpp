#include "memory"
#include "StudentRecord.h"
#include "StudentRecordPhysics.h"
#include "StudentRecordLiterature.h"
#include "StudentRecordHistory.h"

int main(int argc, char* argv[]){
  std::ifstream in(argv[1]);
  std::string line, aline;
  std::vector<StudentRecordPhysics> phyvec;
  std::vector<StudentRecordLiterature> litvec;
  std::vector<StudentRecordHistory> histvec;
  double phytot=0.0, littot=0.0, histtot=0.0;
  while(std::getline(in, line, '\n')){
    std::stringstream sline(line);
    std::getline(sline, aline, ',');

    if(aline == "Physics"){
      StudentRecordPhysics a;
      a.input(sline);
      a.print();
      phyvec.push_back(a);
      phytot += a.score();
    }
    else if(aline == "Literature"){
      StudentRecordLiterature a;
      a.input(sline);
      a.print();
      litvec.push_back(a);
      littot += a.score();
    }
    else if(aline == "History"){
      StudentRecordHistory a;
      a.input(sline);
      a.print();
      histvec.push_back(a);
      histtot += a.score();
    }
    else{ std::cout << "Input in formatted properly, could not get class" <<std::endl;}

  }
  std::cout<< "The averages for Physics, Literature, and History are: " << phytot/phyvec.size() << ", " << littot/ litvec.size() << ", " << histtot/ histvec.size() << " respectively" << std::endl;

  return 0;
} //End of main()
