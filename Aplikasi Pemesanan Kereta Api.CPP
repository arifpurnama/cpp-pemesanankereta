#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <sendiri.h>

judul() // Function
	{
		cout << "\t\t--------------------------------------------\n";
		cout << "\t\t-------- Program Pemesanan Tiket KA --------\n";
		cout << "\t\t------------- STATIUN SUKABUMI -------------\n";
		cout << "\t\t--------------------------------------------\n\n";
  	}

struct Petugas // Struct
{
	int jumlahpesanan;
	char tanggal[30],namapetugas[25];
}petugas;   // objek struct

void TampilkanPetugas(Petugas *data); // Struct dan Pointer

class Pesanan
{
	public:
	char namapemesan[20],ke[20],namatujuan[20],namakelas[10],namakereta[20];
	int kelas,harga;
};

main ()
{
	home: //label
   clrscr();
	int opsi;
	judul();
	cout<<"\n1.Pembelian Tiket\n";
	cout<<"2.Keluar\n";
	cout<<"--------------------------------------------\n";
	cout<<"Silahkan Masukkan Pilihan Anda : ";cin>>opsi;
	
	if(opsi==1)
   {
   menu: // Label
	int i,kode,total=0,bayar;
	char lagi;
		Pesanan kereta[10]; // Pendefinition object Class dengan Nama Kereta
   	clrscr();
	judul(); // Function
   	cout << "============================== Data Petugas"<<endl;
		cout << "Masukan Nama Petugas\t: "; gets(petugas.namapetugas);
		cout << "Masukan Tanggal\t\t: "; gets(petugas.tanggal);
		cout << "Input Jumlah Tiket\t: "; cin >> petugas.jumlahpesanan;
   input: // label
   clrscr();
   judul();
   		cout << "============================== Data Pemesan"<<endl;
		for (i=1;i<=petugas.jumlahpesanan;i++) // perulangan
		{
				cout << "Tiket Ke- " << i << endl;
				cout << "Nama Pemesan\t\t\t\t: "; gets(kereta[i].namapemesan);
				cout << "Kode Asal Keberangkatan\t\t\t: SMI " << endl;
				cout << "Kode Tujuan Keberangkatan[BGR/CJR]\t: "; gets(kereta[i].namatujuan);
				cout << "Kelas Kereta [1/2]\t\t\t: "; cin >> kereta[i].kelas;
				cout << endl;

        if ((strcmp(kereta[i].namatujuan,"BGR")==0) || (strcmp(kereta[i].namatujuan,"bgr")==0)) // kondisi
				{
					strcpy(kereta[i].ke,"BOGOR");
						if (kereta[i].kelas == 1)
						{
							kereta[i].harga=50000;
								strcpy(kereta[i].namakelas,"EKSEKUTIF");
                     				strcpy(kereta[i].namakereta,"KA PANGRANGGO");
						}
							else if(kereta[i].kelas == 2)
							{
								kereta[i].harga=20000;
									strcpy(kereta[i].namakelas,"EKONOMI");
                        				strcpy(kereta[i].namakereta,"KA PANGRANGGO");
							}
								else{
					                	cout << "\t PILIHAN TIDAK DI TEMUKAN - Tekan ENTER untuk Input Kembali"<< endl;
					                		tahan();
					                			goto input;
									}				            
				}
			else if ((strcmp(kereta[i].namatujuan,"CJR")==0) || (strcmp(kereta[i].namatujuan,"cjr")==0))
               	{
					strcpy(kereta[i].ke,"CIANJUR");
						if (kereta[i].kelas == 1 || kereta[i].kelas == 2)
						{
							kereta[i].harga=3000;
								strcpy(kereta[i].namakelas,"PERINTIS");
                     				strcpy(kereta[i].namakereta,"KA SILIWANGI");
						}
						else{
				                	cout << "\t PILIHAN TIDAK DI TEMUKAN - Tekan ENTER untuk Input Kembali"<< endl;
				                		tahan();
				                			goto input;			           	
							}
				}
	        else{
					cout << "\t PILIHAN TIDAK DI TEMUKAN - Tekan ENTER untuk Input Kembali"<< endl;
				    	tahan();
				    		goto input;				                	
				}
		}
      clrscr();

      TampilkanPetugas(&petugas); // Menampikan hasil pointer
      	cout << "-------------------------------------------------------------------------------"<<endl;
		cout << "    ************* PRINT OUT SYSTEM PT. KERETA API INDONESIA ************* "<< endl;
      	cout << "-------------------------------------------------------------------------------\n"<<endl;

			 // Menampilkan Data Hasil Input
      for(i=1;i<=petugas.jumlahpesanan;i++)
      {
      cout << "Tiket ke-" << i << " Dari " << petugas.jumlahpesanan << endl;
          // Penggunaan Random untuk Menghasilkan Kode Booking
					srand(time(NULL)); // srand untuk menentukan seed atau titik awal pengacakan (Number)
					kode = rand(); // time(NULL) untuk seed dengan perhitungan mengembalikan nilai sesuai dengan banyaknya detik sejak 1/1/1970
		cout << "Kode Booking\t: " << kereta[i].namatujuan << "-" <<kereta[i].kelas << kode << endl;
		cout << "Nama Pemesan\t: " << kereta[i].namapemesan;
        	gotoxy(40,wherey()); cout << "Nama Kereta\t: " << kereta[i].namakereta << endl;
		cout << "Kota Asal\t: SUKABUMI";
        	gotoxy(40,wherey()); cout << "Nama Kelas\t: " << kereta[i].namakelas << endl;
		cout << "Kota Tujuan\t: " << kereta[i].ke;
        	gotoxy(40,wherey()); cout << "Harga\t\t: Rp. " << kereta[i].harga << endl;
      cout << endl;
      cout << "-------------------------------------------------------------------------------"<<endl;
			total=total+kereta[i].harga;
      }
      cout << "     ------------ TIKET INI DI CETAK OTOMATIS OLEH SYSTEM ----------------"<<endl;
      cout << "     -------------  HARAP TUNJUKAN TIKET INI KE PETUGAS  -----------------"<<endl;
      cout << "-------------------------------------------------------------------------------"<<endl;
      
      cout << "Total Harga Yang Harus Di Bayar "; // total harga
      		gotoxy(58, wherey()); cout << ":Rp. "<< total << endl;
      cout << "Bayar "; // Input Bayar
      		gotoxy(58, wherey()); cout << ":Rp. "; cin >> bayar;
      cout << "Kembalian "; // perhitungan kembali di ambli dari header sendiri.h
      	  	gotoxy(58, wherey()); cout << ":Rp. " << kembalian << endl << endl << endl;	// menampikan kembalian
      	  	
      gotoxy(10,wherey()); cout << "------ TERIMAKASIH SEMOGA PERJALANAN ANDA MENYENANGKAN ------" <<endl;
      gotoxy(10,wherey()); cout << "-------------------------------------------------------------\n" <<endl;
      cout<<"Press any key to continue...";
        tahan();
        goto home;
	}
		else if (opsi == 2){
	  		goto exit;
    }
     			else {
            cout << "\nPILIHAN TIDAK DI TEMUKAN - Silahkan TEKAN ENTER dan PILIH 1 atau 2";
            	tahan();
       				goto home;
    }	
         tahan(); //pengantian dilakukan di file header sendiri.h
         exit:
}

void TampilkanPetugas(Petugas *data) // deklarasi pointer
{
	cout << "Nama Petugas\t: " << data->namapetugas<< endl;  // anggota nama petugas dari objek data
	cout << "Tanggal\t\t: " << data->tanggal<< endl;
}

