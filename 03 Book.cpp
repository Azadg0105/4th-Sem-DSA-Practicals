#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct node
{
  char name[20];
  node *next;
  node *down;
  int flag;
};

class Gll
{
  char ch[20];
  int n, i;
  node *head = NULL, *temp = NULL, *t1 = NULL, *t2 = NULL;
  
  public:
  node * create ();
  void insertb ();
  void insertc ();
  void inserts ();
  void insertss ();
  void displayb ();
};

node *Gll::create ()
{
  node *p = new (struct node);
  p->next = NULL;
  p->down = NULL;
  p->flag = 0;
  cout << "\n Enter the Name: ";
  cin >> p->name;
  return p;
}

void Gll::insertb ()
{
  if (head == NULL)
    {
      t1 = create ();
      head = t1;
    }
  else
    {
      cout << "\n Book Exist!";
    }
}

void Gll::insertc ()
{
  if (head == NULL)
    {
      cout << "\n There is No Book: ";
    }
  else
    {
      cout << "\n How many Chapters you want to Insert: ";
      cin >> n;
      for (i = 0; i < n; i++)
	{
	  t1 = create ();
	  if (head->flag == 0)
	    {
	      head->down = t1;
	      head->flag = 1;
	    }
	  else
	    {
	      temp = head;
	      temp = temp->down;
	      while (temp->next != NULL)
		temp = temp->next;
	      temp->next = t1;
	    }
	}
    }
}

void Gll::inserts ()
{

  if (head == NULL)
    {
      cout << "\n There is no Book!";
    }
  else
    {
      cout <<
	"\n Enter the name of Chapter on which  you want to Enter the Section: ";
      cin >> ch;
      temp = head;
      if (temp->flag == 0)
	{
	  cout << "\n Their are no Chapters on in Book!";
	}
      else
	{
	  temp = temp->down;
	  while (temp != NULL)
	    {
	      if (!strcmp (ch, temp->name))
		{
		  cout << "\n How many Sections you want to Enter: ";
		  cin >> n;
		  for (i = 0; i < n; i++)
		    {
		      t1 = create ();
		      if (temp->flag == 0)
			{
			  temp->down = t1;
			  temp->flag = 1;
			  cout << "\n****";
			  t2 = temp->down;
			}
		      else
			{
			  cout << "\n#####";
			  while (t2->next != NULL)
			    {
			      t2 = t2->next;
			    }
			  t2->next = t1;
			}
		    }
		  break;
		}
	      temp = temp->next;
	    }
	}
    }
}

void Gll::insertss ()
{
  if (head == NULL)
    {
      cout << "\n There is no Book!";
    }
  else
    {
      cout <<
	"\n Enter the name of Chapter on which you want to Enter the Section: ";
      cin >> ch;
      temp = head;
      if (temp->flag == 0)
	{
	  cout << "\n Their are no Chapters on in Book!";
	}
      else
	{
	  temp = temp->down;
	  while (temp != NULL)
	    {
	      if (!strcmp (ch, temp->name))
		{
		  cout <<
		    "\n Enter name of Section in which you want to Enter the Sub Section: ";
		  cin >> ch;
		  if (temp->flag == 0)
		    {
		      cout << "\n Their are no Sections!";
		    }

		  else
		    {
		      temp = temp->down;
		      while (temp != NULL)
			{
			  if (!strcmp (ch, temp->name))
			    {
			      cout <<
				"\n How many Subsections you want to Enter: ";
			      cin >> n;
			      for (i = 0; i < n; i++)
				{
				  t1 = create ();
				  if (temp->flag == 0)
				    {
				      temp->down = t1;
				      temp->flag = 1;
				      cout << "\n****";
				      t2 = temp->down;
				    }
				  else
				    {
				      cout << "\n#####";
				      while (t2->next != NULL)
					{
					  t2 = t2->next;
					}
				      t2->next = t1;
				    }
				}
			      break;
			    }
			  temp = temp->next;
			}
		    }
		}
	      temp = temp->next;
	    }
	}
    }
}

void Gll::displayb ()
{
  if (head == NULL)
    {
      cout << "\n Book does not Exist!";
    }
  else
    {
      temp = head;
      cout << "\n NAME OF THE BOOK:  " << temp->name;
      if (temp->flag == 1)
	{
	  temp = temp->down;

	  while (temp != NULL)
	    {
	      cout << "\n\t\tNAME OF THE CHAPTER:  " << temp->name;
	      t1 = temp;
	      if (t1->flag == 1)
		{
		  t1 = t1->down;
		  while (t1 != NULL)
		    {
		      cout << "\n\t\t\t\tNAME OF THE SECTION:  " << t1->name;
		      t2 = t1;
		      if (t2->flag == 1)
			{
			  t2 = t2->down;
			  while (t2 != NULL)
			    {
			      cout << "\n\t\t\t\t\t\tNAME OF THE SUBSECTION:  " <<t2->name;
			      t2 = t2->next;
			    }
			}
		      t1 = t1->next;
		    }
		}
	      temp = temp->next;
	    }

	}
    }
}

int main ()
{
  Gll g;
  int x;
  while (1)
    {
      cout << "\n\n --- MAIN MENU ---";
      cout << "\n 1. Insert Book";
      cout << "\n 2. Insert Chapter";
      cout << "\n 3. Insert Section";
      cout << "\n 4. Insert Subsection";
      cout << "\n 5. Display Book";
      cout << "\n 6. Exit";
      cout << "\n Enter Your Choice: ";
      cin >> x;
      switch (x)
	{
	case 1:
	  g.insertb ();
	  break;
	case 2:
	  g.insertc ();
	  break;
	case 3:
	  g.inserts ();
	  break;
	case 4:
	  g.insertss ();
	  break;
	case 5:
	  g.displayb ();
	  break;
	case 6:
	  exit (0);
	}
    }
  return 0;
}
