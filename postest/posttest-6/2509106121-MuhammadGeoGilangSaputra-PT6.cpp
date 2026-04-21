#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_USER 10
#define MAX_RENTAL 50

//================= STRUCT =================
struct Tanggal{
    int hari, bulan, tahun;
};

struct Rental{
    int id; // untuk searching angka
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
    {101,"Andi","PS5",2,50000,{1,1,2024}},
    {102,"Budi","PS4",3,40000,{2,1,2024}},
    {103,"Caca","PS3",1,30000,{3,1,2024}}
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

    cout<<"\nID : ";
    cin>>(r+*jumlah)->id;

    cin.ignore();
    cout<<"Nama Penyewa : ";
    getline(cin,(r+*jumlah)->namaPenyewa);

    cout<<"Playbox : ";
    getline(cin,(r+*jumlah)->playbox);

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
        <<"ID:"<< (r+i)->id<<" | "
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
// Bubble Sort (ID ASC untuk Binary Search)
void sortID(Rental *r, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if((r+j)->id > (r+j+1)->id){
                swap(*(r+j), *(r+j+1));
            }
        }
    }
}

//================= SEARCHING =================

// Linear Search (Nama)
int searchNama(Rental *r, int n, string cari){
    for(int i=0;i<n;i++){
        if((r+i)->namaPenyewa == cari){
            return i;
        }
    }
    return -1;
}

// Binary Search (ID)
int binarySearchID(Rental *r, int n, int target){
    int low = 0, high = n-1;

    while(low <= high){
        int mid = (low + high) / 2;

        if((r+mid)->id == target){
            return mid;
        }
        else if((r+mid)->id < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
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
                    cout<<"\n1.Tambah\n2.Lihat\n3.Ubah\n4.Hapus\n5.Sorting ID\n6.Searching\n7.Logout\nPilih : ";
                    cin>>menu;

                    if(menu==1) tambahRental(dataRental,&jumlahData);
                    else if(menu==2) tampil(dataRental,jumlahData);
                    else if(menu==3) ubah(dataRental,jumlahData);
                    else if(menu==4) hapus(dataRental,&jumlahData);

                    else if(menu==5){
                        sortID(dataRental, jumlahData);
                        cout<<"Data berhasil diurutkan berdasarkan ID\n";
                    }

                    else if(menu==6){
                        int pilihSearch;
                        cout<<"\n1.Cari Nama\n2.Cari ID\nPilih : ";
                        cin>>pilihSearch;

                        if(pilihSearch==1){
                            cin.ignore();
                            string nama;
                            cout<<"Masukkan nama : ";
                            getline(cin,nama);

                            int hasil = searchNama(dataRental, jumlahData, nama);

                            if(hasil != -1){
                                cout<<"Data ditemukan:\n";
                                cout<<(dataRental+hasil)->namaPenyewa<<endl;
                            }else{
                                cout<<"Tidak ditemukan\n";
                            }
                        }

                        else if(pilihSearch==2){
                            int id;
                            cout<<"Masukkan ID : ";
                            cin>>id;

                            int hasil = binarySearchID(dataRental, jumlahData, id);

                            if(hasil != -1){
                                cout<<"Data ditemukan:\n";
                                cout<<(dataRental+hasil)->namaPenyewa<<endl;
                            }else{
                                cout<<"Tidak ditemukan\n";
                            }
                        }
                    }

                }while(menu!=7);
            }
            else{
                cout<<"Login gagal!\n";
            }
        }

    }while(pilih!=3);

    return 0;
}