#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Ruang {
public:
    char kode[10];
    int kapasitas;
    char lokasi[50];
    char fasilitas[100];
};

class Jadwal {
public:
    char kodeMk[10];
    char namaMk[50];
    char dosen[50];
    char hari[10];
    char waktu[20];
    char kodeRuang[10];
};

class SIMERU {
private:
    Ruang daftarRuang[100];
    Jadwal daftarJadwal[100];
    int jumlahRuang;
    int jumlahJadwal;

public:
    SIMERU() {
        jumlahRuang = 0;
        jumlahJadwal = 0;
    }

    void loginAdmin() {
       	int pilihan;
			string username, password;
			cout<<"1.Masukkan username: ";
			cin>>username;
			cout<<"2.Masukkan Password: ";
			cin>>password;
			if(username == "admin" && password == "1994"){
				cout<<"Login Berhasil\n";
				menuAdmin();
			}else{
				cout<<"Username atau password salah!\n";
				}
		}

    void loginMahasiswa() {
        int pilihan;
			string username, password;
			cout<<"\n=== Login sebagai Mahasiswa===\n";
			cout<<"1.Masukkan username: ";
			cin>>username;
			cout<<"2.Masukkan Password: ";
			cin>>password;
			if(username == "mhs" && password == "1994"){
				cout<<"Login Berhasil\n";
				menuMahasiswa();
			}else{
				cout<<"Username atau password salah!\n";
				}
		}

    void menuAdmin() {
        int pilihan;
        do {
            cout << "\n=== MENU ADMIN ===\n";
            cout << "1. Tambah Ruang Kelas\n";
            cout << "2. Hapus Ruang Kelas\n";
            cout << "3. Lihat Daftar Ruang\n";
            cout << "4. Tambah Jadwal Kuliah\n";
            cout << "5. Hapus Jadwal Kuliah\n";
            cout << "6. Ubah Jadwal Kuliah\n";
            cout << "7. Lihat Jadwal Kuliah\n";
            cout << "0. Keluar\n";
            cout << "Pilihan: ";
            cin >> pilihan;

            switch(pilihan) {
                case 1:
                    tambahRuang();
                    break;
                case 2:
                    hapusRuang();
                    break;
                case 3:
                    lihatRuang();
                    break;
                case 4:
                    tambahJadwal();
                    break;
                case 5:
                    hapusJadwal();
                    break;
                case 6:
                    ubahJadwal();
                    break;
                case 7:
                    lihatJadwal();
                    break;
                case 0:
                    cout << "Kembali ke menu utama.\n";
                    break;
                default:
                    cout << "Pilihan tidak valid!\n";
            }
        } while(pilihan != 0);
    }

    void menuMahasiswa() {
        int pilihan;
        do {
            cout << "\n=== MENU MAHASISWA ===\n";
            cout << "1. Lihat Jadwal Kuliah\n";
            cout << "2. Unduh Jadwal Kuliah\n";
            cout << "0. Keluar\n";
            cout << "Pilihan: ";
            cin >> pilihan;

            switch(pilihan) {
                case 1:
                    lihatJadwal();
                    break;
                case 2:
                    simpanJadwalKeFile();
                    break;
                case 0:
                    cout << "Kembali ke menu utama.\n";
                    break;
                default:
                    cout << "Pilihan tidak valid!\n";
            }
        } while(pilihan != 0);
    }

    void tambahRuang() {
        if(jumlahRuang >= 100) {
            cout << "Kapasitas ruang penuh!\n";
            return;
        }

        cout << "\n=== TAMBAH RUANG KELAS ===\n";
        cout << "Kode Ruang: ";
        cin >> daftarRuang[jumlahRuang].kode;
        cout << "Kapasitas: ";
        cin >> daftarRuang[jumlahRuang].kapasitas;
        cout << "Lokasi: ";
        cin.ignore();
        cin.getline(daftarRuang[jumlahRuang].lokasi, 50);
        cout << "Fasilitas: ";
        cin.getline(daftarRuang[jumlahRuang].fasilitas, 100);

        jumlahRuang++;
        cout << "Ruang kelas berhasil ditambahkan!\n";
    }
    void hapusRuang() {
        char kode[10];
        cout << "\n=== HAPUS RUANG KELAS ===\n";
        cout << "Masukkan kode ruang yang akan dihapus: ";
        cin >> kode;

        for(int i = 0; i < jumlahRuang; i++) {
            if(daftarRuang[i].kode, kode == 0) {
                for(int j = i; j < jumlahRuang-1; j++) {
                    daftarRuang[j] = daftarRuang[j+1];
                }
                jumlahRuang--;
                cout << "Ruang berhasil dihapus!\n";
                return;
            }
        }

        cout << "Ruang dengan kode " << kode << " tidak ditemukan!\n";
    }
    void lihatRuang() {
        cout << "\n=== DAFTAR RUANG KELAS ===\n";
        cout << "--------------------------------------------------------------------\n";
        cout << "Kode\tKapasitas\tLokasi\t\tFasilitas\n";
        cout << "--------------------------------------------------------------------\n";

        for(int i = 0; i < jumlahRuang; i++) {
            cout << daftarRuang[i].kode << "\t" 
                 << daftarRuang[i].kapasitas << "\t\t"
                 << daftarRuang[i].lokasi << "\t"
                 << daftarRuang[i].fasilitas << "\n";
        }
        cout << "--------------------------------------------------------------------\n";
    }

    void tambahJadwal() {
        if(jumlahJadwal >= 100) {
            cout << "Kapasitas jadwal penuh!\n";
            return;
        }

        cout << "\n=== TAMBAH JADWAL KULIAH ===\n";
        cout << "Kode Mata Kuliah: ";
        cin >> daftarJadwal[jumlahJadwal].kodeMk;
        cout << "Nama Mata Kuliah: ";
        cin.ignore();
        cin.getline(daftarJadwal[jumlahJadwal].namaMk, 50);
        cout << "Dosen: ";
        cin.getline(daftarJadwal[jumlahJadwal].dosen, 50);
        cout << "Hari: ";
        cin >> daftarJadwal[jumlahJadwal].hari;
        cout << "Waktu: ";
        cin.ignore();
        cin.getline(daftarJadwal[jumlahJadwal].waktu, 20);
        cout << "Kode Ruang: ";
        cin >> daftarJadwal[jumlahJadwal].kodeRuang;

        jumlahJadwal++;
        cout << "Jadwal kuliah berhasil ditambahkan!\n";
    }

    void hapusJadwal() {
        char kode[10];
        cout << "\n=== HAPUS JADWAL KULIAH ===\n";
        cout << "Masukkan kode mata kuliah yang akan dihapus: ";
        cin >> kode;

        bool found = false;
        for(int i = 0; i < jumlahJadwal; i++) {
            if(daftarJadwal[i].kodeMk, kode == 0) {
                for(int j = i; j < jumlahJadwal-1; j++) {
                    daftarJadwal[j] = daftarJadwal[j+1];
                }
                jumlahJadwal--;
                found = true;
                break;
            }
        }

        if(found) {
            cout << "Jadwal berhasil dihapus!\n";
        } else {
            cout << "Jadwal dengan kode " << kode << " tidak ditemukan!\n";
        }
    }

    void ubahJadwal() {
        char kode[10];
        cout << "\n=== UBAH JADWAL KULIAH ===\n";
        cout << "Masukkan kode mata kuliah yang akan diubah: ";
        cin >> kode;

        for(int i = 0; i < jumlahJadwal; i++) {
            if(daftarJadwal[i].kodeMk, kode == 0) {
                cout << "Data saat ini:\n";
                cout << "Nama MK: " << daftarJadwal[i].namaMk << endl;
                cout << "Dosen: " << daftarJadwal[i].dosen << endl;
                cout << "Hari: " << daftarJadwal[i].hari << endl;
                cout << "Waktu: " << daftarJadwal[i].waktu << endl;
                cout << "Ruang: " << daftarJadwal[i].kodeRuang << endl;

                cout << "\nMasukkan data baru:\n";
                cout << "Nama Mata Kuliah: ";
                cin.ignore();
                cin.getline(daftarJadwal[i].namaMk, 50);
                cout << "Dosen: ";
                cin.getline(daftarJadwal[i].dosen, 50);
                cout << "Hari: ";
                cin >> daftarJadwal[i].hari;
                cout << "Waktu: ";
                cin.ignore();
                cin.getline(daftarJadwal[i].waktu, 20);
                cout << "Kode Ruang: ";
                cin >> daftarJadwal[i].kodeRuang;

                cout << "Jadwal berhasil diubah!\n";
                return;
            }
        }

        cout << "Jadwal dengan kode " << kode << " tidak ditemukan!\n";
    }

    void lihatJadwal() {
        cout << "\n=== DAFTAR JADWAL KULIAH ===\n";
        cout << "-------------------------------------------------------------------------\n";
        cout << "Kode MK\tNama Mata Kuliah\tDosen\t\tHari\tWaktu\tRuang\n";
        cout << "-------------------------------------------------------------------------\n";

        for(int i = 0; i < jumlahJadwal; i++) {
            cout << daftarJadwal[i].kodeMk << "\t" 
                 << daftarJadwal[i].namaMk << "\t"
                 << daftarJadwal[i].dosen << "\t"
                 << daftarJadwal[i].hari << "\t"
                 << daftarJadwal[i].waktu << "\t"
                 << daftarJadwal[i].kodeRuang << "\n";
        }
        cout << "-------------------------------------------------------------------------\n";
    }

    void simpanJadwalKeFile() {
        ofstream file("jadwal_kuliah.txt");
        if(file.is_open()) {
            file << "=== DAFTAR JADWAL KULIAH ===\n";
            file << "-------------------------------------------------------------------------\n";
            file << "Kode MK\tNama Mata Kuliah\tDosen\t\tHari\tWaktu\tRuang\n";
            file << "-------------------------------------------------------------------------\n";

            for(int i = 0; i < jumlahJadwal; i++) {
                file << daftarJadwal[i].kodeMk << "\t" 
                     << daftarJadwal[i].namaMk << "\t"
                     << daftarJadwal[i].dosen << "\t"
                     << daftarJadwal[i].hari << "\t"
                     << daftarJadwal[i].waktu << "\t"
                     << daftarJadwal[i].kodeRuang << "\n";
            }
            file << "-------------------------------------------------------------------------\n";
            file.close();
            cout << "Jadwal berhasil disimpan ke file 'jadwal_kuliah.txt'\n";
        } else {
            cout << "Gagal menyimpan jadwal ke file!\n";
        }
    }
};

int main() {
    SIMERU simeru;
    int pilihan;
    do {
        cout << "\n=== SIMERU UAD ===\n";
        cout << "1. Login Admin\n";
        cout << "2. Login Mahasiswa\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                simeru.loginAdmin();
                break;
            case 2:
                simeru.loginMahasiswa();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan SIMERU UAD.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while(pilihan != 0);

    return 0;
}
//Kode A
//PJ Akhyar
