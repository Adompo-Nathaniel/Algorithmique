# Compiler
CC = gcc
# Options de compilation
CFLAGS = -Wall -Wextra -Werror -std=c99

# Noms des fichiers sources
SRCS = Cellule.c cellule2.c Element.c File_ch.c ListeC_F.c Test.c
# Noms des fichiers objets générés
OBJS = $(SRCS:.c=.o)
# Noms des fichiers headers
HEADERS = Cellule.h cellule2.h Element.h File_ch.h ListeC_F.h Liste_.h File_.h

# Nom de l'exécutable final
EXEC = Test

# Règle par défaut : exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Règle de compilation des fichiers objets
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage : suppression des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)