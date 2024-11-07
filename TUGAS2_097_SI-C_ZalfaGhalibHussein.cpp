#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	//MENGGUNAKAN VARIABLE INTEGER DAN STRING
    int jumlah_barang,total_pembayaran, subtotal[1000];
    
    //MENAMPILKAN NAMA TOKO DAN MENYAMBUT PEGAWAI
    cout << setw(82) << setfill(' ') <<"Selamat datang di Minimarket Al - Hussein!" <<  endl;    
    cout << setw(120) << setfill('=')<<""<<endl;
    cout << setw(75) << setfill(' ')<< "Program Minimarket Al - Hussein"<< setfill(' ')<< endl;
    cout << setw(120) << setfill('=')<<""<<endl;
    
    //MEMINTA INPUT DARI PENGGUNA
    cout << "\nMasukkan Jumlah Beli : ";
    cin >> jumlah_barang;
    cout << endl;

    cout << setw(20) << setfill('-')<<""<<endl;

    string nama_barang[jumlah_barang];
    int jumlah_produk[jumlah_barang], harga[jumlah_barang];
    for (int i = 0; i < jumlah_barang; i++) {
        cout << "Masukkan Barang ke-" << i+1 << "\n";
        cout << setw(20) << setfill('-')<<""<<endl;
        cout << "Nama Barang\t: ";
        cin >> nama_barang[i];
        cout << "Jumlah\t\t: ";
        cin >> jumlah_produk[i];
        cout << "Harga\t\t: ";
        cin >> harga[i];
        cout << endl;
    }
    //OUTPUT DARI INPUT YANG TELAH DIBERIKAN PENGGUNA YANG DISAJIKAN DALAM BENTUK STRUK BELANJA
    cout << setw(120) << setfill('-')<<""<<endl;
    cout << setw(5)<< setfill(' ')<< "NO";
    cout << setw(20)<<setfill(' ')<<"Nama Barang";
    cout << setw(10)<<setfill(' ')<<"Jumlah";
    cout << setw(15)<<setfill(' ')<<"Harga";
    cout << setw(20)<<setfill(' ')<<"Sub total"<<endl;
    cout << setw(120) << setfill('-')<<""<<endl;
    
    for(int i=0; i<jumlah_barang; i++){
		subtotal[i]= harga[i]*jumlah_produk[i];
		cout << setw(5)<< setfill(' ')<< i+1;
		cout << setw(20)<<setfill(' ')<<nama_barang[i];
		cout << setw(10)<<setfill(' ')<<jumlah_produk[i];
		cout << setw(15)<<setfill(' ')<<harga[i];
		cout << setw(20)<<setfill(' ')<<subtotal[i]<<endl;
        total_pembayaran += subtotal[i];}
        
    int total_pembelian, bayar;
    int diskon = 0;

    total_pembelian = total_pembayaran;

    // MENGHITUNG DISKON SESUAI DENGAN KETENTUAN
    if (total_pembelian > 100000) {
        diskon = total_pembelian * 6 / 100;  // Diskon 6% untuk pembelian di atas Rp. 100.000
    } else if (total_pembelian > 50000) {
        diskon = total_pembelian * 4 / 100;  // Diskon 4% untuk pembelian di atas Rp. 50.000
    } else if (total_pembelian > 25000) {
        diskon = total_pembelian * 2 / 100;  // Diskon 2% untuk pembelian di atas Rp. 25.000
    }

    // MENGHITUNG JUMLAH BAYAR SETELAH DISKON
    int jumlah_bayar = total_pembelian - diskon;

    // MENAMPILKAN JUMLAH BAYAR DAN DISKON
    cout << "Total Pembelian : Rp. " << total_pembelian-1 << endl;
    cout << "Diskon (" << (diskon * 100 / total_pembelian+1) << "%) : Rp. " << diskon << endl;
    cout << "Total Bayar: Rp. " << jumlah_bayar-1 << endl;
    cout << "Bayar\t: Rp. ";
    cin >> bayar;
    cout << "Kembali\t: Rp. " << bayar - jumlah_bayar+1;

    return 0;
}
