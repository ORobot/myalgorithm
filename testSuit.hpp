#include <iostream>

typedef void (*Funtype)(int data[], int);
bool judeTotrue(int data[], int n);

void test(Funtype fun) {
  int data[] = {7, 1, -1, 0, 3, 2, 9, -2, 5, 4, 6, 10, 8};
  int data_2[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int data_3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int n = 13;

  bool flag = true;
  fun(data, n);
  fun(data_2, n);
  fun(data_3, n);
  flag = judeTotrue(data, n);
  flag = judeTotrue(data_2, n);
  flag = judeTotrue(data_3, n);

  if(flag)
    std::cout << "done." << std::endl;
  else
    std::cout << "error." << std::endl;
}

bool judeTotrue(int data[], int n) {
  
  for(int i = 0; i < n-1; i++){
    if (data[i] > data[i+1]) {
      return false;
      break;
    }
  }

  return true;
}
