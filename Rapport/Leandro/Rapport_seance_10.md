# Rapport de Séance 4

**Date :** 12/11/2025
**Nom :** Leandro Euphrasie
**Formation :** ELSE 4 – FISA

---

## 1. Implémentation d’un écran TFT SPI (ILI9486)

Lors de cette séance, j’ai tenté d’implémenter un écran **TFT SPI ILI9486**, acheté personnellement pour un usage de test.
L’objectif était d’ajouter une interface d’affichage au projet afin de visualiser certaines informations du système.

Pour faciliter les tests et le câblage, j’ai utilisé un **bornier à vis**, permettant des connexions plus rapides et modulables.
Après des recherches sur Internet, j’ai identifié les schémas de câblage nécessaires et procédé à la **soudure de l’ensemble des pins de l’écran** sur les pins correspondants de la carte.

---

## 2. Problème d’alimentation

Un problème d’alimentation a rapidement été identifié :

* L’**ESP32 fournit une tension de 3,3 V**,
* L’**écran TFT nécessite une alimentation comprise entre 5 et 6 V**.

Afin de permettre le fonctionnement de l’écran, j’ai donc utilisé une **alimentation externe** adaptée pour fournir la tension requise.

---

## 3. Configuration logicielle

Pour les tests, j’ai installé **Arduino UNO** ainsi que l’ensemble des **librairies nécessaires** au fonctionnement de l’écran TFT ILI9486.
Cette étape était indispensable pour assurer la communication SPI entre le microcontrôleur et l’écran.

---

## 4. Problème d’affichage rencontré

Malgré une mise sous tension correcte, l’affichage présente un dysfonctionnement :

* Les **couleurs sont très pâles**,
* L’**affichage est peu visible**,
* Le rendu global ne correspond pas au fonctionnement attendu de l’écran.

Ce problème peut provenir de plusieurs causes possibles :

* Une **librairie inadaptée ou mal configurée**,
* Un **problème d’alimentation** (tension ou courant insuffisant),
* Une **erreur de câblage ou de soudure** sur certains pins.

---

## Prochaines étapes

Pour la prochaine séance, les actions prévues sont :

* Analyser en détail l’origine du problème d’affichage,
* Tester différentes **librairies compatibles avec l’ILI9486**,
* Vérifier la **stabilité de l’alimentation** utilisée,
* Contrôler les **soudures et le câblage SPI** afin d’éliminer toute erreur matérielle.
