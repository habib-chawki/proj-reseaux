#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions.h"

// comparer deux adresses ip
int meme_adresse(AdresseIP ip1, AdresseIP ip2)
{
	if (ip1.n1 == ip2.n1 && ip1.n2 == ip2.n2 && ip1.n3 == ip2.n3 && ip1.n4 == ip2.n4)
	{
		return true;
	}
	return false;
}

// verifier si une adresse ip existe dans le reseau
int ip_existe(Machine *res, AdresseIP ip)
{
	while (res != NULL)
	{
		if (meme_adresse(res->ip, ip))
		{
			return true;
		}
		res = res->suivant;
	}
	return false;
}

// afficher les informations de toutes les machines du reseau
void afficher_details_reseau(Machine *res)
{
	printf("\nReseau: ");
	while (res != NULL)
	{
		// afficher le nom et l'adresse
		printf("%s (%d.%d.%d.%d) -> ", res->nom, (res->ip).n1, (res->ip).n2, (res->ip).n3, (res->ip).n4);
		res = res->suivant;
	}
	printf("/\n");
}

// inserer une nouvelle machine
Machine *insertion_machine_fin(Machine *res, Machine *machine)
{
	Machine *x = res;
	if (x != NULL)
	{
		while (x->suivant != NULL)
		{
			x = x->suivant;
		}
		x->suivant = machine;
	}
	else
	{
		res = machine;
	}
	return res;
}

// supprimer une machine
Machine *supprimer_machine(Machine *res, AdresseIP ip)
{
	Machine *x = res, *y;
	if (meme_adresse(res->ip, ip))
	{
		res = res->suivant;
		x->suivant = NULL;
		free(x);
	}
	else
	{
		while (!meme_adresse(x->suivant->ip, ip))
		{
			x = x->suivant;
		}
		y = x->suivant;
		x->suivant = y->suivant;
		y->suivant = NULL;
		free(y);
	}

	return res;
}
