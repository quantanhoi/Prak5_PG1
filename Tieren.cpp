#include"Tieren.h"
//Tieren Quellcode

/*
Breed... lmao es gibt zu wenig Information dazu, kann ein einziges Tier sich vermehren?
oder braucht es immer noch 2 oder mehr Tieren der gleichen Art, um zu vermehren
(dann brauchen wir auch ein Counter)?
Jedoch gehoert breed() zu Klass Tieren (nach Aufgabe), wie kann ich ein Counter fuer Vector von Tieren erstellen ?? :D ??
*/
void Tieren::breed() {     //ein Tier vermehrt sich wie eine Zelle...
    int random;
    random = rand()%100;
    if(random <= Vermehrrate && Gewicht > MinGewicht) {
        breeding = true;
    }
}
bool Tieren::checkAge() {
    if(Gewicht == Maximalgewicht) {
        return true;
    }
    else return false;
}

void Tieren::Alterungsschritt() {
    if(Gewicht < Maximalgewicht) {
        Gewicht = Gewicht*Wachstumsrate;
        if(Gewicht > Maximalgewicht) {
            Gewicht = Maximalgewicht;
        }
    }
}
void Tieren::Altersschwaeche() {
    int random{};
    int dropDead = (Wachstumsrate*100) - 100;
    if(checkAge()) {
        random = rand()%100;
        if(random <= dropDead) {
            dead = true;

        }
    }
}
void Tieren::breedGewicht() {
    Gewicht = MinGewicht;
}
int Tieren::getGewicht() {
    return Gewicht;
}
std::string Tieren::getRasse() {
    return Rasse;
}
int Tieren::getMaxGewicht() {
    return Maximalgewicht;
}
int Tieren::getMinGewicht() {
    return MinGewicht;
}
double Tieren::getWachstumsrate() {
    return Wachstumsrate;
}
double Tieren::getVermehrrate() {
    return Vermehrrate;
}
/*void Tieren::printInfo() {
    log(getGewicht());
    log(getRasse());
    log(getMaxGewicht());
    log(getMinGewicht());
    log(getWachstumsrate());
    log(getVermehrrate());
    log("End");
}*/

void Tieren::setInfo(RaceName Race) {
    /*if(Race == Brachiosaurus) {
        Race = Brachiosaurus;
        Rasse = "Brachiosaurus";
        Maximalgewicht = 30000;
        MinGewicht = (5*Maximalgewicht) / 100;
        Wachstumsrate = 1.2;
        Vermehrrate = 15;
    }
    if(Race == Parasaurolophus) {
        Race = Parasaurolophus;
        Rasse = "Parasaurolophus";
        Maximalgewicht = 1500;
        MinGewicht = (5*Maximalgewicht) / 100;
        Wachstumsrate = 1.4;
        Vermehrrate = 85;
    }
    if(Race == Raptor) {
        Race = Raptor;
        Rasse ="Raptor";
        Maximalgewicht = 500;
        MinGewicht = (20 * Maximalgewicht) / 100;
        Wachstumsrate = 1.3;
        Vermehrrate = 12;
    }
    if(Race == TyrannosaurusRex) {
        Race = TyrannosaurusRex;
        Rasse ="Tyrannosaurus Rex";
        Maximalgewicht = 8000;
        MinGewicht = (20 * Maximalgewicht) / 100;
        Wachstumsrate = 1.2;
        Vermehrrate = 8;
    }*/
    switch(Race) {
    case Brachiosaurus:

        Rasse = "Brachiosaurus";
        Maximalgewicht = 30000;
        MinGewicht = (5*Maximalgewicht) / 100;
        Wachstumsrate = 1.2;
        Vermehrrate = 15;
        break;

    case Parasaurolophus:

        Rasse = "Parasaurolophus";
        Maximalgewicht = 1500;
        MinGewicht = (5*Maximalgewicht) / 100;
        Wachstumsrate = 1.4;
        Vermehrrate = 85;
        break;
    case Raptor:

        Rasse ="Raptor";
        Maximalgewicht = 500;
        MinGewicht = (20 * Maximalgewicht) / 100;
        Wachstumsrate = 1.3;
        Vermehrrate = 12;
        break;
    case TyrannosaurusRex:
        Rasse ="Tyrannosaurus Rex";
        Maximalgewicht = 8000;
        MinGewicht = (20 * Maximalgewicht) / 100;
        Wachstumsrate = 1.2;
        Vermehrrate = 8;
        break;
    }

}
void Tieren::initialisieren() {
    Gewicht = rand()%(Maximalgewicht - MinGewicht) + MinGewicht;     //zufallige Gewicht fuer die Tieren im Park (wird in initating benutzt)
}
