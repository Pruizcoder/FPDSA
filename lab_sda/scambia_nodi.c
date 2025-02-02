#include "lista.h"

/* 
Data una lista, si scriva la funzione che data t, testa della lista, 
e un nodo della lista s e un nodo p predecessore di s,  scambia il nodo s 
con il suo successore modificando opportunamente i puntatori.

Qualora il nodo s coincida con la testa t (e in tal caso il predecessore sia NULL), 
la funzione deve restituire il puntatore al nodo che è diventato la nuova testa 
della lista, in caso contrario la funzione restituirà semplicemente la testa precedente.

Nota: si gestiscano opportunamente tutti i casi particolari (coda della lista, testa della lista)

*/

nodo_lista* scambia_con_successore(nodo_lista* t, nodo_lista* p, nodo_lista* s) {
    nodo_lista *aj, *aj1, *aj2;
    /* caso particolare: lista vuota */
    if (t == NULL) {
        assert(s == NULL && p == NULL);
        return NULL;
    }
    /* se la lista non è vuota, s non può essere NULL */
    assert(s != NULL);
    /* caso particolare: s è la coda della lista */
    
    // RIEMPIRE CON IL CODICE PER GESTIRE IL CASO
    
    /* caso normale: memorizzare in aj, aj1, aj2 gli opportuni puntatori
       ed effettuare gli scambi */
    
    // RIEMPIRE CON IL CODICE PER GESTIRE IL CASO
    
    /* aggiornare il puntatore p->succ solo quando esiste un predecessore
       si osservi che quando p è NULL dev'essere s == t (ossia è la testa della lista) 
       gestire opportunamente il valore restituito nel secondo caso
       */
    if (p == NULL) {
        assert(s == t);
        return t;
    } else {
        // RIEMPIRE CON IL CODICE PER GESTIRE IL CASO
    }
}
