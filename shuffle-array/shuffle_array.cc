#include <iostream>

using namespace std;

bool indexed(int index[], int len, int step, int i) {
  for (int j=0;j<step;j++) {
    if (index[j] == i) {
      return true;
    }
  }

  return false;
}

void shuffle(int arr[], int index[], int len, int step) {
  if (step < len) {
    for (int i=0;i<len;i++) {
      if (!indexed(index, len, step, i)) {
        index[step] = i;
        shuffle(arr, index, len, step + 1);
      }
    }
  } else {
    for (int i=0;i<len;i++) {
      std::cout << arr[index[i]] << "  ";
    }
    std::cout << std::endl;
  }
}

void shuffle_array(int arr[], int len) {
  int *index = new int[len];
  shuffle(arr, index, len, 0);

  delete [] index;
}

int main() {
  int arr[] = {9, 8, 4};
  shuffle_array(arr, 3);

  int arr2[] = {1};
  shuffle_array(arr2, 1);
}
