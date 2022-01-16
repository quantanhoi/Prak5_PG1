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
    double Vermehrrate;
protected:
    std::string Rasse;
public:

    void initialisieren();   //initialisiert den Park mit gegebenen Info
    void age();     //prüfen, ob die Tieren ausgewachsen haben oder nicht
    void Alterungsschritt();    //wachsen
    void Altersschwaeche();     //schwächen
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
    double Versteckchance;
public:
    void setVersteckchance();
    bool hide();
    void extraInfo();   //extra information für Initialisieren
    double getVersteckchance();
};
class Karnivoren:public Tieren {
public:
    void hunt();
    void extraInfo();       //extra information für Initialiesieren

};

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
void Tieren::printInfo() {
    log(getGewicht());
    log(getRasse());
    log(getMaxGewicht());
    log(getMinGewicht());
    log(getWachstumsrate());
    log(getVermehrrate());
    log("End");
}
std::ostream& operator<<(std::ostream& stream, Tieren& Tier) {    //practicing operator overloading
    stream << "Gewicht " << Tier.getGewicht() << "\nRasse " << Tier.getRasse() << "\nMax Gewicht " << Tier.getMaxGewicht() << "\nMin Gewicht " << Tier.getMinGewicht()
           << "\nWachstumsrate " << Tier.getWachstumsrate() << "\nVermehrrate " << Tier.getVermehrrate();
    return stream;
}
void Tieren::setInfo(std::string& Race) {
    if(Race == "Brachiosaurus") {
        Rasse = "Brachiosaurus";
        Maximalgewicht = 30000;
        MinGewicht = (5*Maximalgewicht) / 100;
        Wachstumsrate = 0.2;
        Vermehrrate = 0.15;
    }
    if(Race == "Parasaurolophus") {
        Rasse = "Parasaurolophus";
        Maximalgewicht = 1500;
        MinGewicht = (5*Maximalgewicht) / 100;
        Wachstumsrate = 0.4;
        Vermehrrate = 0.85;
    }
    if(Race == "Raptor") {
        Rasse ="Raptor";
        Maximalgewicht = 500;
        MinGewicht = (20 * Maximalgewicht) / 100;
        Wachstumsrate = 30/100;
        Vermehrrate = 12/100;
    }
    if(Race == "Tyrannosaurus Rex") {
        Rasse ="Tyrannosaurus Rex";
        Maximalgewicht = 8000;
        MinGewicht = (20 * Maximalgewicht) / 100;
        Wachstumsrate = 20/100;
        Vermehrrate = 8/100;
    }

}
void Tieren::initialisieren() {
    Gewicht = rand()%(Maximalgewicht - MinGewicht) + MinGewicht;

}

void Hebivoren::setVersteckchance() {
    if(getRasse() == "Brachiosaurus") {
        Versteckchance = 50/100;
    }
    if(getRasse() == "Parasaurolophus") {
        Versteckchance = 75/100;
    }
}
double Hebivoren::getVersteckchance() {
    return Versteckchance;
}



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
    for(unsigned int i = 0; i < Hebi.size(); i ++ ) {
        std::cout << Hebi.at(i) << std::endl;
        std::cout << Hebi.at(i).getVersteckchance() << std::endl;
    }
    for(unsigned int i = 0; i < Karni.size(); i ++ ) {
        std::cout << Karni.at(i) <<std::endl;
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
}

