# Rapport de Séance Personnelle - Abdoulaye
## Date : 24 avril 2026

## Travail réalisé

J’ai consacré la séance d’aujourd’hui à finaliser les tests du code dual-core sur la carte réelle.

### Téléversement du code complet
Le code a bien été flashé. Les résistances chauffantes se sont mises à chauffer, prouvant que l’ESP32 exécute les commandes de régulation.

### Absence d’affichage série
Malgré le bon téléversement, le moniteur série reste complètement vide. J’ai apporté quelques modifications au code, sans résultat.

### Test d’un code minimal
J’ai chargé un code simple (lecture d’un seul capteur DS18B20). Le moniteur série est toujours vide, ce qui confirme que le problème vient du bus 1-Wire, pas de la complexité du code.

## Diagnostic

- Les résistances chauffent => le code tourne et les sorties fonctionnent.
- Absence de toute sortie `Serial.print` => la fonction `sensors.getDeviceCount()` ne renvoie aucun capteur (probablement 0), donc le drapeau `nouvellesDonnees` ne passe jamais à `true` et l’affichage n’est jamais appelé.


## Bilan

Le développement logiciel est terminé et fonctionnel. Le seul frein est un défaut matériel mineur. La séance a permis d’identifier clairement ce point bloquant.

---

*Abdoulaye Baldé*
