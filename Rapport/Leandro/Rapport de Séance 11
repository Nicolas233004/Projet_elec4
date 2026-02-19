# Rapport de Séance 11

**Date :** 12/11/2025  
**Nom :** Leandro Euphrasie  
**Formation :** ELSE 4 – FISA  

---

## 1. Remise en état matérielle

Lors de cette séance, j’ai commencé par une vérification complète du montage existant.  
Certaines soudures étaient endommagées ou fragilisées, ce qui pouvait provoquer des faux contacts et des dysfonctionnements intermittents.

J’ai donc repris et refait les soudures défectueuses afin d’assurer une meilleure continuité électrique et d’améliorer la fiabilité globale du système.

---

## 2. Migration de l’environnement de développement

J’ai également changé d’environnement de développement.  
Au lieu d’utiliser l’IDE Arduino, j’ai migré vers **Visual Studio Code** avec l’extension **PlatformIO**.

Cette migration m’a permis :

- Une meilleure gestion des dépendances et des librairies  
- Une configuration plus claire des cartes ESP32  
- Une structure de projet plus professionnelle  

La transition a nécessité la reconfiguration complète du projet ainsi que l’adaptation des paramètres de compilation pour la carte ESP32 utilisée.

---

## 3. Vérification et reprise du câblage de l’écran TFT

L’objectif principal de la séance était de faire fonctionner un écran TFT SPI basé sur le contrôleur **ILI9486**.

Pour fiabiliser le câblage, je me suis appuyé sur les schémas de l’ESP32 consultés via le logiciel **Autodesk Eagle**.  

Cela m’a permis de :

- Vérifier la correspondance des broches SPI (MOSI, MISO, SCK, CS, DC, RST)  
- Corriger certaines erreurs de branchement  
- Assurer la cohérence entre le schéma théorique et le montage réel  

Les connexions ont été reprises proprement en respectant les spécifications du bus SPI.

---

## 4. Développement d’un programme de test

Afin de valider le bon fonctionnement du montage, j’ai développé un programme simple permettant :

- D’initialiser la communication SPI  
- D’afficher une couleur unie sur l’écran  

L’objectif de ce test était de vérifier :

- L’initialisation correcte de l’écran  
- La bonne communication entre l’ESP32 et le contrôleur TFT  
- La cohérence du rendu des couleurs  

---

## 5. État actuel et difficultés rencontrées

Malgré la reprise des soudures, la correction du câblage et la migration vers un nouvel environnement de développement, le système ne fonctionne toujours pas correctement.

L’écran ne s’affiche pas comme attendu et ne valide pas encore le test de couleur unie.  
Le dysfonctionnement peut provenir :

- D’un problème de configuration logicielle (driver ou paramètres SPI)  
- D’un défaut matériel persistant (câblage ou composant)  
- D’un problème d’alimentation ou de stabilité électrique  

---

## Prochaines étapes

- Vérifier en détail la configuration du driver ILI9486  
- Tester une autre librairie compatible  
- Mesurer les tensions d’alimentation au multimètre  
- Contrôler chaque ligne SPI individuellement  
- Tester l’écran sur une autre carte pour isoler l’origine du problème  
