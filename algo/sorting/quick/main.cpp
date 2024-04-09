#include <iostream>
#include <stdlib.h>

template <typename T>
void array_print(T array[], int len){
  std::cout << "[";
  for(int i=0; i<len; i++){
    std::cout << array[i] << ", ";
  }
  std::cout << "]" << std::endl;;
}

/**
 * Swap two values in an array
 */
template <typename T>
void swap(T array[], int idx1, int idx2){
  T tmp = array[idx1];
  array[idx1] = array[idx2];
  array[idx2] = tmp;
}

/**
 * Quicksort partition
 * Uses random pivot selection
 */
template <typename T>
int partition(T array[], int lo, int hi){
  int distance = hi - lo;
  if(distance <= 0){
    // array is of size 1, nothing to do
    return hi;
  }
  else if(distance == 1 && array[hi] < array[lo]){
    // array is of size 2, swap only if hi < lo
    swap(array, hi, lo);
  }
  
  // choose a pivot at random
  int pivot_idx = rand() % distance + lo;
  std::cout << "pivot: " << array[pivot_idx] << std::endl;
  // move pivot to the end of the array
  swap(array, pivot_idx, hi); // pivot_value == array[hi];
  std::cout << "pivot: " << array[hi] << std::endl;
  
  int lo_head_idx = lo;
  int hi_head_idx = lo;
  while(hi_head_idx < hi){
    if(array[hi_head_idx] < array[hi]){
      swap(array, lo_head_idx, hi_head_idx);
      lo_head_idx += 1;
    }
    hi_head_idx += 1;
  }
  
  // move pivot back into place
  swap(array, lo_head_idx, hi);
  std::cout << "pivot: " << array[lo_head_idx] << std::endl;
  return lo_head_idx;
}

/**
 * Recursive implementation of quicksort
 */
template <typename T>
void _quicksort(T array[], int lo, int hi){
  std::cout << lo << " " << hi << std::endl;
  if(lo > hi){return;}
  int pivot = partition(array, lo, hi);
  _quicksort(array, lo, pivot-1);
  _quicksort(array, pivot+1, hi);
}

/**
 * Utility wrapper around _quicksort
 */
template <typename T>
void quicksort(T array[], int length){
  _quicksort(array, 0, length - 1);
}


template <typename T>
bool is_sorted(T array[], int length){
  bool sorted = true;
  for(int i=0; i<length-1; i++){
    if(array[i+1] < array[i]){
      sorted = false;
      break;
    }
  }
  return sorted;
}

int main(){
  int array[] = {3, 2, 1, 5, -1, 100, -1000, 8, 2, 4};
  quicksort(array, 10);
  array_print(array, 10);
  std::cout << is_sorted(array, 10) << std::endl; 
  return 0;
}
