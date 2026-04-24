#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <TFT_eSPI.h>

class Affichage {
public:
    Affichage();
    void initialiser();
    void mettreAJourAmbiante(float temp);
    void mettreAJourConsigne(float temp);
    void majStatutWifi(bool connecte);
    void dessinerInterfaceFixe();
    void mettreAJourInterieur(float temp);

private:
    TFT_eSPI tft;
};

#endif