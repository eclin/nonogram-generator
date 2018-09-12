#include <iostream>
#include "generator.h"

using namespace std;

int main(){
  int height;
  int width;
  cout << "Please enter the width" << endl;
  cin >> width;
  cout << "Please enter the height" << endl;
  cin >> height;
  generate(width,height);
}
