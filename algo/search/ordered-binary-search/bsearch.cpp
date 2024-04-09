#include <iostream>

template <typename T>
struct Array{
  T* array;
  int length;
  
  Array(int len){
    length = len;
    array = new T[length];
  }

  ~Array(){
    delete array;
  }
};


Array<int>* range(int start, int end, int step){
  int array_length = (end - start)/step;
  Array<int>* my_array = new Array<int>(array_length);
  for(int idx=0; idx < array_length; idx++){
    my_array->array[idx] = start + idx * step;
  }
  return my_array;
}

template <typename T>
bool __bsearch_contains(T* array, int idx0, int idx1, T value){
  /* Recursive implementation of binary search with boolean return */
  
  if(idx0 == idx1){ // final check condition
    return array[idx0] == value;
  }
  
  int search_idx = (idx1 + idx0)/2; // this biases towards lower value
  if(array[search_idx] > value){
    return __bsearch_contains(array, idx0, search_idx, value);
  } else if(array[search_idx] < value){
    return __bsearch_contains(array, search_idx+1, idx1, value);
  }
  // in the "else" case array[search_idx] == value!
  return true;
}

void assert(bool condition, const char* err_msg){
  if(condition){
    return;
  } else{
    std::cerr << err_msg << std::endl;
    throw;
  }
}

template <typename T>
bool bsearch_contains(Array<T>* array, T value){
  /* utility wrapper around __bsearch_contains */
  return __bsearch_contains(array->array, 0, array->length-1, value);
}


int main(){
  std::cout << "creating uniform range..." << std::endl;
  Array<int>* my_range = range(0, 100, 1);
  std::cout << "checking uniform range..." << std::endl;
  assert(bsearch_contains(my_range, 0), "0 should be contained!");
  assert(bsearch_contains(my_range, 10), "10 should be contained!");
  assert(bsearch_contains(my_range, 11), "11 should be contained!");
  assert(bsearch_contains(my_range, 99), "99 should be contained!");
  assert(! bsearch_contains(my_range, -1), "-1 should not be contained!");
  assert(! bsearch_contains(my_range, 100), "-1 should not be contained!");

  delete my_range;

  std::cout << "creating even range..." << std::endl;
  my_range = range(0, 100, 2); // this time only even numbers!
  std::cout << "checking even range..." << std::endl;
  assert(bsearch_contains(my_range, 0), "0 should be contained!");
  assert(bsearch_contains(my_range, 10), "10 should be contained!");
  assert(bsearch_contains(my_range, 82), "82 should be contained!");
  assert(bsearch_contains(my_range, 98), "98 should be contained!");
  assert(! bsearch_contains(my_range, 11), "11 should not be contained!");
  assert(! bsearch_contains(my_range, 99), "99 should not be contained!");
  assert(! bsearch_contains(my_range, -1), "-1 should not be contained!");
  assert(! bsearch_contains(my_range, 100), "-1 should not be contained!");
  delete my_range;

  return 0;
}
