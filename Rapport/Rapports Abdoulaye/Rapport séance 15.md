# Rapport de Séance Personnelle - Abdoulaye
## Date : 10 avril 2026

## Contexte
Séance consacrée à la phase finale de tests, le matériel étant enfin opérationnel après les réparations (court-circuit, condensateurs, capteur défaillant). L’objectif était de valider le code dual-core sur la carte réelle.

## Travail réalisé

### soudage et préparation
J’ai participé au soudage des capteurs sur la carte, en veillant à la qualité des connexions (pas de faux contacts). Cette étape était indispensable pour garantir des mesures fiables.

### Tentative sur Wokwi
Avant de passer au matériel, j’ai relancé une simulation sur Wokwi avec le code complet. Le moniteur série est resté vide, ce qui m’a conforté dans l’idée de tester directement sur la carte réelle, désormais réparée.

### Test sur le matériel
J’ai compilé le code sur l’ESP32. La compilation a été anormalement longue (plusieurs minutes). Les voyants de la carte s’allumaient, mais je n’ai pas eu le temps d’observer le comportement des actionneurs (résistances, ventilateurs). La séance s’est achevée avant que je puisse lancer un cycle complet de régulation.

## Difficultés rencontrées
- **Compilation lente** : sans doute due à la taille du code ou à un paramètre de l’IDE. À vérifier.
- **Doute sur le board** 
- **Moniteur série Wokwi** : toujours bloqué, mais secondaire maintenant que le matériel fonctionne.

## Bilan et perspectives
Le code est prêt, le matériel est réparé, mais les tests restent encore à finaliser. La priorité pour la prochaine séance sera de :
1. Vérifier le type de board et accélérer la compilation.
2. Lancer un test simple.
3. Activer ensuite la régulation dual-core complète.


---

*Abdoulaye Baldé*
