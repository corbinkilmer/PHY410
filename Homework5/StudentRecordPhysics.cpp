#include "StudentRecordPhysics.h"

StudentRecordPhysics::StudentRecordPhysics(){};
StudentRecordPhysics::~StudentRecordPhysics(){};

void StudentRecordPhysics::print(std::ostream & out) const{
  out << "Physics score: " << lastname_ << "," << firstname_
      << /*", score 0: " << scores_[0] << ", score 1: " << scores_[1]
	   << */", total: " << score() << std::endl;
}

bool StudentRecordPhysics::input( std::istream & in ) {
  std::string line, trash;
  std::getline( in, line, ',');
  lastname_ = line;
  std::getline( in, line, ',');
  firstname_ = line;
  std::getline( in, line, ',');
  scores_.push_back(1.6 * std::atof( line.c_str() ) );
  std::getline( in, line, ',');
  scores_.push_back(0.4 * std::atof( line.c_str() ) );
  if (line == "")
    return false;
  else{
    compute_score();
    return true;
  }
}