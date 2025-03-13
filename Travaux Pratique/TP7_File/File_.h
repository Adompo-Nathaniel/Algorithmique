#ifndef FILE_H
#define FILE_H

#include "Element.h"
#include "Cellule.h"

typedef struct sFile{
    Cellule *deb;
    Cellule *fin;
}File;

void emfiler(File *p,Element e);
void FileAfficher(File *p);
void viderFile(File *p);
void creerFile(File *p);
void defiller(File *p);
int fileVide(File p);
Element tete(File p);

#endif
