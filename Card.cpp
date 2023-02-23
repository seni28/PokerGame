//
// Created by inesc on 14/10/2022.
//

// Pré processeur
#include <iostream>
#include "Card.h"


//CTOR
Card::Card(int val, int col){
    this->valeur=val;
    this->color=col;
}


//DTOR
Card::~Card() {
}


//Cette fonction compare la valeur de deux cartes renvoie -1 si a<c|| 0
// si les cartes on la même valeur || 1

int Card::Comp(Card c){
    int a;
    a= this->valeur - c.valeur;
    if(a<0){
        return -1;
    }
    else if(a==0){
        return 0;
    }
    else{
        return 1;
    }
}

//Fonction retourne 1 si les cartes se suivent

int Card::Next(Card c){
    int a;
    a= this->valeur - c.valeur;
    if(a ==-1 or a == 1) {
        return 1;
    }
    else{
        return 0;
    }
}

//Cette fonction retourne 1 si les cartes sont de la même couleur et 0 si elles sont d'une couleures différentes
int Card::SameColor(Card c){
    if(this->color == c.color){
        return 1;
    }
    else{
        return 0;
    }
}

bool Card::operator<(const Card& other) const {
    return this->valeur < other.valeur;
}

//Cette fonction  retourne 1 si i > j sinon 0
bool ordre_ascendant(int i, int j)
{
   return i > j;
}