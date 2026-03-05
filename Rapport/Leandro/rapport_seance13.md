# Rapport de Séance 13

**Date :** 05/03/2026  
**Nom :** Leandro Euphrasie  
**Formation :** ELSE 4 – FISA  
**Sujet :** Intégration du nouvel écran TFT 128x160 et analyse des schémas

---

## 1. État des lieux après l'incident de la Séance 12
Suite à la surtension accidentelle (montée à 23V) ayant rendu l'écran précédent inutilisable (consommation figée à 0,02 A sans affichage), j'ai procédé au remplacement complet du module par un nouvel écran TFT SPI 128x160.

## 2. Analyse Technique et Documentation
Pour éviter une nouvelle erreur de câblage ou de tension, j'ai récupéré et étudié plusieurs documents techniques :
* **Schémas de l'ESP32-WROOM-32 :** Identification des broches physiques vs GPIO.
* **Schématique du projet (ESP_LoRa_Thermal) :** Analyse du circuit existant pour éviter les conflits avec le module LoRa et le lecteur de carte SD.
* **Pinout Otronic :** Repérage spécifique des labels de ma carte de développement (D2, D4, D18, D23, D5).

## 3. Travaux réalisés : Nouveau Câblage
J'ai mis en place un câblage sécurisé sur le bus **VSPI** de l'ESP32 afin de garantir une vitesse d'affichage optimale sans interférer avec les autres périphériques :

| Écran TFT | ESP32 (Label Carte) | Rôle |
| :--- | :--- | :--- |
| **VCC** | 3V3 | Alimentation |
| **GND** | GND | Masse |
| **SCL / SCK** | D18 (GPIO 18) | Horloge SPI |
| **SDA / SDI** | D23 (GPIO 23) | Données SPI |
| **CS** | D5 (GPIO 5) | Chip Select |
| **A0 (DC)** | D2 (GPIO 2) | Data/Command |
| **RESET** | D4 (GPIO 4) | Réinitialisation |



## 4. Problématique constatée
Malgré le nouveau câblage, l'écran **s'éclaire en blanc** mais n'affiche aucune donnée. 

### Hypothèses de diagnostic :
1.  **Câblage des données :** Inversion possible entre SDA (MOSI) et SCL (Clock), ou mauvaise connexion de la broche A0 (DC).
2.  **Alimentation :** Bien que le rétroéclairage fonctionne (écran blanc), le contrôleur interne de l'écran ne reçoit peut-être pas une tension stable.
3.  **Initialisation logicielle :** Le driver utilisé dans le code (ST7735) nécessite peut-être un "Tab" spécifique (BlackTab vs GreenTab) pour correspondre à cette nouvelle dalle.

## 5. Conclusion et objectifs de la séance 14
L'étape de remplacement matériel est validée. La prochaine séance sera dédiée à la résolution du problème d'affichage ("White Screen").

**Actions prévues :**
* Tester la continuité de chaque fil entre l'ESP32 et l'écran.
* Vérifier au multimètre que la tension sur la broche VCC de l'écran est bien de 3.3V constants.
* Adapter le code de test pour essayer différents types d'initialisation SPI.
