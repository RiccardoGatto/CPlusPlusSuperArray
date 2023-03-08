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
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int *aggiungiInFondo(int base[], int dim, int nuovo)
{
    int *arrayRis = new int[dim + 1];
    for (int i = 0; i < dim; i++)
    {
        arrayRis[i] = base[i];
    }
    arrayRis[dim] = nuovo;
    cout << "\nAggiungo in fondo " << nuovo << endl;
    return arrayRis;
}

int *aggiungiInTesta(int base[], int dim, int nuovo)
{
    int *arrayRis = new int[dim + 1];
    arrayRis[0] = nuovo;
    for (int i = 1; i <= dim; i++)
    {
        arrayRis[i] = base[i - 1];
    }
    cout << "\nAggiungo in testa " << nuovo << endl;
    return arrayRis;
}

int *aggiungiInPosizione(int base[], int dim, int nuovo, int posizione) // AGGIUNGE ALL'INDICE DATO DALLA POSIZIONE
{
    if (posizione >= dim)
    {
        cout << "L'indice si trova al di fuori del range dell'array";
        return base;
    }
    else
    {
        int *arrayRis = new int[dim + 1];
        for (int i = 0; i < posizione; i++)
        {
            arrayRis[i] = base[i];
        }
        arrayRis[posizione] = nuovo;
        for (int i = posizione + 1; i <= dim; i++)
        {
            arrayRis[i] = base[i - 1];
        }
        cout << "\nAggiungo in indice " << posizione << " il numero " << nuovo << endl;
        return arrayRis;
    }
}

int trovaPosizione(int base[], int dim, int cerca) // RESTITUISCE L'INDICE DELLA PRIMA OCCORRENZA
{
    for (int i = 0; i < dim; i++)
    {
        if (base[i] == cerca)
        {
            return i;
        }
    }
    return -1;
}

int *aggiornaInPosizione(int base[], int dim, int valore, int posizione) // AGGIORNA L'ELEMENTO DI INDICE "POSIZIONE"
{
    if (posizione >= dim)
    {
        cout << "L'indice si trova al di fuori del range dell'array";
        return base;
    }
    else
    {
        int *arrayRis = new int[dim];
        for (int i = 0; i < posizione; i++)
        {
            arrayRis[i] = base[i];
        }
        arrayRis[posizione] = valore;
        for (int i = posizione + 1; i < dim; i++)
        {
            arrayRis[i] = base[i];
        }
        cout << "\nAggiorno l'elemento di indice " << posizione << " con il valore " << valore << endl;
        return arrayRis;
    }
}

int *rimuoviIndex(int base[], int dim, int posizione)
{
    if (posizione >= dim)
    {
        cout << "L'indice si trova al di fuori del range dell'array";
        return base;
    }
    else
    {
        int *arrayRis = new int[dim - 1];
        for (int i = 0; i < posizione; i++)
        {
            arrayRis[i] = base[i];
        }
        for (int i = posizione; i < dim; i++)
        {
            arrayRis[i] = base[i + 1];
        }
        cout << "\nElimino l'elemento di indice " << posizione << endl;
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
        int *arrayRis = new int[dim - 1];
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
        cout << "\nElimino la prima occorrenza del numero " << valore << endl;
        return arrayRis;
    }
}

int *rimuoviAll(int base[], int dim, int valore) // RIMUOVE TUTTE LE OCCORRENZE
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
        int newDim = dim - cont;
        int *arrayRis = new int[newDim];
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
        cout << "\nElimino tutte le occorrenze del numero " << valore << endl;
        mostra(arrayRis, newDim);
        return arrayRis;
    }
}

int main()
{
    int base[] = {6, 8, 7, 8, 8, 9};
    int dim = sizeof(base) / sizeof(base[0]);
    int nuovo = 11;
    int posizione = 4;
    int daTrovare = 8;
    cout << "-------------------------------------------";
    int *array1 = aggiungiInFondo(base, dim, nuovo);
    mostra(array1, dim+1);
    cout << "-------------------------------------------";
    int *array2 = aggiungiInTesta(base, dim, nuovo);
    mostra(array2, dim+1);
    cout << "-------------------------------------------";
    int *array3 = aggiungiInPosizione(base, dim, nuovo, posizione);
    mostra(array3, dim+1);
    cout << "-------------------------------------------";
    cout << "\nElemento " << daTrovare << " si trova in indice " << trovaPosizione(base, dim, daTrovare) << endl;
    cout << "-------------------------------------------";
    int *array4 = aggiornaInPosizione(base, dim, nuovo, posizione);
    mostra(array4, dim);
    cout << "-------------------------------------------";
    int *array5 = rimuoviIndex(base, dim, posizione);
    mostra(array5, dim-1);
    cout << "-------------------------------------------";
    int *array6 = rimuovi(base, dim, daTrovare);
    mostra(array6, dim-1);
    cout << "-------------------------------------------";
    int *array7 = rimuoviAll(base, dim, daTrovare);
    cout << "-------------------------------------------";
    cout << endl;
    return 0;
}