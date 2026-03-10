#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_USER 10
#define MAX_RENTAL 50

// Nested Struct tanggal
struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};

// Struct data rental
struct Rental {
    string namaPenyewa;
    string playbox;
    int lamaSewa;
    int harga;
    Tanggal tanggal;
};

// Struct user
struct User {
    string nama;
    string nim;
};

// DATABASE USER (sudah ada akun)
User user[MAX_USER] = {
    {"Geo", "121"}
};

Rental dataRental[MAX_RENTAL];

int jumlahUser = 1;
int jumlahData = 0;


// ================= REGISTER =================
void registerUser() {

    cout << "\n=== REGISTER USER ===\n";

    cout << "Masukkan Nama : ";
    cin >> user[jumlahUser].nama;

    cout << "Masukkan NIM  : ";
    cin >> user[jumlahUser].nim;

    jumlahUser++;

    cout << "Registrasi berhasil!\n";
}


// ================= LOGIN =================
bool login() {

    string nama, nim;
    int percobaan = 0;

    while (percobaan < 3) {

        cout << "\n=== LOGIN ===\n";

        cout << "Nama : ";
        cin >> nama;

        cout << "NIM  : ";
        cin >> nim;

        for (int i = 0; i < jumlahUser; i++) {

            if (nama == user[i].nama && nim == user[i].nim) {

                cout << "Login berhasil!\n";
                return true;
            }
        }

        percobaan++;

        cout << "Login gagal! Sisa kesempatan : "
             << 3 - percobaan << endl;
    }

    cout << "\nAnda gagal login 3 kali.\n";
    cout << "Program berhenti.\n";

    return false;
}


// ================= CREATE =================
void tambahData() {

    cout << "\n=== TAMBAH DATA RENTAL ===\n";

    cin.ignore();

    cout << "Nama Penyewa : ";
    getline(cin, dataRental[jumlahData].namaPenyewa);

    cout << "Jenis Playbox : ";
    getline(cin, dataRental[jumlahData].playbox);

    cout << "Lama Sewa (jam) : ";
    cin >> dataRental[jumlahData].lamaSewa;

    cout << "Harga : ";
    cin >> dataRental[jumlahData].harga;

    cout << "\nTanggal Sewa\n";

    cout << "Hari : ";
    cin >> dataRental[jumlahData].tanggal.hari;

    cout << "Bulan : ";
    cin >> dataRental[jumlahData].tanggal.bulan;

    cout << "Tahun : ";
    cin >> dataRental[jumlahData].tanggal.tahun;

    jumlahData++;

    cout << "Data berhasil ditambahkan!\n";
}


// ================= READ =================
void tampilData() {

    if (jumlahData == 0) {
        cout << "\nBelum ada data rental.\n";
        return;
    }

    cout << "\n=== DATA RENTAL PLAYBOX ===\n";

    cout << left
         << setw(5) << "No"
         << setw(20) << "Nama"
         << setw(15) << "Playbox"
         << setw(10) << "Jam"
         << setw(10) << "Harga"
         << setw(15) << "Tanggal"
         << endl;

    for (int i = 0; i < jumlahData; i++) {

        cout << left
             << setw(5) << i + 1
             << setw(20) << dataRental[i].namaPenyewa
             << setw(15) << dataRental[i].playbox
             << setw(10) << dataRental[i].lamaSewa
             << setw(10) << dataRental[i].harga
             << dataRental[i].tanggal.hari << "/"
             << dataRental[i].tanggal.bulan << "/"
             << dataRental[i].tanggal.tahun
             << endl;
    }
}


// ================= UPDATE =================
void ubahData() {

    tampilData();

    int index;

    cout << "\nPilih nomor data yang ingin diubah : ";
    cin >> index;

    if (index < 1 || index > jumlahData) {

        cout << "Data tidak valid!\n";
        return;
    }

    cin.ignore();

    cout << "Nama Penyewa Baru : ";
    getline(cin, dataRental[index - 1].namaPenyewa);

    cout << "Jenis Playbox Baru : ";
    getline(cin, dataRental[index - 1].playbox);

    cout << "Lama Sewa Baru : ";
    cin >> dataRental[index - 1].lamaSewa;

    cout << "Harga Baru : ";
    cin >> dataRental[index - 1].harga;

    cout << "Hari : ";
    cin >> dataRental[index - 1].tanggal.hari;

    cout << "Bulan : ";
    cin >> dataRental[index - 1].tanggal.bulan;

    cout << "Tahun : ";
    cin >> dataRental[index - 1].tanggal.tahun;

    cout << "Data berhasil diubah!\n";
}


// ================= DELETE =================
void hapusData() {

    tampilData();

    int index;

    cout << "\nPilih nomor data yang ingin dihapus : ";
    cin >> index;

    if (index < 1 || index > jumlahData) {

        cout << "Data tidak valid!\n";
        return;
    }

    for (int i = index - 1; i < jumlahData - 1; i++) {

        dataRental[i] = dataRental[i + 1];
    }

    jumlahData--;

    cout << "Data berhasil dihapus!\n";
}


// ================= MAIN PROGRAM =================
int main() {

    int pilihan;

    while (true) {

        cout << "\n=== MENU AWAL ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilihan;

        if (pilihan == 1) {

            registerUser();
        }

        else if (pilihan == 2) {

            bool statusLogin = login();

            if (!statusLogin) {
                return 0; // PROGRAM BERHENTI JIKA LOGIN GAGAL 3 KALI
            }

            int menu;

            do {

                cout << "\n=== MENU RENTAL PLAYBOX ===\n";
                cout << "1. Tambah Data\n";
                cout << "2. Lihat Data\n";
                cout << "3. Ubah Data\n";
                cout << "4. Hapus Data\n";
                cout << "5. Logout\n";
                cout << "Pilihan : ";
                cin >> menu;

                switch (menu) {

                    case 1:
                        tambahData();
                        break;

                    case 2:
                        tampilData();
                        break;

                    case 3:
                        ubahData();
                        break;

                    case 4:
                        hapusData();
                        break;

                    case 5:
                        cout << "Logout berhasil.\n";
                        break;

                    default:
                        cout << "Pilihan tidak valid!\n";
                }

            } while (menu != 5);
        }

        else if (pilihan == 3) {

            cout << "Program selesai.\n";
            break;
        }

        else {

            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}