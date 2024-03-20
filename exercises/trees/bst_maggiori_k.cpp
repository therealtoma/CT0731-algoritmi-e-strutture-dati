/*
 * dalla dispensa: sia T un BST contentente n chiavi intere distinte. Sia k una chiave di T. Si consideri il problema di
 * eliminare da T tutte le chiavi maggiori di K
 */

#include <iostream>

struct Node {
    int k; // chiave
    Node* left; // sottoalbero sinistro
    Node* right; // sottoalbero destro
    Node* p; // puntatore al padre del nodo

    Node(int k, Node* left, Node* right, Node* p) : k(k), left(left), right(right), p(p) {}

};

void elimina_elementi(Node* n, int k) {
    if (n == nullptr) return;

    Node* tmp = n;
    while(tmp->k < k) tmp = tmp->right;

    if(tmp->left != nullptr) {
        tmp->left->p = tmp->p;
        tmp->p = tmp->left;
    }
    else tmp->p->right = nullptr;
}

void stampa_albero(Node* root) {
    if(root == nullptr) return;

    stampa_albero(root->left);
    std::cout << root->k << std::endl;
    stampa_albero(root->right);
}

int main() {


    Node* nf1 = new Node(8, nullptr, nullptr, nullptr);
    Node* nf2 = new Node(10, nullptr, nullptr, nullptr);
    Node* np1 = new Node(9, nf1, nf2, nullptr);

    Node* nf3 = new Node(3, nullptr, nullptr, nullptr);
    Node* np2 = new Node(7, nf3, np1, nullptr);

    Node* nf4 = new Node(21, nullptr, nullptr, nullptr);
    Node* nf5 = new Node(30, nullptr, nullptr, nullptr);

    Node* np3 = new Node(25, nf4, nf5, nullptr);

    Node* np4 = new Node(20, nullptr, np3, nullptr);

    Node* root = new Node(15, np2, np4, nullptr);

    nf1->p = np1;
    nf2->p = np1;
    np1->p = np2;
    nf4->p = np3;
    nf5->p = np3;
    np4->p = root;
    np2->p = root;

    stampa_albero(root);
    std::cout << "---" << std::endl;
    elimina_elementi(root, 20);
    std::cout << "---" << std::endl;
    stampa_albero(root);

    return 0;
}