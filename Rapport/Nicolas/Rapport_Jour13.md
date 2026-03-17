# 🧾 Rapport journalier – Séance 13

**Date :** 05 mars 2026  
**Projet :** Développement ESP32 – Tests globaux & stabilité alimentation  

---

## 🛠️ Tâches réalisées

### 1. Tests de la maquette complète
- Maintenant que la **carte est fonctionnelle**, réalisation d’un **test global de toute la maquette**.  
- Vérification du comportement de l’ensemble du système (capteurs, résistances, ventilateurs, régulation).

### 2. Problème détecté : reset de l’ESP32
- Observation de **redémarrages aléatoires (reset)** de l’ESP32 pendant les tests.  
- Ce problème empêche un fonctionnement stable du système.

### 3. Analyse et tentative de correction
- Investigation pour identifier l’origine du problème.  
- Hypothèse principale : **consommation de courant trop importante** provoquant une instabilité de l’alimentation.  
- Action réalisée :
  - Remplacement du **condensateur C1** par un modèle de **valeur plus élevée** afin de lisser l’alimentation.  

- Résultat :
  - Le problème de reset **persiste**, la solution n’est donc pas suffisante.

---

## ⚠️ Problème actuel
- **Reset aléatoire de l’ESP32** toujours présent.  
- Cause probable : alimentation insuffisante ou instable face à la consommation globale du système.

---

## ⚙️ Préparation pour la prochaine séance
- Continuer le **débogage de la carte**.  
- Approfondir l’analyse de l’**alimentation** (courant disponible, chutes de tension, pics).  
- Tester d’autres solutions pour stabiliser le système.

---

## ✅ Bilan
- La maquette est globalement **fonctionnelle**, mais instable.  
- Le problème de reset est identifié mais **non résolu**.  
- Le projet nécessite une amélioration de la **gestion de l’alimentation**.
