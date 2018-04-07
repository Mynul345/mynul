#include <stdio.h>
#include <string.h>

char allBlood[9][3];
char allDoner[100][100];
char location[100][100];
char contact[100][100];

//Read All Blood Group

int readBloodGroup()
{
    int i = 0;
    printf("Enter Blood Group Name:\n");

    FILE *allBloodGroup;
    allBloodGroup = fopen("blood.txt","r");

    if (allBloodGroup== NULL)
    {
        printf("can not open file \n");
        return 0;
    }

    while(!feof(allBloodGroup)){
        fscanf(allBloodGroup,"%s",&allBlood[i]);
        //printf("%s", allBlood[i]);
        i++;
    }

    fclose(allBloodGroup);
    return i;
}

//Read Blood Donner
void readBloodDonner()
{
    int index, lines = 1, i = 0;

    FILE *allBloodDoner;
    char ch;
    allBloodDoner = fopen("doner.txt","r");

    if (allBloodDoner== NULL)
    {
        printf("can not open file \n");
        return ;
    }

    while(!feof(allBloodDoner)){
        fscanf(allBloodDoner,"%s",&allDoner[i]);
        i++;
    }

    fclose(allBloodDoner);

}

//Read Location
void readBloodDonnerLocation()
{
    FILE *allBloodDonerLocation;
    char ch;
    allBloodDonerLocation = fopen("location.txt","r");

    if (allBloodDonerLocation== NULL)
    {
        printf("can not open file \n");
        return ;
    }
    int i =0;
    while(!feof(allBloodDonerLocation)){
        fscanf(allBloodDonerLocation,"%s",&location[i]);
        i++;
    }

    fclose(allBloodDonerLocation);
}

void readContact()
{
    FILE *allBloodDonerLocation;
    char ch;
    allBloodDonerLocation = fopen("contact.txt","r");

    if (allBloodDonerLocation== NULL)
    {
        printf("can not open file \n");
        return ;
    }
    int i =0;
    while(!feof(allBloodDonerLocation)){
        fscanf(allBloodDonerLocation,"%s",&contact[i]);
        i++;
    }

    fclose(allBloodDonerLocation);
}


int main()
{
    //readBloodGroup();
    readBloodDonner();
    readContact();
    readBloodDonnerLocation();
    char search[9][9];
    int indexNumber = -1;
    //bool searchBool;

    int j = readBloodGroup();
    gets(search);
    for(int k = 0; k < j; ++k)
    {
        int notf = 0;
        if( !strcmp(search, allBlood[k]) )
        {
            indexNumber = k;
            printf("Donner :%s and Location : %s contact %s\n", allDoner[indexNumber], location[indexNumber], contact[indexNumber]);
            notf = 1;
        }

        if( k== j-1 && notf == 0 ){
            printf("Donner not found");
        }
    }
    return 0;
}
