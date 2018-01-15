//Tomas Mikna 2 grupë
//3-11 uþduotis, iðvesti ilgiausià eilutës þodá

#include <stdio.h>
#include <string.h>



void ilgzod (char* buf, char* IlgZodis);


int main(int argc, char *argv[])
{
    char buf[256];       
    char IlgZodis[256];
    FILE *input;
    FILE *output;

    input = fopen(argv[1], "r");
    if (input==NULL)
    {
        printf ("%s \n", "Vartotojo nurodyto duomenu failo nera");
        return 2;
    }

    output = fopen(argv[2], "w");
    if (output==NULL)
    {
	fclose (input);
        printf ("%s \n", "Rezultatu failo negalima sukurti");
        return 3;
    }

    while (fgets(buf, 256, input)!=0)
    {

        ilgzod (buf, IlgZodis);
        fputs (IlgZodis, output);
        fputc ('\n', output);


    }
    fclose (input);
    fclose (output);
    
    return 0;
}
void ilgzod (char* buf, char* IlgZodis)
{
    char ilg[256];
    int i=0, j=0;
    int IlgIlgis = 0;
    
    while (buf[i+j]!='\0')
    {
        while(buf[i+j]!=' ' && buf[i+j]!='\n')
        {
            ilg[i]=buf[i+j];
            i++;
            
        }
        ilg[i]='\0';
        if (i >= IlgIlgis)
        {
            strcpy(IlgZodis, ilg);
            IlgIlgis=i;
        }
        j=j+i+1;
        i=0;
    }
}

