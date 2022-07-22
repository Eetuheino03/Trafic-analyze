#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int valikko();
int kysyTiedosto();
int lueTiedosto(char tiedostoNimi[35]);
int analysoiJaTulosta();
int kirjoitaTulokset();
const char* haeArvo(char* rivi, int num);

int main()
{
    int valinta;

    do
    {
        valinta = valikko();

        if (valinta == 1)
        {
            kysyTiedosto();
        }
        else if (valinta == 2)
        {
            analysoiJaTulosta();
        }
        else if (valinta == 3)
        {
            kirjoitaTulokset();
        }

    } while (valinta != 0);

    return 0;
}

int valikko()
{
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lue tiedosto\n");
    printf("2) Analysoi ja tulosta tiedot\n");
    printf("3) Kirjoita tulokset\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi:\n");

    int valinta;
    scanf("%d", &valinta);

    return valinta;
}

int kysyTiedosto() // Kysyy tiedoston nimen
{
    printf("Anna luettavan tiedoston nimi:\n");
    char tiedostoNimi[35];
    scanf("%s", &tiedostoNimi);

    lueTiedosto(tiedostoNimi);

    return 0;
}

const char* haeArvo(char* rivi, int num) // palauttaa tietyn sarakkeen arvon tietyltä riviltä tai ainaki pitäs tehä nii
{
    const char* tok;
    for (tok = strtok(rivi, ";");
        tok && *tok;
        tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}


int lueTiedosto(char tiedostoNimi[35])
{

    FILE* pTiedosto = fopen(tiedostoNimi, "r");
    if (pTiedosto == NULL)
    {
        printf("Tiedostoa %s ei voitu avata\n", tiedostoNimi);
        return 1;
    }


    char rivi[1024];
    while (fgets(rivi, 1024, pTiedosto))
    {
        char* tmp = strdup(rivi);
        printf("%s\n", haeArvo(tmp, 1));
    }
    fclose(pTiedosto);

    return 0;
}

int analysoiJaTulosta()
{
    printf("Analysoi\n");
   
}

int kirjoitaTulokset()
{
    printf("kirjoita\n");
}
