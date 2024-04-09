#include <iostream>
#include <string>
#include <vector>
#include <random>

#include <math.h>
#include <stdio.h>


std::vector<bool>* new_building(int length, int thresh){
  std::vector<bool>* vec = new std::vector<bool>;
  for(int i=0; i<length; i++){
    vec->push_back(i > thresh);
  }
  return vec;
}

int __linear_search(std::vector<bool> building, int lo, int hi){
  /* if this function is called, we know the lo value was false
   * and the hi value was true
   */
  int i=lo;
  for(i=lo; i < hi; i++){
    if(building[i]) return i;
  }
  // if no true is found, then we return the sentinal value -1
  return -1;
}


int sqrt_crystall_ball_breaks_at(std::vector<bool> building){
  /* find threshold in O(sqrt N) */
  int size = building.size();
  int step = std::sqrt(size);
  int idx = 0;
  while(idx < size){
    if(building[idx]){
      break;
    }; // if true, break
    idx += step;
  }
  return __linear_search(building, std::max(0, idx - step), idx + 1);
}

void assert(bool condition, std::string err_msg){
  if(!condition){
    std::cerr << err_msg << std::endl;
    throw;
  }
}


int main(){
  int max_height = 10000;
  int trials = 10000;
  std::random_device rd;
  std::default_random_engine generator(rd());
  std::uniform_int_distribution<int> height_dist(10, max_height);
  int height;
  int threshold;
  int found_thresh;
  char err_msg[128];
  for(int i=0; i<trials; i++){
    height = height_dist(generator);
    threshold = height_dist(generator) % height;
    std::cout << "=======================" << std::endl;
    std::cout << "trial: " << i + 1 << std::endl;
    std::cout << "building size: " << height << std::endl;
    std::cout << "ball threshold: " << threshold << std::endl;
    std::vector<bool>* building = new_building(height, threshold-1);
    std::cout << "search for threshold..." << std::endl;
    found_thresh = sqrt_crystall_ball_breaks_at(*building);
    std::cout << "found threshold: " << found_thresh << std::endl;
    sprintf(
      err_msg,
      "found_thresh: %d, true_thresh: %d",
      found_thresh,
      threshold
    );
    assert(threshold == found_thresh, err_msg);
    delete building;
  }
  return 0;
}

