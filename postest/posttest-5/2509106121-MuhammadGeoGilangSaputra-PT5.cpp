#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_USER 10
#define MAX_RENTAL 50

struct Tanggal{
    int hari, bulan, tahun;
};

struct Rental{
    string namaPenyewa;
    string playbox;
    int lamaSewa;
    int harga;
    Tanggal tanggal;
};

struct User{
    string nama;
    string nim;
};

//================= DATA AWAL =================
User user[MAX_USER] = {{"Geo","121"}};

Rental dataRental[MAX_RENTAL] = {
    {"Andi","PS5",2,50000,{1,1,2024}},
    {"Budi","PS4",3,40000,{2,1,2024}},
    {"Caca","PS3",1,30000,{3,1,2024}}
};

int jumlahUser = 1;
int jumlahData = 3;

//================= REGISTER =================
void tambahUser(User *u, int *jumlah){
    cout<<"\n=== REGISTER ===\n";
    cout<<"Nama : ";
    cin>>u[*jumlah].nama;

    cout<<"NIM  : ";
    cin>>u[*jumlah].nim;

    (*jumlah)++;
}

//================= LOGIN =================
bool login(User *u, int jumlah){
    string nama,nim;

    cout<<"\n=== LOGIN ===\n";
    cout<<"Nama : "; cin>>nama;
    cout<<"NIM  : "; cin>>nim;

    for(int i=0;i<jumlah;i++){
        if(nama==u[i].nama && nim==u[i].nim){
            return true;
        }
    }
    return false;
}

//================= TAMBAH DATA =================
void tambahRental(Rental *r, int *jumlah){

    cin.ignore();
    cout<<"\nNama Penyewa : ";
    getline(cin, (r+*jumlah)->namaPenyewa);

    cout<<"Playbox : ";
    getline(cin, (r+*jumlah)->playbox);

    cout<<"Lama Sewa : ";
    cin>>(r+*jumlah)->lamaSewa;

    cout<<"Harga : ";
    cin>>(r+*jumlah)->harga;

    cout<<"Hari : ";
    cin>>(r+*jumlah)->tanggal.hari;

    cout<<"Bulan : ";
    cin>>(r+*jumlah)->tanggal.bulan;

    cout<<"Tahun : ";
    cin>>(r+*jumlah)->tanggal.tahun;

    int total = (r+*jumlah)->lamaSewa * (r+*jumlah)->harga;
    cout<<"Total : "<<total<<endl;

    (*jumlah)++;
}

//================= TAMPIL =================
void tampil(Rental *r, int jumlah){

    cout<<"\n=== DATA ===\n";

    for(int i=0;i<jumlah;i++){
        cout<<i+1<<". "
        <<(r+i)->namaPenyewa<<" | "
        <<(r+i)->playbox<<" | "
        <<(r+i)->lamaSewa<<" | "
        <<(r+i)->harga<<" | "
        <<(r+i)->tanggal.hari<<"/"
        <<(r+i)->tanggal.bulan<<"/"
        <<(r+i)->tanggal.tahun
        <<endl;
    }
}

//================= UPDATE =================
void ubah(Rental *r, int jumlah){
    int idx;
    tampil(r,jumlah);

    cout<<"Pilih : ";
    cin>>idx;

    cin.ignore();
    cout<<"Nama Baru : ";
    getline(cin,(r+idx-1)->namaPenyewa);

    cout<<"Playbox Baru : ";
    getline(cin,(r+idx-1)->playbox);
}

//================= DELETE =================
void hapus(Rental *r, int *jumlah){
    int idx;
    tampil(r,*jumlah);

    cout<<"Pilih : ";
    cin>>idx;

    for(int i=idx-1;i<*jumlah-1;i++){
        *(r+i) = *(r+i+1);
    }

    (*jumlah)--;
}

//================= SORTING =================

// Bubble Sort (Nama ASC)
void sortNamaAsc(Rental *r, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if((r+j)->namaPenyewa > (r+j+1)->namaPenyewa){
                swap(*(r+j), *(r+j+1));
            }
        }
    }
}

// Selection Sort (Harga DESC)
void sortHargaDesc(Rental *r, int n){
    for(int i=0;i<n-1;i++){
        int maxIdx = i;
        for(int j=i+1;j<n;j++){
            if((r+j)->harga > (r+maxIdx)->harga){
                maxIdx = j;
            }
        }
        swap(*(r+i), *(r+maxIdx));
    }
}

// Insertion Sort (Lama Sewa ASC)
void sortLamaAsc(Rental *r, int n){
    for(int i=1;i<n;i++){
        Rental key = *(r+i);
        int j = i-1;

        while(j>=0 && (r+j)->lamaSewa > key.lamaSewa){
            *(r+j+1) = *(r+j);
            j--;
        }
        *(r+j+1) = key;
    }
}

//================= MAIN =================
int main(){

    int pilih;

    do{
        cout<<"\n1.Register\n2.Login\n3.Keluar\nPilih : ";
        cin>>pilih;

        if(pilih==1){
            tambahUser(user, &jumlahUser);
        }

        else if(pilih==2){
            if(login(user,jumlahUser)){

                int menu;
                do{
                    cout<<"\n1.Tambah\n2.Lihat\n3.Ubah\n4.Hapus\n5.Sorting\n6.Logout\nPilih : ";
                    cin>>menu;

                    if(menu==1) tambahRental(dataRental,&jumlahData);
                    else if(menu==2) tampil(dataRental,jumlahData);
                    else if(menu==3) ubah(dataRental,jumlahData);
                    else if(menu==4) hapus(dataRental,&jumlahData);
                    else if(menu==5){
                        int s;
                        cout<<"\n1.Sort Nama ASC\n2.Sort Harga DESC\n3.Sort Lama ASC\nPilih : ";
                        cin>>s;

                        if(s==1) sortNamaAsc(dataRental, jumlahData);
                        else if(s==2) sortHargaDesc(dataRental, jumlahData);
                        else if(s==3) sortLamaAsc(dataRental, jumlahData);

                        tampil(dataRental, jumlahData);
                    }

                }while(menu!=6);
            }
        }

    }while(pilih!=3);
}