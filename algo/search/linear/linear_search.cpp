#include <iostream>
#include <random>

template <typename T>
int linear_search(T* array, T value, int array_len){
  for(int i = 0; i < array_len; i++){
    if(array[i] == value){
      return i;
    }
  }
  return -1;
}

int* zeros(const int length){
  int* array = new int[length];
  for(int i=0; i < length; i++){
    array[i] = 0;
  }
  return array;
}


int main(){
  const int len = 1000;
  const int n_repeats = 1000;
  std::default_random_engine generator;
  std::uniform_int_distribution<int> location_dist(0, len-1);
  int needle_value = 42;

  for(int i=0; i < n_repeats; i++){
    int* haystack = zeros(len);
    int needle_loc = location_dist(generator);
    haystack[needle_loc] = needle_value;

    int found_loc = linear_search(haystack, needle_value, len);
    if(found_loc != needle_loc){
      std::cerr << "Arg!" << std::endl;
      return 1;
    }
    delete[] haystack;
  }
  return 0;
}
