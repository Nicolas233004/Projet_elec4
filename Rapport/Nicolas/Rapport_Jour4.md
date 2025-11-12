# 🧾 Rapport journalier – Jour 4

**Date :** 11 octobre 2025  
**Projet :** Développement ESP32 – Interface Web et intégration PID  

---

## 🛠️ Tâches réalisées

### 1. Amélioration de la page web
- Amélioration de la **page HTML** hébergée sur l’ESP32.  
- Séparation de l’interface en **deux pages distinctes** :
  - **Page utilisateur (User)** : permet de **visualiser la consigne** et la **valeur moyenne des capteurs**.  
  - **Page administrateur (Admin)** : permet de **modifier la consigne** et de **régler les paramètres K du PID** (Kp, Ki, Kd).  
- Ces améliorations permettent une **meilleure organisation** et une **gestion plus claire** entre l’affichage et le contrôle des paramètres.

### 2. Essais sur la maquette
- Tentative de **test complet du système** sur la maquette.  
- Découverte d’un **problème de court-circuit** au niveau des **sorties des résistances sur la carte**.  
- Test interrompu afin d’éviter toute dégradation du matériel.

---

## ⚠️ Problème rencontré
- **Court-circuit** détecté sur la **carte de puissance**, probablement lié au câblage des résistances.  
- Diagnostic en cours pour identifier la source exacte du défaut.  

---

## ⚙️ Préparation pour la prochaine séance
- **Réglage du problème de court-circuit** sur la carte avant de reprendre les tests.  
- Vérification de la continuité et de l’isolation des pistes concernées.  
- Une fois le problème corrigé, **reprise des tests** du PID et validation des deux pages web (user/admin).

---

## ✅ Bilan
- Les **améliorations web** sont terminées et fonctionnelles.  
- Le système côté code est prêt, mais le **problème matériel** doit être résolu avant de poursuivre.  
- Prochaine étape : sécuriser la carte et **tester la régulation complète**.

