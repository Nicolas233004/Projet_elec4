# Rapport de Séance 14 & 15

**Date :** 10/03/2026 et 12/03/2026  
**Nom :** Leandro Euphrasie  
**Formation :** ELSE 4 – FISA  
**Sujet :** Correction du câblage matériel et finalisation de l'interface "TOIT CHAUFFANT"

---

## 1. Objectifs de la séance
L'objectif principal était de résoudre le problème de "l'écran blanc" persistant depuis la séance 13, de valider la communication SPI et de déployer l'interface graphique finale dédiée au contrôle du **Toit Chauffant**.

## 2. Diagnostic et Correction Matérielle
Le dysfonctionnement de l'affichage a été identifié comme une **erreur d'assignation physique des broches** lors de la séance précédente.

### Correction du câblage :
* **Erreur identifiée :** La broche **DC** (Data/Command) de l'écran était câblée sur le **GPIO 2** au lieu du **GPIO 21**. Le GPIO 2 étant une broche de "strapping" (utilisée lors du boot de l'ESP32), cela interférait avec l'initialisation du driver ILI9341 et provoquait un conflit au démarrage.
* **Action :** Basculement du signal DC sur le **GPIO 21** et raccordement du VCC au **5V (VIN)** de l'ESP32. 
* **Justification technique :** Le passage au 5V garantit une tension stable pour le driver et le rétroéclairage, tandis que le GPIO 21 est une broche de données standard ne perturbant pas le cycle de démarrage (boot) de la puce.
* **Résultat :** L'écran est devenu immédiatement fonctionnel, permettant de passer au développement de l'interface utilisateur.

## 3. Développement de l'Interface "TOIT CHAUFFANT"
L'interface a été conçue pour offrir une lecture claire et stable des paramètres de régulation via une bibliothèque personnalisée `Affichage.cpp/h` :
* **Organisation visuelle :** Titre **"TOIT CHAUFFANT"** centré en haut de l'écran. Alignement en colonnes pour les données : les libellés à gauche et les valeurs numériques à droite.
* **Code couleur :** * **Orange** pour la température **ACTUELLE** (mesurée par le serveur).
    * **Vert** pour la **CONSIGNE** (reçue du serveur).
* **Stabilité d'affichage :** Utilisation d'un rafraîchissement sélectif basé sur la comparaison des valeurs (`ancienneTemp` vs `tempActuelle`). Cette méthode permet de mettre à jour les chiffres toutes les 200ms sans aucun clignotement de l'écran (anti-flicker).

## 4. Intégration Réseau et Parsing JSON
L'ESP32 Écran agit en tant que **Client HTTP** pour récupérer les données de régulation du premier module (Serveur AP) :
* **Connexion :** Liaison Wi-Fi stable au point d'accès `SEAN_BONDON` (IP fixe : 192.168.1.15).
* **Récupération :** Interrogation automatique de la route JSON `/status` du serveur.
* **Traitement :** Utilisation de la bibliothèque `ArduinoJson` pour extraire les valeurs `temp` et `setpoint` et les injecter dynamiquement dans les fonctions d'affichage.

## 5. Conclusion
Ces séances ont permis de valider l'intégralité de la chaîne : **Matériel (SPI) -> Protocole (HTTP/JSON) -> Interface (TFT)**. La correction du câblage du signal DC (passage du GPIO 2 au 21) a été l'élément déclencheur du succès. L'interface est désormais robuste, esthétique et communique parfaitement avec l'unité de commande du toit chauffant.

---
