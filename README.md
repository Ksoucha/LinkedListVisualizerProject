# LinkedListVisualizerProject

### **Objectif**

Ce travail pratique vise à renforcer la compréhension des **listes chaînées, de l'allocation dynamique de mémoire, des classes en C++ et de l'animation dans OpenFrameworks**. Les étudiants devront créer une visualisation interactive d'une **liste chaînée** où les nœuds sont représentés visuellement et animés.

---
Vous devez créer une **visualisation d'une liste chaînée** dans OpenFrameworks où :

1. Chaque nœud est représenté par un **cercle (ou un carré)** connecté au suivant par une **ligne**.
2. Chaque nœud **affiche un nombre**, qui détermine également la **taille de la forme** (par exemple, le rayon du cercle).
3. La liste chaînée commence avec seulement un **nœud de tête**.
4. L'utilisateur peut **modifier dynamiquement la liste chaînée** :
    - Appuyer sur **'q'** pour insérer un nœud **au début**.
    - Appuyer sur **'w'** pour insérer un nœud **à la fin**.
    - Appuyer sur **'a'** pour supprimer le **nœud en tête**.
    - Appuyer sur **'s'** pour supprimer le **nœud en queue**.
    - Appuyer sur **'e'** pour trier la liste chaînée en ordre croissant (**fonctionnalité bonus**).
    - Chaque nouveau nœud doit avoir une **valeur aléatoire**.
5. Les nœuds doivent avoir une **animation oscillante**, leur donnant un effet de **mouvement en ondulation**.
6. L'utilisateur peut **ajuster les propriétés d'animation** :
    - Appuyer sur **'z'** pour **augmenter** l'amplitude de l'oscillation.
    - Appuyer sur **'x'** pour **diminuer** l'amplitude de l'oscillation.
7. L'utilisateur peut **déplacer la caméra** :
    - Appuyer sur **la flèche gauche** pour faire défiler la vue **vers la gauche**.
    - Appuyer sur **la flèche droite** pour faire défiler la vue **vers la droite**.

---
Critères d'évaluation :

1. **Structure de base de la liste chaînée (2 Points)**
    - Implémenter une classe `Node` avec :
        - `data` (un entier généré aléatoirement).
        - Un pointeur `next` (pour une liste chaînée simple).
    - Implémenter une classe `LinkedList` avec :
        - `insertAtHead(int value)`, `insertAtTail(int value)`, `deleteHead()`, et `deleteTail()`.
2. **Représentation visuelle (2 Points)**
    - Les nœuds doivent être dessinés sous forme de **cercles (ou carrés)** dans OpenFrameworks.
    - Les nœuds doivent être connectés par des **lignes** pour représenter les liens.
    - Chaque nœud doit **afficher sa valeur** à l'intérieur de la forme.
3. **Interaction utilisateur (2 Points)**
    - Appuyer sur **'q'** ajoute un nœud **au début**.
    - Appuyer sur **'w'** ajoute un nœud **à la fin**.
    - Appuyer sur **'a'** supprime le **nœud en tête**.
    - Appuyer sur **'s'** supprime le **nœud en queue**.
    - Le nouveau nœud doit avoir une **valeur entière aléatoire** qui détermine sa **taille**.
4. **Animation et contrôles (2 Points)**
    - Les nœuds doivent **osciller en douceur**, produisant un **effet d'ondulation**.
    - L'animation ne doit pas briser la structure de la liste chaînée.
    - Appuyer sur **'z'** augmente l'amplitude de l'oscillation.
    - Appuyer sur **'x'** diminue l'amplitude de l'oscillation.
    - Appuyer sur **la flèche gauche** fait défiler la vue vers la **gauche**.
    - Appuyer sur **la flèche droite** fait défiler la vue vers la **droite**.
5. **Soumission via GitHub (2 Points)**
    - Créer un dépôt GitHub public nommé `LinkedListVisualizer`.
    - Pousser tous les fichiers du projet.
    - Inclure un fichier `README.md` avec :
        - Une brève description du projet.
        - Instructions pour exécuter le projet.
        - Liste des touches de contrôle.
6. **Fonctionnalité bonus (1 Point)**
    - Appuyer sur **'e'** trie les nœuds de la liste chaînée en ordre croissant.

---
### **Touches de contrôle**

- **'q'** : Insérer un nœud au **début** de la liste chaînée.
- **'w'** : Insérer un nœud à la **fin** de la liste chaînée.
- **'a'** : Supprimer le **nœud en tête**.
- **'s'** : Supprimer le **nœud en queue**.
- **'e'** : Trier la liste chaînée (**fonctionnalité bonus**).
- **'z'** : Augmenter l'amplitude de l'oscillation.
- **'x'** : Diminuer l'amplitude de l'oscillation.
- **Flèche gauche** : Déplacer la vue **vers la gauche**.
- **Flèche droite** : Déplacer la vue **vers la droite**.