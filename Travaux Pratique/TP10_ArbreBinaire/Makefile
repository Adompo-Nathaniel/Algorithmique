# Compiler
CC = gcc
# Options de compilation
CFLAGS = -Wall -Wextra -Werror -std=c99

# Noms des fichiers sources
SRCS = Noeud.c ArbreBinaire.c principal.c
# Noms des fichiers objets générés
OBJS = $(SRCS:.c=.o)
# Noms des fichiers headers
HEADERS = Noeud.h ArbreBinaire.h

# Nom de l'exécutable final
EXEC = principal

# Règle par défaut : exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Règle de compilation des fichiers objets
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage : suppression des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)