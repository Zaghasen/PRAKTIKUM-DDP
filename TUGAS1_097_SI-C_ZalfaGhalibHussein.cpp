#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	//MENGGUNAKAN VARIABLE INTEGER DAN STRING
    int stok, harga;                                        
    string namaproduk,kategoriproduk;
    
    //MENAMPILKAN NAMA TOKO DAN MENYAMBUT PEGAWAI
    cout << setw(82) << setfill(' ') <<"Selamat datang di Minimarket Al - Hussein!" <<  endl;    
    cout << setw(120) << setfill('=')<<""<<endl;
    cout << setw(75) << setfill(' ')<< "Program Minimarket Al - Hussein"<< setfill(' ')<< endl;
    cout << setw(120) << setfill('=')<<""<<endl;
    cout << "INPUT DATA MINIMARKET"<<endl;
    cout << setw(120) << setfill('-')<<""<<endl;
    
    //MEMINTA INPUT DARI PENGGUNA
    cout << "Kode Produk\t\t: ";
    char kodeproduk[6];
    cin.getline(kodeproduk,6);

    cout << "Nama Produk\t\t: ";
    getline(cin,namaproduk);

    cout <<"Kategori produk\t\t: ";
    getline(cin,kategoriproduk);

    cout << "Jumlah Stok\t\t: ";
    cin>>stok;
    cout << "Harga\t\t\t: ";
    cin>>harga;
    cout<< endl;

    //OUTPUT DARI INPUT YANG TELAH DIBERIKAN PENGGUNA YANG DISAJIKAN DALAM BENTUK TABEL
    cout << "OUTPUT DATA MINIMARKET"<<endl;
    cout << setw(120) << setfill('-')<<""<<endl;
    cout << "kode"<< setw(1)<< setfill(' ')<< "\t|\t";
    cout << "Nama"<< setw(1)<<setfill(' ')<<"\t|\t";
    cout << "Kategori"<< setw(1)<<setfill(' ')<<"\t|\t";
    cout << "stok"<< setw(1)<<setfill(' ')<<"\t|\t";
    cout << "harga"<< setw(1)<<setfill(' ')<<"\t|\t";
    cout << "jumlah harga"<< setw(1)<<setfill(' ')<<"\t|\t" <<endl;
    cout << setw(120) << setfill('-')<<""<<endl;

    cout << kodeproduk << setw(1)<< setfill(' ')<< "\t|\t";
    cout << namaproduk<<setw(1)<<setfill(' ')<<"\t|\t";
    cout << kategoriproduk<<setw(8)<<setfill(' ')<<"\t|\t";
    cout << stok<<setw(1)<<setfill(' ')<<"\t|\t";
    cout << harga<<setw(1)<<setfill(' ')<<"\t|\t";

    cout << stok*harga<<setw(8)<<setfill(' ')<<"\t|\t"<<endl;

    return 0;
}
