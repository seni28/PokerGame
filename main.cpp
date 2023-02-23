#include <iostream>
#include "algorithm"
#include "Card.h"

Card c1 = Card(0, 0);
Card c2 = Card(0, 0);
Card c3 = Card(0, 0);
Card c4 = Card(0, 0);
Card c5 = Card(0, 0);

Card tab[5] = {c1, c2, c3, c4, c5};

bool paire = false;
bool doublepaire = false;
bool brelan = false;
bool suite = false;
bool couleur = false;
bool full = false;
bool carre = false;
bool quinteflush = false;
bool quinteflushroyale = false;
bool cartehaute = false;
bool ERROR = false;


// Cette fonction crée une main de 5 cartes qui contiens l'une des 9 mains
void jeuxessai(const std::string& arg){


    if ((arg == "Paire") or(arg=="paire") ) {

        c1 = Card(11, 1);
        c2 = Card(9, 1);
        c3 = Card(3, 2);
        c4 = Card(2, 1);
        c5 = Card(11, 2);
    }

    if (arg == "Double paire") {

        c1 = Card(13, 1);
        c2 = Card(13, 2);
        c3 = Card(6, 3);
        c4 = Card(4, 4);
        c5 = Card(6, 2);
    }

    if ((arg == "Brelan")or(arg=="brelan")) {

        c1 = Card(1, 1);
        c2 = Card(9, 1);
        c3 = Card(10, 4);
        c4 = Card(1, 3);
        c5 = Card(1, 2);
    }

    if ((arg == "Suite")or(arg=="suite")) {

        c1 = Card(11, 1);
        c2 = Card(9, 3);
        c3 = Card(13, 2);
        c4 = Card(12, 4);
        c5 = Card(10, 1);
    }

    if ((arg == "Couleur")or(arg=="couleur")) {

        c1 = Card(4, 1);
        c2 = Card(5, 1);
        c3 = Card(7, 1);
        c4 = Card(13, 1);
        c5 = Card(2, 1);
    }

    if ((arg == "Full") or(arg=="full")){

        c1 = Card(13, 1);
        c2 = Card(13, 2);
        c3 = Card(14, 3);
        c4 = Card(13, 4);
        c5 = Card(14, 2);
    }

    if ((arg == "Carre") or(arg=="carre")) {

        c1 = Card(11, 1);
        c2 = Card(9, 1);
        c3 = Card(11, 4);
        c4 = Card(11, 3);
        c5 = Card(11, 2);
    }

    if ((arg == "Quinte_flush")or(arg=="quinte_flush")) {
        c1 = Card(11, 1);
        c2 = Card(9, 1);
        c3 = Card(13, 1);
        c4 = Card(12, 1);
        c5 = Card(10, 1);
    }

    if ((arg == "Quinte_royale") or(arg=="RQuinte")) {
        c1 = Card(6, 1);
        c2 = Card(14, 1);
        c3 = Card(13, 1);
        c4 = Card(12, 1);
        c5 = Card(10, 1);
    }

    /*
    if (arg == "Rand") {
        srand (time(NULL));
        c1 = Card(rand() % 14 + 2, rand() % 4 + 1);
        c2 = Card(rand() % 14 + 2, rand() % 4 + 1);
        c3 = Card(rand() % 14 + 2, rand() % 4 + 1);
        c4 = Card(rand() % 14 + 2, rand() % 4 + 1);
        c5 = Card(rand() % 14 + 2, rand() % 4 + 1);
    }
*/
    tab[0] = c1;
    tab[1] = c2;
    tab[2] = c3;
    tab[3] = c4;
    tab[4] = c5;
}



// Cette fonction prend en arguemnt un objet card et traduit ces arguemnts en français
void Trad(const Card& C) {
    std::string v = std::to_string(C.valeur);
    std::string c = std::to_string(C.color);
    if (C.valeur == 11) {
        v = "V";
    }
    if (C.valeur == 12) {
        v = "D";
    }
    if (C.valeur == 13) {
        v = "R";
    }
    if (C.valeur == 14 or C.valeur ==1 ) {
        v = "A";
    }
    if (C.color == 1) {
        c = "Coeur";
    }
    if (C.color == 2) {
        c = "Pique";
    }
    if (C.color == 3) {
        c = "Carreau";
    }
    if (C.color == 4) {
        c = "Trefle";
    }
    std::cout << v << " de " << c << std::endl;
}


// Cette fonction trie un tableau en utilisant le tri a bulle
void tri(){
    std::cout << " ------- Main non triee ------" << std::endl;
    for (const auto & k : tab) {
        Trad(k);
    }
    int i, j;
    Card tmp;
    int SIZE = 5;
    for (i=0 ; i < SIZE-1; i++){
        for (j=0 ; j < SIZE-i-1; j++){
            if (tab[j].valeur > tab[j+1].valeur){
                tmp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = tmp;
            }
        }
    }
    c1 = tab[0];
    c2 = tab[1];
    c3 = tab[2];
    c4 = tab[3];
    c5 = tab[4];
    std::cout << " ------- Main tiree ------" << std::endl;
    for (const auto & k : tab) {
        Trad(k);
    }
    std::cout << " ------- Fin du Tri ------" << std::endl;
}


void TestCard(){

    // Check si notre main est une paire
    if (c1.valeur == c2.valeur or
    c1.valeur == c3.valeur or
    c1.valeur == c4.valeur or
    c1.valeur == c5.valeur or
    c2.valeur == c3.valeur or
    c2.valeur == c4.valeur or
    c2.valeur == c5.valeur or
    c3.valeur == c4.valeur or
    c3.valeur == c5.valeur or
    c4.valeur == c5.valeur){
        std::cout << "Il y a une paire dans la main" << std::endl;
        std::cout << paire << std::endl;
        paire = true;
    }

    // Check si notre main est une double paire
    if ((c1.valeur == c2.valeur and c3.valeur == c4.valeur) or
    (c1.valeur == c2.valeur and c4.valeur == c5.valeur) or
    (c2.valeur == c3.valeur and c4.valeur == c5.valeur)
    ){
            //std::cout << "Il y a deux paires dans la main" << std::endl;
            doublepaire = true;
        }

    // Check si notre main est un brelan
    if ((c1.valeur == c2.valeur) and (c1.valeur == c3.valeur) or
    (c1.valeur == c2.valeur) and (c1.valeur == c4.valeur) or
    (c1.valeur == c2.valeur) and (c1.valeur == c5.valeur) or
    (c1.valeur == c3.valeur) and (c1.valeur == c4.valeur) or
    (c1.valeur == c3.valeur) and (c1.valeur == c5.valeur) or
    (c1.valeur == c4.valeur) and (c1.valeur == c5.valeur) or
    (c2.valeur == c3.valeur) and (c2.valeur == c4.valeur) or
    (c2.valeur == c3.valeur) and (c2.valeur == c5.valeur) or
    (c2.valeur == c4.valeur) and (c2.valeur == c5.valeur) or
    (c3.valeur == c4.valeur) and (c3.valeur == c5.valeur)
    ){
        //std::cout << "Il y a un brelan dans la main" << std::endl;
        brelan = true; paire=false;
    }

    // Check si notre main est un full
    if (((c1.valeur == c2.valeur) and (c1.valeur == c3.valeur)) and (c4.valeur == c5.valeur) or
    ((c3.valeur == c4.valeur) and (c3.valeur == c5.valeur)) and (c1.valeur == c2.valeur))
    {
        //std::cout << "Il y a un full dans la main" << std::endl;
        full = true; doublepaire = false;
}

    // Check si notre main est un carre
    if (doublepaire and (c2.valeur==c4.valeur) ){
        //std::cout << "Il y a un carre dans la main" << std::endl;
        carre = true; doublepaire = false;
    }

    // Check si notre main est une suite
    if (c1.Next(c2)==1 and
        c2.Next(c3)==1 and
        c3.Next(c4)==1 and
        c4.Next(c5)==1 ){
        //std::cout << " Il y a une suite" << std::endl;
        suite=true;
    }
    // Check si notre main est une couleur
    if (c1.color == c2.color  == c3.color == c4.color == c5.color){
        //std::cout << "Il y a une couleur dans cette main" << std::endl;
        couleur=true;
    }

    // Check si notre main est une quinte flush
    if (couleur and suite){
        //std::cout << "Il y a une quinte flush dans la main" << std::endl;
        quinteflush = true;
    }

    // Check si notre main est une quinte flush royale
    if (quinteflush and (c5.valeur == 14)){
       //std::cout << "Il y a une quinte flush royale dans la main" << std::endl;
        quinteflushroyale = true;

    }

    // Check si notre main est impossible
    if (
            //Check si les valeurs de nos cartes sont dans les valeurs acceptées
    (1 >> c1.valeur >> 15) or
    (1 >> c2.valeur >> 15) or
    (1 >> c3.valeur >> 15) or
    (1 >> c4.valeur >> 15) or
    (1 >> c5.valeur >> 15) or
            //Check si les couleurs de nos cartes sont dans les valeurs acceptées
    (0 >> c1.color >> 5) or
    (0 >> c2.color >> 5) or
    (0 >> c3.color >> 5) or
    (0 >> c4.color >> 5) or
    (0 >> c5.color >> 5) or
            //Check si on a deux cartes identiques
    ((c1.valeur == c2.valeur) and (c1.color == c2.color)) or
    ((c1.valeur == c3.valeur) and (c1.color == c3.color)) or
    ((c1.valeur == c4.valeur) and (c1.color == c4.color)) or
    ((c1.valeur == c5.valeur) and (c1.color == c5.color)) or
    ((c2.valeur == c3.valeur) and (c2.color == c3.color)) or
    ((c2.valeur == c4.valeur) and (c2.color == c4.color)) or
    ((c2.valeur == c5.valeur) and (c2.color == c5.color)) or
    ((c3.valeur == c4.valeur) and (c3.color == c4.color)) or
    ((c3.valeur == c5.valeur) and (c3.color == c5.color)) or
    ((c4.valeur == c5.valeur) and (c4.color == c5.color))
    ){
        ERROR = true;
    }

    // Check si notre main est une carte haute
    if(!paire and
       !doublepaire and
       !brelan and
       !suite and
       !couleur and
       !full and
       !carre and
       !quinteflush and
       !quinteflushroyale
    ){
        //std::cout << "Il y a une carte haute dans la main" << std::endl;
        cartehaute=true;
    }

    //Affiche nos variables (pour le debug)

    std::cout << "Paire : " << paire <<
    "\nDoublepaire : " << doublepaire <<
    "\nBrelan : " << brelan <<
    "\nSuite : " << suite <<
    "\nCouleur : " << couleur <<
    "\nFull : " << full <<
    "\nCarre : " << carre <<
    "\nQuinteflush : " << quinteflush <<
    "\nQuinteflushroyale : " << quinteflushroyale <<
    "\nCartehaute : " << cartehaute <<
    "\nErreur : " << ERROR <<
    std::endl;

    std::cout << " ------- Conclusion ------- " << std::endl;

// Permet de conclure sur la combinaison en question
    if(ERROR){
        std::cout << "Votre main n'est pas corecte" << std::endl;
    }

    if (quinteflushroyale) {
        std::cout << "Votre main est une quinte flush royale" << std::endl;
    }

    if (quinteflush and !quinteflushroyale) {
        std::cout << "Votre main est une quinte flush " << std::endl;
    }

    if (carre) {
        std::cout << "Votre main est un carre" << std::endl;
    }

    if (full) {
        std::cout << "Votre main est un full" << std::endl;
    }

    if (couleur and !quinteflush and !quinteflushroyale) {
        std::cout << "Votre main est une couleur" << std::endl;
    }

    if (suite and !quinteflush and !quinteflushroyale) {
        std::cout << "Votre main est une suite" << std::endl;
    }

    if (brelan and !full and !carre) {
        std::cout << "Votre main est un brelan " << std::endl;
    }

    if (doublepaire) {
        std::cout << "Votre main est une double paire" << std::endl;
    }

    if (paire and !doublepaire and !brelan and !carre) {
        std::cout << "Votre main est une paire " << std::endl;
    }

    if (cartehaute and !paire and !doublepaire and !brelan and !full and !carre and !couleur and !suite and !quinteflush and !quinteflushroyale) {
        std::cout << "Votre main est une carte de haute : " << std::endl;
        Trad(c5);
    }
}




int main() {

    std::cout << "Demarage du Adipoker..." << std::endl;
    std::cout << "Jouer comporte des riques" << std::endl;

    std::string arg;
    //Interactive section
    std::cout << " Jeux avec orthographe particuliere: Quinte_royale, Quinte_flush, Full " << std::endl;
    std::cout << "Choisir jeux essai (Ex: Paire, Brelan...) : ";

    //std::cin >> arg;
    std::getline(std::cin , arg);
    jeuxessai(arg); // Valeur disponibles || Paire || Double paire || Brelan || Double paire || Couleur || Full || Carre || Quinte flush || Quinte flush royale || Rand
    tri();
    TestCard();

    return 0;
}