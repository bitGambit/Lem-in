#ifndef LEM_IN
# define LEM_IN

# include "../libft/includes/libft.h"
# include <stdio.h>

/*
** Error message
*/

# define ERR            (0)
# define NOARG          (1)
# define INVDLINK       (2)
# define INVDCOMM       (3)
# define INVDROOM       (4)
# define NOPATH         (5)

# define START          "start"
# define END            "end"
# define SIZE           (1024)

int g_id;

/*
** Data structures
*/
typedef struct      s_path
{
    int             room;
    struct s_path   *next;
}                   t_path;

typedef struct      s_queue
{
    int             items[SIZE];
    int             front;
    int             rear;
}                   t_queue;

typedef struct      s_node
{
    char            *name;
    int             id;
    int             x;
    int             y;
    struct s_node   *next;
}                   t_node;

typedef struct      s_adjacent
{
    t_node          **adjacent;
    int             *visited;
}                   t_adjacent;

typedef struct      s_rooms
{
    t_node          **rooms;
    t_node          *head;
    t_node          *start;
    t_node          *end;
    int             total;
}                   t_rooms;

typedef struct      s_lemin
{
    int             ants;
    t_rooms         *rooms;
    t_adjacent      *adjrms;
    t_path          **parent;
    t_path          **paths;


}                   t_lemin;


/*
** functions for receiving and processing data
*/

void        ft_error(int errcode);
void        lm_strdel(char **str);
char        **lemin_read(char *av[]);
void        lemin_init(t_lemin *lemin, char **str);
int         lemin_validate(char *str[]);
int         get_ants(char *str);
t_rooms     *get_rooms(char *str[]);
void        get_links(t_lemin *lemin, char *str[]);

/*
** preparation of data for work on graphs
*/

void        create_adjrooms(t_rooms *rm, t_adjacent *adj);
void        creat_links(t_node *head, t_adjacent *adj, char *line[]);
t_queue     *creat_queue(void);
void        enqueue(t_queue *queue, int value);
int         dequeue(t_queue *queue);

/*
** search for routes to go through an ant farm (BFS algorithm)
*/

t_path      **creat_paths(int len);
void        push_path(t_path **path, int room);
void        breadth_first_search(t_lemin* farm, t_adjacent *adj, int start);
void        lemin_get_paths(t_lemin *lem, int final);


#endif