

typedef struct Node {
  Node* left;
  Node* right;
  int val;
};

void echo_node(Node* n) {
  std::cout << n->val << " ";
}

void echo_tree(Node* parent) {
  if (!parent) {
    return;
  }

  bool l2r = true;
  std::queue<Node*> q;
  q.push_back(parent);
  while (!q.empty()) {
    // queue to store children
    std::queue<Node*> q_temp;

    // equivalent to q
    std::queue<Node*> q_out;

    while (!q.empty()) {
      Node* n = q.front();
      q.pop_front();
      q_out.push_back(n);

      // push n's children to q_temp
      if (n->left) {
        q_temp->push_back(n);
      }
      if (n->right) {
        q_temp->push_back(n);
      }

    }
    // echo nodes' value
    if (l2r) {
      // left to right
      while (!q_out.empty()) {
        Node* nd = q_out.front();
        q_out.pop_front();
        echo_node(nd);
      }
    } else {
      // right to left
      while (!q_out.empty()) {
        Node* nd = q_out.back();
        q_out.pop_back();
        echo_node(nd);
      }
    }

    // swap q_temp with q
    l2r = !l2r;
    q.swap(q_temp);
  }
}
