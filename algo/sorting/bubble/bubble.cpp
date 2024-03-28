#include <iostream>
#include <vector>


void swap(std::vector<float> &array, int idx1, int idx2){
  float tmp = array[idx1];
  array[idx1] = array[idx2];
  array[idx2] = tmp;
}


void bubble_sort(std::vector<float> &array){
  /** 
   * Simple bubble sort algorithm
   *
   * The algorithm works by looping over the list with two pointers
   * The outer loop loops over every index from i: 0 to n-2
   * The inner loop loops over every index from j: i to n-1
   *
   * If the element at j is larger than the element at i, swap the elements
   *
   * array = [ v0 , v1 , v2 , v3 , ... vn-1 ]
   *            ^i   ^j
   *
   * Since the sorting algorithm uses two nested loops the algorithm is O(n^2)
   * More rigorously, the evaluation of the inner loop
   *
   * @array input vector of floats
   * @returns sorted array
   * */
  for(int i = 0; i < array.size() - 1; i++){
    for(int j=i+1; j < array.size(); j++){
      if(array[j] < array[i]){
        swap(array, i, j);
      }
    }
  }
}

void print_array(std::vector<float> vec){
  std::cout << "[";
  int i;
  for(i=0; i < vec.size(); i++){
    std::cout << vec[i];
    if(i < vec.size() - 1){
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}


int main(){
  std::vector<float> v1 = {0.1, -0.3, 5.6, 8.2, 1.3, 12, 1e9};
  std::vector<float> v2 = {0.1, 0.1, 2, 3.1, 0.5, -1e9, 1e9};
  std::vector<float> v3 = {1e8, 1e2, 1e9, -1e1, 1e-1};
  
  std::cout << "v1" << std::endl;
  std::cout << "unsorted: ";
  print_array(v1);
  bubble_sort(v1);
  std::cout << "sorted: ";
  print_array(v1);

  std::cout << "v2" << std::endl;
  std::cout << "unsorted: ";
  print_array(v2);
  bubble_sort(v2);
  std::cout << "sorted: ";
  print_array(v2);

  std::cout << "v3" << std::endl;
  std::cout << "unsorted: ";
  print_array(v3);
  bubble_sort(v3);
  std::cout << "sorted: ";
  print_array(v3);
  return 0;
}
