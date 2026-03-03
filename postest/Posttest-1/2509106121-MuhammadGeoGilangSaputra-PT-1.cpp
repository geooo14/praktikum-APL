#include <iostream>
using namespace std;

int main() {
    string nama, password;
    int kesempatan = 0;
    string namaBenar = "Geo";      
    string passBenar = "121";         

   
    while (kesempatan < 3) {
        cout << "=====================================\n";
        cout << "           LOGIN SISTEM              \n";
        cout << "=====================================\n";
        cout << "Masukkan Nama     : ";
        cin >> nama;
        cout << "Masukkan Password : ";
        cin >> password;

        if (nama == namaBenar && password == passBenar) {
            cout << "\nLogin Berhasil!\n";
            break;
        } else {
            kesempatan++;
            cout << "Login Salah! Kesempatan tersisa "
                 << 3 - kesempatan << endl << endl;
        }
    }

    if (kesempatan == 3) {
        cout << "Anda gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    
    int pilihan;
    double nilai;

    do {
        cout << "\n=====================================\n";
        cout << "        MENU KONVERSI PANJANG        \n";
        cout << "=====================================\n";
        cout << "1. Meter ke Kilometer & Centimeter\n";
        cout << "2. Kilometer ke Meter & Centimeter\n";
        cout << "3. Centimeter ke Meter & Kilometer\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai dalam Meter: ";
                cin >> nilai;
                cout << "Hasil: " << nilai/1000 << " km dan "
                     << nilai*100 << " cm\n";
                break;

            case 2:
                cout << "Masukkan nilai dalam Kilometer: ";
                cin >> nilai;
                cout << "Hasil: " << nilai*1000 << " m dan "
                     << nilai*100000 << " cm\n";
                break;

            case 3:
                cout << "Masukkan nilai dalam Centimeter: ";
                cin >> nilai;
                cout << "Hasil: " << nilai/100 << " m dan "
                     << nilai/100000 << " km\n";
                break;

            case 4:
                cout << "Terima kasih telah menggunakan program.\n";
                break;

            default:
                cout << "Pilihan tidak tersedia!\n";
        }

    } while (pilihan != 4);

    return 0;
}