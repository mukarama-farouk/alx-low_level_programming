#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Return: pointer
 *
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *ptr_dog;

	ptr_dog = malloc(sizeof(ptr_dog));

	if (ptr_dog == NULL)
		return (NULL);

	ptr_dog->name = malloc(strlen(name) + 1);
	ptr_dog->owner = malloc(strlen(owner) + 1);

	if (ptr_dog->name == NULL)
	{
		free(ptr_dog);
		return (NULL);
	}

	if (ptr_dog->name == NULL)
	{
		free(ptr_dog->name);
		free(ptr_dog);
		return (NULL);
	}

	strcpy(ptr_dog->name, name);
	ptr_dog->age = age;
	strcpy(ptr_dog->owner, owner);
	return (ptr_dog);

}
