//
// Created by inesc on 21/10/2022.
//

#include <algorithm>
#include <iostream>
#include "Hand.h"


//CTOR
Hand::Hand(Card tab[]) {
    for ( int i = 0 ; i < 5 ; i++){
        this->ta[i]=tab[i];
    }
    Tri();
}

//DTOR

Hand::~Hand() {

}

//Methodes
// tri a bulle
void Hand::Tri(){
    int i, j;
    Card tmp;
    int SIZE = 5;
    for (i=0 ; i < SIZE-1; i++){
        for (j=0 ; j < SIZE-i-1; j++){
            if (ta[j] < ta[j+1]){
                tmp = ta[j];
                ta[j] = ta[j+1];
                ta[j+1] = tmp;
            }
        }
    }
    std::sort(std::begin(ta), std::end(ta));
    std::cout << ta <<std::endl;
    std::cout << " ------- Tri finit ------" <<std::endl;
}
