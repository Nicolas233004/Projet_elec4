# 🧾 Rapport journalier 1

**Date :** 8 octobre 2025  
**Nom :** Nicolas  
**Projet :** Développement ESP32 – Configuration et tests capteurs DS18B20  

---

## 🛠️ Tâches réalisées

### 1. Mise en place de l’environnement de développement
- Création d’un environnement de travail sur **Visual Studio Code**.  
- Installation et configuration de l’extension **PlatformIO** pour assurer la compatibilité avec la carte **ESP32**.  
- Vérification du bon fonctionnement du téléversement du code vers la carte.

### 2. Tests unitaires
- Réalisation des **tests unitaires** sur les capteurs de température **DS18B20**.  
- Objectif : s’assurer du bon fonctionnement et de la détection de tous les capteurs connectés.

### 3. Résultats obtenus
- Les **6 capteurs DS18B20** ont été correctement détectés et leurs valeurs de température sont bien remontées.  
- Le test est **concluant**.
- 
## ⚠️ Problèmes rencontrés
- Problème de **connectique** avec le câble reliant les capteurs à l’**ESP32**.  
- Nécessité d’installer le **driver du port COM** pour permettre la communication entre la carte et l’ordinateur.  
- Après résolution de ces problèmes, le téléversement et les tests ont pu être effectués avec succès.

---

## ✅ Bilan
- L’environnement de développement est **opérationnel**.  
- Les capteurs sont **fonctionnels et bien intégrés** au système.  
- Prochaine étape : Continuer les tets unitaires.

---

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

# 🧾 Rapport journalier – Séance 5

**Date :** 27 Novembre 2025  
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


# 🧾 Rapport journalier – Séance 7

**Date :** 11 novembre 2025  
**Nom :** Roth  
**Projet :** Développement ESP32 – Remise en état carte & tests maquette

---

## 🛠️ Tâches réalisées

### 1. Remplacement des composants défectueux
- Remplacement des **transistors cramés** sur la carte.  
- Ajout des **diodes de roue libre** qui manquaient et qui avaient provoqué les pannes précédentes.  
- Les soudures ont été vérifiées et corrigées avant de reprendre les tests.

### 2. Réparation d’un problème de pad arraché
- Lors de la réparation, le **fil rouge de CR1** a causé un problème : le **pad s’est arraché** à cause d’une mauvaise soudure.  
- Pour corriger cela, le fil a été **directement soudé sur une borne du transistor Q3**, ce qui a permis de rétablir la connexion sans refaire la carte.

### 3. Tests du côté gauche de la maquette
- Contrôle complet des **transistors pour la régulation des ventilateurs** : tests concluants.  
- Une fois les problèmes de carte réglés, nous avons testé le **code pour la partie gauche** de la maquette.  
- Les résultats ont été **entièrement satisfaisants**, ce qui nous permet de **mettre de côté** cette partie et de la considérer comme fonctionnelle.

---

## 🔧 Début des tests côté droit
### Ventilateurs
- Tests réalisés sur les ventilateurs du **côté droit** de la maquette.  
- Fonctionnement **du premier coup**, aucune anomalie détectée.

### Capteurs de température
- Suspicion d’un **faux contact** sur les capteurs de température côté droit.  
- Les valeurs ne remontent pas correctement — diagnostic à approfondir lors de la prochaine séance.

### Résistances
- Les **résistances du côté droit** n’ont pas encore été testées.  
- Elles seront vérifiées lors de la prochaine session en même temps que les capteurs.

---

## ⚙️ Préparation pour la prochaine séance
- Vérifier l’origine du **faux contact** sur les capteurs de température côté droit.  
- Tester les **résistances** du même côté.  
- Finaliser la validation complète de la partie droite de la maquette.

---

## ✅ Bilan
- Les réparations matérielles sur la carte ont été **réussies**.  
- La **partie gauche** de la maquette est maintenant **entièrement fonctionnelle**.  
- Début prometteur pour la **partie droite**, avec seulement un souci mineur à régler.
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

# 🧾 Rapport journalier – Séance 10

**Date :** 03 février 2026   
**Projet :** Développement ESP32 – Intégration écran & interface utilisateur  

---

## 🛠️ Contexte
- La **carte principale** est actuellement utilisée par **Sean** pour régler les problèmes **physiques de régulation sur le côté gauche** de la maquette.  
- Afin de ne pas rester inactifs pendant cette phase, une **tâche annexe** a été mise en place.

---

## 🛠️ Tâches réalisées

### 1. Intégration de l’écran
- Avec **Léandro**, nous avons travaillé sur l’**intégration d’un écran** afin d’obtenir un **retour d’information direct** sur la maquette (sans passer uniquement par la page web).  
- Objectif : préparer une **interface locale** pour l’utilisateur.

### 2. Travaux matériels
- Réalisation de la **soudure des pins** de l’écran.  
- **Connexion de l’écran à l’ESP32**.  
- Vérification de la continuité électrique et de la bonne alimentation de l’écran.

---

## ⚙️ Préparation pour la prochaine séance
- Développement du **code de l’interface utilisateur** sur l’écran.  
- Mise en place de la **communication entre l’écran et le code principal de l’ESP32**.  
- Synchronisation des informations (température, consigne, état du système, etc.).

---

## ✅ Bilan
- L’**écran est physiquement intégré** et connecté à l’ESP32.  
- Le matériel est prêt pour la phase logicielle.  
- Prochaine étape : rendre l’écran **fonctionnel et interactif**.

# 🧾 Rapport journalier – Séance 11

**Date :** 17 février 2026  
**Nom :** *(à compléter)*  
**Projet :** Développement ESP32 – Intégration écran & amélioration maquette  

---

## 🛠️ Tâches réalisées

### 1. Tests de l’écran
- Poursuite des **tests d’intégration de l’écran**.  
- Les essais n’ont pas été **concluants**, avec des problèmes persistants de fonctionnement/communication.  
- L’écran n’est pas encore opérationnel dans le système actuel.

### 2. Amélioration mécanique de la maquette
- Ajout de **charnières** sur la maquette.  
- Objectif : améliorer l’**accessibilité** aux composants internes et faciliter la maintenance, le câblage et le débogage.

### 3. Débogage de la carte
- Reprise du **débogage de la carte électronique**.  
- Analyse des problèmes matériels et/ou logiques encore présents.  
- Vérification des connexions, des composants critiques et du comportement global du système.

---

## ⚙️ Préparation pour la prochaine séance
- Continuer les **tests et le diagnostic de l’écran**.  
- Identifier précisément l’origine des problèmes (alimentation, communication, librairies, câblage).  
- Poursuivre le **débogage de la carte**.  
- Reprendre l’intégration logicielle une fois la partie matérielle stabilisée.

---

## ✅ Bilan
- Les tests de l’écran sont en cours mais **non fonctionnels** à ce stade.  
- La maquette est désormais **mécaniquement améliorée** grâce aux charnières.  
- Le travail de **débogage** progresse en parallèle pour fiabiliser le système.

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

# 🧾 Rapport journalier – Séance 17

**Date :** 10 avril 2026  
**Projet :** Développement ESP32 – Finalisation maquette & amélioration logiciel  

---

## 🛠️ Tâches réalisées

### 1. Finalisation de la maquette
- Travail avec **Sean** pour finaliser la partie mécanique de la maquette.  
- Fixation du **cadran en bois** sur la boîte.  
- Ajout de **fines planches en bois** pour créer un **cache-câbles** :
  - Permet d’éviter que les câbles gênent lors de la fermeture.  
- Réalisation d’un **trou dans le cadran** pour faire passer les **câbles d’alimentation**.  
- Soudure du **capteur de température interne** permettant de mesurer la température à l’intérieur de la ruche.

### 2. Tests globaux
- Réalisation d’un **test complet de toute la maquette**.  
- Résultat : fonctionnement global **plutôt concluant**.

### 3. Amélioration du code
- Ajout d’une **sauvegarde de la consigne dans l’EEPROM**.  
- Objectif :
  - Éviter la perte de la consigne lors des **crashs ou resets de l’ESP32**.  
- Amélioration de la **robustesse du système**.

---

## ⚙️ Préparation pour la prochaine séance
- Développement d’un **script Python** pour :
  - Tracer les **courbes de chauffe de la ruche**.  
  - Analyser les performances du système de régulation.  

---

## ✅ Bilan
- La maquette est désormais **finalisée mécaniquement**.  
- Le système fonctionne de manière **globale et cohérente**.  
- Le code est plus **fiable** grâce à la sauvegarde en EEPROM.  
- Prochaine étape : **analyse des données et optimisation**.

# Rapport Séance 1

## 1. Création du GitHub + ajout des membres du groupe
Pour s’assurer de ne pas perdre des documents et pour suivre l’avancement global du projet, j’ai créé un dépôt GitHub.  
J’y ai ajouté mes camarades et nous avons créé différents dossiers (*datasheets*, *Rapport Séance*, *test Capteur*, etc.).

## 2. Prise de connaissance de l’ancien GitHub
J’ai récupéré le lien de l’ancien GitHub via le mail de M. Peter.  
J’ai ensuite pris connaissance de chacun des rapports écrits par les anciens élèves.

## 3. Établissement du CDC + Liste d’actions à mener
Après avoir étudié l’ancien GitHub, nous avons établi un cahier des charges (CDC) ainsi qu’une liste d’actions à mener.  
Nous avons ensuite partagé les tâches à effectuer.

## 4. Ajout de l’extension PlatformIO pour programmer sur ESP32 dans Visual Studio Code
Pour programmer les ESP32, l’extension PlatformIO est nécessaire.  
Je l’ai donc installée dans Visual Studio Code et écrit quelques lignes de code afin de vérifier que l’environnement fonctionnait correctement.

## 5. Installation du logiciel Eagle
Pour consulter les schémas électriques du PCB, j’ai dû installer le logiciel Eagle.  
Ce logiciel pourra également être utile si le PCB créé par les anciens élèves s’avère non fonctionnel.
# Rapport de Séance 2  
**Date :** 08/10/2025  
**Nom :** Leandro Euphrasie  
**Formation :** ELSE 4 – FISA  

## 1. Nettoyage de la maquette
L’une des exigences du projet était de refaire entièrement le câblage du toit de la ruche.  
Je me suis donc équipé des outils nécessaires (fer à souder, pince coupante) afin de remettre la maquette au propre et repartir sur une base saine pour les prochaines manipulations.

## 2. Installation du logiciel Micro-Cap 12
J’ai téléchargé le fichier ZIP du logiciel Micro-Cap 12 depuis le site :  
*https://bvcircuits.com/tools/micro-cap-spice/*  
Après extraction, j’ai procédé à l’installation pour pouvoir simuler les circuits du projet.

## 3. Reproduction du schéma sous Micro-Cap 12
J’ai tenté de reproduire le schéma électrique directement dans Micro-Cap 12.  
Cependant, le logiciel ne permet pas d’ajouter certains composants, notamment les moteurs, ce qui limite la modélisation complète du système.

## 4. Ajout des datasheets au GitHub
J’ai ajouté les datasheets des résistances et des ventilateurs sur le dépôt GitHub afin d'améliorer la documentation du projet et faciliter le travail du groupe.

## 5. Dessoudage des câbles reliant les capteurs
À l’aide d’une pince et d’un fer à souder, j’ai retiré les anciens câbles des capteurs pour préparer une nouvelle installation plus propre et plus fiable.

## 6. Ressoudage des capteurs
J’ai récupéré des gaines thermorétractables au FabLab pour assurer une isolation propre lors du ressoudage des capteurs.  
J’ai commencé la remise en place, mais je me suis arrêté à une patte d’un capteur, le travail devant être finalisé lors de la prochaine séance.
# Rapport Séance 3  
**Date :** 04/11/2025  
**Nom :** Leandro Euphrasie  
**Formation :** ELSE 4 – FISA  

## 1. Finalisation de la soudure des capteurs de température
J’ai récupéré les capteurs de température et commencé à les souder en salle de TP.  
Cependant, les fers à souder du FabLab étant plus adaptés, je m’y suis rendu accompagné de Sean pour réaliser l’ensemble des soudures et ajouter les gaines thermorétractables.

N’ayant jamais soudé auparavant, j’ai demandé l’aide de Sean Bondon pour comprendre :
- la technique de soudure,
- l’utilisation des outils (paille de fer, éponge humide, flux, etc.).

Il a réalisé la moitié des soudures afin de me montrer la méthode, puis j’ai pris le relais et terminé le travail.

## 2. Mise en place des capteurs dans la maquette
Une fois les capteurs entièrement soudés, je les ai insérés dans le toit de la maquette.  
J’ai dû agrandir les emplacements prévus pour permettre une installation propre et stable des capteurs.

## 3. Câblage des résistances
Sean a commencé à souder les résistances, puis j’ai poursuivi et terminé la soudure de l’ensemble des composants.

---

## Prochaines étapes
- Relier tous les câbles au PCB  
- Percer le couvercle du toit chauffant afin de faire passer les câbles proprement  

# Rapport de Séance 4  
**Date :** 12/11/2025  
**Nom :** Leandro Euphrasie  
**Formation :** ELSE 4 – FISA  

## 1. Ajout de pins sur le PCB
Afin de pouvoir tester correctement le PCB, j’ai dû souder des pins directement sur la carte.  
Cette étape permet de faciliter les connexions et de préparer les futurs tests fonctionnels.

## 2. Perçage du couvercle du toit chauffant
Avec Sean, nous nous sommes rendus au FabLab pour percer la planche destinée à accueillir la carte.  
L’objectif était de créer des passages pour l’ensemble des câbles :  
- alimentation des résistances,  
- câbles des ventilateurs,  
- capteurs de température.  

Ce travail permet d’organiser proprement le câblage dans la maquette.

## 3. Ressoudage de l’alimentation sur le PCB
Un court-circuit a été détecté par Nicolas.  
La cause semble provenir de l’ancienne soudure des câbles d’alimentation réalisée par le groupe précédent.  
Il sera nécessaire de ressouder ces câbles proprement afin d’assurer un fonctionnement sécurisé et fiable du circuit.

---

## Prochaines étapes
- Utiliser l’outil mis à disposition par M. Peter pour installer les charnières sur la maquette  
- Ressouder les câbles d’alimentation sur le PCB  
# Rapport de Séance 11

**Date :** 12/11/2025  
**Nom :** Leandro Euphrasie  
**Formation :** ELSE 4 – FISA  

---

## 1. Remise en état matérielle

Lors de cette séance, j’ai commencé par une vérification complète du montage existant.  
Certaines soudures étaient endommagées ou fragilisées, ce qui pouvait provoquer des faux contacts et des dysfonctionnements intermittents.

J’ai donc repris et refait les soudures défectueuses afin d’assurer une meilleure continuité électrique et d’améliorer la fiabilité globale du système.

---

## 2. Migration de l’environnement de développement

J’ai également changé d’environnement de développement.  
Au lieu d’utiliser l’IDE Arduino, j’ai migré vers **Visual Studio Code** avec l’extension **PlatformIO**.

Cette migration m’a permis :

- Une meilleure gestion des dépendances et des librairies  
- Une configuration plus claire des cartes ESP32  
- Une structure de projet plus professionnelle  

La transition a nécessité la reconfiguration complète du projet ainsi que l’adaptation des paramètres de compilation pour la carte ESP32 utilisée.

---

## 3. Vérification et reprise du câblage de l’écran TFT

L’objectif principal de la séance était de faire fonctionner un écran TFT SPI basé sur le contrôleur **ILI9486**.

Pour fiabiliser le câblage, je me suis appuyé sur les schémas de l’ESP32 consultés via le logiciel **Autodesk Eagle**.  

Cela m’a permis de :

- Vérifier la correspondance des broches SPI (MOSI, MISO, SCK, CS, DC, RST)  
- Corriger certaines erreurs de branchement  
- Assurer la cohérence entre le schéma théorique et le montage réel  

Les connexions ont été reprises proprement en respectant les spécifications du bus SPI.

---

## 4. Développement d’un programme de test

Afin de valider le bon fonctionnement du montage, j’ai développé un programme simple permettant :

- D’initialiser la communication SPI  
- D’afficher une couleur unie sur l’écran  

L’objectif de ce test était de vérifier :

- L’initialisation correcte de l’écran  
- La bonne communication entre l’ESP32 et le contrôleur TFT  
- La cohérence du rendu des couleurs  

---

## 5. État actuel et difficultés rencontrées

Malgré la reprise des soudures, la correction du câblage et la migration vers un nouvel environnement de développement, le système ne fonctionne toujours pas correctement.

L’écran ne s’affiche pas comme attendu et ne valide pas encore le test de couleur unie.  
Le dysfonctionnement peut provenir :

- D’un problème de configuration logicielle (driver ou paramètres SPI)  
- D’un défaut matériel persistant (câblage ou composant)  
- D’un problème d’alimentation ou de stabilité électrique  

---

## Prochaines étapes

- Vérifier en détail la configuration du driver ILI9486  
- Tester une autre librairie compatible  
- Mesurer les tensions d’alimentation au multimètre  
- Contrôler chaque ligne SPI individuellement  
- Tester l’écran sur une autre carte pour isoler l’origine du problème  
# Rapport de Séance 11

**Date :** 12/11/2025  
**Nom :** Leandro Euphrasie  
**Formation :** ELSE 4 – FISA  

---

## 1. Remise en état matérielle

Lors de cette séance, j’ai commencé par une vérification complète du montage existant.  
Certaines soudures étaient endommagées ou fragilisées, ce qui pouvait provoquer des faux contacts et des dysfonctionnements intermittents.

J’ai donc repris et refait les soudures défectueuses afin d’assurer une meilleure continuité électrique et d’améliorer la fiabilité globale du système.

---

## 2. Migration de l’environnement de développement

J’ai également changé d’environnement de développement.  
Au lieu d’utiliser l’IDE Arduino, j’ai migré vers **Visual Studio Code** avec l’extension **PlatformIO**.

Cette migration m’a permis :

- Une meilleure gestion des dépendances et des librairies  
- Une configuration plus claire des cartes ESP32  
- Une structure de projet plus professionnelle  

La transition a nécessité la reconfiguration complète du projet ainsi que l’adaptation des paramètres de compilation pour la carte ESP32 utilisée.

---

## 3. Vérification et reprise du câblage de l’écran TFT

L’objectif principal de la séance était de faire fonctionner un écran TFT SPI basé sur le contrôleur **ILI9486**.

Pour fiabiliser le câblage, je me suis appuyé sur les schémas de l’ESP32 consultés via le logiciel **Autodesk Eagle**.  

Cela m’a permis de :

- Vérifier la correspondance des broches SPI (MOSI, MISO, SCK, CS, DC, RST)  
- Corriger certaines erreurs de branchement  
- Assurer la cohérence entre le schéma théorique et le montage réel  

Les connexions ont été reprises proprement en respectant les spécifications du bus SPI.

---

## 4. Développement d’un programme de test

Afin de valider le bon fonctionnement du montage, j’ai développé un programme simple permettant :

- D’initialiser la communication SPI  
- D’afficher une couleur unie sur l’écran  

L’objectif de ce test était de vérifier :

- L’initialisation correcte de l’écran  
- La bonne communication entre l’ESP32 et le contrôleur TFT  
- La cohérence du rendu des couleurs  

---

## 5. État actuel et difficultés rencontrées

Malgré la reprise des soudures, la correction du câblage et la migration vers un nouvel environnement de développement, le système ne fonctionne toujours pas correctement.

L’écran ne s’affiche pas comme attendu et ne valide pas encore le test de couleur unie.  
Le dysfonctionnement peut provenir :

- D’un problème de configuration logicielle (driver ou paramètres SPI)  
- D’un défaut matériel persistant (câblage ou composant)  
- D’un problème d’alimentation ou de stabilité électrique  

---

## Prochaines étapes

- Vérifier en détail la configuration du driver ILI9486  
- Tester une autre librairie compatible  
- Mesurer les tensions d’alimentation au multimètre  
- Contrôler chaque ligne SPI individuellement  
- Tester l’écran sur une autre carte pour isoler l’origine du problème  
# Rapport de Séance 12

**Date :** 19/02/2025  
**Nom :** Leandro Euphrasie  
**Formation :** ELSE 4 – FISA  

---

## 1. Vérification du câblage et incident d’alimentation

Lors de cette séance, j’ai commencé par revérifier l’ensemble des câblages de l’écran TFT afin d’identifier l’origine du dysfonctionnement constaté lors de la séance précédente.

Au cours de cette manipulation, une erreur s’est produite lors du réglage de l’alimentation.  
Initialement réglée à 3 V, j’ai tenté de la passer à 5 V. Cependant, une mauvaise manipulation du curseur de l’alimentation a entraîné une montée accidentelle de la tension à 13 V puis à 23 V.

Cette surtension a provoqué l’extinction immédiate de l’écran.

---

## 2. Analyse de la consommation électrique

Après l’incident, j’ai mesuré la consommation de l’écran.  
Celui-ci consomme désormais environ **0,02 A**, mais ne s’allume plus.

Cette faible consommation peut indiquer :

- Une absence de fonctionnement de la dalle d’affichage  
- Un circuit partiellement endommagé  

---

## 3. Vérifications matérielles approfondies

Afin d’identifier l’origine du problème, j’ai utilisé un multimètre pour :

- Tester la continuité des pistes  
- Vérifier l’absence de court-circuit visible  

J’ai ensuite décollé l’écran du PCB afin d’inspecter les composants situés à l’arrière de la carte.  
Mais je n’ai pu observer Aucune anomalie 

---

## 4. Analyse technique et hypothèse

Il est probable que la surtension ait endommagé la dalle LED ou le système de rétroéclairage.

Selon mon analyse :

- Le PCB et le contrôleur pourraient encore être fonctionnels  
- La dalle d’affichage ou le rétroéclairage semblent défaillants  

La surtension appliquée (jusqu’à 23 V) dépasse largement la spéc.

---

## 5. Conclusion et décision

Je me suis donc separer de l’ecran

---

## Prochaines étapes

- Remplacer l’écran TFT par un nouveau module  
# Rapport de Séance 10

**Date :** 12/11/2025
**Nom :** Leandro Euphrasie
**Formation :** ELSE 4 – FISA

---

## 1. Implémentation d’un écran TFT SPI (ILI9486)

Lors de cette séance, j’ai tenté d’implémenter un écran **TFT SPI ILI9486**, acheté personnellement pour un usage de test.
L’objectif était d’ajouter une interface d’affichage au projet afin de visualiser certaines informations du système.

Pour faciliter les tests et le câblage, j’ai utilisé un **bornier à vis**, permettant des connexions plus rapides et modulables.
Après des recherches sur Internet, j’ai identifié les schémas de câblage nécessaires et procédé à la **soudure de l’ensemble des pins de l’écran** sur les pins correspondants de la carte.

---

## 2. Problème d’alimentation

Un problème d’alimentation a rapidement été identifié :

* L’**ESP32 fournit une tension de 3,3 V**,
* L’**écran TFT nécessite une alimentation comprise entre 5 et 6 V**.

Afin de permettre le fonctionnement de l’écran, j’ai donc utilisé une **alimentation externe** adaptée pour fournir la tension requise.

---

## 3. Configuration logicielle

Pour les tests, j’ai installé **Arduino UNO** ainsi que l’ensemble des **librairies nécessaires** au fonctionnement de l’écran TFT ILI9486.
Cette étape était indispensable pour assurer la communication SPI entre le microcontrôleur et l’écran.

---

## 4. Problème d’affichage rencontré

Malgré une mise sous tension correcte, l’affichage présente un dysfonctionnement :

* Les **couleurs sont très pâles**,
* L’**affichage est peu visible**,
* Le rendu global ne correspond pas au fonctionnement attendu de l’écran.

Ce problème peut provenir de plusieurs causes possibles :

* Une **librairie inadaptée ou mal configurée**,
* Un **problème d’alimentation** (tension ou courant insuffisant),
* Une **erreur de câblage ou de soudure** sur certains pins.

---

## Prochaines étapes

Pour la prochaine séance, les actions prévues sont :

* Analyser en détail l’origine du problème d’affichage,
* Tester différentes **librairies compatibles avec l’ILI9486**,
* Vérifier la **stabilité de l’alimentation** utilisée,
* Contrôler les **soudures et le câblage SPI** afin d’éliminer toute erreur matérielle.
# Rapport de Séance 13

**Date :** 05/03/2026  
**Nom :** Leandro Euphrasie  
**Formation :** ELSE 4 – FISA  
**Sujet :** Intégration du nouvel écran TFT 128x160 et analyse des schémas

---

## 1. État des lieux après l'incident de la Séance 12
Suite à la surtension accidentelle (montée à 23V) ayant rendu l'écran précédent inutilisable (consommation figée à 0,02 A sans affichage), j'ai procédé au remplacement complet du module par un nouvel écran TFT SPI 128x160.

## 2. Analyse Technique et Documentation
Pour éviter une nouvelle erreur de câblage ou de tension, j'ai récupéré et étudié plusieurs documents techniques :
* **Schémas de l'ESP32-WROOM-32 :** Identification des broches physiques vs GPIO.
* **Schématique du projet (ESP_LoRa_Thermal) :** Analyse du circuit existant pour éviter les conflits avec le module LoRa et le lecteur de carte SD.
* **Pinout Otronic :** Repérage spécifique des labels de ma carte de développement (D2, D4, D18, D23, D5).

## 3. Travaux réalisés : Nouveau Câblage
J'ai mis en place un câblage sécurisé sur le bus **VSPI** de l'ESP32 afin de garantir une vitesse d'affichage optimale sans interférer avec les autres périphériques :

| Écran TFT | ESP32 (Label Carte) | Rôle |
| :--- | :--- | :--- |
| **VCC** | 3V3 | Alimentation |
| **GND** | GND | Masse |
| **SCL / SCK** | D18 (GPIO 18) | Horloge SPI |
| **SDA / SDI** | D23 (GPIO 23) | Données SPI |
| **CS** | D5 (GPIO 5) | Chip Select |
| **A0 (DC)** | D2 (GPIO 2) | Data/Command |
| **RESET** | D4 (GPIO 4) | Réinitialisation |



## 4. Problématique constatée
Malgré le nouveau câblage, l'écran **s'éclaire en blanc** mais n'affiche aucune donnée. 

### Hypothèses de diagnostic :
1.  **Câblage des données :** Inversion possible entre SDA (MOSI) et SCL (Clock), ou mauvaise connexion de la broche A0 (DC).
2.  **Alimentation :** Bien que le rétroéclairage fonctionne (écran blanc), le contrôleur interne de l'écran ne reçoit peut-être pas une tension stable.
3.  **Initialisation logicielle :** Le driver utilisé dans le code (ST7735) nécessite peut-être un "Tab" spécifique (BlackTab vs GreenTab) pour correspondre à cette nouvelle dalle.

## 5. Conclusion et objectifs de la séance 14
L'étape de remplacement matériel est validée. La prochaine séance sera dédiée à la résolution du problème d'affichage ("White Screen").

**Actions prévues :**
* Tester la continuité de chaque fil entre l'ESP32 et l'écran.
* Vérifier au multimètre que la tension sur la broche VCC de l'écran est bien de 3.3V constants.
* Adapter le code de test pour essayer différents types d'initialisation SPI.
# Rapport de Séance 14 & 15

**Date :** 10/03/2026 et 12/03/2026  
**Nom :** Leandro Euphrasie  
**Formation :** ELSE 4 – FISA  
**Sujet :** Correction du câblage matériel et finalisation de l'interface "TOIT CHAUFFANT"

---

## 1. Objectifs de la séance
L'objectif principal était de résoudre le problème de "l'écran blanc" persistant depuis la séance 13, de valider la communication SPI et de déployer l'interface graphique finale dédiée au contrôle du **Toit Chauffant**.

## 2. Diagnostic et Correction Matérielle
Le dysfonctionnement de l'affichage a été identifié comme une **erreur d'assignation physique des broches** lors de la séance précédente.

### Correction du câblage :
* **Erreur identifiée :** La broche **DC** (Data/Command) de l'écran était câblée sur le **GPIO 2** au lieu du **GPIO 21**. Le GPIO 2 étant une broche de "strapping" (utilisée lors du boot de l'ESP32), cela interférait avec l'initialisation du driver ILI9341 et provoquait un conflit au démarrage.
* **Action :** Basculement du signal DC sur le **GPIO 21**.
* **Justification technique :**Le GPIO 21 est une broche de données standard ne perturbant pas le cycle de démarrage (boot) de la puce.
* **Résultat :** L'écran est devenu immédiatement fonctionnel, permettant de passer au développement de l'interface utilisateur.

## 3. Développement de l'Interface "TOIT CHAUFFANT"
L'interface a été conçue pour offrir une lecture claire et stable des paramètres de régulation via une bibliothèque personnalisée `Affichage.cpp/h` :
* **Organisation visuelle :** Titre **"TOIT CHAUFFANT"** centré en haut de l'écran. Alignement en colonnes pour les données : les libellés à gauche et les valeurs numériques à droite.
* **Code couleur :** * **Orange** pour la température **ACTUELLE** (mesurée par le serveur).
    * **Vert** pour la **CONSIGNE** (reçue du serveur).
* **Stabilité d'affichage :** Utilisation d'un rafraîchissement sélectif basé sur la comparaison des valeurs (`ancienneTemp` vs `tempActuelle`). Cette méthode permet de mettre à jour les chiffres toutes les 200ms sans aucun clignotement de l'écran (anti-flicker).

## 4. Intégration Réseau et Parsing JSON
L'ESP32 Écran agit en tant que **Client HTTP** pour récupérer les données de régulation du premier module (Serveur AP) :
* **Connexion :** Liaison Wi-Fi stable au point d'accès `SEAN_BONDON` (IP fixe : 192.168.1.15).
* **Récupération :** Interrogation automatique de la route JSON `/status` du serveur.
* **Traitement :** Utilisation de la bibliothèque `ArduinoJson` pour extraire les valeurs `temp` et `setpoint` et les injecter dynamiquement dans les fonctions d'affichage.

## 5. Conclusion
Ces séances ont permis de valider l'intégralité de la chaîne : **Matériel (SPI) -> Protocole (HTTP/JSON) -> Interface (TFT)**. La correction du câblage du signal DC (passage du GPIO 2 au 21) a été l'élément déclencheur du succès. L'interface est désormais robuste, esthétique et communique parfaitement avec l'unité de commande du toit chauffant.

---
# Rapport de Séance 16

**Date :** 03/04/26
**Nom :** Leandro Euphrasie
**Formation :** ELSE 4 – FISA
**Sujet :** Extension du monitoring thermique : Intégration de la température intérieure de la ruche

---

## 1. Objectifs de la séance
L'objectif principal de cette séance était d'enrichir l'interface utilisateur et la logique de traitement des données pour afficher a la fois :
* La **température ambiante** (extérieure).
* La **température intérieure** de la ruche.
* La **consigne** de régulation du toit.

## 2. Évolutions Logicielles

### Traitement du flux JSON
Le programme principal a été mis à jour pour exploiter la nouvelle structure du serveur. L'ESP32 extrait désormais trois variables distinctes via la bibliothèque `ArduinoJson` :
* `temp` : Température ambiante.
* `setpoint` : Consigne actuelle.
* `temp_interieur` : Donnée issue de la sonde interne de la ruche.

> **Optimisation réseau :** J'ai configuré un `http.setTimeout(150)`. Ce délai court permet d'éviter que l'interface ne se fige si le serveur met trop de temps à répondre.

### Mise à jour de la classe `Affichage`
Le fichier `Affichage.cpp` a etait modifier pour le rendre plus ergonomique :
* **Structuration spatiale :** Utilisation de `drawFastHLine` pour séparer visuellement le titre, les mesures et la consigne.
* **Méthodes dédiées :** Création de `mettreAJourInterieur()` et `mettreAJourAmbiante()` pour un contrôle précis des zones d'écriture.
* **Gestion du texte :** Utilisation de `setTextPadding(300)` pour effacer proprement les anciennes valeurs numériques sans avoir à redessiner tout l'écran (évite le scintillement).

## Conclusion

Cette séance 16 marque une étape clé dans le projet : le passage d'un simple afficheur de test à une véritable **interface de monitoring environnemental**. 

Grâce à la restructuration du code et à l'optimisation du parsing JSON, l'affichage est désormais capable de gérer plusieurs flux de données en temps réel sans perte de fluidité. 
L'implémentation de la logique de seuil ($\ge 0.1$ °C) et du padding logiciel garantit une lisibilité professionnelle, sans scintillement. 
Le système est maintenant parfaitement fonctionnel pour assurer le suivi thermique précis de la ruche.
# Compte rendu : Séance 1  
**Projet :** Toit chauffant pour ruche d’abeilles  
**Objectif général :** Éliminer le parasite *Varroa destructor* par chauffage contrôlé de la ruche.

---

## 1. Présentation du projet
Le projet consiste à concevoir un toit chauffant destiné aux ruches d’abeilles.  
Ce système vise à réguler la température interne afin d’éliminer les varroas sans nuire à la colonie.  

Le projet se divise en deux grandes parties :
- **Partie électronique :** conception du circuit d’alimentation et de régulation thermique.  
- **Partie informatique :** développement du système de commande et de supervision.  

Je travaille sur la **partie électronique**.

---

## 2. Objectifs de la séance
- Prendre connaissance du matériel disponible.  
- Mettre en place l’environnement de travail pour la conception électronique.  
- Rédiger le **CCTP** (Cahier des Clauses Techniques Particulières).

---

## 3. Déroulement de la séance

### 3.1. Prise en main du matériel
Inventaire et vérification des composants et équipements nécessaires à la conception :  
- Composants de puissance (résistances chauffantes, MOSFETs, capteurs de température, etc.)  
- Matériel de prototypage (alimentation, multimètre, oscilloscope, fer à souder).  
- Consultation de la documentation technique associée.

### 3.2. Mise en place de l’environnement de travail
- Installation et configuration de **Autodesk Eagle** pour la conception du PCB.  
- Création du projet sur l’environnement local.  
- Organisation des bibliothèques de composants nécessaires.

### 3.3. Rédaction du CCTP
- Définition des besoins fonctionnels et contraintes techniques.  
- Spécification des tensions, courants et puissances attendus.  
- Description des interfaces capteurs/actionneurs et de la partie commande.  

---

## 4. Bilan de la séance
Séance principalement dédiée à la préparation du projet.  
Les bases sont posées : environnement opérationnel, compréhension du matériel, et CCTP rédigé.  

Prochaine étape : commencer la **conception du schéma électronique** et valider le dimensionnement thermique.

---

## 5. Annexes
- Logiciel utilisé : *Autodesk Eagle*  
- Documents produits : *CCTP - Toit chauffant pour ruche d’abeilles*  
# Compte rendu : Séance 2  
**Projet :** Toit chauffant pour ruche d’abeilles  
**Objectif général :** Éliminer le parasite *Varroa destructor* par chauffage contrôlé de la ruche.  

---

## 1. Objectifs de la séance
- Réaliser un schéma électrique complet du toit chauffant.  
- Commencer la réorganisation et la rénovation du câblage du système.  

---

## 2. Déroulement de la séance

### 2.1. Réalisation du plan électrique
Un plan électrique complet du toit a été dressé. Il inclut :
- Le câblage des **ventilateurs** vers la carte principale.  
- Le raccordement des **résistances de chauffe**.  
- Le branchement des **capteurs de température**.  

L’ensemble du système électrique du toit a été **divisé en deux ailes indépendantes**, afin de permettre un pilotage autonome.  
Chaque aile est contrôlée par un cœur du **microcontrôleur ESP32** (double cœur) :
- **Cœur 1 :** pilotage de la première aile (résistances, capteurs, ventilateurs).  
- **Cœur 2 :** pilotage de la seconde aile.  

Cette architecture garantit une gestion simultanée et équilibrée des deux zones du toit.

---

### 2.2. Début de la modification du câblage
Avec l’aide de **Léandro**, la séance a également été consacrée à la **modification du câblage existant**.  
Deux objectifs principaux :
1. **Rendre le câblage plus propre et organisé.**  
2. **Faire sortir les câbles par le dessus du toit** pour un accès plus pratique.  

Le toit se compose de deux compartiments superposés :
- **Compartiment inférieur :** résistances de chauffe, ventilateurs et capteurs.  
- **Compartiment supérieur :** carte de commande à base d’ESP32.  

Le travail a consisté à revoir le passage des câbles entre ces deux niveaux pour améliorer la maintenance et la fiabilité du système.

---

## 3. Bilan de la séance
Les bases de la structure électrique sont maintenant bien établies.  
Le plan global du toit est cohérent et intègre la séparation des ailes.  
La rénovation du câblage est en bonne voie, même si elle reste à finaliser.

---

## 4. Prochaine séance
- Finaliser et mettre **au propre le plan électrique**.  
- Poursuivre la **rénovation complète du câblage** du toit.  

---

## 5. Annexes
- Composant central : *ESP32 double cœur*  
- Collaboration : *Travail effectué avec Léandro*  
- Documents produits : *Plan électrique du toit chauffant*  
# Compte rendu : Séance 3  
**Projet :** Toit chauffant pour ruche d’abeilles  
**Objectif général :** Éliminer le parasite *Varroa destructor* par chauffage contrôlé de la ruche.

---

## 1. Objectifs de la séance
- Poursuivre les travaux de câblage et d’assemblage du toit chauffant.  
- Former Léandro aux techniques de soudure.  
- Finaliser la rédaction du CCTP.  

---

## 2. Déroulement de la séance

### 2.1. Assistance à la soudure
J’ai accompagné **Léandro** dans l’apprentissage de la **soudure**.  
Nous avons finalisé la **ligne des capteurs** d’une des deux ailes du toit.  
Cette étape a permis de consolider le câblage et de garantir la fiabilité des connexions entre les capteurs et la carte principale.

### 2.2. Reprise du câblage des résistances de chauffe
J’ai ensuite procédé au **recâblage complet des résistances de chauffe**.  
Les fils ont été **allongés** afin d’améliorer leur passage et de faciliter le futur montage dans la structure du toit.  
Cette modification permettra un câblage plus propre et mieux organisé lors de l’intégration finale.

### 2.3. Finalisation du CCTP
Le **Cahier des Clauses Techniques Particulières (CCTP)** a été **finalisé** au cours de cette séance.  
Il décrit désormais de manière exhaustive :
- Les spécifications techniques de l’installation.  
- Les contraintes électriques et mécaniques.  
- Les éléments de commande et de sécurité.  

---

## 3. Bilan de la séance
Les soudures de capteurs sont terminées, le câblage des résistances est corrigé, et le CCTP est finalisé.  
Le projet avance de manière structurée, avec un ensemble désormais plus clair et mieux organisé.

---

## 4. Prochaine séance
- Mettre **au propre le plan électrique**.  
- **Percer le haut du toit** afin d’y installer la carte électronique.  
- Réaliser le **câblage final propre et fonctionnel** du système.  

---

## 5. Annexes
- Collaboration : *Travail effectué avec Léandro*  
- Documents produits : *CCTP finalisé - Toit chauffant pour ruche d’abeilles*  
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

# 🧾 Rapport journalier – Séance 5

**Date :** 27 Novembre 2025  
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

# 🧾 Rapport journalier – Séance 7

**Date :** 11 novembre 2025  
**Nom :** Roth  
**Projet :** Développement ESP32 – Remise en état carte & tests maquette

---

## 🛠️ Tâches réalisées

### 1. Remplacement des composants défectueux
- Remplacement des **transistors cramés** sur la carte.  
- Ajout des **diodes de roue libre** qui manquaient et qui avaient provoqué les pannes précédentes.  
- Les soudures ont été vérifiées et corrigées avant de reprendre les tests.

### 2. Réparation d’un problème de pad arraché
- Lors de la réparation, le **fil rouge de CR1** a causé un problème : le **pad s’est arraché** à cause d’une mauvaise soudure.  
- Pour corriger cela, le fil a été **directement soudé sur une borne du transistor Q3**, ce qui a permis de rétablir la connexion sans refaire la carte.

### 3. Tests du côté gauche de la maquette
- Contrôle complet des **transistors pour la régulation des ventilateurs** : tests concluants.  
- Une fois les problèmes de carte réglés, nous avons testé le **code pour la partie gauche** de la maquette.  
- Les résultats ont été **entièrement satisfaisants**, ce qui nous permet de **mettre de côté** cette partie et de la considérer comme fonctionnelle.

---

## 🔧 Début des tests côté droit
### Ventilateurs
- Tests réalisés sur les ventilateurs du **côté droit** de la maquette.  
- Fonctionnement **du premier coup**, aucune anomalie détectée.

### Capteurs de température
- Suspicion d’un **faux contact** sur les capteurs de température côté droit.  
- Les valeurs ne remontent pas correctement — diagnostic à approfondir lors de la prochaine séance.

### Résistances
- Les **résistances du côté droit** n’ont pas encore été testées.  
- Elles seront vérifiées lors de la prochaine session en même temps que les capteurs.

---

## ⚙️ Préparation pour la prochaine séance
- Vérifier l’origine du **faux contact** sur les capteurs de température côté droit.  
- Tester les **résistances** du même côté.  
- Finaliser la validation complète de la partie droite de la maquette.

---

## ✅ Bilan
- Les réparations matérielles sur la carte ont été **réussies**.  
- La **partie gauche** de la maquette est maintenant **entièrement fonctionnelle**.  
- Début prometteur pour la **partie droite**, avec seulement un souci mineur à régler.

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

# 🧾 Rapport journalier – Séance 10

**Date :** 03 février 2026   
**Projet :** Développement ESP32 – Intégration écran & interface utilisateur  

---

## 🛠️ Contexte
- La **carte principale** est actuellement utilisée par **Sean** pour régler les problèmes **physiques de régulation sur le côté gauche** de la maquette.  
- Afin de ne pas rester inactifs pendant cette phase, une **tâche annexe** a été mise en place.

---

## 🛠️ Tâches réalisées

### 1. Intégration de l’écran
- Avec **Léandro**, nous avons travaillé sur l’**intégration d’un écran** afin d’obtenir un **retour d’information direct** sur la maquette (sans passer uniquement par la page web).  
- Objectif : préparer une **interface locale** pour l’utilisateur.

### 2. Travaux matériels
- Réalisation de la **soudure des pins** de l’écran.  
- **Connexion de l’écran à l’ESP32**.  
- Vérification de la continuité électrique et de la bonne alimentation de l’écran.

---

## ⚙️ Préparation pour la prochaine séance
- Développement du **code de l’interface utilisateur** sur l’écran.  
- Mise en place de la **communication entre l’écran et le code principal de l’ESP32**.  
- Synchronisation des informations (température, consigne, état du système, etc.).

---

## ✅ Bilan
- L’**écran est physiquement intégré** et connecté à l’ESP32.  
- Le matériel est prêt pour la phase logicielle.  
- Prochaine étape : rendre l’écran **fonctionnel et interactif**.

# 🧾 Rapport journalier – Séance 11

**Date :** 17 février 2026  
**Nom :** *(à compléter)*  
**Projet :** Développement ESP32 – Intégration écran & amélioration maquette  

---

## 🛠️ Tâches réalisées

### 1. Tests de l’écran
- Poursuite des **tests d’intégration de l’écran**.  
- Les essais n’ont pas été **concluants**, avec des problèmes persistants de fonctionnement/communication.  
- L’écran n’est pas encore opérationnel dans le système actuel.

### 2. Amélioration mécanique de la maquette
- Ajout de **charnières** sur la maquette.  
- Objectif : améliorer l’**accessibilité** aux composants internes et faciliter la maintenance, le câblage et le débogage.

### 3. Débogage de la carte
- Reprise du **débogage de la carte électronique**.  
- Analyse des problèmes matériels et/ou logiques encore présents.  
- Vérification des connexions, des composants critiques et du comportement global du système.

---

## ⚙️ Préparation pour la prochaine séance
- Continuer les **tests et le diagnostic de l’écran**.  
- Identifier précisément l’origine des problèmes (alimentation, communication, librairies, câblage).  
- Poursuivre le **débogage de la carte**.  
- Reprendre l’intégration logicielle une fois la partie matérielle stabilisée.

---

## ✅ Bilan
- Les tests de l’écran sont en cours mais **non fonctionnels** à ce stade.  
- La maquette est désormais **mécaniquement améliorée** grâce aux charnières.  
- Le travail de **débogage** progresse en parallèle pour fiabiliser le système.

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

# 🧾 Rapport journalier – Séance 17

**Date :** 10 avril 2026  
**Projet :** Développement ESP32 – Finalisation maquette & amélioration logiciel  

---

## 🛠️ Tâches réalisées

### 1. Finalisation de la maquette
- Travail avec **Sean** pour finaliser la partie mécanique de la maquette.  
- Fixation du **cadran en bois** sur la boîte.  
- Ajout de **fines planches en bois** pour créer un **cache-câbles** :
  - Permet d’éviter que les câbles gênent lors de la fermeture.  
- Réalisation d’un **trou dans le cadran** pour faire passer les **câbles d’alimentation**.  
- Soudure du **capteur de température interne** permettant de mesurer la température à l’intérieur de la ruche.

### 2. Tests globaux
- Réalisation d’un **test complet de toute la maquette**.  
- Résultat : fonctionnement global **plutôt concluant**.

### 3. Amélioration du code
- Ajout d’une **sauvegarde de la consigne dans l’EEPROM**.  
- Objectif :
  - Éviter la perte de la consigne lors des **crashs ou resets de l’ESP32**.  
- Amélioration de la **robustesse du système**.

---

## ⚙️ Préparation pour la prochaine séance
- Développement d’un **script Python** pour :
  - Tracer les **courbes de chauffe de la ruche**.  
  - Analyser les performances du système de régulation.  

---

## ✅ Bilan
- La maquette est désormais **finalisée mécaniquement**.  
- Le système fonctionne de manière **globale et cohérente**.  
- Le code est plus **fiable** grâce à la sauvegarde en EEPROM.  
- Prochaine étape : **analyse des données et optimisation**.

