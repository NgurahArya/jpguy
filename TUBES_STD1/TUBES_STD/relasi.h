#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "paper.h"
#include "keyword.h"

void showAll(list_G L); //menampilkan seluruh data
void showPaper(list_G L, list_K LC, string namaCari);
void showKeyword(list_G L, adrG G); //menampilkan member yang ada di sebuah grup
void del(list_G &L, list_K &LC, string namaCari);
void deletePaper(list_G &L, adrG &P); //menghapus grup dan membernya
void deleteKeyword(list_K &L, string namaCari);
void MinMax (list_G L, list_K LC);



#endif // RELASI_H_INCLUDED
