#include "relasi.h"

void showAll(list_G L){
    if (isEmpty(L)){
        cout << "Empty";
    }else{
        adrG G = first(L);
        while(next(G) != first(L)){
            cout << endl;
            cout << "Paper: " << info(G).nama << "  ";
            cout << "Keyword: ";
            showKeyword(keyword(G));
            G = next(G);
        }
        cout << endl;
        cout << "Paper: " << info(G).nama <<"  ";
        cout << "Keyword: ";
        showKeyword(keyword(G));
    }

}

void showPaper(list_G L, list_K LC, string namaCari){
    adrG P = first(L);
    while (next(P) != first(L)){
        adrK C = searchKeyword(keyword(P),namaCari);
        //cout << C;
        if(C != NULL){
            cout << info(C).nama << " terdaftar di Paper: " << info(P).nama;
        }
        P = next(P);
    }
    cout <<  ", " << info(P).nama<< endl;
}

void showKeyword(list_G L, adrG G){
    list_K LC = keyword(G);
    adrK C = first(LC);
    if (first(LC) == NULL){
        cout << "Paper kosong";
    }else{
        cout << "Keyword dari Paper " << info(G).nama << ": ";
        while(C != NULL){
            cout << info(C).nama << ", " ;
            C = next(C);

        }
    }
    cout << endl;
}

void deletePaper(list_G &L, adrG &P){
    if (P == first(L)){
        deletefirst(L,P);
    }else if (next(P) == first(L)){
        deleteLastG(L,P);
    }else{
        adrG Prec = first(L);
        while (next(Prec) != P){
            Prec = next(Prec);
        }
        deleteAfterG(L,Prec,P);
    }
}

void deleteKeyword(list_K &L, string namaCari){
    adrK C, Prec;
    C = searchKeyword(L,namaCari);
    cout << C << endl;
    if (C != NULL){
        if(C == first(L)){
            if (next(first(L)) == NULL){
                first(L) = NULL;
            }else{
                deletefirst(L,C);
            }
        }else if (C == last(L)){
            deletelast(L,C);
        }else{
            Prec = prev(C);
            deleteAfterK(L,Prec,C);
        }
    }
}

void del(list_G &L, list_K &LC, string namaCari){
    adrK C,Prec;
    adrG P = first(L);
    cout << P << endl;
    while (next(P) != first(L)){
        deleteKeyword(keyword(P),namaCari);
        P = next(P);
    }
    deleteKeyword(keyword(P),namaCari);
}

void MinMax (list_G L, list_K LC){
    adrG P, Pmax, Pmin;
    int max = 0;
    int min = 1000;
    P = first(L);
    while (next(P) != first(L)){
        if(first(L) == NULL){
            cout << "kosong" << endl;
        }else{
            adrK C = first(keyword(P));
            int jum = 0;
            while (C != NULL){
                jum++;
                C = next(C);
            }
            //cout << info(P).nama << "member: " << endl;
            if (jum == 0){
                cout << "kosong" << endl;
            }else{
                cout << jum << endl;
            }
            if (jum > max){
                max = jum;
                Pmax = P;
            }
            if (jum < min){
                min = jum;
                Pmin = P;
            }
        }
        P = next(P);
    }
    int min2 = min;
    int max2 = max;
    adrG Pmin2 = Pmin;
    adrG Pmax2 = Pmax;
    adrK C = first(keyword(P));
    int jum = 0;
    while (C != NULL){
        jum++;
        C = next(C);
    }
    //cout << info(P).nama << "member: " << endl;
    if (jum == 0){
        cout << "kosong" << endl;
    }else{
        cout << jum << endl;
    }
    if (jum >= max2){
        max2 = jum;
        Pmax2 = P;
    }
    if (jum >= min2){
        min2 = jum;
        Pmin2 = P;
    }
    cout << "Paper dengan Keyword paling banyak adalah " << info(Pmax2).nama << " dengan " << max2 << " Keyword " << endl;
    cout << "Paper dengan Keyword paling sedikit adalah " << info(Pmin2).nama << " dengan " << min2 << " Keyword " << endl;
}

