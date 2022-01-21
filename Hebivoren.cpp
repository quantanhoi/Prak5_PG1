#include"Tieren.h"
//Hebivoren Quellcode

void Hebivoren::setVersteckchance() {
    if(getRasse() == "Brachiosaurus") {
        Versteckchance = 50;
    }
    if(getRasse() == "Parasaurolophus") {
        Versteckchance = 75;
    }
}
int Hebivoren::getVersteckchance() {
    return Versteckchance;
}
