












































 1 #include<stdio.h>
  2 #define SIZE 9
  3 typedef struct{unsigned char x:1;}bit;
  4 /* universal set (hardcode)*/
  5 const int uset[SIZE]={1,2,3,4,5,6,7,8,9};
  6 void readset(bit a[],int n);
  7 void printset(const bit a[]);
  8 void unionset(const bit a[],const bit b[],bit c[]);
  9 void intersect(const bit a[],const bit b[],bit c[]);
 10 void difference(const bit a[],const bit b[],bit c[]);
 11 int main(void)
 12 {
 13     bit a[SIZE]={{0}},b[SIZE]={{0}},c[SIZE]={{0}};
 14     int n;
 15     printf("universal set:{1,2,3,4,5,6,7,8,9}\n\n");
 16     printf(" no.of elements in set A:");
 17     if(scanf("%d",&n)!=1)return 1;
 18     readset(a,n);
 19     printf("no.of elements in set B:");
 20     if(scanf("%d",&n)!=1)return 1;
 21     readset(b,n);
 22     printf("\n set A:");
 23     printset(a);
 24     printf("set B: ");
 25     printset(b);
 26     unionset(a,b,c);
 27     printf("\n\tA union B = ");
 28     printset(c);
 29     intersect(a,b,c);
 30     printf("\n\tA intersect B = ");
 31     printset(c);
 32     difference(a,b,c);
 33     printf("\n\tA-B=");
 34     printset(c);
 35     return 0;
 36 }
 37 /* Read n elements of a subset and store as a bit string*/
 38 void readset(bit a[],int n)
 39 {
 40     int i,k,x;
 41     if(n<0||n>SIZE){
 42         printf("Invalid size; must be between 0 and %d \n",SIZE);
 43         return;
 44     }
 45     printf("enter %d elements:",n);
 46     for(i=0;i<n;i++){
 47         if(scanf("%d",&x)!=1)return;
 48         for(k=0;k<SIZE;k++){
 49                 if(uset[k]==x){a[k].x=1;break;}
 50         }
  51         if (k==SIZE)
 52             printf("%d is not in the universal set, ignored.\n",x);
 53     }
 54 }
 55 /*print a set from its bit string representation*/
 56 void printset(const bit a[])
 57 {
 58      int k,first=1;
 59      printf("{");
 60      for(k=0;k<SIZE;k++){
 61         if(a[k].x){
 62            printf(first? "%d":",%d",uset[k]);
 63            first=0;
 64         }
 65     }
 66     printf("}\n");
 67 }
 68 void unionset(const bit a[],const bit b[],bit c[])
 69 {
 70     for(int k=0;k<SIZE;k++)
 71         c[k].x=a[k].x|b[k].x;
 72 }
 73 void intersect(const bit a[],const bit b[],bit c[])
 74 {
 75     for(int k=0;k<SIZE;k++)
 76     c[k].x=a[k].x&b[k].x;
 77 }
 78 void difference(const bit a[],const bit b[],bit c[])
 79 {
 80     for(int k=0;k<SIZE;k++)
 81         c[k].x=a[k].x&&!b[k].x;
 82 }

OUTPUT

no.of elements in set A:4
enter 4 elements:1 2 3 4
no.of elements in set B:6
enter 6 elements:1 2 3 4 5 6

 set A:{1,2,3,4}
set B: {1,2,3,4,5,6}

        A union B = {1,2,3,4,5,6}

        A intersect B = {1,2,3,4}

        A-B={}
