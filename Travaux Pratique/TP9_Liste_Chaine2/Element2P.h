#ifndef ELEMENT2P_H
#define ELEMENT2P_H
#include "Element.h"

typedef struct sElement2p{
    struct sElement2p *pred;
    struct sElement2p *succ;
    int cle;
}Element2p;

#endif

