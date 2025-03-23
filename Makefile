CLIENT = client
SERVER = server

BCLIENT = client_bonus
BSERVER = server_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

HEADER = minitalk.h

C_SRC = client.c utils.c
S_SRC = server.c utils.c

OS_SRC = $(S_SRC:%.c=%.o)
OS_CRC = $(C_SRC:%.c=%.o)

BC_SRC = client_bonus.c utils.c
BS_SRC = server_bonus.c utils.c

BOS_SRC = $(BS_SRC:%.c=%.o)
BOS_CRC = $(BC_SRC:%.c=%.o)

all : $(CLIENT) $(SERVER)

bonus : $(BCLIENT) $(BSERVER)

%.o : %.c
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "compiling" $< "to" $@

$(CLIENT) : $(OS_CRC)
	@$(CC) $(CFLAGS) $(OS_CRC) -o $(CLIENT)

$(SERVER) : $(OS_SRC)
	@$(CC) $(CFLAGS) $(OS_SRC) -o $(SERVER)

$(BCLIENT) : $(BOS_CRC)
	@$(CC) $(CFLAGS) $(BOS_CRC) -o $(BCLIENT)

$(BSERVER) : $(BOS_SRC)
	@$(CC) $(CFLAGS) $(BOS_SRC) -o $(BSERVER)

clean : 
	@rm -f $(OS_SRC) $(OS_CRC) $(BOS_SRC) $(BOS_CRC)

fclean : clean
	@rm -f $(CLIENT) $(SERVER) $(BCLIENT) $(BSERVER)

re : fclean all

.PHONY : all clean fclean re bonus
