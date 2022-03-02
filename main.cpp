#include"main.h"
int main()
{
    srand(time(NULL));
    std::vector<Hebivoren> Hebi;
    std::vector<Karnivoren> Karni;
    Hebivoren h1;
    Karnivoren k1;
    int BrachiCount{}, ParaCount{}, RaptorCount{}, TrexCount{}, gesamt{0};   //counter fuer alle Tieren
    int passMonth{};
    char fortsetzen{};
    Initating(Hebi, Karni, h1, k1);      //Park mit gegebenen Informationen initialisieren
    while(true) {      //loop to see how many month has passed
        fortsetzen = 'c';
        std::cout << "Wie viele Monate sind vergangen?: " ;
        std::cin >> passMonth;
        if(passMonth <= 0) {
            continue;
        }
        for(int i{}; i < passMonth; i++) {
            printPark( Hebi, Karni,  BrachiCount, ParaCount, RaptorCount, TrexCount,  gesamt);
            passingTime(Hebi,Karni, h1, k1, gesamt);
            BrachiCount =0; ParaCount = 0; RaptorCount = 0; TrexCount = 0;  gesamt =0; //reset counter
        }
        printPark(Hebi, Karni, BrachiCount, ParaCount, RaptorCount, TrexCount, gesamt);
        log(passMonth << " Monate sind vergangen...");
        std::cout << "Brachio: " << BrachiCount << "\nPara: " << ParaCount << "\nRaptor: " << RaptorCount << "\nTrex: " << TrexCount << "\nGesamt: " << gesamt << std::endl;
        BrachiCount =0; ParaCount = 0; RaptorCount = 0; TrexCount = 0;  gesamt =0; //reset counter
        while(fortsetzen!= 'y' && fortsetzen!= 'n') {
            std::cout << "Continue? (y/n): ";
            std::cin >> fortsetzen;
            if(fortsetzen == 'n') {
                return 0;
            }
        }
    }
    return 0;

}

