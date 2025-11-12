# Rapport de Séance - Abdoulaye
## Date : 11/11/2025

## Objectifs de la Séance
Cette séance avait pour but de tester les capteurs de température afin d'établir la correspondance entre les index logiciels et les positions physiques, de comprendre le fonctionnement dual-core de l'ESP32, et de valider le bon fonctionnement des trois capteurs du côté A de la maquette.

## Déroulement de la Séance
La séance a débuté par une étude théorique sur l'architecture dual-core de l'ESP32 pendant que le matériel était utilisé par l'autre binôme pour des travaux de perçage et de soudure. J'ai profité de ce temps pour me familiariser avec la gestion des tâches parallèles et les mécanismes de synchronisation entre les deux cœurs du processeur.

Lorsque nous avons enfin pu accéder à la maquette, nous avons malheureusement découvert un court-circuit sur la carte. Nous avons immédiatement entrepris un diagnostic en vérifiant les connexions et en utilisant le multimètre pour identifier les pistes endommagées.

Malgré ce problème technique, j'ai pu réaliser des tests sur les trois capteurs du côté A. Ces tests ont confirmé le bon fonctionnement des capteurs DS18B20, avec des lectures de température cohérentes affichées dans le moniteur série.

## Bilan des Résultats
Les tests des capteurs côté A se sont avérés concluants, ce qui représente un point positif important. Cependant, le court-circuit détecté sur la carte nous a empêchés de procéder aux tests de la gestion dual-core et a retardé l'avancement global du projet.

Cette situation m'a néanmoins permis d'acquérir une expérience précieuse dans le diagnostic de pannes électroniques et de renforcer mes compétences en travail d'équipe face à des contraintes techniques imprévues.

## Perspectives
La priorité pour la prochaine séance sera de résoudre définitivement le problème de court-circuit. Une fois cette étape franchie, nous pourrons procéder aux tests complets des six capteurs et implémenter la solution dual-core que j'ai préparée.

Cette expérience m'a confirmé l'importance de la flexibilité et de l'adaptation dans la conduite de projets techniques.

---

*Abdoulaye Baldé*
