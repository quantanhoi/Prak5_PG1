#ifndef TIEREN_H
#define TIEREN_H
#include<iostream>
#include<string>
#include<vector>
#include<time.h>

#define log(x) std::cout << x << std::endl;
#include"Hebivoren.h"
#include"Karnivoren.h"
enum RaceName{Brachiosaurus = 0, Parasaurolophus, Raptor, TyrannosaurusRex};
class Tieren {
private:

    int Maximalgewicht;
    int MinGewicht;
    double Wachstumsrate;
    int Vermehrrate;


protected:

    std::string Rasse;
    int Gewicht;
public:
    RaceName Race;
    bool dead{false};
    bool breeding{false};
    void initialisieren();   //initialisiert den Park mit gegebenen Info
    bool checkAge();     //prüfen, ob die Tieren ausgewachsen haben oder nicht
    void Alterungsschritt();    //wachsen
    void Altersschwaeche();     //schwächen und sterben
    void breed();
    void breedGewicht();
//getFunktion
    int getGewicht();
    int getMaxGewicht();
    int getMinGewicht();
    double getWachstumsrate();
    double getVermehrrate();
    void setInfo(RaceName Race);
    std::string getRasse();
    RaceName& getRaceName() {
        return Race;
    }
    void printInfo();
    Tieren() {
        dead = false;
        breeding = false;
    }
};


class Hebivoren:public Tieren {
private:
    int Versteckchance;
public:
    void setVersteckchance();
    bool hide();
    void extraInfo();   //extra information für Initialisieren
    int getVersteckchance();
};

class Karnivoren:public Tieren {
private:
    int FailedHuntCounter;
    bool huntSuccess{false};
public:
    void hunt(std::vector<Hebivoren>& Hebi);
    void extraInfo();       //extra information für Initialiesieren
    int getFailHunt();
    Karnivoren() {
        FailedHuntCounter = 0;
    }

};
#endif // TIEREN_H
