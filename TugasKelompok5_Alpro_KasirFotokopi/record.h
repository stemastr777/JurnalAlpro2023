#include <vector>
#include <string>
#include "layanan.h"

class Record {

    public:
        
        struct tanggal
        {
            int hari;
            int bulan;
            int tahun;
        };

        std::string id;
        std::string pelanggan;
        tanggal Tanggal;
        int total_harga = 0;
        Fotokopi data_fc;        // Data layanan fotokopi pada record
        Jilid data_jd;           // Data layanan jilid pada record
        Print data_pr;           // Data layanan print pada record
        std::vector<int> signal; // Penanda layanan yang aktif

        void addFotokopi(int jml_kertas) {
            this->data_fc.jml_kertas = jml_kertas;
            total_harga += this->data_fc.hitungHarga();
            this->signal.push_back(1);
        }

        void addJilid(int mika) {
            this->data_jd.mika = mika;
            total_harga += this->data_jd.hitungHarga();
            this->signal.push_back(2);
        }

        void addPrint(int warna, int jml_kertas) {
            this->data_pr.warna = warna;
            this->data_pr.jml_kertas = jml_kertas;
            total_harga += this->data_pr.hitungHarga();
            this->signal.push_back(3);
        }

        int checkDuplicate(int pilihan_layanan) {

            // Cek pilihan layanan
            for (int i = 0; i < this->signal.size(); i++)
            {
                if (this->signal[i] == pilihan_layanan)
                {
                    char approve;
                    std::cout << "Layanan sudah terpilih. Apakah anda ingin menumpuk data sebelumnya?(y/n) : ";
                    std::cin >> approve;
                    if (approve != 'y') {
                        return -1;
                    } else {
                        this->signal.erase(this->signal.begin() + i);
                        
                        if (signal[i] == 1) {
                            this->total_harga -= this->data_fc.total;
                        } else if (signal[i] == 2) {
                            this->total_harga -= this->data_jd.total;
                        } else if (signal[i] == 3) {
                            this->total_harga -= this->data_pr.total;
                        }

                        return 1;
                    }
                }
            }
            return 0;
        }

};