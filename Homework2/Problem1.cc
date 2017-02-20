#include <iostream>

int main(){
  int x1, y1, x2, y2;
  std::cout << "Enter two points in the form (x1, y1, x2, y2):" << std::endl;
  std::cout << "x1:" << std::endl;
  std::cin >> x1;
  std::cout << "y1:" << std::endl;
  std::cin >> y1;
  std::cout << "x2:" << std::endl;
  std::cin >> x2;
  std::cout << "y2:" << std::endl;
  std::cin >> y2;
  if (x2 - x1 == 0){
    std::cout << "The slope is undefined!";
      }
  else {
  float midx = (x1 + x2)/2;
  float midy = (y1 + y2)/2;
  float m = (y2 - y1)/(x2 - x1);
  float b = y1 - (m * x1);
  float mperp = -1/m;
  float bperp = y1 - (mperp * x1);
  std::cout << "The midpoint of the segment is: (" << midx << "," << midy
	    << ")" << std::endl;
  std::cout << "The slope of the line is: " << m << std::endl;
  std::cout << "The y-intercept of the line is: " << b << std::endl;
  std::cout << "The equation of the line is y= " << m << "x + " << b
 << std::endl;
  std::cout << "The equation the the line perpendicular through (" << x1
	    << "," << y1 << ") is y= " << mperp << "x + " << bperp << std::endl;
  }
  return 0;
}
