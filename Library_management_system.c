#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct book
{
  char title[100], author[20];
  int ISBN;
}b[100];

void addbook(struct book *);
void display(struct book *b , char *n );
void search();
void delete();

int main ()
{
  
  int choice, count = 0;
  char name[20];
  while(1)
  {
    printf("Welcome to library management system!\n");
    printf("1.add book.\n");
    printf("2.Display book.\n");
    printf("3.Search book.\n");
    printf("4.Delete book.\n");
    printf("5.Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    getchar();
    
    switch(choice)
    {
      case 1:  //for adding book.
      if (count < 100 )
      {
        addbook(&b[count]);
        count++;
      }
      else 
      printf("The library is full.");
      break;

      case 2:  // for displaying book by author name.
      printf("write whose book you want to display?");
      fgets(name, 20, stdin);
      name[strcspn(name, "\n")] = '\0';

      display(b, name);
    }
  }
}



void addbook(struct book *b)
{
   FILE *file;
   file = fopen("library.txt", "a");
   if (file == NULL)
   {
    printf("The file is not exist.");
    exit(1);
   }
     printf("Enter the title of book:\n");
     fgets(b->title, 100, stdin);
     int l= strcspn(b->title, "\n");
     b->title[l]= '\0';
     printf("Enter the author name:\n");
     fgets(b->author, 20, stdin);
     b->title[strcspn(b->title, "\n")] = '\0';
     printf("Enter the isbn number:\n");
     scanf("%d", &b->ISBN);
     getchar();
     fprintf(file,"title:%s\tauthor name:%s\tISBN:%d\t", b->title, b->author, b->ISBN);
     fclose(file);
     printf("Book added successfully.\n");
}

void display(struct book *b, char *n)
{ 
  FILE *file;
  int k = 0;
  file = fopen ("library.txt", "r");
  if (file == NULL)
  {
    printf("The file is not exist");
    exit(1);
  }
  
  while (fscanf(file, "%s%s%d", b[k].title, b[k].author, &b[k].ISBN) != EOF)
  {
    k++;
  }
  if (k == 0)
  {
    printf("No books available");
  }

  for (int i = 0; i < k; i++)
  {
    
     if (strcmp(b[i].author, n) == 0)
     {
         printf("Title = %s\n author = %s\n ISBN = %d\n",  b[i].title, b[i].author, b[i].ISBN);
     }
       
  }
  fclose(file);
}

