#ifndef StudentRecord_h
#define StudentRecord_h

#include <iostream>
#include <string>
#include <cstdlib>

class StudentRecord {
 public:
  StudentRecord( std::string ilast="", std::string ifirst="", double iscore=0.0);
  ~StudentRecord();

  double score() const;

  void print() const;

  bool input(std::istream &in);
  //  StudentRecord operator+(StudentRecord const & right) const;

 private:
  std::string lastname_;
  std::string firstname_;
  double score_;
};

#endif
