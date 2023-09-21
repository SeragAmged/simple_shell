#include "shell.h"

/**
 * _reallocate - custom re-allocation helper
 * @ptr: void pointer
 * @old_size: current size of ptr
 * @new_size: required size of the pointer
 * Return: a new pointer
 */
char **_reallocate(char **ptr, size_t old_size, size_t new_size)
{
	char **new_ptr;
	unsigned long i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (old_size == new_size)
		return (ptr);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (ptr);

	for (i = 0; (i < old_size) && (i < new_size); i++)
		new_ptr[i] = ptr[i];
	free(ptr);

	if (new_size > old_size)
	{
		for (; i < new_size; i++)
			new_ptr[i] = NULL;
	}
	return (new_ptr);
}

/**
 * _free - frees a pointer
 * @ptr: pointer
 */
void _free_pointer(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

/**
 * bigFree - frees 2d array
 * @ptr: pointer
 */
void _mass_free(char **ptr)
{
	void *p = ptr;

	while (*ptr != NULL)
		_free_pointer(*ptr++);

	_free_pointer(p);
}

/**
 * freeBuffs - frees program buffers
 * @buffer: dealloc buffer
 * @argv: dealloc argv
 */
void freeBuffs(char *buffer, char **argv)
{
	_free_pointer(buffer);
	_free_pointer(argv);
}
