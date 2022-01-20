#include"Karnivoren.h"
//Karnivoren Quellcode

void Karnivoren::hunt(std::vector<Hebivoren>& Hebi) {          //here the Karnivoren will hunt a pack of Hebivoren, so there're little chance that these meat-craving guys will die
    int random{};
    for(unsigned int i{}; i < Hebi.size(); i++) {
        if(getGewicht() >= Hebi.at(i).getGewicht()) {    //check if the prey is smaller than the hunter
            random = rand() % 100;
            if(random > Hebi.at(i).getVersteckchance() && Hebi.at(i).dead == false) {
                Hebi.at(i).dead = true;
                Gewicht = Gewicht + ((getMaxGewicht()*20)/100);
                std::cout << "A " << Hebi.at(i).getRasse() << " has been hunted down" << std::endl;
                huntSuccess = true;
                break;
            }

        }
    }
    if(huntSuccess == false) {
        FailedHuntCounter++;
    }
    if(FailedHuntCounter >= 2) {
        dead = true;
    }
}
int Karnivoren::getFailHunt() {
    return FailedHuntCounter;
}
