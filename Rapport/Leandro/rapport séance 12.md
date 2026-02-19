# Rapport de Séance 12

**Date :** 19/02/2025  
**Nom :** Leandro Euphrasie  
**Formation :** ELSE 4 – FISA  

---

## 1. Vérification du câblage et incident d’alimentation

Lors de cette séance, j’ai commencé par revérifier l’ensemble des câblages de l’écran TFT afin d’identifier l’origine du dysfonctionnement constaté lors de la séance précédente.

Au cours de cette manipulation, une erreur s’est produite lors du réglage de l’alimentation.  
Initialement réglée à 3 V, j’ai tenté de la passer à 5 V. Cependant, une mauvaise manipulation du curseur de l’alimentation a entraîné une montée accidentelle de la tension à 13 V puis à 23 V.

Cette surtension a provoqué l’extinction immédiate de l’écran.

---

## 2. Analyse de la consommation électrique

Après l’incident, j’ai mesuré la consommation de l’écran.  
Celui-ci consomme désormais environ **0,02 A**, mais ne s’allume plus.

Cette faible consommation peut indiquer :

- Une absence de fonctionnement de la dalle d’affichage  
- Un circuit partiellement endommagé  

---

## 3. Vérifications matérielles approfondies

Afin d’identifier l’origine du problème, j’ai utilisé un multimètre pour :

- Tester la continuité des pistes  
- Vérifier l’absence de court-circuit visible  

J’ai ensuite décollé l’écran du PCB afin d’inspecter les composants situés à l’arrière de la carte.  
Mais je n’ai pu observer Aucune anomalie 

---

## 4. Analyse technique et hypothèse

Il est probable que la surtension ait endommagé la dalle LED ou le système de rétroéclairage.

Selon mon analyse :

- Le PCB et le contrôleur pourraient encore être fonctionnels  
- La dalle d’affichage ou le rétroéclairage semblent défaillants  

La surtension appliquée (jusqu’à 23 V) dépasse largement la spéc.

---

## 5. Conclusion et décision

Je me suis donc separer de l’ecran

---

## Prochaines étapes

- Remplacer l’écran TFT par un nouveau module  
