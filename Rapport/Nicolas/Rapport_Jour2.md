# 🧾 Rapport journalier – Jour 2

**Date :** 23 octobre 2025  
**Nom :** *ROTH*  
**Projet :** Développement ESP32 – Gestion des capteurs, résistances et ventilateurs  

---

## 🛠️ Tâches réalisées

### 1. Développement des tests unitaires
- Rédaction du **code de tests unitaires** pour les **résistances chauffantes** et les **ventilateurs**.  
- Vérification du bon fonctionnement des sorties et du contrôle via l’ESP32.  

### 2. Résolution de problèmes techniques
- Identification de **problèmes de câblage** sur les résistances.  
- **Dessoudage et ressoudage** des fils des résistances pour corriger les connexions défectueuses.  
- Découverte d’un problème lors des tests :  
  - En mettant la sortie de la résistance à **LOW**, une tension résiduelle de **30V** persistait.  
  - Après analyse, il s’est avéré que le problème venait de l’absence de **charge** pendant le test, et non d’un défaut matériel.  
- Après correction, les tests se sont avérés **concluants**.

### 3. Intégration du code principal
- Création du **code principal** regroupant l’ensemble des tests unitaires (capteurs, résistances et ventilateurs).  
- Mise en place d’un **PID** (Proportionnel – Intégral – Dérivé) pour gérer la régulation et le regroupement des sous-ensembles.

---

## ⚙️ Préparation pour la prochaine séance
- Mise en place de la **gestion des deux cœurs** de l’ESP32 (répartition des tâches).  
- Si le temps le permet début du développement de la **page web de supervision**.  

---

## ✅ Bilan
- Les tests unitaires sont **fonctionnels** pour les résistances et ventilateurs.  
- Le **PID** est opérationnel et intégré au code principal.  
- La plateforme est prête pour l’étape suivante d’optimisation et d’interface web.

---

