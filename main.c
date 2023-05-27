#include "shell.h"

int main() {
    list_t *head = NULL;

    // Add nodes to the list
    add_node(&head, "First Node", 1);
    add_node(&head, "Second Node", 2);
    add_node_end(&head, "Last Node", 3);

    // Print the list
    print_list_str(head);

    // Delete a node at index 1
    delete_node_at_index(&head, 1);

    // Print the updated list
    print_list_str(head);

    // Free the list
    free_list(&head);

#include "shell.h"
/**
 * main - Ensure that program variables are initialized
 * @argc: The amount of values received by the command line
 * @argv: these are the values of the command line which are received 
 * @env: The amount of values received by the command line
 * Return: 0 if successful
 */
int main(int argc, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	inicialize_data(data, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{ /* terminal interactive mode */
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;
	sisifo(prompt, data);
	return (0);
}

/**
 * handle_ctrl_c - print prompt in new line
 * when the signal SIGINT (ctrl + c) sent to the program
 * @UNUSED: prototype option
 */
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
 * inicialize_data - This will start the programs structure
 * @data: this is the data pointer structurer
 * @argv: these are arguments that have been sent to the program
 * @env: the execution of the program will go through the environment
 * @argc: these are the values of the command line which are received
 */
void inicialize_data(data_of_program *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;
	/* file descriptor to be read is defined */
	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printe(data->program_name);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = str_duplicate(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alias_list[i] = NULL;
	}
}
/**
 * sisifo - this will show the prompt
 * @prompt: printed prompt
 * @data: This will show the prompt
 */
void sisifo(char *prompt, data_of_program *data)
{
	int error_code = 0, string_len = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		error_code = string_len = _getline(data);

		if (error_code == EOF)
		{
			free_all_data(data);
			exit(errno);
		}
		if (string_len >= 1)
		{
			expand_alias(data);
			expand_variables(data);
			tokenize(data);
			if (data->tokens[0])
			{ 
				error_code = execute(data);
				if (error_code != 0)
					_print_error(error_code, data);
			}
			free_recurrent_data(data);
		}
	}
}


    return 0;
}
