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

User user[MAX_USER] = {{"Geo","121"}};
Rental dataRental[MAX_RENTAL];

int jumlahUser = 1;
int jumlahData = 0;

//================= POINTER FUNCTION =================
void tambahUser(User *u, int *jumlah){
    cout<<"\n=== REGISTER ===\n";
    cout<<"Nama : ";
    cin>>u[*jumlah].nama;

    cout<<"NIM  : ";
    cin>>u[*jumlah].nim;

    (*jumlah)++; // dereference
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
        *(r+i) = *(r+i+1); // dereference pointer
    }

    (*jumlah)--;
}

//================= MAIN =================
int main(){

    int pilih;

    do{
        cout<<"\n1.Register\n2.Login\n3.Keluar\nPilih : ";
        cin>>pilih;

        if(pilih==1){
            tambahUser(user, &jumlahUser); // address-of
        }

        else if(pilih==2){
            if(login(user,jumlahUser)){

                int menu;
                do{
                    cout<<"\n1.Tambah\n2.Lihat\n3.Ubah\n4.Hapus\n5.Logout\nPilih : ";
                    cin>>menu;

                    if(menu==1) tambahRental(dataRental,&jumlahData);
                    else if(menu==2) tampil(dataRental,jumlahData);
                    else if(menu==3) ubah(dataRental,jumlahData);
                    else if(menu==4) hapus(dataRental,&jumlahData);

                }while(menu!=5);
            }
        }

    }while(pilih!=3);
}