#include <iostream>
#include <conio.h>
using namespace std;


//Halo jon
struct node
{
       int data;
       node *prev;
       node *next;
};

node *head = NULL, *tail = NULL, *cari, *hapus;

int x;

//Prosedur untuk menampilkan data pada Double linked Circular list dari head
void tampil()
{
   node *bantu;
   bantu = head;
   if (head != NULL)
   {
		do 
		{
			cout<<bantu->data<<" ";
			bantu=bantu->next;
		}
		while(bantu!=head);
   }
   else
   {
   	cout<<"Data masih kosong";
   }
	cout<<endl;
}

//Ivano Done
void insert_diawal(int data)
{
	if (head != NULL)
	{
		head->prev = new node;
		head->prev->data = data;
		head->prev->next = head;
		head->prev->prev = tail;
		head = head->prev;
		tail->next = head;
	}
	else
	{
		head = new node;
		head->data = data;
		head->prev = head;
		head->next = head;
		tail = head;
	}
}

void insert_sebelum(int data, int x)
{
	node *masuk;
	masuk = new node;
	masuk->data = data;
	cari = head;
	while (cari->next != head)
	{
		cari = cari->next;
	}
	if (cari->data == x)
	{
    	if (cari == head)
    	{
    		masuk->next = head;
    		masuk->prev = tail;
    		head->prev   = masuk;
    		head = masuk; 
    		tail -> next = head;
		}
		else if (cari = tail)
		{
    		tail->prev->next = masuk;
			masuk->prev = tail->prev;
			tail->prev = masuk;
			masuk->next = tail;
		}
		else
		{
			cari->prev->next = masuk;
			masuk->prev = cari->prev;
			cari->prev = masuk;
			masuk->next = cari;
		}
	}
	cout<<endl;
}

void insert_setelah(int data,int x)
{
	node *masuk;
	masuk = new node;
	masuk->data = data;
	cari = head;
	while ((cari->data != x)&&(cari->next != head)){
    		cari = cari->next;
	}
	if (cari->data == x){
		masuk->prev = cari;
		masuk->next = cari->next;
		cari->next = masuk;
		cari->next->prev = masuk;
	}
	cout<<endl;
}

//Yulia Done
void insert_akhir(int data)
{
	if(head != NULL)
	{
		tail->next = new node;
		tail->next->data = data;
		tail->next->prev = tail;
		tail->next->next = head;
		tail = tail->next;
		head->prev = tail;		
	}
	else
	{
		head = new node;
		head->data = data;
		head->prev = head;
		head->next = head;
		tail = head;
	}
}
	
//Tia Done
void delete_awal()
{
	if (head == tail)
	{
		head = NULL;
	}
	else
	{
		hapus=head;
		head=head->next;
		head->prev=tail;
		tail->next = head;
		delete hapus;
	}
	
}

void delete_tertentu(int x)
{
	cari = head;
	while (cari->data != x)
	{
		cari = cari->next;
	}
	if (cari == head)
	{
		hapus = head;
		head = head->next;
		head->prev = tail;
		tail->next = head;
		delete hapus;
	}
	else if (cari == tail)
	{
		hapus = tail;
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
		delete hapus;
	}
	else
	{
		hapus = cari;
		hapus->prev->next = cari->next;
		hapus->next->prev = cari->prev;
		delete hapus;
	}
}

void delete_setelah()
{
	cari = head;
	while ((cari->data != x)&&(cari->next != head)){
	    cari = cari->next;
	}
	if (cari->next->data != head->data){
	hapus = cari->next;
	cari->next = hapus->next;
	hapus->next->prev = cari;
	hapus->prev = NULL;
	hapus->next = NULL;
	delete hapus;
	}
	else {
	    cout<<"Data tidak ditemukan";
	}
	cout<<endl;
}

//Fay Done
void delete_akhir()
{
	if(head != tail)
	{
		hapus = tail;
		hapus->prev->next= tail->next;
		hapus->next->prev= tail->prev;
		tail = tail->prev;
		tail->next = head;
		delete hapus;
	}
	else
	{
		head = NULL;
	}
	
}

int pilihan (int pilih, int data)
{
	switch (pilih)
		{
			case 1:
				cout<<"Input data : ";
				cin>>data;
				insert_diawal(data);
			break;
			case 2:
				cout<<"Input data : ";
				cin>>data;
				cout<<"Anda ingin masukkan data sebelum node : ";
				cin>>x;
				insert_sebelum(data, x);
			break;
			case 3:
				cout<<"Input data : ";
				cin>>data;
				cout<<"Anda ingin masukkan data setelah node : ";
				cin>>x;
				insert_setelah(data, x);
			break;
			case 4:
				cout<<"Input data : ";
				cin>>data;
				insert_akhir(data);
			break;
			case 5:
				delete_awal();
			break;
			case 6:
				cout<<"Anda ingin menghapus data yang mana? ";
				cin>>x;
				delete_tertentu(x);
			break;
			case 7:
				cout<<"Anda ingin menghapus data setelah node mana? ";
				cin>>x;
				delete_setelah();
			break;
			case 8:
				delete_akhir();
			break;
			default:
				cout<<"Pilihan tidak tersedia"<<endl;
			break;
		}
	return data;
}

int main()
{
	int pilih, data;
	char ulang;
	
	insert_diawal(10);
	insert_diawal (5);
	insert_diawal (1);
	insert_akhir (20);
	insert_akhir (30);
	insert_akhir (40);
	insert_akhir (50);
	cout<<endl;
	
	do
	{
		cout<<"Hasil proses	: ";
		tampil();
		cout<<"1. Insert diawal node\n";
		cout<<"2. Insert sebelum node tertentu\n";
		cout<<"3. Insert setelah node tertentu\n";
		cout<<"4. Insert diakhir node\n";
		cout<<"5. Delete awal node\n";
		cout<<"6. Delete node tertentu\n";
		cout<<"7. Delete setelah node tertentu\n";
		cout<<"8. Delete diakhir node\n";
		cout<<"Masukkan pilihan : ";
		cin>>pilih;
		
		pilihan(pilih, data);

		cout<<"Hasil proses	: ";
		tampil();
		
		cout<<"Ingin mengulangi proses ?";
		cin>>ulang;
		system ("cls");
	} while (ulang != 't' || ulang != 'T');
	
   
   tampil();
   system("pause");
}

