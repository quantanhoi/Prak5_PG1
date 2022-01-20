#include"main.h"
int main()
{
    srand(time(NULL));
    std::vector<Hebivoren> Hebi;
    std::vector<Karnivoren> Karni;
    Hebivoren h1;
    Karnivoren k1;
    int BrachiCount{}, ParaCount{}, RaptorCount{}, TrexCount{};
    Initating(Hebi, Karni, h1, k1);

    passingTime(Hebi,Karni, h1, k1);
    printPark(Hebi, Karni, BrachiCount, ParaCount, RaptorCount, TrexCount);
    std::cout << "Brachio: " << BrachiCount << "\nPara: " << ParaCount << "\nRaptor: " << RaptorCount << "\nTrex: " << TrexCount << std::endl;

}

