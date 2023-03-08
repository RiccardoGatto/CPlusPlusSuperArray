#include <array>
#include <iostream>
using namespace std;

int conta(int numero, int arr[], int lung)
{
    int cont = 0;
    for (int i = 0; i < lung; i++)
    {
        if (arr[i] == numero)
        {
            cont++;
        }
    }
    return cont;
}

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
    return arrayRis;
}

int *aggiungiInPosizione(int base[], int dim, int nuovo, int posizione) // AGGIUNGE ALL'INDICE DATO DALLA POSIZIONE
{
    if (posizione >= dim)
    {
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
        return arrayRis;
    }
}

int *rimuoviIndex(int base[], int dim, int posizione)
{
    if (posizione >= dim)
    {
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
        return arrayRis;
    }
}

int *rimuovi(int base[], int dim, int valore) // RIMUOVE LA PRIMA OCCORRENZA
{
    if (!presente(valore, base, dim))
    {
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
        return arrayRis;
    }
}

int *rimuoviAll(int base[], int dim, int valore) // RIMUOVE TUTTE LE OCCORRENZE
{
    int cont = conta(valore, base, dim);
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
    return arrayRis;
}

int main()
{
    int base[] = {6, 8, 7, 8, 8, 9};
    int dim = sizeof(base) / sizeof(base[0]);
    int daAggiungere = 11;
    int daCercare = 6;
    int daEliminare = 14;
    int indice = 2;
    cout << "-------------------------------------------" << endl;
    cout << "Aggiungo in fondo " << daAggiungere << endl;
    int *array1 = aggiungiInFondo(base, dim, daAggiungere);
    mostra(array1, dim + 1);
    cout << "-------------------------------------------" << endl;
    cout << "Aggiungo in testa " << daAggiungere << endl;
    int *array2 = aggiungiInTesta(base, dim, daAggiungere);
    mostra(array2, dim + 1);
    cout << "-------------------------------------------" << endl;
    cout << "Aggiungo in indice " << indice << " il numero " << daAggiungere << endl;
    int *array3 = aggiungiInPosizione(base, dim, daAggiungere, indice);
    if (array3 == base)
    {
        cout << "L'indice si trova al di fuori del range dell'array" << endl;
    }
    else
    {
        mostra(array3, dim + 1);
    }
    cout << "-------------------------------------------" << endl;
    int pos = trovaPosizione(base, dim, daCercare);
    if (pos == -1)
    {
        cout << "Elemento non trovato" << endl;
    }
    else
    {
        cout << "Elemento " << daCercare << " si trova in indice " << pos << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << "Aggiorno l'elemento di indice " << indice << " con il valore " << daAggiungere << endl;
    int *array4 = aggiornaInPosizione(base, dim, daAggiungere, indice);
    if (array4 == base)
    {
        cout << "L'indice si trova al di fuori del range dell'array" << endl;
    }
    else
    {
        mostra(array4, dim);
    }
    cout << "-------------------------------------------" << endl;
    cout << "Elimino l'elemento di indice " << indice << endl;
    int *array5 = rimuoviIndex(base, dim, indice);
    if (array5 == base)
    {
        cout << "L'indice si trova al di fuori del range dell'array" << endl;
    }
    else
    {
        mostra(array5, dim - 1);
    }
    cout << "-------------------------------------------" << endl;
    cout << "Elimino la prima occorrenza del numero " << daEliminare << endl;
    int *array6 = rimuovi(base, dim, daEliminare);
    if (array6 == base)
    {
        cout << "Elemento da eliminare non trovato" << endl;
    }
    else
    {
        mostra(array6, dim - 1);
    }
    cout << "-------------------------------------------" << endl;
    cout << "Elimino tutte le occorrenze del numero " << daEliminare << endl;
    int quantiEliminati = conta(daEliminare, base, dim);
    if (quantiEliminati == 0)
    {
        cout << "Elemento da eliminare non trovato" << endl;
    }
    else
    {
        int *array7 = rimuoviAll(base, dim, daEliminare);
        mostra(array7, dim - quantiEliminati);
    }
    cout << "-------------------------------------------" << endl;
    cout << endl;
    return 0;
}