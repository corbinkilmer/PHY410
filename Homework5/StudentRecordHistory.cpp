#include "StudentRecordHistory.h"

StudentRecordHistory::StudentRecordHistory(){};
StudentRecordHistory::~StudentRecordHistory(){};

void StudentRecordHistory::print(std::ostream & out) const{
  out << "History score: " << lastname_ << "," << firstname_
      <</* ", score 0: " << scores_[0] << ", score 1: " << scores_[1]
      <<*/ ", total: " << score() << std::endl;
}

bool StudentRecordHistory::input( std::istream & in ) {
  double exam1, exam2;
  std::string line;
  std::getline( in, line, ',');
  lastname_ = line;
  std::getline( in, line, ',');
  firstname_ = line;
  std::getline( in, line, ',');
  exam1 = std::atof( line.c_str() );
  std::getline( in, line, ',');
  exam2 = std::atof( line.c_str() );
  if (exam1 > exam2){
    scores_.push_back(1.2 * exam1);
    scores_.push_back(0.8 * exam2);}
  else{
    scores_.push_back(0.8 * exam1);
    scores_.push_back(1.2 * exam2);}
  if (line == "")
    return false;
  else{
    compute_score();
    return true;
  }
}
