//
// Created by Alberto Tomasin on 05/03/24.
//
#include <iostream>

struct Node {
    int key; // la chiave

    Node* root; // puntatore al padre, nullptr se è il padre
    Node* left; // sottoalbero sinistro
    Node* right; // sottoalbero destro
};

typedef Node* PNode;

int central_nodes_aux(PNode n, int sum, int& nleafs) {
    int cnodes, nfsx, nfdx;
    // caso base: l'albero è vuoto
    if(n == nullptr) {
        cnodes = 0;
        nleafs = 0;
    }

    // caso base: è la radice / foglia
    if(n->left == nullptr && n->right == nullptr) {
        nleafs = 1;
        cnodes = 0;
    }
    else {
        sum += n->key; // aggiungo alla somma delle chiavi dalla radice all'elemento corrente
        int c_sx = central_nodes_aux(n->left, sum, nfsx); // ottengo il numero di nodi centrali a sinistra con il relativo numero di foglie
        int c_dx = central_nodes_aux(n->right, sum, nfdx); // ottengo il numero di nodi centrali a destra con il relativo numero di foglie
        nleafs = nfsx + nfdx; // aggiungo le foglie al totale
        cnodes = c_sx + c_dx; // aggiungo i nodi centrali al totale
    }

    // se anche l'elemento corrente è nodo centrale lo aggiungo
    if(nleafs == sum + n->key)
        return cnodes + 1;
    return cnodes;
}

int central_nodes(PNode n) {
    int nleafs;
    return central_nodes_aux(n, 0, nleafs);
}
