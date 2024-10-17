#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
};


struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}


int search(struct node* root, int target) {
    if (root == NULL) {
        return 0; 
    }
    if (root->data == target) {
        return 1; 
    }
    if (target < root->data) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}


struct node* findMin(struct node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}


struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

      
        struct node* temp = findMin(root->right);
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    }
    return root;
}


void inOrderTraversal(struct node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}


int main() {
    struct node* root = NULL;
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display (In-Order Traversal)\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (search(root, data)) {
                    printf("%d is present in the tree.\n", data);
                } else {
                    printf("%d is not present in the tree.\n", data);
                }
                break;

            case 4:
                printf("In-Order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
