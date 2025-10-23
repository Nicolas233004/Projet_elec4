# Compte Rendu de Séance 1 - Projet de Régulation Thermique pour Ruche

## Contexte et Objectifs de la Séance

À la suite de la présentation initiale du projet par notre professeur encadrant M. Peter, notre équipe de quatre étudiants s'est réunie pour approfondir la compréhension du système de régulation thermique destiné à protéger les ruches. L'objectif principal de cette séance était d'établir une feuille de route claire et de procéder aux premiers tests de la maquette existante, en nous appuyant sur les travaux antérieurs documentés dans le rapport de l'année précédente.

## Analyse des Ressources et Planification

Notre première tâche a consisté en une analyse minutieuse des ressources disponibles sur GitHub, qui nous a permis de saisir la complexité technique du projet. La documentation du groupe précédent a été particulièrement instructive, révélant à la fois les avancées significatives réalisées et les défis techniques rencontrés. Cette analyse rétrospective nous évite de répéter les mêmes erreurs et nous fournit une base solide pour notre propre développement.

La structuration de notre équipe en binômes spécialisés s'est avérée être une décision stratégique judicieuse. Tandis que Léandro et Sean se concentrent sur la conception matérielle et les aspects PCB, notre binôme (Nicolas et Abdoulaye) assume la responsabilité de la programmation de l'ESP32. Cette répartition des tâches nous permet d'optimiser notre efficacité en capitalisant sur les compétences spécifiques de chaque membre.

## Tests Fonctionnels et Identification des Problèmes

Notre première session de tests pratiques a révélé un problème matériel critique : une sensibilité excessive du câblage aux mouvements de la maquette. Cette fragilité se manifeste par des dysfonctionnements intermittents qui compromettent la fiabilité du système. La nécessité de manipuler le dispositif avec une extrême précaution constitue un obstacle significatif à des tests rigoureux et répétables.

L'analyse du code existant nous a permis d'identifier plusieurs axes d'amélioration, notamment dans l'implémentation du contrôle PID et l'exploitation du potentiel multicœur de l'ESP32. Le rapport précédent mentionnait des difficultés avec la régulation thermique et la gestion parallèle des deux côtés de la maquette, défis que nous devrons résoudre dans notre propre développement.

## Feuille de Route Détaillée

### Phase 1 : Tests Unitaires
Cette phase initiale consiste à valider individuellement chaque composant de la maquette. Nous testerons systématiquement les capteurs de température DS18B20, les résistances chauffantes THS50 et les ventilateurs, en documentant précisément leur comportement et leurs spécifications techniques.

### Phase 2 : Intégration Logicielle
Sur la base des tests unitaires, nous développerons un programme unifié qui coordonnera l'ensemble des fonctionnalités. Cette phase inclura l'implémentation d'un contrôleur PID robuste et l'exploitation des capacités multicœurs de l'ESP32 pour gérer simultanément les deux côtés de la maquette.

### Phase 3 : Interface Web
Nous concevrons une interface web intuitive permettant de monitorer et de contrôler le système à distance. Cette interface fournira une visualisation en temps réel des températures, l'historique des données et la possibilité d'ajuster les paramètres de régulation.

### Phase 4 : Validation et Optimisation
La phase finale consistera en des tests exhaustifs pour valider le bon fonctionnement de l'ensemble du système. Nous procéderons aux ajustements nécessaires et optimiserons les performances pour assurer une régulation thermique précise et fiable.

## Défis Techniques et Perspectives

Les principaux défis techniques identifiés incluent la stabilisation du câblage, l'optimisation des paramètres PID et la gestion efficace du parallélisme sur l'ESP32. La collaboration étroite avec l'équipe matérielle sera essentielle pour résoudre les problèmes d'instabilité physique de la maquette.

La perspective de contribuer à la protection des abeilles contre les parasites grâce à la régulation thermique constitue une motivation significative pour notre équipe. Nous sommes conscients de l'importance écologique de ce projet et nous nous engageons à fournir un travail de qualité qui réponde aux attentes scientifiques et techniques du projet.

## Prochaines Étapes

Notre prochaine séance sera consacrée au diagnostic approfondi du problème de câblage et au début des tests unitaires systématiques. Nous coordonnerons également nos efforts avec les autres membres de l'équipe pour assurer une intégration harmonieuse entre les aspects matériels et logiciels du projet.

---

**Équipe projet :**
- Léandro & Sean : Conception carte électronique et PCB
- Nicolas & Abdoulaye : Programmation ESP32

