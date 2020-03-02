#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions.h"

int main()
{

	Machine *reseau = NULL, *machine;
	AdresseIP ip;

	int reste = true;
	do
	{
		// lire les informations de la nouvelle machine a ajouter
		machine = malloc(sizeof(Machine));
		printf("\n___ Tapez les informations de la machine ___\n\n");
		printf("Nom: ");
		scanf("%s", &machine->nom);
		printf("Adresse IP (n1,n2,n3,n4): ");
		scanf("%d%d%d%d", &((machine->ip).n1), &((machine->ip).n2), &((machine->ip).n3), &((machine->ip).n4));
		machine->suivant = NULL;

		// verifier si la machine existe deja
		if (ip_existe(reseau, machine->ip))
		{
			printf("La machine existe deja ! \n");
		}
		else
		{
			reseau = insertion_machine_fin(reseau, machine);
		}

		// verifier s'il existe d'autres machines a ajouter
		printf("Reste-t-il des machines a ajouter ? ");
		scanf("%d", &reste);
	} while (reste);

	printf("\nSaisir l'adresse d'une machine a supprimer: ");
	scanf("%d%d%d%d", &ip.n1, &ip.n2, &ip.n3, &ip.n4);

	// supprimer la machine par son adresse si elle existe
	if (ip_existe(reseau, ip))
	{
		reseau = supprimer_machine(reseau, ip);
	}
	else
	{
		printf("La machine n'existe pas ! ");
	}

	// afficher les informations du reseau
	printf("\n");
	afficher_details_reseau(reseau);
	return 0;
}
