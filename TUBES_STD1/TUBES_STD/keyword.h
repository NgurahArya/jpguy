#ifndef KEYWORD_H_INCLUDED
#define KEYWORD_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define info(K) K->info
#define next(K) K->next
#define prev(K) K->prev



struct keyword{
    string nama;

};
typedef keyword infotype_K;
typedef struct elmKeyword *adrK;

struct elmKeyword{
    infotype_K info;
    adrK next;
    adrK prev;
};
struct list_K{
    adrK first;
    adrK last;
};

bool isEmpty(list_K L);
void createlist_K(list_K &L);
adrK alokasiK(string nama_keyword);
void addKeyword(list_K &L, adrK P);
void deletefirst(list_K &L, adrK &P);
void deletelast(list_K &L, adrK &P);
void deleteAfterK(list_K &L, adrK Prec, adrK &P);
adrK searchKeyword(list_K L, string namaCari);
void showKeyword(list_K L);

#endif // KEYWORD_H_INCLUDED
