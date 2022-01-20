#include"Tieren.h"


//Alle Funktionen Quellcode
void CreatingKarni(std::vector<Karnivoren>& Karni, Karnivoren& k1, std::string& Race);
void CreatingHebi (std::vector<Hebivoren>& Hebi, Hebivoren& h1, std::string& Race );
void Initating(std::vector<Hebivoren>& Hebi, std::vector<Karnivoren>& Karni, Hebivoren& h1, Karnivoren& k1);
void printPark(std::vector<Hebivoren>& Hebi, std::vector<Karnivoren>& Karni);
void removeDead(std::vector<Hebivoren>& Hebi, std::vector<Karnivoren>& Karni);



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
        if(Hebi.at(i).checkAge()) {
            Hebi.at(i).Altersschwaeche();
        }
        if(!Hebi.at(i).dead) {
            Hebi.at(i).breed();
            if(Hebi.at(i).breeding == true) {
                breedHebi(Hebi, h1, Hebi.at(i).getRasse());
                std::cout << "A wild "<< Hebi.at(i).getRasse() << " has been born" << std::endl;
            }
        }
        Hebi.at(i).Alterungsschritt();
    }
    std::cout << "\n";
    for(unsigned int i{}; i < Karni.size(); i++) {
        if(Karni.at(i).checkAge()) {
            Karni.at(i).Altersschwaeche();
        }
        if(!Karni.at(i).dead) {
            Karni.at(i).breed();
            if(Karni.at(i).breeding == true) {
                breedKarni(Karni, k1, Karni.at(i).getRasse());
                std::cout << "A wild "<< Karni.at(i).getRasse() << " has been born" << std::endl;
            }
        }
        Karni.at(i).Alterungsschritt();
        Karni.at(i).hunt(Hebi);
    }
    removeDead(Hebi, Karni);

}
void printPark(std::vector<Hebivoren>& Hebi, std::vector<Karnivoren>& Karni, int& BrachiCount, int& ParaCount, int& RaptorCount, int& TrexCount) {
    for(unsigned int i = 0; i < Hebi.size(); i ++ ) {      //print out all information to check
            std::cout << Hebi.at(i) << std::endl;
            std::cout << "Vermehrrate: " <<Hebi.at(i).getVersteckchance() << std::endl<< std::endl;
            if(Hebi.at(i).getRasse() == "Brachiosaurus") BrachiCount++;
            if(Hebi.at(i).getRasse() == "Parasaurolophus") ParaCount++;
        }
        for(unsigned int i = 0; i < Karni.size(); i ++ ) {
            std::cout << Karni.at(i) <<std::endl;
            std::cout << Karni.at(i).getFailHunt() << std::endl<< std::endl;
            if(Karni.at(i).getRasse() == "Raptor") RaptorCount++;
            if(Karni.at(i).getRasse() == "Tyrannosaurus Rex") TrexCount++;
        }
}
void removeDead(std::vector<Hebivoren>& Hebi, std::vector<Karnivoren>& Karni) {
    for(unsigned int i = 0; i < Hebi.size(); i ++ ) {
        if(Hebi.at(i).dead) {
            std::cout << "A " << Hebi.at(i).getRasse() << " is dead" << std::endl ;
            Hebi.erase(Hebi.begin()+i);
            i--;
        }
    }
    for(unsigned int i = 0; i < Karni.size(); i ++ ) {
        if(Karni.at(i).dead) {
            std::cout << "A " << Karni.at(i).getRasse() << " is dead" << std::endl;
            Karni.erase(Karni.begin()+i);
            i--;
        }
    }
}
