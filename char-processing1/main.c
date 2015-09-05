#include "string.h"
#include "stdio.h"

void move_substr(char str[], int dup_pos, int del_pos) {
  // move substr, eg 'uiauibui'
  if(dup_pos > del_pos) {//aaabb, del a, dup b
    // double b, del a
    int pos = del_pos;
    while(pos < dup_pos) {
      str[pos] = str[pos+1];
      pos++;
    }
  } else {
    // double a, del b
    int pos = del_pos;
    while(pos > dup_pos) {
      str[pos] = str[pos-1];
      pos--;
    }
  }
  printf("%s\n", str);
}

int get_pos(char str[], char c, int from_pos, int len) {
  while(from_pos < len) {
    if(str[from_pos] == c) {
      return from_pos;
    } else {
      from_pos++;
    }
  }

  return -1;
}

// uibuibui
void del_all(char str[], char del, int del_from, int len) {
  int pos = del_from;
  int dest_pos = del_from;
  while(pos < len) {
    if(str[pos] == del) {
      pos++;
    } else {
      str[dest_pos] = str[pos];
      pos++;
      dest_pos++;
    }
  }

  str[dest_pos] = 0;
}

bool process(char str[], char dup, char del, int len) {
  int dup_from = 0;
  int del_from = 0;
  while(true) {
    int dup_pos = get_pos(str, dup, dup_from, len);
    int del_pos = get_pos(str, del, del_from, len);

    if(dup_pos == -1) {
      if(del_pos == -1) {
        return true;
      } else {
        // eg 'uiauiaui', del a
        del_all(str, del, del_pos, len);
        return true;
      }
    } else {
      if(del_pos == -1) {
        return false;
      } else {
        // move substr, eg 'uiauibui'
        move_substr(str, dup_pos, del_pos);
        if(dup_pos < del_pos) {// dup a, del b
          dup_from = dup_pos + 2;
          del_from = del_pos + 1;
        } else {// dup b, del a
          dup_from = dup_pos + 1;
          del_from = del_pos;
        }
      }
    }
  }
}

void test(char str[], int len) {
  printf("before processing, str is %s\n", str);
  process(str, 'b', 'a', strlen(str));
  printf(" after processing, str is %s\n", str);
}


int main(int args, char** argv) {
  char str1[] = "aaabb";
  test(str1, strlen(str1));
  char str[] = "iabaaabbyaonbxoikmaaabbaa";
  test(str, strlen(str));
}




