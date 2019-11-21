#include <iostream> 
#include <stack> 
#include <queue> 

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

//Allocates memory to and initilizes it
struct node *newnode(int data) {
    struct node *node;
    //node = new (sizeof(struct node));
    node = new (struct node);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

//Inorder traversal method using recursion
struct node* InOrderTraversalRecursion(struct node* root)
{
    if (root == NULL)
        return root;
    InOrderTraversalRecursion(root->left);
    cout<<root->data<<",";
    InOrderTraversalRecursion(root->right);
}

//Post order traversal method using recursion
struct node* PostOrderTraversalRecursion(struct node* root)
{
    if (root == NULL)
        return root;
    PostOrderTraversalRecursion(root->left);
    PostOrderTraversalRecursion(root->right);
    cout<<root->data<<",";
}

//Pre order traversal method using recursion
struct node* PreOrderTraversalRecursion(struct node* root)
{
    if (root == NULL)
        return root;
    cout<<root->data<<",";
    PreOrderTraversalRecursion(root->left);
    PreOrderTraversalRecursion(root->right);
}

void PrintAtGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        cout<<root->data<<", ";
    }
    else
    {
        PrintAtGivenLevel(root->left, level -1);
        PrintAtGivenLevel(root->right, level -1);
    }
}

//Level order traversal method using recursion
struct node* LevelOrderTraversalRecursion(struct node* root)
{
    int count = 0;
    struct node* temp = root;
    while (temp != NULL)
    {
        temp = temp->right;
        ++count;
        PrintAtGivenLevel(root, count);
        cout<<endl;
    }
}

//Inorder traversal iteratively 
struct node* InOrderTraversalItrative(struct node* root)
{
    struct node* temp = root;
    stack <node *> s1;
    while (temp != NULL || !s1.empty())
    {
        while(temp)
        {
            s1.push(temp);
            temp = temp->left;
        }
        temp = s1.top();
        s1.pop();
        cout<<temp->data<<",";
        temp = temp->right;
    }
}

//Preorder traversal iteratively 
struct node* PreOrderTraversalItrative(struct node* root)
{
    struct node* temp = root;
    stack <node *> s1;
    s1.push(temp);
    while (!s1.empty())
    {
        temp = s1.top();
        cout<<temp->data<<",";
        s1.pop();
        if (temp->right)
            s1.push(temp->right);
        if (temp->left)
            s1.push(temp->left);
    }
}

//Postorder traversal iteratively 
struct node* PostOrderTraversalItrative(struct node* root)
{
    struct node* temp = root;
    stack <node *> s1,s2;
    s1.push(temp);
    while (!s1.empty())
    {
        struct node* n1 = s1.top();
        s2.push(n1);
        s1.pop();
        if (n1->right)
            s1.push(n1->left);
        if (n1->left)
            s1.push(n1->right);
    }

    while (!s2.empty())
    {
        struct node* n2 = s2.top();
        cout<<n2->data<<",";
        s2.pop();
    }
}

struct node* LevelOrderTraversalUsingQueues(struct node* root)
{
    queue <struct node*> q1;
    struct node* temp = root;

    q1.push(temp);
    while (!q1.empty())
    {
        temp = q1.front();
        cout<<temp->data<<",";
        q1.pop();
        if (temp->left)
            q1.push(temp->left);
        if (temp->right)
            q1.push(temp->right);
    }
}

//Get InOrder Succesor 
struct node* GetMinValueNode(struct node* root)
{
    if (root != NULL && root->left != NULL)
        GetMinValueNode(root->left);
    return root;
}

//Get InOrder ansistor 
struct node* GetMaxValueNode(struct node* root)
{
    if (root != NULL && root->right != NULL)
        GetMaxValueNode(root->right);
    return root;
}

//Delete Node from BST
struct node* DeleteNode(struct node* root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data > data)
        root->left = DeleteNode(root->left, data);
    else if(root->data < data)
        root->right = DeleteNode(root->right, data);
    else 
    {
        struct node *temp;
        if (root->right == NULL)
        {
            temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL)
        {
            temp = root->right;
            delete root;
            return temp;
        }
#ifdef USINGMAX
        temp = GetMaxValueNode(root->left);
        root->data = temp->data;
        root->left = DeleteNode(root->left, temp->data);
#else
        temp = GetMinValueNode(root->right);
        root->data = temp->data;
        root->right = DeleteNode(root->right, temp->data);
#endif
    }
    return root;
}

//Search if given data is present or not in BST
struct node* Search(struct node* root, int data)
{
    if (root == NULL)
    {
        cout<<data<<" Not Found"<<endl;
        return NULL;
    }

    if (root->data == data)
    {
        cout<<data<<" Found"<<endl;
        return root;
    }
    else if (root->data > data)
    {
        Search(root->left, data);
    }
    else if (root->data < data)
    {
        Search(root->right, data);
    }
}

//Add node to BST
struct node* InsertNode(struct node* root, int data)
{
    if (root == NULL)
    {
        root = newnode(data);
    }

    if (root->data > data)
        root->left = InsertNode(root->left, data);
    else if (root->data < data)
        root->right = InsertNode(root->right, data);

    return root;
}

int main()
{
   /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 
   */

    struct node *root = NULL; 
    root = InsertNode(root, 50); 
    InsertNode(root, 30); 
    InsertNode(root, 20); 
    InsertNode(root, 40); 
    InsertNode(root, 70); 
    InsertNode(root, 60); 
    InsertNode(root, 80);
    cout<<endl<<"================ InOrder Traversal using Recursion ==================="<<endl;
    InOrderTraversalRecursion(root);
    cout<<endl<<"================ InOrder Traversal using Iteration ==================="<<endl;
    InOrderTraversalItrative(root);
    cout<<endl<<"================ Post Order Traversal using Recursion ==================="<<endl;
    PostOrderTraversalRecursion(root);
    cout<<endl<<"================ InOrder Traversal using Iteration ==================="<<endl;
    PostOrderTraversalItrative(root);
    cout<<endl<<"================ Pre Order Traversal using Recursion ==================="<<endl;
    PreOrderTraversalRecursion(root);
    cout<<endl<<"================ Pre Order Traversal using Iteration ==================="<<endl;
    PreOrderTraversalItrative(root);
    cout<<endl<<"================ Level Order Traversal using Recursion ==================="<<endl;
    LevelOrderTraversalRecursion(root);
    cout<<endl<<"================ Level Order Traversal Using Queue ==================="<<endl;
    LevelOrderTraversalUsingQueues(root);
    cout<<endl<<"========================================================================"<<endl;
    cout<<"Search OutPut"<<endl;
    Search(root, 10);
    Search(root, 40);
    cout<<"Deleting node 30"<<endl;
    root = DeleteNode(root, 30);
}
