#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Color
{
    RED,
    BLACK
} Color;

typedef struct LineNumber
{
    int line;
    struct LineNumber *next;
} LineNumber;

typedef struct Node
{
    char word[100];
    struct Node *parent;
    struct Node *left;
    struct Node *right;
    LineNumber *lines;
    Color color;
} Node;

Node *createNode(char *word, int line)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->lines = (LineNumber *)malloc(sizeof(LineNumber));
    newNode->lines->line = line;
    newNode->lines->next = NULL;
    newNode->color = RED;
    return newNode;
}

void insertNode(Node **root, char *word, int line);
Node *searchNode(Node *root, char *word);
void deleteNode(Node **root, char *word, int line);
void printTree(Node *root);
void printWordLines(Node *node);
void freeTree(Node *root);

Node *grandparent(Node *node)
{
    if (node != NULL && node->parent != NULL)
    {
        return node->parent->parent;
    }
    else
    {
        return NULL;
    }
}

Node *uncle(Node *node)
{
    Node *gp = grandparent(node);
    if (gp == NULL)
    {
        return NULL;
    }
    if (node->parent == gp->left)
    {
        return gp->right;
    }
    else
    {
        return gp->left;
    }
}

void rotate_left(Node **root, Node *node)
{
    Node *right = node->right;
    node->right = right->left;
    if (right->left != NULL)
    {
        right->left->parent = node;
    }
    right->parent = node->parent;
    if (node->parent == NULL)
    {
        *root = right;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = right;
    }
    else
    {
        node->parent->right = right;
    }
    right->left = node;
    node->parent = right;
}

void rotate_right(Node **root, Node *node)
{
    Node *left = node->left;
    node->left = left->right;
    if (left->right != NULL)
    {
        left->right->parent = node;
    }
    left->parent = node->parent;
    if (node->parent == NULL)
    {
        *root = left;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = left;
    }
    else
    {
        node->parent->right = left;
    }
    left->right = node;
    node->parent = left;
}

void insert_case1(Node **root, Node *node);
void insert_case2(Node **root, Node *node);
void insert_case3(Node **root, Node *node);
void insert_case4(Node **root, Node *node);
void insert_case5(Node **root, Node *node);

void insertNode(Node **root, char *word, int line)
{
    Node *newNode = createNode(word, line);

    if (*root == NULL)
    {
        *root = newNode;
        newNode->color = BLACK;
    }
    else
    {
        Node *parent = NULL;
        Node *current = *root;

        while (current != NULL)
        {
            parent = current;
            int cmp = strcmp(word, current->word);
            if (cmp < 0)
            {
                current = current->left;
            }
            else if (cmp > 0)
            {
                current = current->right;
            }
            else
            {
                newNode->lines->next = current->lines;
                current->lines = newNode->lines;
                free(newNode);
                return;
            }
        }

        if (strcmp(word, parent->word) < 0)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
        newNode->parent = parent;

        insert_case1(root, newNode);
    }
}

void insert_case1(Node **root, Node *node)
{
    if (node->parent == NULL)
    {
        node->color = BLACK;
    }
    else
    {
        insert_case2(root, node);
    }
}

void insert_case2(Node **root, Node *node)
{
    if (node->parent->color == BLACK)
    {
        return;
    }
    else
    {
        insert_case3(root, node);
    }
}

void insert_case3(Node **root, Node *node)
{
    Node *u = uncle(node);
    Node *gp;

    if ((u != NULL) && (u->color == RED))
    {
        node->parent->color = BLACK;
        u->color = BLACK;
        gp = grandparent(node);
        gp->color = RED;
        insert_case1(root, gp);
    }
    else
    {
        insert_case4(root, node);
    }
}

void insert_case4(Node **root, Node *node)
{
    Node *gp = grandparent(node);

    if ((node == node->parent->right) && (node->parent == gp->left))
    {
        rotate_left(root, node->parent);
        node = node->left;
    }
    else if ((node == node->parent->left) && (node->parent == gp->right))
    {
        rotate_right(root, node->parent);
        node = node->right;
    }

    insert_case5(root, node);
}

void insert_case5(Node **root, Node *node)
{
    Node *gp = grandparent(node);
    node->parent->color = BLACK;
    gp->color = RED;
    if ((node == node->parent->left) && (node->parent == gp->left))
    {
        rotate_right(root, gp);
    }
    else
    {
        rotate_left(root, gp);
    }
}

Node *searchNode(Node *root, char *word)
{
    if (root == NULL || strcmp(word, root->word) == 0)
    {
        return root;
    }

    if (strcmp(word, root->word) < 0)
    {
        return searchNode(root->left, word);
    }
    else
    {
        return searchNode(root->right, word);
    }
}

void removeLine(Node *node, int line)
{
    LineNumber *current = node->lines;
    LineNumber *prev = NULL;

    while (current != NULL)
    {
        if (current->line == line)
        {
            if (prev == NULL)
            {
                node->lines = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
}

void delete_case1(Node **root, Node *node);
void delete_case2(Node **root, Node *node);
void delete_case3(Node **root, Node *node);
void delete_case4(Node **root, Node *node);
void delete_case5(Node **root, Node *node);
void delete_case6(Node **root, Node *node);

void deleteNode(Node **root, char *word, int line)
{
    Node *node = searchNode(*root, word);
    if (node == NULL)
    {
        return;
    }

    removeLine(node, line);

    if (node->lines == NULL)
    {
        Node *child;
        if (node->left != NULL)
        {
            child = node->left;
        }
        else
        {
            child = node->right;
        }

        if (node->color == BLACK)
        {
            node->color = child->color;
            delete_case1(root, node);
        }

        if (node->parent == NULL)
        {
            *root = child;
        }
        else
        {
            if (node == node->parent->left)
            {
                node->parent->left = child;
            }
            else
            {
                node->parent->right = child;
            }
        }

        if (child != NULL)
        {
            child->parent = node->parent;
        }

        free(node);
    }
}

void delete_case1(Node **root, Node *node)
{
    if (node->parent == NULL)
    {
        return;
    }
    else
    {
        delete_case2(root, node);
    }
}

void delete_case2(Node **root, Node *node)
{
    Node *sibling = NULL;
    if (node == node->parent->left)
    {
        sibling = node->parent->right;
    }
    else
    {
        sibling = node->parent->left;
    }

    if (sibling->color == RED)
    {
        node->parent->color = RED;
        sibling->color = BLACK;
        if (node == node->parent->left)
        {
            rotate_left(root, node->parent);
        }
        else
        {
            rotate_right(root, node->parent);
        }
    }

    delete_case3(root, node);
}

void delete_case3(Node **root, Node *node)
{
    Node *sibling = NULL;
    if (node == node->parent->left)
    {
        sibling = node->parent->right;
    }
    else
    {
        sibling = node->parent->left;
    }

    if ((node->parent->color == BLACK) && (sibling->color == BLACK) && (sibling->left->color == BLACK) &&
        (sibling->right->color == BLACK))
    {
        sibling->color = RED;
        delete_case1(root, node->parent);
    }
    else
    {
        delete_case4(root, node);
    }
}

void delete_case4(Node **root, Node *node)
{
    Node *sibling = NULL;
    if (node == node->parent->left)
    {
        sibling = node->parent->right;
    }
    else
    {
        sibling = node->parent->left;
    }

    if ((node->parent->color == RED) && (sibling->color == BLACK) && (sibling->left->color == BLACK) &&
        (sibling->right->color == BLACK))
    {
        sibling->color = RED;
        node->parent->color = BLACK;
    }
    else
    {
        delete_case5(root, node);
    }
}

void delete_case5(Node **root, Node *node)
{
    Node *sibling = NULL;
    if (node == node->parent->left)
    {
        sibling = node->parent->right;
    }
    else
    {
        sibling = node->parent->left;
    }

    if (sibling->color == BLACK)
    {
        if ((node == node->parent->left) && (sibling->right->color == BLACK) && (sibling->left->color == RED))
        {
            sibling->color = RED;
            sibling->left->color = BLACK;
            rotate_right(root, sibling);
        }
        else if ((node == node->parent->right) && (sibling->left->color == BLACK) && (sibling->right->color == RED))
        {
            sibling->color = RED;
            sibling->right->color = BLACK;
            rotate_left(root, sibling);
        }
    }

    delete_case6(root, node);
}

void delete_case6(Node **root, Node *node)
{
    Node *sibling = NULL;
    if (node == node->parent->left)
    {
        sibling = node->parent->right;
    }
    else
    {
        sibling = node->parent->left;
    }

    sibling->color = node->parent->color;
    node->parent->color = BLACK;

    if (node == node->parent->left)
    {
        sibling->right->color = BLACK;
        rotate_left(root, node->parent);
    }
    else
    {
        sibling->left->color = BLACK;
        rotate_right(root, node->parent);
    }
}

void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->left);
    printf("%s: ", root->word);
    printWordLines(root);
    printf("\n");
    printTree(root->right);
}

void printWordLines(Node *node)
{
    LineNumber *current = node->lines;
    while (current != NULL)
    {
        printf("%d ", current->line);
        current = current->next;
    }
}

void freeTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    LineNumber *current = root->lines;
    while (current != NULL)
    {
        LineNumber *temp = current;
        current = current->next;
        free(temp);
    }
    free(root);
}

int main()
{
    FILE *file;
    char filename[100];
    char word[100];
    int line = 1;
    Node *root = NULL;

    file = fopen("texto.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fscanf(file, "%s", word) != EOF)
    {
        insertNode(&root, word, line);
        char c;
        while ((c = fgetc(file)) != '\n' && c != EOF)
        {
            // Ler até o final da linha
        }
        line++;
    }

    fclose(file);

    printf("Palavras encontradas:\n");
    printTree(root);

    char searchWord[100];
    printf("\nDigite a palavra que deseja buscar: ");
    scanf("%s", searchWord);

    Node *searchResult = searchNode(root, searchWord);
    if (searchResult != NULL)
    {
        printf("A palavra '%s' foi encontrada nas linhas: ", searchWord);
        printWordLines(searchResult);
        printf("\n");
    }
    else
    {
        printf("A palavra '%s' não foi encontrada.\n", searchWord);
    }

    char deleteWord[100];
    int deleteLine;
    printf("\nDigite a palavra que deseja excluir: ");
    scanf("%s", deleteWord);
    printf("Digite o número da linha: ");
    scanf("%d", &deleteLine);

    deleteNode(&root, deleteWord, deleteLine);

    char addWord[100];
    int addLine;
    printf("\nDigite a palavra que deseja acrescentar: ");
    scanf("%s", addWord);

    printf("Digite o número da linha: ");
    scanf("%d", &addLine);

    insertNode(&root, addWord, addLine);

    printf("\nPalavras atualizadas:\n");
    printTree(root);

    freeTree(root);

    return 0;
}
