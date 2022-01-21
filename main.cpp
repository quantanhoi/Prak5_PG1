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
    Initating(Hebi, Karni, h1, k1);

    while(true) {
        std::cout << "Wie viele Monate sind vergangen?: " ;
        std::cin >> passMonth;
        for(int i{}; i < passMonth; i++) {
            passingTime(Hebi,Karni, h1, k1);
        }
        printPark(Hebi, Karni, BrachiCount, ParaCount, RaptorCount, TrexCount);
        log(passMonth << " Monate sind vergangen...");
        std::cout << "Brachio: " << BrachiCount << "\nPara: " << ParaCount << "\nRaptor: " << RaptorCount << "\nTrex: " << TrexCount << std::endl;
    }




}

