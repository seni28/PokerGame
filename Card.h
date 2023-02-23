//
// Created by inesc on 14/10/2022.
//

#ifndef POKERGAME_CARD_H
#define POKERGAME_CARD_H
#include <string>

class Card {
public:

    //static bool comp(const Card&c1, const Card&c2) { return c1 < c2 ; }
    //CTOR
    Card(int val=0, int col=0) ;
    //DTOR
    ~Card();

    bool operator<(const Card& other) const ;

    //Methodes

    int Comp(Card);
    int Next(Card);
    int SameColor(Card);

// Attributs
public:
    int valeur;
    int color;
    std::string Trad;
};


#endif //POKERGAME_CARD_H