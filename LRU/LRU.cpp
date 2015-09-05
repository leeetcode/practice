#include <map>
#define NULL 0

class LRU{
  public:
    struct Node {
      Node* prev;
      Node* next;
      int key;
      int value;
    };

    LRU(int capacity) {
      _capacity = capacity;
      _size = 0;
      _head = NULL;
      _tail = NULL;
    }

    int get(int key) {
      std::map<int, Node*>::iterator it = _slots.find(key);
      if(it != _slots.end()) {
        removeNode(it->second);
        addNode(it->second);
        return it->second->value;
      }

      return -1;
    }

    void removeNode(Node* node) {
      if(node != _head && node != _tail) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
      }
      else {
        if(node == _head) {
          _head = node->next;
          if(_head) {
            _head->prev = NULL;
          }
        }

        if(node == _tail) {
          _tail = node->prev;
          if(_tail) {
            _tail->next = NULL;
          }
        }
      }
    }

    void addNode(Node* node) {
      if(_head && _tail) {
        node->next = NULL;
        node->prev = _tail;
        _tail->next = node;
        _tail = node;
      } else {
        _head = _tail = node;
      }
    }

    void set(int key, int value) {
      std::map<int, Node*>::iterator it = _slots.find(key);

      if(it != _slots.end()) {
        Node* node = it->second;
        node->value = value;

        removeNode(node);
        addNode(node);
      } else {
        if(_size == _capacity) {
          Node* nDel = _head;
          removeNode(nDel);

          _slots.erase(_slots.find(nDel->key));
          delete nDel;
        } else {
          _size ++;
        }
        Node* node = new Node;
        node->key = key;
        node->value = value;
        node->next = NULL;
        node->prev = NULL;

        addNode(node);
        _slots[key] = node;
      }
    }

    std::map<int, Node*> _slots; // key<->value pair
    Node* _head;
    Node* _tail;

    int _capacity;
    int _size;
};



int main() {
  LRU lru(10);
  lru.set(1,2);
  lru.set(2,3);
  lru.set(1,5);
  lru.set(2,6);
  lru.get(2);
}




