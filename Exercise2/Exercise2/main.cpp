#include <fstream> //libreria per lavorare con i file 
#include <iostream> //libreria per input/ouput
#include <iomanip> //libreria per manipolare la precisione dei dati

double transformation(double val) //definisco una funzione transformation che realizzi la trasformazione affine richiesta
{
    return (3.0/4.0)*val -(7.0/4.0);
}

int main()
{
    std::ifstream file("data.txt"); //Apro il file in modalità di lettura
    if (file.fail()) //gestistsco l'errore di apertura filein
    {
        std::cerr << "Non è stato possibile aprire il file di input" << std::endl;
        return 1; // return 1 per segnalare errore
    }

    std::ofstream outputFile("result.txt"); //Apro il file di output in modalità di scrittura
    if (outputFile.fail()) //gestistsco l'errore di apertura fileout
    {
        std::cerr << "Non è stato possibile aprire il file di output" << std::endl;
        return 1; // return 1 per segnalare errore
    }

    outputFile << "# N Mean" << std::endl; //stampo la prima riga di stringa del file result

    //definisco le variabili necessarie al calcolo
    double val; //variabile letta nel file iniziale 
    double newval; //variabile trasformata
    double sum=0; //somma dei valori trasformati
    double mean; //media dei valori trasformati
    int i = 1; //counter delle iterate
    
    while(file>>val) //finche non finisce il file
    {
        newval = transformation(val); //ottengo il valore trasformato
        sum = sum + newval; //calcolo la sommma della iterata corrente
        mean = sum/i; //calcolo la media dei valori finora trasformati
        outputFile << i << " " << std::scientific << std::setprecision(16) << mean << std::endl; //Stampo ogni valore sul file di output manipolando la precisione in notazione scientifica
        i = i+1; //incremento il counter
    } 
    std::cout << "I risultati sono stati scritti correttamente nel file 'output.txt'." << std::endl; //Comunico che il salvataggio è avventuto correttamente

    //chiudo i file 
    file.close();
    outputFile.close();

    return 0;
}
