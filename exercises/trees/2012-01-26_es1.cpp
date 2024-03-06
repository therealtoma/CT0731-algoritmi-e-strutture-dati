/*
 * dato l'albero seguente, eseguire visite in PREORDINE, SIMMETRICHE, POSTORDINE e indicare l'ordine dei nodi visitati
 *            A
 *           / \
 *          B   C
 *         /     \
 *        D       G
 *         \     / \
 *          E   I   F
 *         /
 *        F
*/

#include <string>
#include <iostream>

struct Node {
    std::string key;
    Node* left;
    Node* right;

    Node(std::string key, Node* left, Node* right) : key(key), left(left), right(right) {}
};

typedef Node* PNode;

void preorder_visit(PNode n) {
    if(n == nullptr) return;

    std::cout << n->key << " ";

    preorder_visit(n->left);
    preorder_visit(n->right);
}

void postorder_visit(PNode n) {
    if(n == nullptr) return;

    postorder_visit(n->left);
    postorder_visit(n->right);

    std::cout << n->key << " ";
}

void simmetric_visit(PNode n) {
    if(n == nullptr) return;

    simmetric_visit(n->left);

    std::cout << n->key << " ";

    simmetric_visit(n->right);
}

int main() {

    // Creazione dei nodi
    Node* nF1 = new Node("F", nullptr, nullptr);
    Node* nE = new Node("E", nF1, nullptr);
    Node* nD = new Node("D", nullptr, nE);
    Node* nB = new Node("B", nD, nullptr);

    Node* nI = new Node("I", nullptr, nullptr);
    Node* nF2 = new Node("F", nullptr, nullptr);
    Node* nG = new Node("G", nI, nF2);
    Node* nC = new Node("C", nullptr, nG);

    // Nodo radice
    Node* nA = new Node("A", nB, nC);

    std::cout << "preorder visit: ";
    preorder_visit(nA);
    std::cout << std::endl;

    std::cout << "postorder visit: ";
    postorder_visit(nA);
    std::cout << std::endl;

    std::cout << "simmetric visit: ";
    simmetric_visit(nA);

    return 0;
}
