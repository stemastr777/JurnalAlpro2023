#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "sepeda.h"
#include <vector>
#include <sstream>

class Kamus {
    public:

        // Attribute
        std::vector<Sepeda> list_sepeda; // Array untuk menyimpan data dari file
        std::vector<Sepeda> valid;       // Array untuk menyimpan hasil pencarian

        // Constructor kamus
        Kamus() {
            sinkron_file();
        }
        
        // Method

        // Menampilkan menu utama
        void menu_utama() {

            // Kamus lokal
            int pilihan_menu_utama;

            // Setiap masuk ke halaman utama, valid dikosongkan
            this->valid = {};

            std::cout << "\033[2J\033[1;1H";
            std::cout << "=======================================================================================\n";
            std::cout << "                                    Halaman utama                                      \n";
            std::cout << "=======================================================================================\n\n";
            std::cout << "                               |    1. Input data        |                            \n";
            std::cout << "                               |    2. Lihat database    |                           \n";
            std::cout << "                               |    3. Cari data         |                            \n";
            std::cout << "                               |    4. Selesai           |                            \n\n";
            std::cout << "Input menu yang ingin dipilih: ";
            std::cin >> pilihan_menu_utama;
            
            // Pemilihan menu pada halaman utama
            if (pilihan_menu_utama == 1) {

                inputData();
                sinkron_file();
                menu_utama();
            } 
            else if (pilihan_menu_utama == 2) {
                std::cout << "\033[2J\033[1;1H";
                std::cout << "=======================================================================================\n";
                std::cout << "                                   Database sepeda                                     \n";
                std::cout << "=======================================================================================\n\n";
                outputData(list_sepeda);
                menu_tambahan();
            } 
            else if (pilihan_menu_utama == 3) {
                std::cout << "\033[2J\033[1;1H";
                std::cout << "=======================================================================================\n";
                std::cout << "                                   Pencarian sepeda                                    \n";
                std::cout << "=======================================================================================\n\n";
                std::cout << "                             __________________________________                            \n\n";
                std::cout << "                               |    1. Merk                  |                            \n";
                std::cout << "                               |    2. Tipe                  |                            \n";
                std::cout << "                               |    3. Tinggi                |                            \n";
                std::cout << "                               |    4. panjang               |                            \n";
                std::cout << "                               |    5. Berat                 |                            \n";
                std::cout << "                               |    6. Jenis                 |                            \n";
                std::cout << "                               |    7. Warna                 |                            \n";
                std::cout << "                               |    8. Gear maksimal         |                            \n";
                std::cout << "                               |    9. Kecepatan maksimal    |                            \n";
                std::cout << "                             __________________________________                            \n\n";
                linearSearch();
                outputData(valid);
                menu_tambahan();
            } 
            else {
                return;
            }
        }

        // Menampilan menu saat menampilkan data file
        void menu_tambahan() {
            int pilihan;
            std::string kriteria;

            std::cout << std::endl;
            std::cout << "                               __________________________________                            \n\n";
            std::cout << "                               |    1. Simulasi sepeda          |                            \n";
            std::cout << "                               |    2. Kembali ke menu utama    |                            \n";
            std::cout << "                               __________________________________                            \n\n";
            std::cout << "Input menu yang ingin dipilih: ";
            std::cin >> pilihan;

            // Pilih menu
            if (pilihan == 1) {
                std::cout << "\033[2J\033[1;1H";
                std::cout << "=======================================================================================\n";
                std::cout << "                                   Simulasi Sepeda                                     \n";
                std::cout << "=======================================================================================\n\n";
                if (valid.size() == 0) {
                    outputData(list_sepeda);
                } else {
                    outputData(valid);
                }
                simulasi();
            } 
            else if (pilihan == 2) {
                menu_utama();
            } 
        }

        // Header halaman simulasi
        void header_simulasi(Sepeda sepeda) {
            std::cout << "=======================================================================================\n";
            std::cout << "                                   Simulasi Sepeda                                     \n";
            std::cout << "=======================================================================================\n\n";

            std::cout << sepeda.merk << "  " << sepeda.tipe << std::endl;
            std::cout << "Tinggi: " << sepeda.ukuran.tinggi << std::endl;
            std::cout << "Panjang: " << sepeda.ukuran.panjang << std::endl;
            std::cout << "Berat: " << sepeda.berat << std::endl;
            std::cout << "Jenis: " << sepeda.jenis << std::endl;
            std::cout << "Warna: " << sepeda.warna << std::endl;
            std::cout << "Gear maksimum: " << sepeda.max_gear << std::endl;

            for (int i = 0; i < sepeda.v_max.size(); i++) {
                std::cout << "Kecepatan maksimum(gear" << i+1 << "): " << sepeda.v_max[i] << std::endl;
            }
            

            std::cout << "=======================================================================================\n\n";

            std::cout << "                               |   1. Waktu tempuh min.(jam)|                            \n";
            std::cout << "                               |   2. Gear min.             |                            \n";
            std::cout << "                               |   3. Jarak tempuh max.(km) |                            \n";
            std::cout << "                               |   4. Pilih sepeda lain     |                            \n";
            std::cout << "                               |   5. Kembali ke menu utama |                            \n\n";
        }

        // Menuju bagian simulasi
        void simulasi(){

            int pilihan_menu_simulasi;
            int pilihan_sepeda;
            Sepeda sepeda;
            char simulasi_lagi = 'y';
            
            // Memilih sepeda yang mau disimulasi
            while (true) {
                    std::cout << "\nPilih id sepeda mana yang mau disimulasi: ";
                    std::cin >> pilihan_sepeda;

                    if ((valid.size() != 0)) {
                        if (pilihan_sepeda < 0 || pilihan_sepeda > valid.size())
                        {
                            std::cout << "Tidak terdapat sepeda dengan id tersebut. Coba lagi" << std::endl;
                            continue;
                        } else{
                            sepeda = valid[pilihan_sepeda - 1];
                            break;
                        }
                    } 
                    else {
                        // Apabila tidak ada pencarian(valid kosong)
                        sepeda = list_sepeda[pilihan_sepeda - 1];
                        break;
                    }
            }



            // Masuk ke header halaman simulasi

            while (simulasi_lagi == 'y') {
                std::cout << "\033[2J\033[1;1H";
                header_simulasi(sepeda);


                // Bagian simulasi (tempat input data dari user)
                std::cout << "Pilih salah satu menu di atas: ";
                std::cin >> pilihan_menu_simulasi;

                if (pilihan_menu_simulasi == 1) {
                    float jarak;
                    int  gear;
                    std::cout << "Masukkan jarak tempuh(km): ";
                    std::cin >> jarak;
                    std::cout << "Masukkan gear yang akan dipakai: ";
                    std::cin >> gear;
                    std::cout << "Waktu tempuh minimal sepeda(jam): " << sepeda.waktuTempuh(jarak, gear) << "" << std::endl; 
                } 
                else if (pilihan_menu_simulasi == 2 ) {
                    float jarak;
                    int waktu;
                    std::cout << "Masukkan jarak tempuh(km): ";
                    std::cin >> jarak;
                    std::cout << "Masukkan waktu tempuh(detik): ";
                    std::cin >> waktu;
                    std::cout << "Gear minimal: " << sepeda.gearMin(jarak, waktu) << std::endl;
                } 
                else if (pilihan_menu_simulasi == 3 ) {
                    int gear;
                    int waktu;
                    std::cout << "Masukkan gear: ";
                    std::cin >> gear;
                    std::cout << "Masukkan waktu tempuh(detik): ";
                    std::cin >> waktu;
                    std::cout << "Jarak tempuh maksimal(km): " << sepeda.jarakTempuh(gear, waktu) << std::endl;
                } 
                else if (pilihan_menu_simulasi == 4) {
                    std::cout << "\033[2J\033[1;1H";
                    std::cout << "=======================================================================================\n";
                    std::cout << "                                   Simulasi Sepeda                                     \n";
                    std::cout << "=======================================================================================\n\n";
                    if (valid.size() == 0) {
                        outputData(list_sepeda);
                    } else {
                        outputData(valid);
                    }
                    simulasi();
                } 
                else {
                    menu_utama();
                    return;
                }

                std::cout << "Mau masih di halaman simulasi?('y' jika ya): ";
                std::cin >> simulasi_lagi; 
            }

            // Ke halaman utama apabila sudah selesai
            menu_utama();
        };

        // Menyamakan state list sepeda pada kamus dengan data pada data_sepeda.txt
        void sinkron_file() {
            std::ifstream infile("data_sepeda.txt", std::ios::in);
            Sepeda curr_sepeda;
            std::string line, curr_data;

            this->list_sepeda = {};

            while (getline(infile, line)) {
                std::istringstream iss(line);

                // Merk dan tipe
                getline(iss, curr_data, ',');
                curr_sepeda.merk = curr_data;
                getline(iss, curr_data, ',');
                curr_sepeda.tipe = curr_data;

                // Ukuran
                getline(iss, curr_data, ',');
                curr_sepeda.ukuran.tinggi = stof(curr_data);
                getline(iss, curr_data, ',');
                curr_sepeda.ukuran.panjang = stof(curr_data);

                // Berat
                getline(iss, curr_data, ',');
                curr_sepeda.berat = stof(curr_data);

                // string
                getline(iss, curr_data, ',');
                curr_sepeda.jenis = curr_data;
                getline(iss, curr_data, ',');
                curr_sepeda.warna = curr_data;

                // max gear dan v max
                getline(iss, curr_data, ',');
                curr_sepeda.max_gear = stof(curr_data);

                int index_gear = 0;
                curr_sepeda.v_max = {};
                while (index_gear < curr_sepeda.max_gear) {
                    getline(iss, curr_data, ';');
                    curr_sepeda.v_max.push_back(stof(curr_data));
                    index_gear += 1;
                }

                list_sepeda.push_back(curr_sepeda);
            }
        }

        // Prosedur input data void inputData(Sepeda &arr, int urutan)
        void inputData()
        {

            // Kamus lokal
            std::ofstream offile("data_sepeda.txt", std::ios::app);
            Sepeda new_sepeda;

            // Algoritma
            std::cout << "\033[2J\033[1;1H";
            std::cout << "=======================================================================================\n";
            std::cout << "                                   Tambah Sepeda                                       \n";
            std::cout << "=======================================================================================\n\n";

            std::cout << std::left << std::setw(30) << "Merk"
                      << ":";
            std::cin >> new_sepeda.merk;
            std::cout << std::left << std::setw(30) << "Tipe"
                      << ":";
            std::cin >> new_sepeda.tipe;
            std::cout << std::left << std::setw(30) << "Ukuran" << std::endl;

            std::cout << std::left << std::setw(25) << "     Tinggi"
                      << ":";
            std::cin >> new_sepeda.ukuran.tinggi;

            std::cout << std::left << std::setw(25) << "     Panjang"
                      << ":";
            std::cin >> new_sepeda.ukuran.panjang;

            std::cout << std::left << std::setw(30) << "Berat"
                      << ":";
            std::cin >> new_sepeda.berat;

            std::cout << std::left << std::setw(30) << "Jenis( listrik | konvensional )"
                      << ":";
            std::cin >> new_sepeda.jenis;

            std::cout << std::left << std::setw(30) << "Warna"
                      << ":";
            std::cin >> new_sepeda.warna;

            std::cout << std::left << std::setw(30) << "Gear maksimum"
                      << ":";
            std::cin >> new_sepeda.max_gear;
            
            for (int i = 0; i < new_sepeda.max_gear; i++) {
                
                float curr_max; // Menyimpan sementara kecepatan maksimum untuk setiap gear
                std::cout << std::left << "Kecepatan maksimum(gear " << i+1 << "):";
                std::cin >> curr_max;

                new_sepeda.v_max.push_back(curr_max);
            }
            

            std::cout << std::endl;

            offile << new_sepeda.merk << "," << new_sepeda.tipe << "," << new_sepeda.ukuran.tinggi << "," << new_sepeda.ukuran.panjang << "," << new_sepeda.berat << ","
                   << new_sepeda.jenis << "," << new_sepeda.warna << "," << new_sepeda.max_gear << ",";

            for (int i = 0; i < new_sepeda.max_gear; i++) {
                offile << new_sepeda.v_max[i] << ";";
            }

            offile << std::endl;
            offile.close();
            std::cout << "Data berhasil diinput." << std::endl;

        }

        // Prosedur output data
        void outputData(std::vector<Sepeda> arr)
        {

            // Kamus lokal
            int i = 0;

            // Algoritma

            // Apabila tidak ada data pada arr
            if (arr.size() == 0) {
                std::cout << "Data tidak ditemukan";
                return;
            }

            // Print header
            std::cout << std::endl;
            std::cout << std::setw(10) << "id";
            std::cout << std::setw(10) << "merk";
            std::cout << std::setw(10) << "tipe";
            std::cout << std::setw(15) << "jenis";
            std::cout << std::setw(10) << "warna";
            std::cout << "\n    ======================================================="; 
            std::cout << std::endl;

            while (i < arr.size())
            {
                std::cout << std::setw(10) << i+1;
                std::cout << std::setw(10) << arr[i].merk;
                std::cout << std::setw(10) << arr[i].tipe;
                std::cout << std::setw(15) << arr[i].jenis;
                std::cout << std::setw(10) << arr[i].warna;
                /* std::cout << std::setw(10) << arr[i].ukuran.tinggi;
                std::cout << std::setw(10) << arr[i].ukuran.panjang;
                std::cout << std::setw(10) << arr[i].berat;
                std::cout << std::setw(10) << arr[i].max_gear;
                std::cout << std::setw(10) << arr[i].v_max; */
                std::cout << std::endl;

                i++;
            }
        }

        // Fungsi pencarian dengan menggunakan algoritma linear search dan hasil disimpan ke attribut "valid"
        void linearSearch()
        {

            // Kamus lokal
            int kriteria;
            std::string filter;

            // Algoritma
            std::cout << "Pilih kriteria: ";
            std::cin >> kriteria;

            if (kriteria == 1 || kriteria == 2 || kriteria == 5 || kriteria == 6) {
                std::cout << "Ketik string yang ingin dicari: ";
                std::cin >> filter;
            } else {
                std::cout << "Masukan angka minimal dari kriteria yang ingin dicari: ";
                std::cin >> filter;
            }
            

            // Mengambil record yang memenuhi
            int i = 0;
            while (i < list_sepeda.size())
            {

                // Apabila memenuhi
                if (kriteria == 1 && list_sepeda[i].merk == filter) {
                    this->valid.push_back(this->list_sepeda[i]);
                }
                else if (kriteria == 2 && list_sepeda[i].tipe == filter) {
                    this->valid.push_back(this->list_sepeda[i]);
                }
                else if (kriteria == 2 && list_sepeda[i].ukuran.tinggi >= stof(filter))
                {
                    this->valid.push_back(this->list_sepeda[i]);
                }
                else if (kriteria == 3 && list_sepeda[i].ukuran.panjang >= stof(filter))
                {
                    this->valid.push_back(this->list_sepeda[i]);
                }
                else if (kriteria == 4 && list_sepeda[i].berat >= stof(filter))
                {
                    this->valid.push_back(this->list_sepeda[i]);
                }
                else if (kriteria == 5 && list_sepeda[i].jenis == filter)
                {
                    this->valid.push_back(this->list_sepeda[i]);
                }
                else if (kriteria == 6 && list_sepeda[i].warna == filter)
                {
                    this->valid.push_back(this->list_sepeda[i]);
                }
                else if (kriteria == 7 && list_sepeda[i].max_gear >= stoi(filter))
                {
                    this->valid.push_back(this->list_sepeda[i]);
                }
                else if (kriteria == 8 && list_sepeda[i].v_max[list_sepeda[i].v_max.size() - 1] >= stof(filter))
                {
                    this->valid.push_back(this->list_sepeda[i]);
                }

                i++;
            }

        }
};






