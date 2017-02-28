#include <iostream>
#include <cmath>
#include <limits>

int main(){
  float xi=0., yi=0.,minx=0.,miny=0.;
  float minv= std::numeric_limits<float>::max();
  while( std::cin >> xi >> yi ) {
    std::cout << xi << "," << yi << std::endl;
    if ((pow(xi,2) + pow(yi,2)) < minv){
      minv = pow(xi,2) + pow(yi,2);
      minx = xi;
      miny = yi;
    }
  }
  std::cout << "The smallest vector is: (" << minx << "," << miny << ")" << std::endl;
  return 0;
}
