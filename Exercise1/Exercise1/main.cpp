
#include <fstream> // stream per i file
#include <iostream>

int main()
{
    std::fstream file("data.txt"); //crea un nuovo oggetto che possa leggere il file e legalo a data.txt
    // I file hanno uno stato positivo e negativo -> negativo se operazione non a buon fine -> non posso eseguirne altre

    if (file.fail())
    {
        std::cerr << "Non è stato possibile aprire il file" << std:endl;
        return 1; // return 1 per segnalare errore
    }

    std::string tmp;
    std::getline(file, tmp); //legge la linea del file e la salva in var tmp
    std::cout << tmp << std::endl;

    int val;
    int sum = 0;
    while(file>>val)
    {
        sum = sum + val*val; //nel momento un cui arriva al al carattere end of line, file >> val diventa falso perché non ha senso, quindi si esce dal while 
    }

    return 0;
}
