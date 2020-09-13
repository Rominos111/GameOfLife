# GameOfLife
Jeu de la vie "smart" en C

<sub>"Smart" = économise de la RAM (1 byte par cellule) et le CPU (liste des cellules actives).</sub>

<sub>1000*1000 avec 1000 actives : environ 1 Mo en RAM et environ 1% des cellules mises à jour par update.</sub>

### Fonctionnement 

Chaque simulation contient un tableau 2D d'entiers 8-bits.
Chaque case est composée suivant ce pattern binaire :

[a b t ø n n n n], avec :
*    a : active ou non au tour précédent
*    b : active ou non à ce tour
*    t : dernier tour touché, 0 ou 1, si différent de ce tour alors le nombre de voisins de la cellule doit être reset et non pas incrémenté
*    n n n n : nombre de voisins, entre 0 et 8

La simulation contient aussi une liste des cellules actives en ce moment, afin de ne pas avoir à chercher les cellules actives parmi la grille et d'économiser des accès mémoires.
Cette liste ne contient qu'un pointeur sur la case dans la grille.

Enfin, la simulation comporte une liste des cellules inactives qui ont le potentiel de devenir active,
afin de ne pas avoir à parcourir toute la grille pour retrouver les nouvelles cellules.
