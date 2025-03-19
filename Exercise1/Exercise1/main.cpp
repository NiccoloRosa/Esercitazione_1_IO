#include <fstream> // stream per i file
#include <iostream> //tipi che vanno ad ereditare i tipi pi� famosi di input e output


unsigned int sum_values(unsigned int N);
// nota che le assegnazioni, a differenza delle definizioni, possono essere ripetute senza generare errore. 
unsigned int sum_values(unsigned int N);

unsigned int sum_values( unsigned int N) // con la keyword const ho accesso al dato ma non lo posso modificare 
{
    return N * (N+1) * (2*N +1)/6; 
}

int main()
{
    std::ifstream file("data.txt"); //crea un nuovo oggetto che possa leggere il file e lo associo a data.txt
    // I file hanno permessi di scrittura, lettura, esecuzione. Devo controllare di avere i permessi (potrebbe generare errore)
    // 
    // I file hanno uno stato positivo e negativo -> negativo se operazione non a buon fine -> non posso eseguirne altre

    if (file.fail())
    {
        std::cerr << "Non � stato possibile aprire il file" << std::endl;
        return 1; // return 1 per segnalare errore
    }

    std::string tmp; //tmp � una stringa
    std::getline(file, tmp); //legge la linea del file e la salva in var tmp
    std::cout << tmp << std::endl; // stampa '#Values'
    // al posto 

    unsigned int val; // variabile che 
    unsigned int sum = 0; 
    unsigned int n=0; // variabile che conta le iterate corrette
    while(file>>val) 
    {
        sum = sum + val*val; //nel momento un cui arriva al al carattere end of line, file >> val diventa falso perch� non ha senso, quindi si esce dal while
        n++; //incremento la variabile n ad ogni lettura corretta che ho fatto
    }

    unsigned int S = sum_values(n);
    std::cout << "sum = " << sum << std::endl; // stampa sum = 2109
    std::cout << "S = " << S << std::endl; // stampa S = 2109

    return 0;
}
