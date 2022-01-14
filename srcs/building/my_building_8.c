#include "minishell.h"

int     add_var(t_env *tmp)
{
    int i;
    int k;
    
    k = 0;
    i = -1;
    while (term->my_env[k].key)
        k++;
    while (++i < k)
    {
        free(term->my_env[i].key);
        free(term->my_env[i].var);
    }
    free(term->my_env);
    term->my_env = tmp;
    return (0);
}

int     add_elem(char *key, char *var)
{
    int i;
    t_env   *tmp;

    i = 0;
    while (term->my_env[i].key)
        i++;
    tmp = malloc(sizeof(t_env) * (i + 2));
    if (!tmp)
        return (-1);
    i = 0;
    while (term->my_env[i].key)
    {
        tmp[i].key = ft_strdup(term->my_env[i].key);
        tmp[i].var = ft_strdup(term->my_env[i].var);
        i++;
    }
    tmp[i].key = ft_strdup(key);
    tmp[i].var = ft_strdup(var);
    i++;
    tmp[i].key = NULL;
    tmp[i].var = NULL;
    add_var(tmp);
    aj_env_to_exp(key, var);
    return (0);
}

char    *remp_var(char *dst, char *src)
{
    int i;
    int j;

    i = 0;
    j = 0;
    dst = malloc(sizeof(char *) * ft_strlen(src));
    if (!dst)
        return (NULL);
    while (src[i] && src[i] != '=')
        i++;
    i++;
    while (src[i])
    {
        dst[j] = src[i];
        i++;
        j++;
    }
    dst[j] = '\0';
    return (dst);
}

char	*remp_key(char *dst, char *src)
{
	int i;

    dst = malloc(sizeof(char *) * ft_strlen(src) + 1);
    if (!dst)
        return (NULL);
	i = 0;
	while (src[i] && src[i] != '=')
	{
		dst[i] = src[i];
		i++;
	}
    dst[i] = '\0';
	return (dst);
}


int     my_export(char **argv)
{
    int     i;
    char    *key;
    char    *var;

    i = 1;
    if (!(argv[1]))
        sort_exp();
    while (argv[i])
    {
        if (check_arg(argv[i]) == 1)
            return (-1);
        if (check2(argv[i]))
        {
            if (verif(argv[i]) == 0)
                aj_export(argv[i]);
            else
                return (0);
        }
        else
        {
            key = remp_key(key, argv[i]);
            var = remp_var(var, argv[i]);
            if (check_dbl(key, var) == 0)
                add_elem(key, var);
            else
                change_var(key, var);
        }
        i++;
    }
    return (0);
}