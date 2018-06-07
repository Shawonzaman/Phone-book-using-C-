#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <conio.h>

typedef struct Phonebook_Contacts
   {
      char FirstName[1000];
      char LastName[1000];
      char PhoneNumber[1000];
      char email[100];
      char Address[];
   } phone;


void AddEntry(phone * );
void DeleteEntry(phone * );
void PrintEntry(phone * );
void SearchForNumber(phone * );
void DeleteAll(phone * );
void FreeContacts (phone * );


int counter = 0;
char FileName[256];
FILE *pRead;
FILE *pWrite;


int main (void)
   {
       system("cls");
        printf("\n\n\n\n\n\n\n\n");
    printf("\t\t***************************************************\n");
    printf("\t\t*************** Welcome To My Project ************\n");
    printf("\t\t**************                         ***********\n");
    printf("\t\t***************                       ************\n");
    printf("\t\t***************************************************\n");
    printf("\n\n\n\t\tTo Start Press Any Key-");
    getch();
    system("cls");

      phone *phonebook;
      phonebook = (phone*) malloc(sizeof(phone)*100);
      int iSelection = 0;


         if (phonebook == NULL)
         {

         printf("Out of Memory. The program will now exit");
         return 1;
         }
         else {}

      do
      {
         //system("cls");
         printf("\n\t\t\tPhonebook Menu");
         printf("\n\n\t(1)\tAdd A Contact");
         printf("\n\t(2)\tDelete A Contact");
         printf("\n\t(3)\tDisplay Phonebook Entries");
         printf("\n\t(4)\tSearch for Phone Number");
         printf("\n\t(5)\tDelete All Entries");
         printf("\n\t(6)\tExit Phonebook");
         printf("\n\nWhat would you like to do? ");
         scanf("%d", &iSelection);



         if (iSelection == 1)
         {
            AddEntry(phonebook);
         }



         if (iSelection == 2)
         {
            DeleteEntry(phonebook);
         }


         if (iSelection == 3)
         {
            PrintEntry(phonebook);
         }



         if (iSelection == 4)
         {
            SearchForNumber(phonebook);
         }





         if (iSelection == 5)
         {
            DeleteAll(phonebook);
         }


         if (iSelection == 6)
         {
            printf("\nYou have chosen to exit the Phonebook.\n");
            system("pause");

         }
      } while (iSelection <= 9);
   }


void AddEntry (phone * phonebook)
{

   pWrite = fopen("phonebook_contacts.dat", "a");
   if ( pWrite == NULL )
   {
      perror("The following error occurred ");

   }
      else
      {
         counter++;


         printf("\nFirst Name: ");
         scanf("%s", phonebook[counter-1].FirstName);
         printf("Last Name: ");
         scanf("%s", phonebook[counter-1].LastName);
         printf("Phone Number (XXXXX-XXXXXX): ");
         scanf("%s", phonebook[counter-1].PhoneNumber);
         printf("E-mail Address: ");
         scanf("%s", phonebook[counter-1].email);
         printf("Present Address: ");
         scanf("%s", phonebook[counter-1].Address);

         printf("\n\tFriend successfully added to Phonebook\n");

         fprintf(pWrite, "%s\t%s\t%s\t%s\t%s\n", phonebook[counter-1].FirstName, phonebook[counter-1].LastName, phonebook[counter].PhoneNumber,phonebook[counter].email, phonebook[counter-1].Address);
         fclose(pWrite);
      }
}

void DeleteEntry (phone * phonebook)
{
   int x = 0;
   int i = 0;
   char deleteFirstName[20];
   char deleteLastName[20];

      printf("\nFirst name: ");
      scanf("%s", deleteFirstName);
      printf("Last name: ");
      scanf("%s", deleteLastName);

      for (x = 0; x < counter; x++)
      {
         if (strcmp(deleteFirstName, phonebook[x].FirstName) == 0)
         {
            if (strcmp(deleteLastName, phonebook[x].LastName) == 0)
            {
                for ( i = x; i < counter ; i++ )
               {
                  strcpy(phonebook[i].FirstName, phonebook[i+1].FirstName);
                  strcpy(phonebook[i].LastName, phonebook[i+1].LastName);
                  strcpy(phonebook[i].PhoneNumber, phonebook[i+1].PhoneNumber);
                  strcpy(phonebook[i].email, phonebook[i+1].email);
                strcpy(phonebook[i].email, phonebook[i].Address);
               }
               printf("Record deleted from the phonebook.\n\n");
               --counter;
               return;
            }
         }
      }

   printf("That contact was not found, please try again.");
}

void PrintEntry (phone * phonebook)
{


   printf("\nPhonebook Entries:\n\n ");
   pRead = fopen("phonebook_contacts.dat", "r");
   if ( pRead == NULL)
   {
      perror("The following error occurred: ");
      exit(EXIT_FAILURE);
   }
   else
   {
      for( x = 0; x < counter; x++)
      {
         printf("\n(%d)\n", x+1);
         printf("Name: %s %s\n", phonebook[x].FirstName, phonebook[x].LastName);
         printf("Number: %s\n", phonebook[x].PhoneNumber);
         printf("E-mail: %s\n", phonebook[x].email);
         printf("Present Address: %s\n", phonebook[x].Address);
      }
   }
   fclose(pRead);
}


void SortByFirstName (phone * phonebook)
{
   int i = 0;
   int x = 0;
   int swap;
   int TempCounter = counter;
   phone Temp;

   do
   {
      swap = 0;
      for(i = 1; i < TempCounter; i++)
      {

         if(strcmp(phonebook[i-1].FirstName, phonebook[i].FirstName) > 0)
         {
            Temp = phonebook[i];
            phonebook[i] = phonebook[i-1];
            phonebook[i-1] = Temp;

            strcpy(Temp.FirstName, phonebook[i].FirstName);
            strcpy(Temp.LastName, phonebook[i].LastName);
            strcpy(Temp.PhoneNumber, phonebook[i].PhoneNumber);
            strcpy(Temp.PhoneNumber, phonebook[i].email);
            strcpy(Temp.PhoneNumber, phonebook[i].Address);

            swap = 1;
         }
      }
      TempCounter--;
   } while (swap);

   printf("\nYour friends in Alphabetical Order by First Name:\n\n");
   for( x = 0; x < counter; x++ )
   {
      printf("\n(%d)\n", x);
      printf("Name: %s %s\n", phonebook[x].FirstName, phonebook[x].LastName);
      printf("Number: %s\n", phonebook[x].PhoneNumber);
      printf("E-mail: %s\n", phonebook[x].email);
      printf("present address: %s\n", phonebook[x].Address);
   }
}


void SortByLastName (phone * phonebook)
   {
   int i = 0;
   int x = 0;
   int swap;
   int TempCounter = counter;
   phone Temp;

   do
   {
      swap = 0;
      for(i = 1; i < TempCounter; i++)
      {

         if(strcmp(phonebook[i].LastName, phonebook[i].LastName) > 0)
         {
            Temp = phonebook[i];
            phonebook[i] = phonebook[i];
            phonebook[i-1] = Temp;

            strcpy(Temp.FirstName, phonebook[i].FirstName);
            strcpy(Temp.LastName, phonebook[i].LastName);
            strcpy(Temp.PhoneNumber, phonebook[i].PhoneNumber);
            strcpy(Temp.FirstName, phonebook[i].email);
            strcpy(Temp.FirstName, phonebook[i].Address);

            swap = 1;
         }
      }

   } while (swap);

   printf("\nYour friends in Alphabetical Order by First Name:\n\n");
   for( x = 0; x < counter; x++ )
   {
      printf("\n(%d)\n", x);
      printf("Name: %s %s\n", phonebook[x].FirstName, phonebook[x].LastName);
      printf("Number: %s\n", phonebook[x].PhoneNumber);
      printf("E-mail: %s\n", phonebook[x].email);
      printf("Present Address: %s\n", phonebook[x].Address);
   }
}


void SearchForNumber (phone * phonebook)
{
   int x = 0;
   char TempFirstName[10];
   char TempLastName[20];

   printf("\nPlease type the name of the friend you wish to find a number for.");
   printf("\n\nFirst Name: ");
   scanf("%s", TempFirstName);
   printf("Last Name: ");
   scanf("%s", TempLastName);
   for (x = 0; x < counter; x++)
   {
      if (strcmp(TempFirstName, phonebook[x].FirstName) == 0)
      {
         if (strcmp(TempLastName, phonebook[x].LastName) == 0)
         {

            printf("\n%s %s's phone number is %s\n", phonebook[x].FirstName, phonebook[x].LastName, phonebook[x].PhoneNumber, phonebook[x].email);
         }
      }
   }
}

void DeleteAll (phone * phonebook)
{
   int x = 0;
   char nullStr[200] = {'0'};

   for ( x = 0; x < counter; x++ )
   {
      strcpy(phonebook[x].FirstName, nullStr);
      strcpy(phonebook[x].LastName, nullStr);
      strcpy(phonebook[x].PhoneNumber, nullStr);
      strcpy(phonebook[x].email, nullStr);
      strcpy(phonebook[x].Address, nullStr);
      counter;phonebook[counter].email;
   }

   printf("All Contacts have been deleted.\n");
}
void FreeContacts (phone * phonebook)
{

     for ( i=0; counter > 0; counter)
     {
        free(phonebook[counter].FirstName);
        free(phonebook[counter].LastName);
        free(phonebook[counter].PhoneNumber);
        free(phonebook[counter].email);
        free(phonebook[counter].Address);
        free(phonebook);
        counter = 0;

     }
}
