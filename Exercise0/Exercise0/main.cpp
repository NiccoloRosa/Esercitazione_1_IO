#include <iostream>
#include <cmath>
#include <limits> //Contiene le funzioni min e max
#include <iomanip> // Libreria contenente i manipolatori di output -> setprecision(16) = 16 cifre significative, scientific = notazione scientifica
#include <numbers> //Contiene numeri significativi come pi --> introdotti nel 2020, quindi usare versioni > 2020

int main()
{
    int a=-1; // le costanti si dicono literal, esistono di tipi diversi
    unsigned int b=2; // utili per memorizzare numeri positivi senza utilizzare memoria per il segno
    bool c = true; //false altro valore assumibile
    double d=3.5; //1.0e-12 altra notazione possibile
    std::string str= "Hello"; // Per questo tipo ho bisogno di usare la libreria standard iostream 
    char e = 'a';  // != da str per mancanza di carattere '/0' detto carattere di terminazione
   // a = 2 se non assegno un valore iniziale mi causa errore --> routine: assegnare un valore iniziale

    std::cout << sizeof(int) << std::endl; 
    std::cout << -pow(2, 31) << " " << pow(2, 31) -  1 << std::endl; //pow = 2^31 (qui usiamo la libreria math)
    std::cout << std::numeric_limits<int>::min() << std::numeric_limits<int>::max() << std::endl; //int chiede di trattare come un intero (qui usiamo la libreria limits)

    std::cout << std::setprecision(16) << std::scientific; //Da questa riga in poi CONTINUERA' ad usare 16 cifre e notazione scientifica (qui usiamo la libreria iomanip)
    std::cout << std::numbers::pi << std::endl; // (qui usiamo la libreria numbers)


    int a1 = a + d; //stampa 2, ma -1 + 3.5 != 2 -> in un int io non posso memorizzare un double; in particolare a diventa double, somma di double, poi torno a int
    std::string s1 = str + std::to_string(d); //to_string converte a stringa
    std::cout << "a1 = " << a1 << std::endl;
    std::cout << "s1 = " << s1 << std::endl; // concatenazione di stringhe

    
    return 0;
}
