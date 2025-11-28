# 🧾 Rapport journalier – Séance 5

**Date :** 12 octobre 2025  
**Projet :** Développement ESP32 – Tests matériel & corrections câblage  

---

## 🛠️ Tâches réalisées

### 1. Analyse du problème de court-circuit
- Au départ, nous pensions qu’il s’agissait d’un **court-circuit sur la carte**.  
- Après analyse, nous avons constaté que le problème venait du fait que les **résistances tiraient trop d’intensité** par rapport au **réglage de l’alimentation**.  
- Ajustement des réglages et vérification du fonctionnement électrique.

### 2. Tests du signal PWM
- Réalisation de **tests pour vérifier que la PWM arrivait bien jusqu’aux bornes des résistances**.  
- Résultat : le signal n’arrivait pas correctement.  
- Cause identifiée : **faux contact** sur certains câbles.

### 3. Travaux de câblage
- Décision de **dessouder et ressouder** les fils posant problème.  
- Après intervention, un **nouveau court-circuit** est apparu entre **deux fils ressoudés**.  
- Nouvelle analyse nécessaire pour comprendre l’origine exacte du défaut.

---

## ⚠️ Problème actuel
- Persistance d’un **court-circuit entre deux fils** des résistances malgré la reprise du câblage.  
- Les tests électriques ne peuvent pas continuer tant que ce problème n’est pas résolu.

---

## ⚙️ Préparation pour la prochaine séance
- Continuer le **diagnostic du court-circuit** et reprendre la soudure si nécessaire.  
- Si la situation n’avance pas, Sean prendra le relais sur la partie **câblage et diagnostic matériel**, afin de ne pas bloquer le reste du projet.  
- Pendant ce temps, je travaillerai sur la **modification du code pour le faire fonctionner sur les 2 cœurs de l’ESP32** (répartition des tâches entre `core 0` et `core 1`).

---

## ✅ Bilan
- Le problème ne venait pas de la carte mais de la **consommation excessive des résistances** puis d’un **faux contact**.  
- Les interventions de soudure ont progressé, mais un court-circuit persiste.  
- La partie logicielle va continuer en parallèle pour éviter de perdre du temps.

