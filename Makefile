NAME = philo

SRC = actions.c\
	actions2.c\
	ft_atoi.c\
	init.c\
	monitoring.c\
	philosophers.c\
	routine.c\
	utils.c\

FLAGS += -Werror -Wextra -Wall -g

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME) $(FLAGS)

all: $(NAME)

%.o:%.c
	cc ${FLAGS} $< -c

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)


re: fclean all
