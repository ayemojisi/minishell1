#include "minishell.h"

void	cmd_control(t_struct *list)
{
	char *str;
	int		i;

	i = 0;
	str = list->cmd;
	list->tek_tirnak = 0;
	list->cift_tirnak = 0;
	while(str[i])
	{
		if(str[i] == '"')
		{
			list->cift_tirnak++;
			i++;
			while(str[i] && str[i] != '"')
			{
				printf("gir lan buraya %d\n", i);
				i++;
				if(str[i] == '"')
					list->cift_tirnak++;
			}
		}
		if(str[i] == '\'')
		{
			list->tek_tirnak++;
			i++;
			while(str[i] && str[i] != '\'')
			{
				i++;
				if(str[i] == '\'')
					list->tek_tirnak++;
			}
		}
		i++;
	}
	if(list->cift_tirnak % 2 != 0)
		exit_error(list, "cift tırnak kapanmadı");
	if(list->tek_tirnak % 2 != 0)
		exit_error(list, "tek tırnak kapanmadı");
}