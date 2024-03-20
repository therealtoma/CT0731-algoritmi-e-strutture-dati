/*
 * Dato un albero con chiavi intere positive e negative, progettare un algoritmo EFFICIENTE che restituisca la somma
 * totale di tutte le chiavi dell'albero.
 * Definire un secondo algoritmo, anch'esso EFFICIENTE, che restituisca il massimo peso di tutti i sottoalberi,
 * dove il peso di un sottoalbero è la somma di tutte le chiavi dei suoi nodi.
 */

#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int key, Node* left, Node* right) : key(key), left(left), right(right) {}
};

int somma_chiavi(Node* n){
    int ssx, sdx;

    // caso base: nodo vuoto
    if(n == nullptr) return 0;

    // caso base: foglia
    if(n->left == nullptr && n->right == nullptr) return n->key;
    else {
        ssx = somma_chiavi(n->left);
        sdx = somma_chiavi(n->right);
    }

    return n->key + sdx + ssx;
}

int peso_massimo(Node* n) {
    int m_sx, m_dx;

    // caso base: albero vuoto
    if(n == nullptr) return 0;

    // caso base: foglia
    if(n->left == nullptr && n->right == nullptr) return n->key;

    m_sx = somma_chiavi(n->left) + n->key;
    m_dx = somma_chiavi(n->right) + n->key;

    return (m_sx > m_dx) ? m_sx : m_dx;
}

int main() {

    Node* n = new Node(
            1,
            new Node(2,
                    new Node(4, nullptr, nullptr),
                    new Node(5, nullptr, nullptr)
                    ),
            new Node(3,
                     new Node(6, nullptr, nullptr),
                     nullptr)
            );

    std::cout << somma_chiavi(n) << std::endl;
    std::cout << peso_massimo(n) << std::endl;
    return 0;
}