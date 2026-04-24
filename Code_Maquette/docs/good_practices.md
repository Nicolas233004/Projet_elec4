# 📚 Politique Git d'Équipe – Feature Branching

## 🔧 Objectif

Ce document définit les bonnes pratiques de gestion de code chez Osmose, en suivant le modèle **Feature Branching**. Il vise à garantir la qualité, la traçabilité et la stabilité du code dans un environnement collaboratif.


## 🔄 Workflow Git

### 1. 🌳 Branche principale

- La branche `master` ou  `main` représente la version **stable** du projet.
- Elle ne doit **jamais être modifiée directement**. Toutes les modifications doivent passer par des **Pull Requests**.

### 2.🌿 Création d'une branche de travail

- Chaque nouvelle fonctionnalité, correction ou amélioration doit être développée dans une branche dédiée.
- Elle est créée à partir de `main` :

```bash
git checkout main
git pull origin main
git checkout -b feature/nom-clair
```

### 3. 🌱 Convention de nommage des branches

| Préfixe       | Usage                                      | Exemple                            |
|---------------|--------------------------------------------|------------------------------------|
| `feature/`    | Nouvelle fonctionnalité                    | `feature/presence_detection`       |
| `bugfix/`     | Correction de bug                          | `bugfix/DS18B20_surchauffe`        |
| `hotfix/`     | Correction urgente en production           | `hotfix/crash_on_startup`          |
| `refactor/`   | Nettoyage ou amélioration technique        | `refactor/reformat_cta_code`       |

![Git branching & merging](https://git-scm.com/book/fr/v2/images/basic-rebase-1.png)
### 📥 4. Commits

Un message de commit court et explicite, au présent, en français ou en anglais (selon la base de code). ✅

| Type      | Description                                              | Exemple                        |
|-----------|----------------------------------------------------------|--------------------------------|
| `new`     | Nouvelle fonctionnalité                                  | new presence detection system  |
| `fix`     | Correction de bug                                        | fix issu 1801 on DS18B20 sensor|
| `refactor`| Amélioration technique sans ajout de fonctionnalité      | refactor CTA code              |
| `docs`    | Modification de la documentation                         | docs modbus table              |
| `test`    | Ajout ou modification de tests                           | test EEPROM load               |
| `misc`   | Tâches annexes (build, config, nettoyage, etc.)          | misc install libToto          |

### 5. ♻️ [Rebase](https://git-scm.com/book/fr/v2/Les-branches-avec-Git-Rebaser-Rebasing) régulier sur main

Pendant le développement, synchronisez régulièrement votre branche :

```sh
git checkout feature/xxx
git rebase master
```

![Git rebase](https://git-scm.com/book/fr/v2/images/basic-rebase-3.png)
### 6. 🔃 Pull Request

Créez une PR vers main une fois le développement terminé. Ajoutez une description claire (ce qui a été fait, pourquoi, comment tester). Demandez une revue à au moins 1 développeur.

### 7. 🔀 Merge et suppression
Après validation : squash & merge.

Supprimez ensuite la branche distante :
```sh
git checkout master
git merge feature/xxx
git push origin --delete feature/xxx
```
![Git merge](https://git-scm.com/book/fr/v2/images/basic-rebase-4.png)
### ✅ Récapitulatif rapide

1.  Étape	Commande / Convention
2. Créer branche	`git checkout -b feature/xxx`
3. Nom branche	feature/, bugfix/, refactor/
4. Convention commit (new, fix, refactor, docs, test) + decription courte et claire
5. Rebase régulier sur main	`git pull origin main --rebase`
6. PR	Vers main, avec description claire
7. Squash & Merge, puis suppression de branche

## 📦 Suivis des dépendances
Grâce à son fichier platformio.ini, platformio permet de garder la liste des dépendances utilisées ainsi que leurs version dans la variable [`lib_deps`](https://docs.platformio.org/en/latest/projectconf/sections/env/options/library/lib_deps.html#lib-deps). Cela permet aux nouveaux arrivant d'installer leur environnement de travail rapidement et de maitriser parfaitement les dépendances utilisées.

```ini
lib_deps = 
	controllino-plc/CONTROLLINO@^3.0.10
	paulstoffregen/OneWire@^2.3.8
	milesburton/DallasTemperature@^4.0.4
	br3ttb/PID@^1.2.1
	4dsystems/genieArduino@^1.5.3
```

## ⚙️ Option de compilation
### 🎯 Quel est le but des build flags ?
Les build flags (ou drapeaux de compilation) servent à contrôler la façon dont le code est compilé et construit. Ils sont utilisés dans les systèmes de compilation pour plusieurs raisons.

### 🔧 1. Contrôler le comportement de la compilation
Ils permettent de spécifier comment le compilateur doit traiter le code :

Niveaux d’optimisation (ex : -O2, -O3 pour la vitesse, -Os pour la taille). Ajout d’informations de débogage (-g). Activation des avertissements (-Wall, -Werror, etc.)

### 🧩 2. Activer ou désactiver des fonctionnalités
Grâce à la compilation conditionnelle, certaines parties du code peuvent être incluses ou exclues selon les flags définis :
```c
#ifdef DEBUG
    printf("Infos de debug\n");
#endif
```

On active le flag DEBUG comme ceci :
```sh
gcc -DDEBUG main.c -o app
```

### 🛠️ 3. Cibler différentes plateformes ou architectures
Ils permettent de compiler pour des systèmes ou processeurs spécifiques. Activer des instructions spécifiques au matériel (ex : SSE, NEON). Choisir l’architecture (-m64 pour 64 bits, -m32 pour 32 bits)

### 🧪 4. Contrôler l’édition des liens (linking)
Les flags servent aussi à lier des bibliothèques spécifiques (-lm, -lpthread, etc.).Indiquer où chercher les bibliothèques (-L/path/to/lib). Choisir le type de lien : statique (-static) ou dynamique (-shared)

### 🧱 5. Gérer différentes configurations de build
Ils permettent de différencier Debug vs Release, Versions internes vs versions publiques, fonctionnalités expérimentales vs stables ou même de compiler des produits différents mais qui utilisent des codes communs.

### Exemple avec platformio.ini
```ini
build_flags = -DCLIMATIC_KIT

[env:debug]
build_flags = ${env.build_flags} -DDEBUG -Og

[env:release]
build_flags = ${env.build_flags} -Os
```

### 6. Injecter des informations dynamiquement
### Exemple
platformio.ini
```ini
extra_scripts = pre:version.py
```
version.py
```py
env.Append(
    CPPDEFINES=[
        ("COMMIT_ID", f'\\"{get_git_commit_id()}\\"')
    ]
)
```
In main.cpp:
```arduino
Serial.println(COMMIT_ID);
```
## 🧪 Tests unitaires
Les tests unitaires sont des tests automatisés qui vérifient le bon fonctionnement de petites unités de code, généralement des fonctions ou des méthodes. Leur objectif est de s'assurer que chaque composant se comporte comme attendu, indépendamment du reste de l'application. Ils jouent un rôle clé dans la détection rapide des erreurs, facilitent les refactorings, et contribuent à maintenir un code fiable et robuste au fil du temps. Intégrés dans le workflow de développement, ils permettent une validation continue du code à chaque modification.