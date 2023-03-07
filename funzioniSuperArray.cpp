#include <array>
#include <iostream>
using namespace std;

bool presente(int num, int arr[], int lung)
{
    for (int i = 0; i < lung; i++)
    {
        if (num == arr[i])
        {
            return true;
        }
    }
    return false;
}
void mostra(int arr[], int lung)
{
    for (int i = 0; i < lung; i++)
    {
        cout << arr[i] << endl;
    }
}
int *aggiungiInFondo(int base[], int dim, int nuovo)
{
    int arrayRis[dim + 1];
    for (int i = 0; i < dim; i++)
    {
        arrayRis[i] = base[i];
    }
    arrayRis[dim] = nuovo;
    cout << "Aggiungo in fondo " << nuovo << endl;
    mostra(arrayRis, dim + 1);
    return arrayRis;
}
int *aggiungiInTesta(int base[], int dim, int nuovo)
{
    int arrayRis[dim + 1];
    arrayRis[0] = nuovo;
    for (int i = 1; i <= dim; i++)
    {
        arrayRis[i] = base[i - 1];
    }
    cout << "Aggiungo in testa " << nuovo << endl;
    mostra(arrayRis, dim + 1);
    return arrayRis;
}
int *aggiungiInPosizione(int base[], int dim, int nuovo, int posizione) // NON INDICE, MA POSIZIONE
{
    if (posizione > dim)
    {
        cout << "La posizione si trova al di fuori del range dell'array";
        return base;
    }
    else
    {
        int arrayRis[dim + 1];
        for (int i = 0; i < posizione - 1; i++)
        {
            arrayRis[i] = base[i];
        }
        arrayRis[posizione - 1] = nuovo;
        for (int i = posizione; i <= dim; i++)
        {
            arrayRis[i] = base[i - 1];
        }
        cout << "Aggiungo in posizione " << posizione << " il numero " << nuovo << endl;
        mostra(arrayRis, dim + 1);
        return arrayRis;
    }
}
int trovaPosizione(int base[], int dim, int cerca) // RESTITUISCE LA POSIZIONE DELLA PRIMA OCCORRENZA
{
    for (int i = 0; i < dim; i++)
    {
        if (base[i] == cerca)
        {
            return i + 1;
        }
    }
    return -1;
}
int *aggiornaInPosizione(int base[], int dim, int valore, int posizione) // NON INDICE, MA POSIZIONE
{
    if (posizione > dim)
    {
        cout << "La posizione si trova al di fuori del range dell'array";
        return base;
    }
    else
    {
        int arrayRis[dim];
        for (int i = 0; i < posizione - 1; i++)
        {
            arrayRis[i] = base[i];
        }
        arrayRis[posizione - 1] = valore;
        for (int i = posizione; i < dim; i++)
        {
            arrayRis[i] = base[i];
        }
        mostra(arrayRis, dim);
        return arrayRis;
    }
}
int *rimuovi(int base[], int dim, int valore) // RIMUOVE LA PRIMA OCCORRENZA
{
    if (!presente(valore, base, dim))
    {
        cout << "L'elemento da eliminare non e' presente nell'array";
        return base;
    }
    else
    {
        int arrayRis[dim - 1];
        int i = 0;
        while (base[i] != valore)
        {
            arrayRis[i] = base[i];
            i++;
        }
        while (i < dim)
        {
            arrayRis[i] = base[i + 1];
            i++;
        }
        cout << "Elimino la prima occorrenza del numero " << valore << endl;
        mostra(arrayRis, dim - 1);
        cout << endl;
        return arrayRis;
    }
}
int *rimuoviAll(int base[], int dim, int valore)
{
    if (!presente(valore, base, dim))
    {
        cout << "L'elemento da eliminare non e' presente nell'array";
        return base;
    }
    else
    {
        int cont = 0;
        for (int i = 0; i < dim; i++)
        {
            if (base[i] == valore)
            {
                cont++;
            }
        }
        int arrayRis[dim - cont];
        int i = 0;
        int j = 0;
        while (i < dim)
        {
            while (base[i] != valore)
            {
                arrayRis[j] = base[i];
                i++;
                j++;
            }
            i++;
        }
        mostra(arrayRis, dim - cont);
        return arrayRis;
    }
}

int main()
{
    int base[] = {6, 8, 7, 8, 8, 9};
    int dim = sizeof(base) / sizeof(base[0]);
    int nuovo = 11;
    int posizione = 3;
    int daTrovare = 8;
    // int *array1 = aggiungiInFondo(base, dim, nuovo);
    // cout << endl;
    // int *array2 = aggiungiInTesta(base, dim, nuovo);
    // cout << endl;
    // int *array3 = aggiungiInPosizione(base, dim, nuovo, posizione);
    // cout << endl;
    // cout << "Elemento " << daTrovare << " si trova in posizione " << trovaPosizione(base, dim, daTrovare) << endl;
    // cout << endl;
    // int *array4 = aggiornaInPosizione(base, dim, nuovo, posizione);
    // cout << endl;
    // int *array5 = rimuovi(base, dim, daTrovare);
    // cout << endl;
    // int *array6 = rimuoviAll(base, dim, daTrovare);
    // cout << endl;
    return 0;
}