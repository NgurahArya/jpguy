#include "keyword.h"
#include "paper.h"

bool isEmpty (list_K L){
  if (first(L) == NULL){
    return true;
  }else{
    return false;
  }
}

void createlist_K(list_K &L){
    first(L) = NULL;
    last(L) = NULL;
}

adrK alokasiK(string nama_keyword){
    adrK P = new elmKeyword;
    info(P).nama = nama_keyword;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void addKeyword(list_K &L, adrK P){
    if (isEmpty(L)){
        first(L) = P;
        last(L) = P;
   }else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
   }
}

void showKeyword(list_K L){
    adrK P;
    P = first(L);
    if (isEmpty(L)){
        cout << "kosong";
    }else{
        while (P != NULL){
            cout << info(P).nama << ", ";
            P = next(P);
        }
    }
    cout << endl;
}

adrK searchKeyword(list_K L, string namaCari){
    adrK P = first(L);
    while (P != NULL){
        if (info(P).nama == namaCari){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

/** PROSEDUR DELETE */
void deletefirst(list_K &L, adrK &P){
    P = first(L);
    first(L) = next(P);
    next(P) = NULL;
    prev(first(L)) = NULL;
}

void deleteAfterK(list_K &L, adrK Prec, adrK &P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}

void deletelast(list_K &L, adrK &P){
    P = last(L);
    last(L) = prev(P);
    next(last(L)) = NULL;
    prev(P) = NULL;
}

