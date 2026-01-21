# 🧾 Rapport journalier – Séance 9

**Date :** 21 janvier 2026  
**Nom :** *(à compléter)*  
**Projet :** Développement ESP32 – Gestion WiFi et multitâche  

---

## 🛠️ Tâches réalisées

### 1. Modification de la gestion WiFi
- Modification du mode de connexion WiFi de l’**ESP32**.  
- Initialement, l’ESP32 se connectait à un **réseau WiFi existant**.  
- Désormais, l’ESP32 crée son propre **hotspot WiFi (mode Access Point)**.  
- La **page web embarquée** est accessible via l’adresse IP :  
  **192.168.1.15**.  
- Cette solution rend le système **autonome** et plus simple à utiliser sans dépendre d’un réseau externe.

### 2. Répartition des tâches sur les deux cœurs de l’ESP32
- Modification du code pour exploiter les **deux cœurs** de l’ESP32 :  
  - **Cœur 0** : gestion de la **page web** et du serveur HTTP.  
  - **Cœur 1** : gestion de la **régulation PID**.  
- La séparation des tâches fonctionne et permet une meilleure organisation du programme.

---

## ⚠️ Problème rencontré
- Malgré le bon fonctionnement global, l’**ESP32 redémarre de manière intempestive (reset)**.  
- Le problème semble lié à la **gestion du multitâche** ou à une surcharge/erreur dans l’exécution des tâches sur les deux cœurs.  
- Des investigations supplémentaires sont nécessaires pour identifier la cause exacte (watchdog, stack overflow, accès concurrent, etc.).

---

## ⚙️ Préparation pour la prochaine séance
- Identifier et corriger la cause des **reset de l’ESP32**.  
- Vérifier :
  - La gestion des tâches FreeRTOS.  
  - La taille des stacks.  
  - Les accès partagés entre le cœur 0 et le cœur 1.  
- Stabiliser le fonctionnement avant de poursuivre les améliorations fonctionnelles.

---

## ✅ Bilan
- Le **mode hotspot WiFi** est fonctionnel et la page web est accessible.  
- La **répartition du code sur les deux cœurs** est en place.  
- Le système nécessite encore une **phase de stabilisation** à cause des redémarrages.

