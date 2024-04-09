#include <iostream>
#include <string>

template <typename T>
class Node{
  public:
    T value;
    Node* next = nullptr;

    Node(T val){
      value = val;
    }

    Node(T val, Node* nxt){
      value = val;
      next = nxt;
    }

    std::string repr(){
      return std::string("Node(") + std::to_string(value) + std::string(")");
    }
};


template <typename T>
class LinkedList{
  Node<T>* head = nullptr;
  int size = 0;

  public:
    LinkedList(){}
    ~LinkedList(){}

    void push(T value){
      if(head == nullptr){
        head = new Node(value);
      } else {
        Node<T>* last = walk_to(size-1);
        last->next = new Node(value);
      }
      size += 1;
    }

    T get(int idx){
      assert_valid_idx(idx);
      return walk_to(idx)->value;
    }

    T pop(){
      assert_non_empty_list();
      Node<T>* second_to_last = walk_to(size-2);
      T last_value = second_to_last->next->value;
      delete second_to_last->next;
      second_to_last->next = nullptr;
      size -= 1;
      return last_value;
    }


    T pop(int idx){
      assert_valid_idx(idx);
      assert_non_empty_list();
      if(idx == 0){
        Node<T>* new_head = head->next;
        T value = head->value;
        head = new_head;
        return value;
      }
      Node<T>* second_to_idx = walk_to(idx-1);
      Node<T>* next_after_idx = second_to_idx->next->next;
      T last_value = second_to_idx->next->value;
      delete second_to_idx->next;
      second_to_idx->next = next_after_idx;
      size -= 1;
      return last_value;
    }

    void print(){
      // I know this is a lazy way to print but whatever
      std::cout << "[";
      Node<T>* current = head;
      for(int i=0; i<size; i++){
        std::cout << current->value << ", ";
        current = current->next;
      }
      std::cout << "]" << std::endl;
    }


  private:
    void assert_valid_idx(int idx){
      if(idx < 0 || idx >= size){
        std::cerr << "idx out of range" << std::endl;
        throw 1;
      }
    }

    void assert_non_empty_list(){
      if(size == 0){
        std::cerr << "tried to pop empty list" << std::endl;
        throw 1;
      }
    }

    Node<T>* walk_to(int idx){
      if(idx > size){
        std::cerr << "index out of range" << std::endl;
        throw 1; 
      }
      Node<T>* current = head;
      for(int i=0; i<idx; i++){
        current = current->next;
      }
      return current;
    }
};


int main(){
  LinkedList<float> linked_list = LinkedList<float>();
  std::cout << "created ll" << std::endl;
  linked_list.push(10.);
  linked_list.print();
  linked_list.push(1.);
  linked_list.push(-1e3);
  linked_list.push(3.141592);
  std::cout << "pushed some values" << std::endl;
  linked_list.print();
  std::cout << linked_list.pop() << std::endl;
  linked_list.push(1.);
  linked_list.print(g;
  std::cout << linked_list.pop() << std::endl;
  linked_list.print();
  std::cout << linked_list.pop(0) << std::endl;
  std::cout << linked_list.get(0) << std::endl;
  linked_list.print();
  return 0;
}
