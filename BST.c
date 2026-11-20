  1  #include <stdio.h>
  2  #include <stdlib.h>
  3  struct Node {
  4   int data;
  5  struct Node *left, *right;
  6  };
  7   struct Node* newNode(int key) {
  8   struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  9   node->data = key;
 10    node->left = node->right = NULL;
 11    return node;
 12   }
 13    struct Node* insert(struct Node* root, int key) {
 14    if (root == NULL)
 15    return newNode(key);
 16    if (key < root->data)
 17    root->left = insert(root->left, key);
 18    else if (key > root->data)
 19    root->right = insert(root->right, key);
 20    else
 21    printf("%d already exists.\n", key);
 22    return root;
 23   }
 24   struct Node* minNode(struct Node* root) {
 25   while (root->left != NULL)
 26   root = root->left;
 27   return root;
 28  }
 29   struct Node* deleteNode(struct Node* root, int key) {
 30   if (root == NULL) {
 31   printf("%d not found.\n", key);
 32   return NULL;
 33  }
 34   if (key < root->data)
 35   root->left = deleteNode(root->left, key);
 36   else if (key > root->data)
 37   root->right = deleteNode(root->right, key); 
 38   else {
 39   if (root->left == NULL) {
 40   struct Node* temp = root->right;
 41   free(root);
 42   return temp;
 43  }
 44   if (root->right == NULL) {
 45   struct Node* temp = root->left;
 46   free(root);
 47   return temp;
 48   }
 49   struct Node* succ = minNode(root->right);
 50   root->data = succ->data;
 51   root->right = deleteNode(root->right, succ->data);
 52   }
 53   return root;
 54  }
 55  void inorder(struct Node* root) {
 56   if (root == NULL) return;
 57   inorder(root->left);
 58   printf("%d ", root->data);
 59   inorder(root->right);
 60  } void preorder(struct Node* root) {
 61   if (root == NULL) return;
 62   printf("%d ", root->data);
 63   preorder(root->left);
 64   preorder(root->right);
 75  }
 76  void postorder(struct Node* root) {
 77   if (root == NULL) return;
 78   postorder(root->left);
 79   postorder(root->right);
 80   printf("%d ", root->data);
 81  }
 82  int main() {
 83  struct Node* root = NULL;
 84  int choice, value;
 85  while (1) {
 86  printf("\n--- Binary Search Tree ---\n");
 87  printf("1. Insert\n");
 88  printf("2. Delete\n");
 89  printf("3. Inorder\n");
 90  printf("4. Preorder\n");
 91  printf("5. Postorder\n");
 92    printf("6. Exit\n");
 93    printf("Enter choice: ");
 94  scanf("%d", &choice);
 95  switch (choice) {
 96  case 1:
 97  printf("Enter value to insert: ");
 98  scanf("%d", &value);
 99  root = insert(root, value);
100   break;
101  case 2:
102 printf("Enter value to delete: ");
103  scanf("%d", &value);
104  root = deleteNode(root, value);
105 break;
106 case 3:
107 printf("Inorder: ");
108 inorder(root);
109 printf("\n");
110 break;
111 case 4:
112 printf("Preorder: ");
113 preorder(root);
114 printf("\n");
115 break;
116 case 5:
117 printf("Postorder: ");
118 postorder(root);
119 printf("\n");
120 break;
121 case 6:
122 return 0;
123 default:
124 printf("Invalid choice.\n");
125  }
126  }
127 }