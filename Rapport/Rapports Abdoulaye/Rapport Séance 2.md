# Rapport de Séance - Tests des Actionneurs et Capteurs

## Tests des Résistances Chauffantes

Lors de cette séance, nous avons procédé au test des résistances chauffantes qui joueront un rôle crucial dans la régulation thermique de la ruche. Pour vérifier leur bon fonctionnement, nous avons utilisé un générateur délivrant une tension de 30V, conformément aux spécifications du système.

La mesure de la tension aux bornes des résistances à l'aide d'un voltmètre nous a permis de confirmer que l'alimentation électrique était correctement établie et que les résistances étaient prêtes à assurer leur fonction de chauffage.

## 🔌 Validation du Convertisseur de Tension

Le système nécessitant une alimentation différenciée entre les actionneurs, nous avons testé le convertisseur 30V/12V destiné à alimenter les ventilateurs. Après avoir appliqué les 30V en entrée du convertisseur, nous avons mesuré la tension de sortie avec précision.

Les mesures au voltmètre ont confirmé une sortie stable à 12V, validant ainsi le bon fonctionnement de ce composant essentiel à l'architecture électrique du projet.

## Tests des Ventilateurs

Avec le convertisseur validé, nous avons pu procéder au test des ventilateurs. Le branchement d'un ventilateur sur la sortie 12V du convertisseur a immédiatement montré son fonctionnement optimal.

Cette étape cruciale nous assure que les ventilateurs pourront effectivement assurer l'homogénéisation de la température dans les différents compartiments de la ruche, répartissant uniformément la chaleur générée par les résistances.

## Travail en Cours sur les Capteurs

Actuellement, je me consacre à la finalisation du système d'acquisition des données des capteurs de température. Mon travail consiste à récupérer systématiquement les index de chacun des six capteurs DS18B20 ainsi que leurs mesures de température respectives.

Cette cartographie précise est fondamentale pour le futur algorithme de régulation qui devra traiter les données de trois capteurs sur chaque côté de la ruche.

## Perspectives et Prochaines Étapes

Une fois la cartographie des capteurs finalisée, l'étape suivante consistera à intégrer l'ensemble des actionneurs - résistances chauffantes et ventilateurs - dans un système de contrôle unifié.

Le développement de l'algorithme de régulation thermique pourra alors commencer, visant à maintenir des conditions optimales pour la colonie d'abeilles tout en éliminant les parasites par contrôle thermique différenciel.

---

