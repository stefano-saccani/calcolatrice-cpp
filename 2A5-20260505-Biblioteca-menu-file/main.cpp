#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Libro
{   int inventario;
    string titolo;
    string autore;
    int anno;
};
const int dimax=5;
Libro biblioteca[dimax];
int dim=0;
int main()
{   ifstream in;
    in.open("biblioteca.txt");
    if(in.is_open())
    {   dim=0;
        Libro copia;
        in>>copia.inventario;
        in.ignore();
        getline(in, copia.titolo);
        getline(in, copia.autore);
        in>>copia.anno;
        in.ignore();
        while(in.good() && dim <dimax)
        {   biblioteca[dim]=copia;
            dim++;
            in>>copia.inventario;
            in.ignore();
            getline(in, copia.titolo);
            getline(in, copia.autore);
            in>>copia.anno;
            in.ignore();
        }
        in.close();
    }
    int scelta;
    do
    {   system("cls");
        cout<<"MENU (libri presenti:"<<dim<<")"
            "\n"
            "\n1) Cerca per codice"
            "\n2) Inserisci libro"
            "\n3) Elimina libro"
            "\n4) Salva biblioteca"
            "\n0) Uscita"
            "\n Scelta: ";
        cin>>scelta;
        cin.ignore();
        if(scelta == 1)
        {   int inv;
            cout <<"Inserire il numero di inventario: ";
            cin >> inv;
            for(int k=0; k<dim; k++)
            {   if(biblioteca[k].inventario==inv)
                {   cout<<biblioteca[k].titolo<<endl;
                    cout<<biblioteca[k].autore<<endl;
                    cout<<biblioteca[k].anno<<endl;
                }
            }
            getch();
        }
        if(scelta==2)
        {   if(dim<dimax)
            {   Libro copia;
                cout<<"Numero di inventario: ";
                cin >> copia.inventario;
                cin.ignore();
               /* cout<<"Titolo: ";
                getline(cin,copia.titolo);
                cout<<"Autore: ";
                getline(cin,copia.autore);
                cout<<"Anno di pubblicazione: ";
                cin>>copia.anno;*/
                bool nonpresente=true;
                for(int k=0; k<dim && nonpresente ; k++)
                {   if(biblioteca[k].inventario==copia.inventario)
                    {   nonpresente=false;
                    }
                }
                if(nonpresente)
                {   cout<<"Titolo: ";
                    getline(cin,copia.titolo);
                    cout<<"Autore: ";
                    getline(cin,copia.autore);
                    cout<<"Anno di pubblicazione: ";
                    cin>>copia.anno;
                    biblioteca[dim] = copia;
                    dim++;
                }
                else
                {   cout<<"Inserimento non possibile: inventario gia' presente"<<endl;
                    getch();
                }
            }
            else
            {   cout<<"Impossibile aggiungere libri; spazio esaurito"<<endl;
                getch();
            }
        }
        if(scelta==3)
        {   int inv;
            cout <<"Inserire il numero di inventario del libro da togliere: ";
            cin >> inv;
            int pos=-1;
            for(int k=0; k<dim && pos==-1; k++)
            {   if(biblioteca[k].inventario==inv)
                {   pos = k;
                }
            }
            if (pos>=0)
            {   for(int k=pos; k<dim-1; k++)
                {   biblioteca[k]=biblioteca[k+1];
                }
                dim--;
            }

        }
        if(scelta == 4)
        {   ofstream out;
            out.open("biblioteca.txt");
            if(out.is_open())
            {   for(int k=0; k<dim; k++)
                {   out<<biblioteca[k].inventario<<endl;
                    out<<biblioteca[k].titolo<<endl;
                    out<<biblioteca[k].autore<<endl;
                    out<<biblioteca[k].anno<<endl;
                }
                out.close();
            }

        }


    }
    while(scelta!=0);

    return 0;
}
