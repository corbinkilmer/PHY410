#include "StudentRecord.h"

StudentRecord::StudentRecord(std::string ilast, std::string ifirst, double iscore){lastname_ = ilast; firstname_ = ifirst; score_ = iscore;}

StudentRecord::~StudentRecord(){}

double StudentRecord::score() const {return score_;}

void StudentRecord::print() const {
  std::cout << "Last:"<< lastname_ << "First" << firstname_ << "Score" << score_ << std::endl;}

bool StudentRecord::input(std::istream &in){
  std::string line;
  std::getline(in, line, ',');
  lastname_= line;
  std::getline(in, line, ',');
  firstname_= line;
  score_= std::atof( line.c_str());
  if( line== ""){return false;}
  else{
    return true;}
}
/*StudentRecord StudentRecord::operator+(StudentRecord const & right) const {
  StudentRecord retval(last_, first_, score_ + right.score_);
  return retval;*/


