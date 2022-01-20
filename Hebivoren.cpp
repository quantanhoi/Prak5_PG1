#include"Hebivoren.h"
//Hebivoren Quellcode

void Hebivoren::setVersteckchance() {
    if(getRasse() == "Brachiosaurus") {
        Versteckchance = 50;
    }
    if(getRasse() == "Parasaurolophus") {
        Versteckchance = 75;
    }
}
double Hebivoren::getVersteckchance() {
    return Versteckchance;
}
