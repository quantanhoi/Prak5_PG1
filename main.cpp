#include"main.h"
int main()
{
    srand(time(NULL));
    std::vector<Hebivoren> Hebi;
    std::vector<Karnivoren> Karni;
    Hebivoren h1;
    Karnivoren k1;
    int BrachiCount{}, ParaCount{}, RaptorCount{}, TrexCount{};
    int passMonth{};
    char fortsetzen{};
    Initating(Hebi, Karni, h1, k1);

    while(true) {      //loop to see how many month has passed
        fortsetzen = 'c';
        std::cout << "Wie viele Monate sind vergangen?: " ;
        std::cin >> passMonth;
        if(passMonth <= 0) {
            continue;
        }
        for(int i{}; i < passMonth; i++) {
            passingTime(Hebi,Karni, h1, k1);
        }
        printPark(Hebi, Karni, BrachiCount, ParaCount, RaptorCount, TrexCount);
        log(passMonth << " Monate sind vergangen...");
        std::cout << "Brachio: " << BrachiCount << "\nPara: " << ParaCount << "\nRaptor: " << RaptorCount << "\nTrex: " << TrexCount << std::endl;
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

