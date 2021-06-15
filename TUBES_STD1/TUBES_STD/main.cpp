#include "paper.h"
#include "keyword.h"
#include "relasi.h"

list_G paper;
list_K keyword;
int main()
{
    adrG P;
    adrK C,Prec,K;
    string namaG, namaK, namaCari, keywordCari, paperCari, x, baru;
    int umur,pil,pil2,hasil;
    createlist_G(paper);
    createlist_K(keyword);

    MENU:
    cout <<"================================================================================"<<endl;
    cout << "SELAMAT DATANG DI PAPER KEYWORD" << endl;
    cout << "Silahkan pilih menu di bawah " << endl;
    cout << "1.    Menambahkan Paper baru" << endl;
    cout << "2.    Menambahkan Keyword baru" << endl;
    cout << "3.    Menambahkan hubungan antara paper dan keyword" << endl;
    cout << "4.    Menghapus Paper tertentu" << endl;
    cout << "5.    Menghapus Keyword tertentu" << endl;
    cout << "6.    Menampilkan semua keyword; masing-masing dengan paper-nya" << endl;
    cout << "7.    Menampilkan paper dengan keyword tertentu" << endl;
    cout << "8.    Menampilkan paper yang memiliki keyword yang sama" << endl;
    cout << "9.    SELESAI" << endl;
    cout <<"================================================================================"<<endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> pil;

    cout <<"================================================================================"<<endl;

/** Menambahkan Paper*/
    if (pil == 1){
        cout << "Masukkan data paper" << endl;
        cout << "Nama Paper: ";
        cin >> namaG;
        P = alokasiG(namaG);
        addPaper(paper,P);
        cout << ">>>>> Paper " << namaG << " telah terdaftar <<<<<" << endl;
        //grup sudah terbentuk
        cout <<"-------------------------------------------------------------------------------"<<endl;
        cout << "Apakah Anda ingin menambahkan Keyword? (1.Ya / 2.Tidak)" << endl;
        cout << "Pilihan Anda:";
        cin >> pil2;

        while (pil2 == 1){
            cout <<"-------------------------------------------------------------------------------"<<endl;
            cout << "Masukkan Keyword" << endl;
            cout << "Nama Keyword: ";
            cin >> namaK;
            addKeyword(keyword(P),alokasiK(namaK));
            cout <<"-------------------------------------------------------------------------------"<<endl;
            cout << "Apakah Anda ingin menambahkan Keyword? (1.Ya / 2.Tidak)" << endl;
            cout << "Pilihan Anda:";
            cin >> pil2;
        }
    goto MENU;
/** Menambah Keyword*/
    }else if (pil == 2){
        cout << "Masukkan Keyword" << endl;
        cout << "Nama Member: ";
        cin >> namaK;
        cout <<"-------------------------------------------------------------------------------"<<endl;
        cout << "Paper yang tersedia: " << endl;
        printPaper(paper);
        cout << "Akan dimasukkan ke Paper: ";
        cin >> namaG;
        P = searchPaper(paper, namaG);
        addKeyword(keyword(P),alokasiK(namaK));
    goto MENU;
/** Menampilkan Seluruh Data*/
    }else if (pil == 3){
        cout <<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  DATA SAAT INI  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
        showAll(paper);
        cout << endl;
    goto MENU;
/** Menghapus Paper*/
    }else if (pil == 4){
        cout << "Masukkan data Paper yang akan dihapus: ";
        cin >> paperCari;
        P = searchPaper(paper,paperCari);
        deletePaper(paper,P);
        cout << "Paper " << info(P).nama << " telah dihapus" << endl;
    goto MENU;
/** Menghapus Keyword*/
    }else if (pil == 5){
        cout << "Masukkan data Keyword yang akan dihapus: ";
        cin >> keywordCari;
        del(paper,keyword(P),keywordCari);

    goto MENU;
/** Mencari Keyword ditambahkan di paper mana saja */
    }else if (pil == 6){
        cout << "Masukkan Keyword yang akan dicari pada Papernya: ";
        cin >> keywordCari;
        showPaper(paper,keyword(P),keywordCari);
    goto MENU;
/** Mencari Paper dengan keyword*/
    }else if (pil == 7){
       cout << "Masukkan data Paper yang akan dilihat Keywordnya: ";
       cin >> paperCari;
       cout << endl;
       P = searchPaper(paper,paperCari);
       showKeyword(paper,P);

    goto MENU;
    }else if (pil == 8){
        MinMax(paper,keyword(P));
    goto MENU;
    }else if (pil != 9){
        goto MENU;
    }else if(pil == 9){
        cout << "Thank You";
    }

}

