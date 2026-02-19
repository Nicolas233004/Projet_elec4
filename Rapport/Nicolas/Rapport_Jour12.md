# 🧾 Rapport journalier – Séance 12

**Date :** 19 février 2026  
**Projet :** Développement ESP32 – Correction carte de puissance & contrôle des résistances  

---

## 🛠️ Tâches réalisées

### 1. Résolution du problème de contrôle des résistances
- Travail en collaboration avec **Sean** sur la **carte électronique**, au niveau de la **partie contrôle des résistances**.  
- Problème initial :  
  - Impossible de **couper le circuit** via un code de test simple (ON/OFF des sorties des résistances).  
- Diagnostic et identification des causes :
  - **Transistor Q5 défectueux**.  
  - **Résistance R6 défectueuse**.  

### 2. Corrections matérielles
- **Remplacement du transistor Q5**.  
- **Remplacement de la résistance R6**.  
- Modification du montage du **convertisseur** :
  - Nouvelle méthode de soudure pour le rendre **amovible**.  
  - Repositionnement **plus en hauteur**, afin de faciliter l’accès aux points de mesure.  
  - Objectif : permettre des mesures propres à l’**oscilloscope**.

### 3. Validation fonctionnelle
- Après modifications, les tests ON/OFF des résistances sont désormais **fonctionnels**.  
- Le **contrôle logiciel** des résistances est validé.

---

## ⚙️ Préparation pour la prochaine séance
- **Validation de la partie ventilateurs** sur la carte.  
- Tests complets de la régulation côté ventilateurs.  
- Vérification de la cohérence entre matériel et code.

---

## ✅ Bilan
- Les problèmes matériels sur la **partie résistances** sont corrigés.  
- La carte est désormais **fonctionnelle pour le contrôle ON/OFF** des résistances.  
- Le projet peut avancer sur la partie **ventilation**.


