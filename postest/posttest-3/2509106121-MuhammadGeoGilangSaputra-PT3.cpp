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

//================= PROSEDUR =================
void tampilJudul(string judul){
    cout << "\n=== " << judul << " ===\n";
}

//================= FUNGSI OVERLOADING =================
int hitungTotal(int jam, int harga){
    return jam * harga;
}

double hitungTotal(double jam, double harga){
    return jam * harga;
}

//================= FUNGSI REKURSIF =================
int hitungJumlahData(int n){
    if(n==0)
        return 0;
    return 1 + hitungJumlahData(n-1);
}

//================= REGISTER =================
void registerUser(User user[], int &jumlahUser){

    tampilJudul("REGISTER USER");

    cout<<"Masukkan Nama : ";
    cin>>user[jumlahUser].nama;

    cout<<"Masukkan NIM  : ";
    cin>>user[jumlahUser].nim;

    jumlahUser++;

    cout<<"Registrasi berhasil!\n";
}

//================= LOGIN =================
bool login(User user[], int jumlahUser){

    string nama,nim;
    int percobaan=0;

    while(percobaan<3){

        tampilJudul("LOGIN");

        cout<<"Nama : ";
        cin>>nama;

        cout<<"NIM  : ";
        cin>>nim;

        for(int i=0;i<jumlahUser;i++){
            if(nama==user[i].nama && nim==user[i].nim){
                cout<<"Login berhasil\n";
                return true;
            }
        }

        percobaan++;
        cout<<"Login gagal sisa kesempatan "<<3-percobaan<<endl;
    }

    return false;
}

//================= CREATE =================
void tambahData(Rental dataRental[], int &jumlahData){

    tampilJudul("TAMBAH DATA RENTAL");

    cin.ignore();

    cout<<"Nama Penyewa : ";
    getline(cin,dataRental[jumlahData].namaPenyewa);

    cout<<"Jenis Playbox : ";
    getline(cin,dataRental[jumlahData].playbox);

    cout<<"Lama Sewa : ";
    cin>>dataRental[jumlahData].lamaSewa;

    cout<<"Harga : ";
    cin>>dataRental[jumlahData].harga;

    cout<<"Tanggal : ";
    cin>>dataRental[jumlahData].tanggal.hari;

    cout<<"Bulan : ";
    cin>>dataRental[jumlahData].tanggal.bulan;

    cout<<"Tahun : ";
    cin>>dataRental[jumlahData].tanggal.tahun;

    int total = hitungTotal(
        dataRental[jumlahData].lamaSewa,
        dataRental[jumlahData].harga
    );

    cout<<"Total Bayar : "<<total<<endl;

    jumlahData++;
}

//================= READ =================
void tampilData(Rental dataRental[], int jumlahData){

    if(jumlahData==0){
        cout<<"Belum ada data\n";
        return;
    }

    tampilJudul("DATA RENTAL");

    cout<<left
    <<setw(5)<<"No"
    <<setw(20)<<"Nama"
    <<setw(15)<<"Playbox"
    <<setw(10)<<"Jam"
    <<setw(10)<<"Harga"
    <<setw(15)<<"Tanggal"
    <<endl;

    for(int i=0;i<jumlahData;i++){

        cout<<left
        <<setw(5)<<i+1
        <<setw(20)<<dataRental[i].namaPenyewa
        <<setw(15)<<dataRental[i].playbox
        <<setw(10)<<dataRental[i].lamaSewa
        <<setw(10)<<dataRental[i].harga
        <<dataRental[i].tanggal.hari<<"/"
        <<dataRental[i].tanggal.bulan<<"/"
        <<dataRental[i].tanggal.tahun
        <<endl;
    }

    cout<<"Total Data : "<<hitungJumlahData(jumlahData)<<endl;
}

//================= UPDATE =================
void ubahData(Rental dataRental[], int jumlahData){

    tampilData(dataRental,jumlahData);

    int index;

    cout<<"Pilih nomor data : ";
    cin>>index;

    if(index<1 || index>jumlahData){
        cout<<"Data tidak valid\n";
        return;
    }

    cin.ignore();

    cout<<"Nama Baru : ";
    getline(cin,dataRental[index-1].namaPenyewa);

    cout<<"Playbox Baru : ";
    getline(cin,dataRental[index-1].playbox);

    cout<<"Jam Baru : ";
    cin>>dataRental[index-1].lamaSewa;

    cout<<"Harga Baru : ";
    cin>>dataRental[index-1].harga;

    cout<<"Hari : ";
    cin>>dataRental[index-1].tanggal.hari;

    cout<<"Bulan : ";
    cin>>dataRental[index-1].tanggal.bulan;

    cout<<"Tahun : ";
    cin>>dataRental[index-1].tanggal.tahun;

    cout<<"Data berhasil diubah\n";
}

//================= DELETE =================
void hapusData(Rental dataRental[], int &jumlahData){

    tampilData(dataRental,jumlahData);

    int index;

    cout<<"Pilih nomor data : ";
    cin>>index;

    if(index<1 || index>jumlahData){
        cout<<"Data tidak valid\n";
        return;
    }

    for(int i=index-1;i<jumlahData-1;i++){
        dataRental[i]=dataRental[i+1];
    }

    jumlahData--;

    cout<<"Data berhasil dihapus\n";
}

//================= MENU =================
void menuRental(){

    int menu;

    do{

        tampilJudul("MENU RENTAL PLAYBOX");

        cout<<"1 Tambah Data\n";
        cout<<"2 Lihat Data\n";
        cout<<"3 Ubah Data\n";
        cout<<"4 Hapus Data\n";
        cout<<"5 Logout\n";
        cout<<"Pilihan : ";
        cin>>menu;

        switch(menu){

            case 1:
                tambahData(dataRental,jumlahData);
                break;

            case 2:
                tampilData(dataRental,jumlahData);
                break;

            case 3:
                ubahData(dataRental,jumlahData);
                break;

            case 4:
                hapusData(dataRental,jumlahData);
                break;

            case 5:
                cout<<"Logout\n";
                break;

            default:
                cout<<"Pilihan salah\n";
        }

    }while(menu!=5);
}

//================= MAIN =================
int main(){

    int pilihan;

    do{

        tampilJudul("MENU AWAL");

        cout<<"1 Register\n";
        cout<<"2 Login\n";
        cout<<"3 Keluar\n";
        cout<<"Pilihan : ";
        cin>>pilihan;

        switch(pilihan){

            case 1:
                registerUser(user,jumlahUser);
                break;

            case 2:
                if(login(user,jumlahUser))
                    menuRental();
                else{
                    cout<<"Login gagal 3x program berhenti\n";
                    return 0;
                }
                break;

            case 3:
                cout<<"Program selesai\n";
                break;

            default:
                cout<<"Pilihan tidak valid\n";
        }

    }while(pilihan!=3);

}