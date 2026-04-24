#include "Affichage.h"

// Constructeur
Affichage::Affichage() : tft(TFT_eSPI()) {}

void Affichage::initialiser() {
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    dessinerInterfaceFixe();
}

void Affichage::dessinerInterfaceFixe() {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(TC_DATUM);
    tft.drawString("TOIT RUCHE", 160, 10, 4);
    
    tft.drawFastHLine(0, 42, 320, TFT_WHITE);     // Ligne sous le titre
    tft.drawFastHLine(20, 150, 280, TFT_DARKGREY); // Ligne entre Actuelle et Consigne

    // Labels pour les températures en haut
    tft.setTextDatum(TL_DATUM);
    tft.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
    tft.drawString("INTERIEUR", 10, 50, 2);
    tft.drawString("AMBIANTE", 170, 50, 2);
}

void Affichage::mettreAJourAmbiante(float temp) {
    // Nettoyer la zone complètement avec un rectangle noir
    tft.fillRect(170, 65, 140, 50, TFT_BLACK);
    
    // Dessin de la température à côté
    tft.setTextColor(TFT_ORANGE, TFT_BLACK);
    tft.setTextDatum(TL_DATUM);
    tft.drawFloat(temp, 1, 210, 70, 6); 
    
    // Unité "C"
    tft.drawString("C", 305, 70, 4);
}

void Affichage::mettreAJourInterieur(float temp) {
    // Nettoyer la zone complètement avec un rectangle noir
    tft.fillRect(10, 65, 140, 50, TFT_BLACK);
    
    // Dessin de la température
    tft.setTextColor(TFT_ORANGE, TFT_BLACK);
    tft.setTextDatum(TC_DATUM);
    tft.drawFloat(temp, 1, 80, 75, 6); 
    
    // Unité "C"
    tft.setTextDatum(TL_DATUM);
    tft.drawString("C", 130, 75, 4);
}

void Affichage::mettreAJourConsigne(float consigne) {
    // Nettoyer la zone complètement avec un rectangle noir
    tft.fillRect(20, 165, 140, 50, TFT_BLACK);
    
    // Dessin de la consigne
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    tft.setTextDatum(TL_DATUM);
    tft.drawFloat(consigne, 1, 50, 170, 6);
    
    // Unité "C"
    tft.drawString("C", 130, 170, 4);
}

void Affichage::majStatutWifi(bool connecte) {
    // Nettoyer la zone du statut WiFi
    tft.fillRect(240, 45, 70, 25, TFT_BLACK);
    
    tft.setTextDatum(TR_DATUM);
    if(connecte) {
        tft.setTextColor(TFT_GREEN, TFT_BLACK);
        tft.drawString("WIFI OK", 310, 48, 2);
    } else {
        tft.setTextColor(TFT_RED, TFT_BLACK);
        tft.drawString("WIFI !!", 310, 48, 2);
    }
}