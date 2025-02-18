CC = cc
FLAGS = -Werror -Wextra -Wall

CLIENT_SRC = client.c utils.c
CLIENT_OBJ = client.o utils.o
CLIENT_X = client

SERVER_SRC = server.c utils.c
SERVER_OBJ = server.o utils.o
SERVER_X = server

PRINTF_OBJ = printf/libftprintf.a

all: $(CLIENT_X) $(SERVER_X)


$(CLIENT_X): $(CLIENT_OBJ)
	$(CC) $(FLAGS) -o $(CLIENT_X) $(CLIENT_OBJ) $(PRINTF_OBJ)

$(SERVER_X): $(SERVER_OBJ)
	$(CC) $(FLAGS) -o $(SERVER_X) $(SERVER_OBJ) $(PRINTF_OBJ)

client.o: client.c
	$(CC) $(FLAGS) -c client.c

server.o: server.c
	$(CC) $(FLAGS) -c server.c

utils.o: utils.c
	$(CC) $(FLAGS) -c utils.c

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	rm -f $(CLIENT_X) $(SERVER_X)

re: fclean all

.PHONY: all clean fclean re
