# Rapport de Séance Personnelle - Abdoulaye
## Date : 5 mars 2026

## Contexte
Séance partagée entre résolution de problèmes matériels et tests logiciels sur simulateur.

## Travail Réalisé

### Diagnostics et Corrections Matérielles
Nous avons identifié une **chute de tension** qui empêchait les résistances chauffantes d'atteindre la température souhaitée. Après analyse, nous avons décidé de remplacer les condensateurs de 10µF par des modèles de **40µF** pour stabiliser l'alimentation.

Par ailleurs, l'un des capteurs de température présentait un dysfonctionnement. Nous l'avons également **remplacé** pour garantir la fiabilité des futures mesures.

### Tests sur Wokwi
En parallèle, j'ai commencé à explorer le simulateur **Wokwi** pour tester le code dual-core en attendant que la carte soit pleinement opérationnelle. J'ai :
- Configuré un projet ESP32 avec 6 capteurs DS18B20 virtuels
- Implémenté le code de gestion dual-core
- Observé les premières réactions du système simulé

Bien que la simulation ne soit pas encore parfaitement au point, cette première prise en main est prometteuse.

## Problèmes Rencontrés
- **Chute de tension** résolue par changement de condensateurs
- **Capteur défaillant** identifié et remplacé
- **Circuit sur Wokwi** encore problématique 

## Acquis de la Séance
- Diagnostic de problèmes d'alimentation (condensateurs)
- Remplacement de composants défaillants
- Utilisation de Wokwi pour simulation ESP32
- Compréhension de l'intérêt des simulateurs en phase de développement

## Prochaines Étapes
1. Finaliser la configuration Wokwi pour visualiser correctement le circuit
2. Tester exhaustivement le code dual-core en simulation
3. Reprendre les tests matériels dès que la carte sera stabilisée

## Bilan Personnel
Séance productive malgré les aléas techniques. La résolution des problèmes matériels (condensateurs, capteur) était indispensable pour la suite. Parallèlement, l'utilisation de Wokwi ouvre une nouvelle voie pour valider le code indépendamment du matériel. Une approche à développer davantage.

---

*Abdoulaye Baldé*
