#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class Tree
{
public:
    
    node *create(int a)
    {
            node *root = new node;
            cout<<"Enter value for root : ";
            cin>>a;
            root->data = a;
            root->left = NULL;
            root->right = NULL;
    }

    void insertnode(node *root, int a)
    {
        node *child = new node;
        child->data = a;
        child->left = NULL;
        child->right = NULL;

        if (root->data > a)
        {
            if (root->left == NULL)
            {
                root->left = child;
            }
            else
            {
                insertnode(root->left, a);
            }
        }
        else if (root->data < a)
        {
            if (root->right == NULL)
            {
                root->right = child;
            }
            else
            {
                insertnode(root->right, a);
            }
        }
    }

    void displayInorder(node *root)
    {
        if(root != NULL)
        {
            displayInorder(root->left);
            cout << " " << root->data;
            displayInorder(root->right);
        }
    }

    void displayPreorder(node *root)
    {
        if(root != NULL)
        {
            cout << " " << root->data;
            displayPreorder(root->left);
            displayPreorder(root->right);
        }
    }

    void displayPostorder(node *root)
    {
        if(root != NULL)
        {
            displayPostorder(root->left);
            displayPostorder(root->right);
            cout << " " << root->data;
        }
    }

    int longestPath(node *root)
    {
        if (root==NULL)
            return 0;
        int Lctr= longestPath(root->left);
        int Rctr= longestPath(root->right);
        if(Lctr>Rctr)
            return (Lctr+1);
        else return (Rctr+1);
    }

    void minimum(node *root)
    {
        while(root->left != NULL)
        {
            root = root->left;
        }
        cout<<"\nMinimum number is : "<<root->data;
    }

     void search(node *root, int searchKey)
    {
        if(searchKey<root->data)
        {
            if(root->left==NULL)
                cout<<"\nNumber not found !! ";
            else
                search(root->left, searchKey);
        }
        else if(searchKey>(root->data))
        {
            if(root->right==NULL)
                cout<<"\nNumber not found !! ";
           else
                search(root->right, searchKey);
        }
        else if(searchKey==(root->data))
        {
            cout<<"\nNumber Found ";
        }
    }

    node *swapNodes(node *root)
    {
        node* temp;
        if(root==NULL)
            return NULL;
            
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        
        swapNodes(root->left);
        swapNodes(root->right);
    }


};

int main()
{
    int ch, a, flag=0;
    Tree obj;
    node *root;
    do
    {
        cout << "\n--------------------";
        cout << "\nBinary Search Tree";
        cout << "\n--------------------";
        cout << "\n1.Insert New Node";
        cout << "\n2.Number of Nodes of Longest Path";
        cout << "\n3.Minimum Data Value in Tree";
        cout << "\n4.Swap";
        cout << "\n5.Search";
        cout << "\n6.Display";
        cout << "\n7.Exit";
        cout << "\nEnter Choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if(flag==0)
            {
                root=obj.create(a);
                flag=1;
            }
            else
            {
                cout<<"Enter the data to be entered : ";
                cin>>a;
                obj.insertnode(root,a);
            }
            break;
    
        case 2:
            cout<<"The height of tree of longest path is : "<<obj.longestPath(root);
            break;

        case 3:
        obj.minimum(root);
            break;

        case 4:
        obj.swapNodes(root);
            break;

        case 5:
            int key;
            cout<<"Enter the Number to be Searched : ";
            cin>>key;
            obj.search(root,key);
            break;            

        case 6:
            cout<<"\n1.Pre-Order";
            cout<<"\n2.In-Order";
            cout<<"\n3.Post-Order";
            cout<<"\nEnter Choice : ";
            cin>>a;
            if(a==1)
            {
                obj.displayPreorder(root);
            }
            else if(a==2)
            {
                obj.displayInorder(root);            }
            else if(a==3)
            {
                obj.displayPostorder(root);
            }
            else
            {
                cout<<"\nInvalid Input";
            }
            break;

        case 7:
            exit(0);

        default:
            cout<<"\nInvalid Input";
            break;
        }
    }while(ch!=0);
    return 0;
}