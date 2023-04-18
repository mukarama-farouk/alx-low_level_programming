#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: struct dog
 * NULL if function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *ptr_dog;
	int n, name1, owner1;

	ptr_dog = malloc(sizeof(ptr_dog));

	if (ptr_dog == NULL || !(name) || !(owner))
	{
		free(ptr_dog);
		return (NULL);
	}

	for (name1 = 0; name[name1]; name1++)
		;
	for (owner1 = 0; owner[owner1]; owner++)
		;

	ptr_dog->name = malloc(name1 + 1);
	ptr_dog->owner = malloc(owner1 + 1);

	if (!(ptr_dog->name) || !(ptr_dog->owner))
	{
		free(ptr_dog->name);
		free(ptr_dog->owner);
		free(ptr_dog);
		return (NULL);
	}

	for (n = 0; n < name1; n++)
		ptr_dog->name[n] = name[n];
	ptr_dog->name[n] = '\0';

	ptr_dog->age = age;

	for (n = 0; n < owner1; n++)
		ptr_dog->owner[n] = owner[n];
	ptr_dog->owner[n] = '\0';

	return (ptr_dog);

}
