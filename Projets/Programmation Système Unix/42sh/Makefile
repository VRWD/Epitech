##
## Makefile for Make file of minishell1 in /u/all/algrin_t/cu/rendu/c/minishell1bis
## 
## Made by thibaut algrin
## Login   <algrin_t@epitech.net>
## 
## Started on  Mon Jan 19 19:00:50 2009 thibaut algrin
## Last update Mon Jun 22 00:42:16 2009 kevin duplant
##

CC_FreeBSD	=	gcc
CC_solaris	=	/usr/sfw/bin/gcc
CC_Linux	=	gcc
CC_freebsd5.5	=	gcc

NAME		=	42sh

SRC		=	extraction_com_opt.c	\
			get_next_line.c		\
			get_to_path.c		\
			main.c			\
			my_cd.c			\
			my_env.c		\
			my_exit.c		\
			my_get_line_com.c	\
			my_free_tab.c		\
			my_putstr.c		\
			my_setenv.c		\
			my_show_str_list.c	\
			my_str_in_tab.c		\
			my_strcmp.c		\
			my_strcpy.c		\
			my_unsetenvbis.c	\
			my_xmalloc.c		\
			mysh.c			\
			path.c			\
			my_list_size.c		\
			my_exeve.c		\
			my_strcat.c		\
			epur_str.c		\
			my_echo.c		\
			aff_err.c		\
			redirection.c		\
			opt_liste_chaine.c	\
			aff_prompt.c		\
			my_alias.c		\
			my_check_alias.c	\
			my_unalias.c		\
			my_exeve_gauche.c	\
			my_exe_com_gauche.c	\
			check_dol_tild.c	\
			my_redi.c		\
			my_redi_double.c	\
			conf.c			\
			xfonction.c		\
			inibiteur.c		\
			gest_err.c		\
			aff_key.c		\
			check_str.c		\
			my_str_in_tab_sup.c	\
			my_redi_double_as.c	\
			extraction_file.c	\
			conf_prompt.c		\
			parseur_minishell.c	\
			put_argv_in_tab.c	\
			command_not_found.c	\
			my_cd_opt.c		\
			my_redir_optsec.c	\
			extraction_key.c	\
			put_av_in_tab.c		\
			my_getpwd.c		\
			xstat.c			\
			my_hist.c		\
			my_cd_opdir.c		\
			my_put_nbr.c		\
			go_init.c		\
			cd_check.c		\
			xfunc.c

RM		=	rm -f
CFLAGS		=	-W -Wall -pedantic -ansi

OBJ		=	$(SRC:.c=.o)

all		:	$(OBJ)
			$(CC_$(OSTYPE)) $(CFLAGS) $(OBJ) -o $(NAME)

clean		:
			$(RM) $(OBJ)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all