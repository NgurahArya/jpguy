#ifndef PAPER_H_INCLUDED
#define PAPER_H_INCLUDED

#include <iostream>
using namespace std;

#include "keyword.h"

#define first(L) L.first
#define info(G) G->info
#define next(G) G->next
#define keyword(G) G->keyword


struct paper{
    string nama;
    int jum;
};

typedef paper infotype_G;
typedef struct elmPaper *adrG;

struct elmPaper{
    infotype_G info;
    adrG next;
    list_K keyword;
};
struct list_G{
    adrG first;
};

/** YANG DIPAKAI */
bool isEmpty(list_G &L);
void createlist_G(list_G &L);
adrG alokasiG(string nama_paper);
void addPaper(list_G &L, adrG P);
void deletefirst(list_G &L, adrG &P);
void deleteLastG(list_G &L, adrG &P);
void deleteAfterG(list_G &L, adrG Prec, adrG &P);
adrG searchPaper(list_G L, string nama);
void printPaper(list_G L);



#endif // PAPER_H_INCLUDED
