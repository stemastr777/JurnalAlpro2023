#include "interfaceKasir.h"

/*
    Judul    : Program kasir fotokopi
    Kelompok : A11.4210 (Kelompok 5)
    Anggota  :
       1. Muhammad Addissahhilna  (A11.2022.14200)
       2. Arizal Irsyad Imanullah (A11.2022.14224)
       3. Aji Bayu Wicaksono      (A11.2022.14262)
       4. Steven Adi Suryanto     (A11.2022.14623)
*/

/* 
    NOTE: untuk menjalankan program ini harus dengan terminal yang fullscreen untuk memastikan bahwa output bisa 
          ditampilkan dengan benar. 
*/

// Program utama
int main() {

    // Menginialisasi kasir
    Kasir kasir;

    // Membuka halaman utama dari kasir
    kasir.menu_utama();

    return 0;
}