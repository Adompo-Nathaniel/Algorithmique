# Compiler
CC = gcc
# Options de compilation
CFLAGS = -Wall -Wextra -Werror -std=c99

# Noms des fichiers sources
SRCS = Pile_ch.c TestParentheses.c
# Noms des fichiers objets générés
OBJS = $(SRCS:.c=.o)
# Noms des fichiers headers
HEADERS = Pile_ch.h Pile_h Element.h cellule.h

# Nom de l'exécutable final
EXEC = TestParentheses

# Règle par défaut : exécutable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Règle de compilation des fichiers objets
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage : suppression des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)