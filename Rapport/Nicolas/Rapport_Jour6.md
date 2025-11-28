# 🧾 Rapport journalier – Séance 6

**Date :** 28 novembre 2025  
**Projet :** Développement ESP32 – Tests matériel et régulation ventilateurs  

---

## 🛠️ Tâches réalisées

### 1. Tests sur le côté gauche de la maquette
- Travail concentré sur le **côté gauche de la maquette**.  
- Réalisation d’un **test complet** avec tous les sous-ensembles câblés (résistances, capteurs, ventilateurs, PWM).  
- Les tests étaient globalement **concluants**, malgré un problème identifié sur la régulation des ventilateurs.

### 2. Problème détecté : régulation ventilateurs
- Découverte d’un dysfonctionnement au niveau du **transistor chargé de réguler les ventilateurs** (commande PWM).  
- Pour pouvoir continuer les essais, nous avons **contourné temporairement le problème** en alimentant le ventilateur directement en **12 volts**, sans régulation.  
- Cela a permis de valider le fonctionnement général du côté gauche de la maquette.

### 3. Analyse approfondie du problème
- Analyse du circuit de commande du ventilateur à l’**oscilloscope**.  
- Résultat :  
  - Le transistor était **cramé**.  
  - Cause identifiée : **absence des diodes de protection** qui auraient dû être soudées sur le circuit.  
- Sans ces diodes, les pics de tension ont détruit le transistor lors des premiers essais.

---

## ⚠️ Problème actuel
- **Transistor HS** sur la ligne de commande du ventilateur.  
- **Diodes de protection manquantes**, ce qui a causé la panne.  
- Les tests de régulation PWM ne peuvent pas reprendre tant que le composant n’est pas remplacé.

---

## ⚙️ Préparation pour la prochaine séance
- **Remplacer le transistor** défectueux.  
- **Souder les diodes de protection** afin de sécuriser le circuit.  
- Reprendre les **tests de régulation PWM du ventilateur**.  
- Validation finale du côté gauche de la maquette avant d’attaquer le côté droit.

---

## ✅ Bilan
- Les tests globaux sont concluant malgré une panne matérielle.  
- Le diagnostic est clair et la solution identifiée.  
- Le projet peut reprendre normalement une fois les composants remplacés.


