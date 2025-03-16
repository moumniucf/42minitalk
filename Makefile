CLIENT = client
SERVER = server

CC = cc

CFLAGS = -Wall -Wextra -Werror

HEADER = minitalk.h

C_SRC = client.c
S_SRC = server.c

OS_SRC = $(S_SRC:%.c=%.o)
OS_CRC = $(C_SRC:%.c=%.o)

all : $(CLIENT) $(SERVER)

%.o : %.c
	@$(CC) -c $< $(CFLAGS) -o $@
	@echo "compiling" $< "to" $@

$(CLIENT) : $(OS_CRC)
	@$(CC) $(CFLAGS) $(OS_CRC) -o $(CLIENT)

$(SERVER) : $(OS_SRC)
	@$(CC) $(CFLAGS) $(OS_SRC) -o $(SERVER)

clean : 
	@rm -f $(OS_SRC) $(OS_CRC)
fclean : clean
	@rm -f $(CLIENT) $(SERVER)
re : fclean all
PHONY : fclean