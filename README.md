# JonSpaceInvader
https://github.com/user-attachments/assets/8a730bfe-fbd3-4a81-93fb-b3c91ee15364

JonSpaceInvader est un jeu 2D de type Space Invader écrit en C++ en utilisant la bibliothèque [SFML (Simple and Fast Multimedia Library)](https://www.sfml-dev.org/) pour la gestion des graphismes et des événements. Le jeu comprend des ennemis qui se déplacent et peuvent être touchés par des balles. Il est compilé en utilisant C++17 et comporte plusieurs classes, avec `Enemy` et `Bullet` comme composants principaux.

## Fonctionnalités

- **Gestion des graphismes** : Utilisation de SFML pour dessiner les sprites et gérer les textures.
- **Mouvement et animation** : Les ennemis se déplacent et sont animés au fil du temps.
- **Détection des collisions** : Les balles peuvent toucher et détruire les ennemis.
- **Gestion des événements** : Utilisation de SFML pour gérer les événements de la fenêtre.

## Classes

### 1. Enemy (Ennemi)

Représente les ennemis dans le jeu.

- **Attributs** :
  - `directionX`, `directionY` : Booléens indiquant la direction de déplacement de l'ennemi.
  - `direction` : Direction actuelle de l'ennemi.
  - `x`, `y` : Position actuelle de l'ennemi.
  - `sprite` : Sprite SFML représentant l'ennemi.
  - `timeranimation`, `move_timer` : Timers pour gérer l'animation et le mouvement.
  - `death` : Booléen indiquant si l'ennemi est mort.
  - `isFrame1` : Booléen pour gérer les frames d'animation.
  - `texture1`, `texture2` : Textures SFML utilisées pour l'ennemi.

- **Méthodes** :
  - `Enemy(sf::Texture& texture, sf::Texture& texture2, short p_x, short p_y)` : Constructeur.
  - `void draw(sf::RenderWindow& window)` : Dessine l'ennemi dans la fenêtre.
  - `void move(short p_X, short p_Y)` : Déplace l'ennemi.
  - `void moveDown()` : Déplace l'ennemi vers le bas.
  - `bool checkHit(Bullet& p_bullet)` : Vérifie si l'ennemi est touché par une balle.
  - `bool getDeath()` : Retourne l'état de mort de l'ennemi.
  - `short getY()` : Retourne la position Y de l'ennemi.
  - `short getX()` : Retourne la position X de l'ennemi.

### 2. Bullet (Balle)

Représente les balles dans le jeu.

- **Attributs** :
  - `death` : Booléen indiquant si la balle est inactive.
  - `_x`, `_y` : Position flottante de la balle.
  - `step_x`, `step_y` : Pas de déplacement de la balle.
  - `x`, `y` : Position entière de la balle.
  - `old_x`, `old_y` : Vecteurs stockant les anciennes positions de la balle.

- **Méthodes** :
  - `Bullet(float p_step_x, float p_step_y, short p_x, short p_y)` : Constructeur.
  - `void update()` : Met à jour la position de la balle.

## Conclusion

Ce programme constitue une base pour un jeu ou une simulation dans laquelle des ennemis se déplacent et peuvent être détruits par des balles. Il utilise SFML pour la gestion des graphismes et des événements, et est structuré à l'aide de classes représentant les ennemis et les balles.

## Prérequis

- SFML (version utilisée : 2.5.1 ou plus récente)
- Compilateur supportant C++17

## Compilation et Exécution

1. Clonez le dépôt :
   ```bash
   git clone https://github.com/votre-utilisateur/JonSpaceInvader.git
   g++ -std=c++17 -o JonSpaceInvader main.cpp -lsfml-graphics -lsfml-window -lsfml-system
  ./JonSpaceInvader


