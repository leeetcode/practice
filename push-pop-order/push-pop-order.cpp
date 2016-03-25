#include <stack>
#include <string>
#include <iostream>

std::string push_pop_order(int src_arr[], int dest_arr[], int len) {
  int i = 0;
  int j = 0;

  std::stack<int> s;
  std::string op;

  s.push(src_arr[i]);
  i++;
  op.append("P");
//  std::cout << 'P' << std::endl;

  while(true) {
    if (!s.empty() && s.top() == dest_arr[j]) {
      s.pop();
      j++;
      op.append("Q");
//      std::cout << 'Q' << std::endl;
    } else {
      // src_arr reached the end
      if (i == len) {
        return std::string("NULL");
      } else {
        s.push(src_arr[i]);
        i++;
        op.append("P");
//        std::cout << 'P' << std::endl;
      }
    }

    if (j == len) {
      return op;
    }
  }

}

int main() {
  std::cout << "process begin" << std::endl;
  int src_arr1[] = {1, 2, 3, 4};
  int dest_arr1[] = {1, 2, 3, 4};
  std::cout << "process begin" << std::endl;
  std::string op1 = push_pop_order(src_arr1, dest_arr1, 4);
  std::cout << "src:1 2 3 4, dest:1, 2, 3, 4" << ". OP:" << op1 << std::endl;

  int src_arr2[] = {1, 2, 3, 4};
  int dest_arr2[] = {4, 3, 2, 1};
  std::string op2 = push_pop_order(src_arr2, dest_arr2, 4);
  std::cout << "src:1 2 3 4, dest:4, 3, 2, 1" << ". OP:" << op2 << std::endl;

  int src_arr3[] = {1, 2, 3, 4};
  int dest_arr3[] = {1, 3, 2, 4};
  std::string op3 = push_pop_order(src_arr3, dest_arr3, 4);
  std::cout << "src:1 2 3 4, dest:1, 3, 2, 4" << ". OP:" << op3 << std::endl;

  int src_arr4[] = {1, 2, 3, 4};
  int dest_arr4[] = {3, 1, 2, 4};
  std::string op4 = push_pop_order(src_arr4, dest_arr4, 4);
  std::cout << "src:1 2 3 4, dest:3, 1, 2, 4" << ". OP:" << op4 << std::endl;

  int src_arr5[] = {1, 2, 3, 4};
  int dest_arr5[] = {3, 4, 2, 1};
  std::string op5 = push_pop_order(src_arr5, dest_arr5, 4);
  std::cout << "src:1 2 3 4, dest:3, 4, 2, 1" << ". OP:" << op5 << std::endl;
  return 0;
}


