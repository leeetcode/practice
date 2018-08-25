#include <deque>
#include <iostream>

using namespace std;

struct Node {
    Node* lChild;
    Node* rChild;

    int val;
};

void visit(Node* n) {
    std::cout << n->val << std::endl;
}

void in_order_visit(Node* root) {
    Node* n = root;
    std::deque<Node*> nStack;
    nStack.push_back(n);
    while (!nStack.empty()) {
        while (n->lChild) {
            n = n->lChild;
            nStack.push_back(n);
        }

        Node* v = nStack.back();
        nStack.pop_back();

        visit(v);

        if (v->rChild) {
            n = v->rChild;
            nStack.push_back(n);
        }
    }
}

Node* new_node(int val) {
    Node* n = new Node;
    n->lChild = NULL;
    n->rChild = NULL;
    n->val = val;
    return n;
}

Node* join_child(Node* root, int val, bool left) {
    Node * c = new Node;
    c->lChild = NULL;
    c->rChild = NULL;
    c->val = val;

    if (left) {
        root->lChild = c;
    } else {
        root->rChild = c;
    }

    return c;
}

int main(int argc, char* argv[]) {
    Node* root = new_node(45);
    Node* l = join_child(root, 25, true);
    Node* r = join_child(root, 67, false);

    join_child(l, 12, true);
    join_child(l, 32, false);
    join_child(r, 54, true);
    join_child(r, 87, false);

    in_order_visit(root);
    return 0;
}
