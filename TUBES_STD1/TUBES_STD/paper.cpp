#include "paper.h"

bool isEmpty(list_G &L){
    if (first(L) == NULL){
        return true;
    }else{
        return false;
    }
}

void createlist_G(list_G &L){
    first(L) = NULL;
}

adrG alokasiG(string nama_paper){
    adrG P = new elmPaper;
    info(P).nama = nama_paper;
    createlist_K(keyword(P));
    next(P) = NULL;
    return P;
}


void addPaper(list_G &L, adrG P){
    if (isEmpty(L)){
        first(L) = P;
        next(first(L)) = first(L);
    }else{
        adrG Q = first(L);
        while (next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
}

adrG searchPaper(list_G L, string namaCari){
    adrG P = first(L);
    while (next(P) != first(L) && info(P).nama != namaCari){
        P = next(P);
    }
    if (info(P).nama == namaCari){
        return P;
    }else{
        return NULL;
    }
}

void printPaper(list_G L){
    int j;
    int i = 0;
    adrG P = first(L);
    while(next(P) != first(L)){
        i++;
        cout << i << ". " << info(P).nama << endl;
        j = i;
        P = next(P);

    }
    cout << j << ". " << info(P).nama << endl;
}

/** PROSEDUR DELETE */
void deletefirst(list_G &L, adrG &P){

    P = first(L);
    if(next(first(L)) == first(L)){
        first(L) = NULL;
    }else{
        first(L) = next(P);
        adrG Q = first(L);
        while (next(Q) != P){
            Q = next(Q);
        }
        next(Q) = first(L);
        next(P) = NULL;
    }
}

void deleteLastG(list_G &L, adrG &P){
    P = first(L);
    if(next(first(L)) == first(L)){
        first(L) = NULL;
    }else{
        adrG Q = first(L);
        while (next(P) != first(L)){
            Q = P;
            P = next(P);
        }
        next(Q) = first(L);
    }
}

void deleteAfterG(list_G &L, adrG Prec, adrG &P){
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}


