# Pathfinder

## Pré requis d'installation 

### Avoir VCPKG dans le path

Pour installer [vcpkg](https://vcpkg.io/en/getting-started.html), suivez l'étape **Install vcpkg** sur le lien précédent correspondante à votre système d'exploitation (vous pouvez changer via une liste sur la gauche).

Vous devez également ajouter la variable d'environnement *VCPKG_ROOT* avec pour valeur *le chemin vers votre dossier vcpkg* (le chemin doit être fait avec des / et non des \) .

### OU BIEN Modification CMakePreset.json

Vous pouvez, **AU LIEU** de faire l'étape précédente ou en cas de problème avec l'étape précédente, modifier la ligne 12 du fichier CMakePreset.json.

Pour la modification vous devez remplacer `$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake` par le chemin absolu menant au vcpkg.cmake


## UML

Vous pouvez retrouver sur ce [lien](https://drive.google.com/file/d/1n2fPojlz1dlJhTK4wzJhoQgyHpE-c5P_/view?usp=sharing) le schéma UML en lecture seule, pour une meilleure visibilité vous devrez ouvrir le diagramme sur diagrams.net. 
