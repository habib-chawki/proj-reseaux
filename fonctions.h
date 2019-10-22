typedef struct{
	int n1, n2, n3, n4;
}AdresseIP;

typedef struct Machine Machine;
struct Machine{
	char nom[20];
	AdresseIP ip;
	Machine *suivant;
};

int meme_adresse(AdresseIP ip1, AdresseIP ip2);
Machine *insertion_machine_fin(Machine *li, Machine *machine);
int ip_existe(Machine *li, AdresseIP ip);
Machine *supprimer_machine(Machine *li, AdresseIP ip);
void afficher_details_reseau(Machine *li);
