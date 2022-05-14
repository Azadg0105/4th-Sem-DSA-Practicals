#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
} * temp, *head[100], *new_node;

class Graph
{
    int adj[40][40];
    int n;
    int i, j;
    char ch;

public:
    void Adj_Mat();

    void Adj_List();

    void Dispaly_Mat();

    void print_list();
};

void Graph::Adj_Mat()
{
    cout << "Enter no of vertex" << endl;
    cin >> n;

    // It will make all positions 0 initially...
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            adj[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {

            if (adj[i][j] == -1)
            {

                cout << "Do you want edge from " << i << " to " << j << "yes(y)/no(n)" << endl;
                cin >> ch;

                if (ch == 'y')
                {

                    adj[i][j] = 1;
                    adj[j][i] = 1;
                }
                else
                {

                    adj[i][j] = 0;
                    adj[j][i] = 0;
                }
            }

            else if (adj[i][j] == 1)
            {

                cout << " As it is a undirected graph there is already a edge from " << i << " to " << j << " as specified earlier...\n";
                cout << endl;
            }
            else
            {

                cout << "As specified earlier, There is no edge from " << i << " to " << j << endl
                     << endl;
            }
        }
    }

    Adj_List();
}

void Graph::Adj_List()
{

    for (int i = 0; i < n; i++)
    {
        new_node = new Node;
        new_node->data = i;
        new_node->next = NULL;
        head[i] = new_node;
        temp = head[i];

        for (int j = 0; j < n; j++)
        {

            if (adj[i][j] == 1)
            {

                new_node = new Node;

                new_node->data = j;
                new_node->next = NULL;

                if (head[i]->next == NULL)
                {
                    head[i]->next = new_node;
                }
                else
                {

                    //  temp = head[i];

                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }

                    temp->next = new_node;
                }
            }
        }
    }
    // print_list();
}

void Graph::Dispaly_Mat()
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            cout << " " << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::print_list()
{
    for (int i = 0; i < n; i++)
    {

        if (head[i] == NULL)
        {
            cout << "List is Empty\n";
            break;
        }
        else
        {
            cout << head[i]->data << ": ";

            Node *temp = head[i];

            temp = temp->next;

            while (temp != NULL)
            {

                cout << temp->data << " -> ";
                temp = temp->next;
            }

            cout << "NULL\n";
        }
    }
}

int main()
{
    Graph G;
    int choice = 0;

    while (choice != 4)
    {
        cout << "-------------------------------------------------------------------------------------------\n";
        cout << "Menu:\n";
        cout << "1. Input the Values of Graph\n";
        cout << "2. Adjacency Matrix Representation of Graph\n";
        cout << "3. Adjacency List Represention of Graph\n";
        cout << "4. Exit\n";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "-------------------------------------------------------------------------------------------\n";
            G.Adj_Mat();
            break;
        case 2:
            cout << "-------------------------------------------------------------------------------------------\n";
            cout << "Matrix Representation of Graph:\n\n";
            G.Dispaly_Mat();
            break;
        case 3:
            cout << "-------------------------------------------------------------------------------------------\n";
            cout << "List Representation of Graph:\n\n";
            G.print_list();
            break;
        case 4:
            cout << "-------------------------------------------------------------------------------------------\n";
            cout << "Closing Program\n";
            cout << "-------------------------------------------------------------------------------------------\n";
            exit(0);
        default:
            cout << "-------------------------------------------------------------------------------------------\n";
            cout << "Invalid Input\nTry Again\n";
        }
    }

    return 0;
}