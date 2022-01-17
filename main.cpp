#include <iostream>
#include<string>
#include<vector>
#include<time.h>
#define log(x) std::cout << x << std::endl;


class Tieren {
private:
    int Gewicht;
    int Maximalgewicht;
    int MinGewicht;
    double Wachstumsrate;
    int Vermehrrate;

protected:
    std::string Rasse;

public:
    bool dead{false};
    bool breeding{false};
    void initialisieren();   //initialisiert den Park mit gegebenen Info
    bool checkAge();     //prüfen, ob die Tieren ausgewachsen haben oder nicht
    void Alterungsschritt();    //wachsen
    void Altersschwaeche();     //schwächen und sterben
    void breed();
    void breedGewicht();

    int getGewicht();
    int getMaxGewicht();
    int getMinGewicht();
    double getWachstumsrate();
    double getVermehrrate();
    void setInfo(std::string& Rasse);
    std::string getRasse();
    void printInfo();

};

class Hebivoren:public Tieren {
private:
    int Versteckchance;
public:
    void setVersteckchance();
    bool hide();
    void extraInfo();   //extra information für Initialisieren
    double getVersteckchance();
};
class Karnivoren:public Tieren {
private:
    int FailedHuntCounter;
public:
    void hunt();
    void extraInfo();       //extra information für Initialiesieren
    Karnivoren() {
        FailedHuntCounter = 0;
    }

};



void CreatingKarni(std::vector<Karnivoren>& Karni, Karnivoren& k1, std::string& Race);
void CreatingHebi (std::vector<Hebivoren>& Hebi, Hebivoren& h1, std::string& Race );
void Initating(std::vector<Hebivoren>& Hebi, std::vector<Karnivoren>& Karni, Hebivoren& h1, Karnivoren& k1);
void printPark(std::vector<Hebivoren>& Hebi, std::vector<Karnivoren>& Karni);
void removeDead(std::vector<Hebivoren>& Hebi, std::vector<Karnivoren>& Karni);


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
    if(random <= Vermehrrate) {
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
std::ostream& operator<<(std::ostream& stream, Tieren& Tier) {    //practicing operator overloading
    stream << "Rasse " << Tier.getRasse() << "\nGewicht " << Tier.getGewicht() << "\nMax Gewicht " << Tier.getMaxGewicht() << "\nMin Gewicht " << Tier.getMinGewicht()
           << "\nWachstumsrate " << Tier.getWachstumsrate() << "\nVermehrrate " << Tier.getVermehrrate() <<"%";
    return stream;
}
void Tieren::setInfo(std::string& Race) {
    if(Race == "Brachiosaurus") {
        Rasse = "Brachiosaurus";
        Maximalgewicht = 30000;
        MinGewicht = (5*Maximalgewicht) / 100;
        Wachstumsrate = 1.2;
        Vermehrrate = 15;
    }
    if(Race == "Parasaurolophus") {
        Rasse = "Parasaurolophus";
        Maximalgewicht = 1500;
        MinGewicht = (5*Maximalgewicht) / 100;
        Wachstumsrate = 1.4;
        Vermehrrate = 85;
    }
    if(Race == "Raptor") {
        Rasse ="Raptor";
        Maximalgewicht = 500;
        MinGewicht = (20 * Maximalgewicht) / 100;
        Wachstumsrate = 1.3;
        Vermehrrate = 12;
    }
    if(Race == "Tyrannosaurus Rex") {
        Rasse ="Tyrannosaurus Rex";
        Maximalgewicht = 8000;
        MinGewicht = (20 * Maximalgewicht) / 100;
        Wachstumsrate = 1.2;
        Vermehrrate = 8;
    }

}
void Tieren::initialisieren() {
    Gewicht = rand()%(Maximalgewicht - MinGewicht) + MinGewicht;
}


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

//Karnivoren Quellcode



//Alle Funktionen Quellcode


void CreatingHebi (std::vector<Hebivoren>& Hebi, Hebivoren& h1, std::string& Race ) {
    h1.setInfo(Race);
    h1.setVersteckchance();
    h1.initialisieren();
    Hebi.push_back(h1);
}
void CreatingKarni(std::vector<Karnivoren>& Karni, Karnivoren& k1, std::string& Race) {
    k1.setInfo(Race);
    k1.initialisieren();
    Karni.push_back(k1);
}
void breedHebi (std::vector<Hebivoren>& Hebi, Hebivoren& h1, std::string Race ) {
    h1.setInfo(Race);
    h1.setVersteckchance();
    h1.breedGewicht();
    Hebi.push_back(h1);
}
void breedKarni (std::vector<Karnivoren>& Karni, Karnivoren& k1, std::string Race) {
    k1.setInfo(Race);
    k1.breedGewicht();
    Karni.push_back(k1);
}
void Initating(std::vector<Hebivoren>& Hebi, std::vector<Karnivoren>& Karni, Hebivoren& h1, Karnivoren& k1) {
    std::string Race = "Brachiosaurus";    //initating Brachiosaurus
    for(int i = 0; i < 4; i++ ) {
        CreatingHebi(Hebi, h1, Race);
    }

    Race = "Parasaurolophus";
    for(int i = 0; i < 5; i++){
        CreatingHebi(Hebi, h1, Race);
    }
    Race = "Raptor";
    for(int i = 0; i < 4; i++) {
        CreatingKarni(Karni, k1, Race);
    }
    Race = "Tyrannosaurus Rex";
    for(int i = 0; i < 2; i++) {
        CreatingKarni(Karni, k1, Race);
    }
    //printPark(Hebi, Karni);             //checking the list of all inititated animal in the park

}
void passingTime(std::vector<Hebivoren>& Hebi, std::vector<Karnivoren>& Karni, Hebivoren& h1, Karnivoren& k1) {
    for(unsigned int i{}; i < Hebi.size(); i++) {
        Hebi.at(i).Alterungsschritt();
        if(Hebi.at(i).checkAge()) {
            Hebi.at(i).Altersschwaeche();
        }
        if(!Hebi.at(i).dead) {
            Hebi.at(i).breed();
            if(Hebi.at(i).breeding) {
                breedHebi(Hebi, h1, Hebi.at(i).getRasse());
                std::cout << "A wild "<< Hebi.at(i).getRasse() << " has been born" << std::endl;
            }
        }
    }
}
void printPark(std::vector<Hebivoren>& Hebi, std::vector<Karnivoren>& Karni) {
    for(unsigned int i = 0; i < Hebi.size(); i ++ ) {      //print out all information to check
            std::cout << Hebi.at(i) << std::endl;
            std::cout << "Vermehrrate: " <<Hebi.at(i).getVersteckchance() << std::endl<< std::endl;
        }
        for(unsigned int i = 0; i < Karni.size(); i ++ ) {
            std::cout << Karni.at(i) <<std::endl<< std::endl;
        }
}
void removeDead(std::vector<Hebivoren>& Hebi, std::vector<Karnivoren>& Karni) {
    for(unsigned int i = 0; i < Hebi.size(); i ++ ) {
        if(Hebi.at(i).dead) {
            Hebi.erase(Hebi.begin()+i);
            std::cout << "A " << Hebi.at(i).getRasse() << " is dead" << std::endl ;
        }
    }
    for(unsigned int i = 0; i < Karni.size(); i ++ ) {
        if(Karni.at(i).dead) {
            Karni.erase(Karni.begin()+i);
            std::cout << "A " << Karni.at(i).getRasse() << " is dead" << std::endl;
        }
    }
}

int main()
{
    srand(time(NULL));
    std::vector<Hebivoren> Hebi;
    std::vector<Karnivoren> Karni;
    Hebivoren h1;
    Karnivoren k1;
    Initating(Hebi, Karni, h1, k1);

    passingTime(Hebi,Karni, h1, k1);
    printPark(Hebi, Karni);
}

