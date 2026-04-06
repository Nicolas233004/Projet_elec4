# 🧾 Rapport journalier – Séance 16

**Date :** 03 avril 2026  
**Projet :** Développement ESP32 – Alimentation, stabilité et améliorations système  

---

## 🛠️ Tâches réalisées

### 1. Tests avec une nouvelle alimentation
- Test d’une **alimentation plus puissante**, capable de fournir davantage de courant.  
- Résultat :
  - Possibilité d’exploiter **100% de la puissance de chauffe**.  
  - Alimentation stable en **24V**.  
- Concernant les **problèmes de reset** :
  - Le problème est **atténué** (moins fréquent),  
  - mais **toujours présent**.

### 2. Adaptation de la stratégie de régulation
- Abandon temporaire de la **régulation PID**.  
- Mise en place d’une régulation simplifiée :
  - Définition d’une **température cible**.  
  - Si la température est **inférieure à la consigne → chauffage ON**.  
  - Sinon → chauffage OFF.  
- Objectif : améliorer la **robustesse** du système face aux resets.

### 3. Gestion des erreurs liées aux capteurs
- Problème identifié :
  - Les resets peuvent perturber le **bus OneWire** des capteurs de température.  
  - Valeur d’erreur observée : **-127°C**.  
- Solution mise en place :
  - Ajout d’une **sécurité logicielle** :
    - Si la valeur lue est **-127**, alors **réinitialisation des capteurs**.  

### 4. Ajout d’un capteur
- Intégration d’un **nouveau capteur de température** pour mesurer la température **à l’intérieur de la ruche**.  
- Mise à jour du code pour prendre en compte cette nouvelle donnée.

### 5. Amélioration mécanique de la maquette
- Déplacement des **charnières** sur la maquette.  
- Objectif :
  - Permettre une **ouverture plus facile**.  
  - Éviter de devoir **tout décâbler** lors des interventions.

---

## ⚠️ Problème actuel
- Les **resets de l’ESP32** sont toujours présents, bien que moins fréquents.  
- Une solution définitive n’a pas encore été trouvée.

---

## ⚙️ Préparation pour la prochaine séance
- Continuer à **limiter l’impact des resets** via des sécurités logicielles.  
- Investiguer plus en profondeur la cause du problème.  
- Tester la stabilité du système sur une durée prolongée.
- Tester la capacitée de chauffe de la ruche 

---

## ✅ Bilan
- L’alimentation plus puissante améliore les performances globales.  
- Le système est rendu plus **robuste** grâce à des sécurités logicielles.  
- Des améliorations matérielles et ergonomiques ont été apportées.  
- Le problème de reset persiste mais est mieux maîtrisé.

