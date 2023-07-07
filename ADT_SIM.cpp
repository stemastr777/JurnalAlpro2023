#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

// Struktur alamat rumah
struct Alamat {
    std::string jalan;
    std::string kelurahan;
    std::string kota;
};

// Struktur nama 
struct Nama {
    std::string depan;
    std::string tengah;
    std::string belakang;
};

// Struktur tanggal
struct Tanggal {
    int tgl;
    int bulan;
    int tahun; 
};

// Struktur dokumen SIM
struct SIM {
    long no_SIM;
    char tipe_SIM;
    Nama nama_lengkap;
    std::string tempat_lahir;
    Tanggal tanggal_lahir;
    std::string golongan_darah;
    std::string jenis_kelamin;
    Alamat tempat_tinggal;
    std::string profesi;
    std::string provinsi_SIM; // Provinsi tempat SIM dibuat/diperpanjang
    Tanggal tanggal_kadaluwarsa;
};

// Prosedur untuk menginput data SIM
void inputData(SIM &sim) {

    std::cout << std::endl;
    std::cout << std::left << std::setw(30) << "Nomor SIM(hanya angka)" << ": " ;
    std::cin >> sim.no_SIM;
    std::cout << std::left << std::setw(30) << "Tipe SIM"  << ": ";
    std::cin >> sim.tipe_SIM;
    std::cout << std::left << std::setw(30) << "Nama lengkap" << std::endl;
        std::cout << std::setw(5) << " " << std::left << std::setw(25) << "Nama depan"  << ": ";
        std::cin >> sim.nama_lengkap.depan;
        std::cout << std::setw(5) << " " << std::left << std::setw(25) << "Nama tengah(jika ada)" << ": ";
        std::cin >> sim.nama_lengkap.tengah;
        std::cout << std::setw(5) << " " << std::left << std::setw(25) << "Nama belakang(jika ada)" << ": ";
        std::cin >> sim.nama_lengkap.belakang;
    std::cout << std::left << std::setw(30) << "Tempat lahir" << ": ";
    std::cin >> sim.tempat_lahir;
    std::cout << std::left << std::setw(30) << "Tanggal lahir" << std::endl;
        std::cout << std::setw(5) << " " << std::left << std::setw(25) << "Tanggal(1-31)" << ": ";
        std::cin >> sim.tanggal_lahir.tgl;
        std::cout << std::setw(5) << " " << std::left << std::setw(25) << "Bulan(1-12)" << ": ";
        std::cin >> sim.tanggal_lahir.bulan;
        std::cout << std::setw(5) << " " << std::left << std::setw(25) << "Tahun(yyyy)" << ": ";
        std::cin >> sim.tanggal_lahir.tahun;
    std::cout << std::left << std::setw(30) << "Golongan darah" << ": ";
    std::cin >> sim.golongan_darah;
    std::cout << std::left << std::setw(30) << "Jenis kelamin" << ": ";
    std::cin >> sim.jenis_kelamin;
    std::cout << std::left << std::setw(30) << "Tempat tinggal" << std::endl;
        std::cout << std::setw(5) << " " << std::left << std::setw(25) << "Jalan" << ": ";
        std::cin >> sim.tempat_tinggal.jalan;
        std::cout << std::setw(5) << " " << std::left << std::setw(25) << "Kelurahan" << ": ";
        std::cin >> sim.tempat_tinggal.kelurahan;
        std::cout << std::setw(5) << " " << std::left << std::setw(25) << "Kota" << ": ";
        std::cin >> sim.tempat_tinggal.kota;
    std::cout << std::left << std::setw(30) << "Profesi" << ": ";
    std::cin >> sim.profesi;
    std::cout << std::left << std::setw(30) << "Provinsi SIM" << ": ";
    std::cin >> sim.provinsi_SIM;
    std::cout << std::left << std::setw(30) << "Tanggal kadaluwarsa" << ": " << std::endl;
        std::cout << std::setw(5) << " " << std::left << std::setw(25) << "Tanggal(1-31)" << ": ";
        std::cin >> sim.tanggal_kadaluwarsa.tgl;
        std::cout << std::setw(5) << " " << std::left << std::setw(25) << "Bulan(1-12)" << ": ";
        std::cin >> sim.tanggal_kadaluwarsa.bulan;
        std::cout << std::setw(5) << " " << std::left << std::setw(25) << "Tahun(yyyy)" << ": ";
        std::cin >> sim.tanggal_kadaluwarsa.tahun;

}

void outputData(std::vector<SIM>& sim) {

    // Kamus lokal
    int size = sim.size();
    
    // Print baris header
    std::cout << std::setw(15) << "No_SIM";
    std::cout << std::setw(10) << "Tipe_SIM";
    std::cout << std::setw(20) << "Nama_pemilik";
    std::cout << std::setw(10) << "Tp_lahir";
    std::cout << std::setw(12) << "Tgl_lahir";
    std::cout << std::setw(10) << "Gol_dar";
    std::cout << std::setw(10) << "Jns_kel";
    std::cout << std::setw(20) << "Tp_tinggal";
    std::cout << std::setw(10) << "Profesi";
    std::cout << std::setw(10) << "Prov_SIM";
    std::cout << std::setw(10) << "Tgl_aktif";
    std::cout << std::endl;

    // Print isi
    for (int i = 0; i < size; i++) {
        std::cout << std::setw(15) <<  sim[i].no_SIM;
        std::cout << std::setw(10) <<  sim[i].tipe_SIM;
        std::cout << std::setw(20) << sim[i].nama_lengkap.depan + " " + sim[i].nama_lengkap.tengah + " " + sim[i].nama_lengkap.belakang;
        std::cout << std::setw(10) <<  sim[i].tempat_lahir;
        std::cout << std::setw(12) <<  std::to_string(sim[i].tanggal_lahir.tgl) + "-" +  std::to_string(sim[i].tanggal_lahir.bulan) + "-" + std::to_string(sim[i].tanggal_lahir.tahun);
        std::cout << std::setw(10) <<  sim[i].golongan_darah;
        std::cout << std::setw(10) << sim[i].jenis_kelamin;
        std::cout << std::setw(20) <<  sim[i].tempat_tinggal.jalan + "," +  sim[i].tempat_tinggal.kelurahan + "," +  sim[i].tempat_tinggal.kota;
        std::cout << std::setw(10) <<  sim[i].profesi;
        std::cout << std::setw(10) << sim[i].provinsi_SIM;
        std::cout << std::setw(10) << std::to_string(sim[i].tanggal_kadaluwarsa.tgl) + "-" + std::to_string(sim[i].tanggal_kadaluwarsa.bulan) + "-" + std::to_string(sim[i].tanggal_kadaluwarsa.tahun);
        std::cout << std::endl;
    }
}

// Prosedur pertukaran nilai elemen
template <typename T>
void swap(T *nilai1, T *nilai2) {
    auto temp = *nilai1;
    *nilai1 = *nilai2;
    *nilai2 = temp;
}

// Selection sort(ascending)
void selectionSort(std::vector<SIM>& arr, int kriteria) {

    // Kamus lokal
    int i = arr.size() - 1,
        j;
    int max_idx = 0;



    if (kriteria == 1) {
        
        while (i > 0) {
            
            max_idx = 0;
            j = 0;
            
            // Mencari nilai terbesar pada rentang [0..i]
            while (j <= i) {
                if (arr[j].no_SIM > arr[max_idx].no_SIM) {
                    max_idx = j;
                }
                j++;
            }
            
            swap(&arr[max_idx], &arr[i]); // Memindahkan nilai pada max ke index ke-i(paling belakang untuk setiap iterasi)
            i--;
        }
    } 
    else if (kriteria == 2) {
        while (i > 0) {
            
            max_idx = 0;
            j = 0;
            
            // Mencari nilai terbesar pada rentang [0..i]
            while (j <= i) {
                if (arr[j].tipe_SIM > arr[max_idx].tipe_SIM) {
                    max_idx = j;
                }
                j++;
            }
            
            swap(&arr[max_idx], &arr[i]); // Memindahkan nilai pada max ke index ke-i(paling belakang untuk setiap iterasi)
            i--;
        }
    }
    else if (kriteria == 3)
    {
        while (i > 0)
        {

            max_idx = 0;
            j = 0;

            // Mencari nilai terbesar pada rentang [0..i]
            while (j <= i)
            {
                std::string nama_j = arr[j].nama_lengkap.depan + arr[j].nama_lengkap.tengah + arr[j].nama_lengkap.belakang;
                std::string nama_max = arr[max_idx].nama_lengkap.depan + arr[max_idx].nama_lengkap.tengah + arr[max_idx].nama_lengkap.belakang;
                
                if (nama_j > nama_max)
                {
                    max_idx = j;
                }
                j++;
            }

            swap(&arr[max_idx], &arr[i]); // Memindahkan nilai pada max ke index ke-i(paling belakang untuk setiap iterasi)
            i--;
        }
    }
    else if (kriteria == 4)
    {
        while (i > 0)
        {

            max_idx = 0;
            j = 0;

            // Mencari nilai terbesar pada rentang [0..i]
            while (j <= i)
            {
                if (arr[j].tempat_lahir > arr[max_idx].tempat_lahir)
                {
                    max_idx = j;
                }
                j++;
            }

            swap(&arr[max_idx], &arr[i]); // Memindahkan nilai pada max ke index ke-i(paling belakang untuk setiap iterasi)
            i--;
        }
    }
    else if (kriteria == 5)
    {
        while (i > 0)
        {

            max_idx = 0;
            j = 0;

            // Mencari nilai terbesar pada rentang [0..i]
            while (j <= i)
            {
                int jarak_hari =    (arr[max_idx].tanggal_lahir.tgl - arr[max_idx].tanggal_lahir.tgl) + 
                                    (arr[max_idx].tanggal_lahir.bulan-arr[j].tanggal_lahir.bulan) * 30 + 
                                    (arr[max_idx].tanggal_lahir.tahun-arr[j].tanggal_lahir.tahun) * 365;
                if (jarak_hari < 0)
                {
                    max_idx = j;
                }
                j++;
            }

            swap(&arr[max_idx], &arr[i]); // Memindahkan nilai pada max ke index ke-i(paling belakang untuk setiap iterasi)
            i--;
        }
    }
    else if (kriteria == 6)
    {
        while (i > 0)
        {

            max_idx = 0;
            j = 0;

            // Mencari nilai terbesar pada rentang [0..i]
            while (j <= i)
            {
                if (arr[j].golongan_darah > arr[max_idx].golongan_darah)
                {
                    max_idx = j;
                }
                j++;
            }

            swap(&arr[max_idx], &arr[i]); // Memindahkan nilai pada max ke index ke-i(paling belakang untuk setiap iterasi)
            i--;
        }
    }
    else if (kriteria == 7)
    {
        while (i > 0)
        {

            max_idx = 0;
            j = 0;

            // Mencari nilai terbesar pada rentang [0..i]
            while (j <= i)
            {
                if (arr[j].jenis_kelamin > arr[max_idx].jenis_kelamin)
                {
                    max_idx = j;
                }
                j++;
            }

            swap(&arr[max_idx], &arr[i]); // Memindahkan nilai pada max ke index ke-i(paling belakang untuk setiap iterasi)
            i--;
        }
    }
    else if (kriteria == 8)
    {
        while (i > 0)
        {

            max_idx = 0;
            j = 0;

            // Mencari nilai terbesar pada rentang [0..i]
            while (j <= i)
            {
                std::string alamat_j = arr[j].tempat_tinggal.jalan + arr[j].tempat_tinggal.kelurahan + arr[j].tempat_tinggal.kota;
                std::string alamat_max = arr[max_idx].tempat_tinggal.jalan + arr[max_idx].tempat_tinggal.kelurahan + arr[max_idx].tempat_tinggal.kota;
                if (alamat_j > alamat_max)
                {
                    max_idx = j;
                }
                j++;
            }

            swap(&arr[max_idx], &arr[i]); // Memindahkan nilai pada max ke index ke-i(paling belakang untuk setiap iterasi)
            i--;
        }
    }
    else if (kriteria == 9)
    {
        while (i > 0)
        {

            max_idx = 0;
            j = 0;

            // Mencari nilai terbesar pada rentang [0..i]
            while (j <= i)
            {
                if (arr[j].profesi > arr[max_idx].profesi)
                {
                    max_idx = j;
                }
                j++;
            }

            swap(&arr[max_idx], &arr[i]); // Memindahkan nilai pada max ke index ke-i(paling belakang untuk setiap iterasi)
            i--;
        }
    }
    else if (kriteria == 10)
    {
        while (i > 0)
        {

            max_idx = 0;
            j = 0;

            // Mencari nilai terbesar pada rentang [0..i]
            while (j <= i)
            {
                if (arr[j].provinsi_SIM > arr[max_idx].provinsi_SIM)
                {
                    max_idx = j;
                }
                j++;
            }

            swap(&arr[max_idx], &arr[i]); // Memindahkan nilai pada max ke index ke-i(paling belakang untuk setiap iterasi)
            i--;
        }
    }
    else if (kriteria == 11)
    {
        while (i > 0)
        {

            max_idx = 0;
            j = 0;

            // Mencari nilai terbesar pada rentang [0..i]
            while (j <= i)
            {
                int jarak_hari = (arr[max_idx].tanggal_kadaluwarsa.tgl - arr[max_idx].tanggal_kadaluwarsa.tgl) +
                                 (arr[max_idx].tanggal_kadaluwarsa.bulan - arr[j].tanggal_kadaluwarsa.bulan) * 30 +
                                 (arr[max_idx].tanggal_kadaluwarsa.tahun - arr[j].tanggal_kadaluwarsa.tahun) * 365;
                if (jarak_hari < 0)
                {
                    max_idx = j;
                }
                j++;
            }

            swap(&arr[max_idx], &arr[i]); // Memindahkan nilai pada max ke index ke-i(paling belakang untuk setiap iterasi)
            i--;
        }
}
}

int main() {

    // Kamus global
    std::vector<SIM> arr;
    int size = 0;
    int kriteria = 1;

    // Input data SIM
    int lagi = 1;
    while (lagi == 1) {
        arr.push_back({});
        inputData(arr[size]);
        size += 1;
        std::cout << "Masukkan data lagi?(1 | 0) ";
        std::cin >> lagi;
    }

    // Output data SIM
    outputData(arr);
    
    // Pilih kriteria untuk pengurutan
    int urut = 1;
    while (urut == 1) {
        std::cout << std::endl << std::endl << "Pilih kriteria untuk mengurutkan" << std::endl << std::endl;
        std::cout << "1 : Nomer SIM (default)" << std::endl
                << "2 : Tipe SIM" << std::endl
                << "3 : Nama lengkap" << std::endl
                << "4 : Tempat lahir" << std::endl
                << "5 : Tanggal lahir" << std::endl
                << "6 : Golongan darah" << std::endl
                << "7 : Jenis kelamin" << std::endl
                << "8 : Tempat tinggal" << std::endl
                << "9 : Profesi" << std::endl
                << "10: Provinsi SIM" << std::endl
                << "11: Tanggal kadaluwarsa" << std::endl;
        std::cout << "Kriteria yang dipilih: ";
        std::cin >> kriteria;

        // Output setelah pengurutan
        selectionSort(arr, kriteria);

        std::cout << std::endl << "Data setelah diurutkan" << std::endl << std::endl;
        outputData(arr);

        std::cout << std::endl << "Urutkan lagi?(1 | 0) ";
        std::cin >> urut;
    }

    
    

    return 0;
}