  1
  2 #include <stdio.h>
  3 #include <stdlib.h>
  4
  5 struct node {
  6     int data;
  7     struct node *prev;
  8     struct node *next;
  9 };
 10
 11 struct node *head = NULL, *tail = NULL;
 12
 13 void insert_begin() {
 14     struct node *newnode;
 15     newnode = (struct node *)malloc(sizeof(struct node));
 16
 17     if (newnode == NULL) {
 18         printf("Memory allocation failed.\n");
 19         return;
 20     }
 21
 22     printf("Enter data: ");
 23     scanf("%d", &newnode->data);
 24
 25     newnode->prev = NULL;
 26     newnode->next = head;
 27
 28     if (head == NULL)
 29         head = tail = newnode;
 30     else {
 31         head->prev = newnode;
 32         head = newnode;
 33     }
 34
 35     printf("Node inserted at beginning.\n");
 36 }
 37
 38 void insert_end() {
 39     struct node *newnode;
 40     newnode = (struct node *)malloc(sizeof(struct node));
 41
 42     if (newnode == NULL) {
 43         printf("Memory allocation failed.\n");
 44         return;
 45     }
 46
 47     printf("Enter data: ");
 48     scanf("%d", &newnode->data);
 49
 50     newnode->next = NULL;
   51     newnode->prev = tail;
 52
 53     if (tail == NULL)
 54         head = tail = newnode;
 55     else {
 56         tail->next = newnode;
 57         tail = newnode;
 58     }
 59
 60     printf("Node inserted at end.\n");
 61 }
 62
 63 void display_forward() {
 64     struct node *temp = head;
 65
 66     if (head == NULL) {
 67         printf("List is empty.\n");
 68         return;
 69     }
 70
 71     printf("Forward: ");
 72     while (temp != NULL) {
 73         printf("%d <-> ", temp->data);
 74         temp = temp->next;
 75     }
 76     printf("NULL\n");
 77 }
 78
 79 void delete_node() {
 80     struct node *temp;
 81     int value;
 82
 83     if (head == NULL) {
 84         printf("List is empty.\n");
 85         return;
 86     }
 87
 88     printf("Enter value to delete: ");
 89     scanf("%d", &value);
 90
 91     temp = head;
 92
 93     while (temp != NULL && temp->data != value)
 94         temp = temp->next;
 95
 96     if (temp == NULL) {
 97         printf("Node not found.\n");
 98         return;
 99     }
 100
101     if (temp->prev != NULL)
102         temp->prev->next = temp->next;
103     else
104         head = temp->next;
105
106     if (temp->next != NULL)
107         temp->next->prev = temp->prev;
108     else
109         tail = temp->prev;
110
111     free(temp);
112
113     printf("Node deleted successfully.\n");
114 }
115
116 void display_reverse() {
117     struct node *temp = tail;
118
119     if (tail == NULL) {
120         printf("List is empty.\n");
121         return;
122     }
123
124     printf("Reverse: ");
125     while (temp != NULL) {
126         printf("%d <-> ", temp->data);
127         temp = temp->prev;
128     }
129     printf("NULL\n");
130 }
131
132 int main() {
133     int choice;
134
135     do {
136         printf("\n--- DOUBLY LINKED LIST ---\n");
137         printf("1. Insert at beginning\n");
138         printf("2. Insert at end\n");
139         printf("3. Display forward\n");
140         printf("4. Delete a node\n");
141         printf("5. Display reverse\n");
142         printf("6. Exit\n");
143         printf("Enter your choice: ");
144         scanf("%d", &choice);
145
146         switch (choice) {
147             case 1:
148                 insert_begin();
149                 break;
150
151             case 2:
152                 insert_end();
153                 break;
154
155             case 3:
156                 display_forward();
157                 break;
158
159             case 4:
160                 delete_node();
161                 break;
162
163             case 5:
164                 display_reverse();
165                 break;
166
167             case 6:
168                 printf("Program terminated.\n");
169                 break;
170
171             default:
172                 printf("Invalid choice.\n");
173         }
174
175     } while (choice != 6);
176
177     return 0;
178 }


OUTPUT  
--- DOUBLY LINKED LIST ---
1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter your choice: 3
Forward: 2 <-> 4 <-> NULL

--- DOUBLY LINKED LIST ---
1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter your choice: 4
Enter value to delete: 2
Node deleted successfully.

--- DOUBLY LINKED LIST ---
1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter your choice: 5
Reverse: 4 <-> NULL

--- DOUBLY LINKED LIST ---
1. Insert at beginning
2. Insert at end
3. Display forward
4. Delete a node
5. Display reverse
6. Exit
Enter your choice: 6
Program terminated.
                                                                                      