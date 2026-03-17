# 🧾 Rapport journalier – Séances 14-15

**Date :** 17 mars 2026  
**Projet :** Développement ESP32 – Stabilisation alimentation & gestion WiFi  

---

## 🛠️ Tâches réalisées

### 1. Analyse du problème de reset de l’ESP32
- Travail concentré sur le **bug de reset de l’ESP32**.  
- Cause identifiée : **consommation élevée du module WiFi**, entraînant des instabilités d’alimentation.  
- Le changement de capacité réalisé lors de la séance précédente n’a pas permis de résoudre le problème.

### 2. Optimisation du code
- Tentative d’allègement du code pour réduire la charge :
  - Suppression des **paramètres K du PID**.  
  - Suppression de la **page admin**.  
  - Conservation d’une seule **page web simplifiée** permettant :
    - d’afficher la **température moyenne**,  
    - de modifier la **consigne**.  

- Modification de la logique de régulation :
  - Passage de la **régulation sur le cœur 1**.  
  - Suppression de la **boucle PID**, remplacée temporairement par une gestion **ON/OFF des résistances**.

### 3. Ajustement de l’alimentation
- Mise en place d’une solution temporaire :
  - **Abaissement de la tension d’alimentation à 12V** pour limiter les problèmes liés à l’alimentation.  
- Cette solution permet de **réduire les risques de reset**, mais ne constitue pas une solution définitive.

---

## ⚠️ Problème actuel
- Le système reste **instable** lorsque la consommation augmente (notamment avec le WiFi).  
- L’alimentation actuelle ne fournit pas suffisamment de **courant stable** pour l’ensemble du système.

---

## ⚙️ Préparation pour la prochaine séance
- Tester le système avec une **alimentation plus puissante** afin de fournir un courant suffisant.  
- Vérifier la stabilité de l’ESP32 avec le WiFi actif.  
- Réintroduire progressivement les fonctionnalités supprimées (PID, page admin).  
- Valider une solution **stable et durable**.

---

## ✅ Bilan
- Le problème de reset est mieux compris (lié à l’alimentation et au WiFi).  
- Des solutions temporaires ont été mises en place pour stabiliser le système.  
- Une amélioration matérielle (alimentation) est nécessaire pour finaliser le projet.

---

**Signature :** *(à compléter)*
