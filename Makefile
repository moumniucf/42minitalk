CLIENT = client
SERVER = server

BCLIENT = client_bonus
BSERVER = server_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = minitalk.h
BHEADER = bonus/minitalk_bonus.h

C_SRC = client.c utils.c utils2.c 
S_SRC = server.c utils.c utils2.c 

OS_SRC = $(S_SRC:%.c=%.o)
OS_CRC = $(C_SRC:%.c=%.o)

BC_SRC = bonus/client_bonus.c bonus/utils_bonus.c bonus/utils2_bonus.c bonus/ctlc_bonus.c bonus/ft_bzero_bonus.c 
BS_SRC = bonus/server_bonus.c bonus/utils_bonus.c bonus/utils2_bonus.c  bonus/ctlc_bonus.c bonus/ft_bzero_bonus.c 

BOS_SRC = $(BS_SRC:%.c=%.o)
BOS_CRC = $(BC_SRC:%.c=%.o)

all : $(CLIENT) $(SERVER)

bonus : $(BCLIENT) $(BSERVER)

%_bonus.o : %_bonus.c $(BHEADER)
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "compiling" $< "to" $@

%.o : %.c $(HEADER)
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
