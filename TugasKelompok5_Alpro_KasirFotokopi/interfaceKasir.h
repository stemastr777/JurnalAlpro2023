#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include "record.h"
#include <ctime>


class Kasir {
    public:

        // Attribute
        std::vector<Record> list_record; // Array untuk menyimpan data dari file
        std::vector<Record> valid;       // Array untuk menyimpan hasil pencarian

        // Constructor kamus
        Kasir() {
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

            } 
            else if (pilihan_menu_utama == 2) {
                std::cout << "\033[2J\033[1;1H";
                std::cout << "=======================================================================================\n";
                std::cout << "                                   Database transaksi                                     \n";
                std::cout << "=======================================================================================\n\n";
                outputData(list_record);
                menu_tambahan();
            } 
            else if (pilihan_menu_utama == 3) {
                std::cout << "\033[2J\033[1;1H";
                std::cout << "=======================================================================================\n";
                std::cout << "                                   Pencarian transaksi                                    \n";
                std::cout << "=======================================================================================\n\n";
                std::cout << "                             __________________________________                            \n\n";
                std::cout << "                               |    1. Nama                  |                            \n";
                std::cout << "                               |    2. Total minimum         |                            \n";
                std::cout << "                               |    3. Tanggal minimum       |                            \n";
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
            std::string id_pilihan = "-1";

            std::cout << std::endl;
            std::cout << "                               __________________________________                            \n\n";
            std::cout << "                               |    1. Lihat nota               |                            \n";
            std::cout << "                               |    2. Kembali ke menu utama    |                            \n";
            std::cout << "                               __________________________________                            \n\n";
            std::cout << "Input menu yang ingin dipilih: ";
            std::cin >> pilihan;

            // Pilih menu
            if (pilihan == 1) {
                std::cout << "\033[2J\033[1;1H";
                std::cout << "=======================================================================================\n";
                std::cout << "                                      Nota Transaksi                                   \n";
                std::cout << "=======================================================================================\n\n";

                if (this->valid.size() == 0) {
                    outputData(list_record);
                } else {
                    outputData(valid);
                }
                

                // Memilih record yang ingin dicek
                while (id_pilihan == "-1") {
                    std::cout << std::endl;
                    std::cout << "Masukkan id transaksi yang mau dicek: ";
                    std::cin >> id_pilihan;

                    int i = 0;
                    while (i < list_record.size()) {
                        Record rec = list_record[i];
                        if (rec.id == id_pilihan) {

                            buatNota(rec);
            
                            break;
                        }
                        i++;
                    }

                    if (i == list_record.size()) {
                        std::cout << "Id transaksi tidak ditemukan. Coba lagi\n"; 
                        id_pilihan = "-1";
                    }
                }

                menu_tambahan();

            } 
            else if (pilihan == 2) {
                menu_utama();
            } 
        }

        // Menyamakan state list transaksi pada kamus dengan data pada data_transaksi.txt
        void sinkron_file() {
            std::ifstream infile("data_transaksi.txt", std::ios::in);
            std::string line, curr_data;

            this->list_record = {};

            while (getline(infile, line))
            {
                Record curr_transaksi;
                std::istringstream iss(line);

                // Id transaksi
                getline(iss, curr_data, ',');
                curr_transaksi.id = curr_data;

                // Nama pelanggan
                getline(iss, curr_data, ',');
                curr_transaksi.pelanggan = curr_data;

                // Total harga (tidak dimasukkan agar tidak double)
                getline(iss, curr_data, ',');

                // Hari pencatatan
                getline(iss, curr_data, ',');
                curr_transaksi.Tanggal.hari = stoi(curr_data);

                // Bulan pencatatan
                getline(iss, curr_data, ',');
                curr_transaksi.Tanggal.bulan = stoi(curr_data);

                // Tahun pencatatan
                getline(iss, curr_data, ';');
                curr_transaksi.Tanggal.tahun = stoi(curr_data);


                // Layanan
                std::string data_layanan;
                while (getline(iss, data_layanan, ';'))
                {

                    std::stringstream iss2(data_layanan);
                    getline(iss2, curr_data, ',');

                    if (curr_data == "1")
                    {
                        getline(iss2, curr_data);
                        curr_transaksi.addFotokopi(stoi(curr_data));
                    }
                    else if (curr_data == "2")
                    {
                        getline(iss2, curr_data);
                        curr_transaksi.addJilid(stoi(curr_data));
                    }
                    else if (curr_data == "3")
                    {

                        std::vector<int> placeholder;

                        // Mengambil data warna
                        getline(iss2, curr_data, ',');
                        placeholder.push_back(stoi(curr_data));

                        // Mengambil data jumlah kertas print
                        getline(iss2, curr_data);
                        placeholder.push_back(stoi(curr_data));

                        curr_transaksi.addPrint(placeholder[0], placeholder[1]);
                    }
                }

                list_record.push_back(curr_transaksi);
            }

            infile.close();
            std::cout << list_record[1].data_jd.mika;
        }

        // Memasukkan transaksi baru ke database
        void inputData()
        {

            // Kamus lokal
            std::ofstream offile("data_transaksi.txt", std::ios::app);
            Record transaksi_baru;
            int pilihan_layanan;
            char pilih = 'y';

            // Algoritma
            std::cout << "\033[2J\033[1;1H";
            std::cout << "=======================================================================================\n";
            std::cout << "                                   Tambah Record                                       \n";
            std::cout << "=======================================================================================\n\n";

            std::cout << "Nama pelanggan: ";
            std::cin >> transaksi_baru.pelanggan;

            // Random number generator untuk id transaksi
            srand((unsigned)time(NULL));
            transaksi_baru.id = std::to_string(rand() % 10000);

            // Input tanggal otomatis
            time_t waktu = time(0);
            std::tm *now = std::localtime(&waktu);
            
            transaksi_baru.Tanggal.tahun = 1900 + now->tm_year;
            transaksi_baru.Tanggal.bulan = 1 + now->tm_mon;
            transaksi_baru.Tanggal.hari = now->tm_mday;

            std::cout<< std::endl;
            std::cout << "                               ________________________________                           \n\n";
            std::cout << "                               |    1. Fotokopi               |                            \n";
            std::cout << "                               |    2. Jilid                  |                            \n";
            std::cout << "                               |    3. Print                  |                            \n";
            std::cout << "                               ________________________________                             \n\n";
            

            while (pilih == 'y') {

                std::cout << "Pilih layanan: ";
                std::cin >> pilihan_layanan;

                // Apabila layanan sudah ada dan tidak mau diubah
                if (transaksi_baru.checkDuplicate(pilihan_layanan) == -1) {
                    continue;
                }

                if (pilihan_layanan == 1) {

                    int jml_kertas;
                    std::cout << "Masukkan jumlah kertas hasil fotokopi: ";
                    std::cin >> jml_kertas;

                    transaksi_baru.addFotokopi(jml_kertas);

                } else if (pilihan_layanan == 2) {

                    int mika;
                    std::cout << "Apakah pakai mika? (1 | 0):  ";
                    std::cin >> mika;

                    transaksi_baru.addJilid(mika);

                } else if (pilihan_layanan == 3) {

                    int warna;
                    int jml_kertas;

                    std::cout << "Apakah hasil berwarna? (1 | 0):  ";
                    std::cin >> warna;

                    std::cout << "Masukkan jumlah kertas hasil print: ";
                    std::cin >> jml_kertas;

                    transaksi_baru.addPrint(warna, jml_kertas);

                } else {
                    std::cout << "Pilihan tidak valid. Coba lagi." << std::endl;
                    continue;
                }
                
                // Apabila semua sudah dimasukkan
                if (transaksi_baru.signal.size() == 3) {
                    break;
                }

                std::cout << "Mau pilih yang lain lagi? (y/n)";
                std::cin >> pilih;
            }

            offile << transaksi_baru.id << ',' << transaksi_baru.pelanggan << ',' << transaksi_baru.total_harga << ','
                   << transaksi_baru.Tanggal.hari << ',' << transaksi_baru.Tanggal.bulan << ','
                   << transaksi_baru.Tanggal.tahun << ';';
            for (int i = 0; i < transaksi_baru.signal.size(); i++) {

                if (transaksi_baru.signal[i] == 1) {
                    offile << 1 << ',' << transaksi_baru.data_fc.jml_kertas << ';';
                } else if (transaksi_baru.signal[i] == 2) {
                    offile << 2 << ',' << transaksi_baru.data_jd.mika << ';';
                } else if (transaksi_baru.signal[i] == 3) {
                    offile << 3 << ',' << transaksi_baru.data_pr.warna << ',' << transaksi_baru.data_pr.jml_kertas << ';';
                }

            }
            offile << std::endl;
            offile.close();

            // Menyinkronkan kamus dengan data di file
            sinkron_file();

            std::cout << "Data berhasil diinput." << std::endl;

            // Tampilkan nota
            buatNota(transaksi_baru);
        
            menu_tambahan();
        }

        // Prosedur output data
        void outputData(std::vector<Record> arr)
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
            std::cout << std::setw(20) << "nm_plg";
            std::cout << std::setw(10) << "total";
            std::cout << std::setw(15) << "tanggal";
            std::cout << "\n======================================================="; 
            std::cout << std::endl;

            while (i < arr.size())
            {
                std::cout << std::setw(10) << arr[i].id;
                std::cout << std::setw(20) << arr[i].pelanggan;
                std::cout << std::setw(10) << arr[i].total_harga;
                std::cout << std::setw(15) << std::to_string(arr[i].Tanggal.hari) + "-" + std::to_string(arr[i].Tanggal.bulan) + "-" + std::to_string(arr[i].Tanggal.tahun);
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
            Record::tanggal filterTanggal;

            // Algoritma
            std::cout << "Pilih kriteria: ";
            std::cin >> kriteria;

            if (kriteria == 1) {
                std::cout << "Ketik nama pelanggan yang ingin dicari: ";
                std::cin >> filter;
            } else if (kriteria == 2) {
                std::cout << "Masukan total minimal : ";
                std::cin >> filter;
            } else if (kriteria == 3) {
                std::cout << "Masukkan hari: ";
                std::cin >> filterTanggal.hari;
                std::cout << "Masukkan bulan: ";
                std::cin >> filterTanggal.bulan;
                std::cout << "Masukkan tahun: ";
                std::cin >> filterTanggal.tahun;
            }
            

            // Mengambil record yang memenuhi
            int i = 0;
            while (i < list_record.size())
            {

                // Apabila memenuhi
                if (kriteria == 1 && list_record[i].pelanggan == filter) {
                    this->valid.push_back(this->list_record[i]);
                }
                else if (kriteria == 2 && list_record[i].total_harga >= stoi(filter)) {
                    this->valid.push_back(this->list_record[i]);
                }
                else if (kriteria == 3) {

                    if (
                        list_record[i].Tanggal.tahun > filterTanggal.tahun ||
                        list_record[i].Tanggal.tahun == filterTanggal.tahun && list_record[i].Tanggal.bulan > filterTanggal.bulan ||
                        list_record[i].Tanggal.tahun == filterTanggal.tahun && list_record[i].Tanggal.bulan == filterTanggal.bulan && list_record[i].Tanggal.hari >= filterTanggal.hari
                    )
                    {
                        this->valid.push_back(this->list_record[i]);
                    }
                }

                i++;
            }

        }

        // Prosedur untuk membuat nota
        void buatNota(Record transaksi)
        {

            std::cout << "\033[2J\033[1;1H";
            std::cout << "=======================================================================================\n";
            std::cout << "                                      Nota Transaksi                                   \n";
            std::cout << "=======================================================================================\n\n";

            std::cout << "Id transaksi   : " << transaksi.id << std::endl;
            std::cout << "Nama pelanggan : " << transaksi.pelanggan << std::endl;
            std::cout << "Tanggal cetak  : " << transaksi.Tanggal.hari << '-' << transaksi.Tanggal.bulan << '-'
                      << transaksi.Tanggal.tahun;

            // Bagian layanan
            std::cout << "\n\n===========LAYANAN============\n";

            for (int i = 0; i < transaksi.signal.size(); i++)
            {
                if (transaksi.signal[i] == 1)
                {
                    std::cout << "\nFOTOCOPY\n";
                    std::cout << "    Jumlah kertas : " << transaksi.data_fc.jml_kertas << "\n";
                }
                else if (transaksi.signal[i] == 2)
                {
                    std::cout << "\nJILID\n";
                    std::cout << "    Pakai mika atau tidak : " << transaksi.data_jd.mika << "\n";
                }
                else if (transaksi.signal[i] == 3)
                {
                    std::cout << "\nPRINT\n";
                    std::cout << "    Jumlah kertas       : " << transaksi.data_pr.jml_kertas << "\n";
                    std::cout << "    Berwarna atau tidak : " << transaksi.data_pr.warna << "\n";
                }
            }

            std::cout << "\n==============================\n";

            // Bagian harga
            for (int i = 0; i < transaksi.signal.size(); i++) {

                if (transaksi.signal[i] == 1)
                {
                    std::cout << "\nFotokopi : " << std::setw(15) << std::left << std::to_string(transaksi.data_fc.jml_kertas) + " x 200";
                    std::cout << "= " << transaksi.data_fc.total;
                }
                else if (transaksi.signal[i] == 2)
                {
                    if (transaksi.data_jd.mika == 1) {
                        std::cout << "\nJilid    : " << std::setw(15) << std::left << " 1 x 2000";
                        std::cout << "= " << transaksi.data_jd.total;
                    } else {
                        std::cout << "\nJilid    : " << std::setw(15) << std::left << " 1 x 1000";
                        std::cout << "= " << transaksi.data_jd.total;
                    }
                    
                }
                else if (transaksi.signal[i] == 3)
                {
                    if (transaksi.data_pr.warna == 1) {
                        std::cout << "\nPrint    : " << std::setw(15) << std::left << std::to_string(transaksi.data_pr.jml_kertas) + "  x 500";
                        std::cout << "= " << transaksi.data_pr.total;
                    } else {
                        std::cout << "\nPrint    : " << std::setw(15) << std::left << std::to_string(transaksi.data_pr.jml_kertas) + "  x 300";
                        std::cout << "= " << transaksi.data_pr.total;
                    }
                }
            }
            std::cout << "\n---------------------------------- +\n";
            std::cout << std::setw(26) << "Total harga" << "= " << transaksi.total_harga;

            std::cout << "\n\n=======================================================================================";
        }
};






