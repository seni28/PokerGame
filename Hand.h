//h
// Created by inesc on 21/10/2022.
//

#ifndef POKERGAME_HAND_H
#define POKERGAME_HAND_H


#include "Card.h"

class Hand {
public:


    //CTOR
    Hand(Card ta[]);

    //DTOR
    ~Hand();

    //Methodes
    void Tri();

    //Attribut
public :
    Card ta[5];



};

#endif //POKERGAME_HAND_H