/*
 * Questo file contiene l'implementazione di una classe Albero attraverso l'utilizzo di array
 * Un albero, implementato tramite un array consiste in una lista di coppie (info, parent), nel nostro caso
 * facciamo riferimento ad una struct Node.
 * info rappresenta il valore del nodo, parent è l'indice del padre
 * chiaramente l'implementazione non funziona perche si sta utilizzando del pseudocodice
 */

# include <vector>

struct Node{
    int info; // contiene il valore del nodo
    int parent; // contiene l'indice del padre
};

class TreeArray {
private:
    std::vector<Node*> treeArray;
public:

    TreeArray() {}

//    definizione dei metodi
    /**
     * post-condizione: crea un nuovo albero vuoto
     * @return TreeArray un albero vuoto
     */
    TreeArray newtree();

    /**
     * post-condizione: capisce se l'albero è vuoto o meno
     * @return true se l'albero è vuoto, false altrimenti
     */
    bool treeEmpty();

    /**
     * pre-condizione: il nodo n deve essere contenuto all'interno dell'albero t
     * post-condizione: viene restituito il nodo padre, null nel caso in cui n sia la radice
     * @param t l'albero sul quale cercare il padre
     * @param n il nodo figlio
     * @return il nodo padre di n nell'albero t
     */

    Node* father(TreeArray t, Node n);

    /**
     * pre-condizione: il nodo n deve essere contenuto nell'albero t
     * post-condizione: la lista dei nodi figli di n
     * @param t l'albero sul quale cercare i nodi figli di n
     * @param n il nodo sul quale cercare la lista dei nodi figli
     * @return una lista di nodi figli di n nell'albero t nel caso in cui n non sia una foglia, una lista vuota altrimenti
     */
    std::vector<Node> sons(TreeArray t, Node n);

//    implementazione dei metodi

};

TreeArray TreeArray::newtree() {
    return TreeArray();
}

bool TreeArray::treeEmpty() {
    return treeArray.empty();
}

Node* TreeArray::father(TreeArray t, Node n) {
    if(n.parent == -1)
        return nullptr;
    return this->treeArray[n.parent];
}

std::vector<Node> TreeArray::sons(TreeArray t, Node n) {
    if(n.parent == -1)
        return std::vector<Node>(0);

    std::vector<Node> s;

    bool found = false;

    int fatherIndex = -1;

    // individuo la posizione del padre
    for(int i = 0; i < this->treeArray.size() && !found; i++) {
        if(this->treeArray[i]->info == n.info && this->treeArray[i]->parent == n.parent) {
            fatherIndex = i;
            found = true;
        }
    }

    // ottengo la lista dei nodi figli
    for(int i = 0; i < this->treeArray.size(); i++) {
        if(this->treeArray[i]->parent == fatherIndex) {
            s.insert(s.begin(), this->treeArray[i], i);
        }
    }

    return s;
}
