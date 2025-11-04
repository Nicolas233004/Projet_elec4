# 🧾 Rapport journalier – Jour 3

**Date :** 10 octobre 2025  
**Projet :** Développement ESP32 – Interface Web et serveur embarqué  

---

## 🛠️ Tâches réalisées

### 1. Développement de la page web
- Conception et mise en place d’une **page web** hébergée directement sur l’**ESP32**.  
- Cette page permet d’afficher la **température actuelle** ainsi que la **consigne**, et de **modifier la consigne** via un champ de saisie.  
- L’interface est accessible en se connectant sur le **même réseau Wi-Fi** que l’ESP32, puis en entrant son **adresse IP** dans un navigateur.

### 2. Problèmes rencontrés et résolus
- Un **gros problème de librairies manquantes** a ralenti le développement.  
- En cause : suppression accidentelle de **fichiers essentiels** aux librairies utilisées.  
- Solution : réinstallation complète des librairies et vérification de la compatibilité avec PlatformIO.  
- Après résolution, le **serveur web** a pu être relancé et fonctionne correctement.

---

## 🖥️ Résultat
La page web est désormais **opérationnelle** et accessible via le navigateur.  
Voici une capture d’écran de l’interface en fonctionnement :

![Interface Web ESP32 – Régulation de Température](<img width="1913" height="1017" alt="image" src="https://github.com/user-attachments/assets/f87efa31-8ccb-4212-873e-38066f2389d9" />
)

---

## ⚙️ Préparation pour la prochaine séance
- **Amélioration de la page web** pour y ajouter les **paramètres du PID** (P, I, D).  
- Ajout de contrôles interactifs pour ajuster les réglages en temps réel.  
- Vérification de la réactivité de la page et de la mise à jour dynamique des données.

---

## ✅ Bilan
- Le **serveur web ESP32** est fonctionnel.  
- L’interface permet déjà de contrôler la consigne de température.  
- La base est solide pour l’intégration future du PID et des fonctionnalités avancées.


