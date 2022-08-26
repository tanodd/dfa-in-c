#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <conio.h>
// #include <ctype.h>

/**
 * @id: id cua trang thai
 * @flag_end: flag trang thai cuoi -- 1 true -- o false
 * @link0: dia chi trang thai neu input la 0
 * @link1: dia chi trang thai neu input la 1
 */
struct node
{
  int id;
  int flag_end;
  struct node *link0;
  struct node *link1;
};

struct node *start, *q, *ptr;
int vst_arr[100], a[10];
int main()
{
  int count, i, posi, j, loop;
  char n[100];
  printf("\n\n");
  printf("\t---------------------------------------------------------------------------------\n");
  printf("\t|\tCHUONG TRINH MO PHONG HOAT DONG CUA OTOMAT HUU HAN DON DINH\t\t|\n");
	printf("\t|\tHo va ten: NGUYEN KIM THANH TAN - 19T1021229\t\t\t\t|\n");
  printf("\t|\tGiao vien huong dan: NGUYEN THI BICH LOC \t\t\t\t|\n");
  printf("\t---------------------------------------------------------------------------------\n");
  

  printf("\n");
  printf("\t\tHay nhap so luong cua tap trang thai Q\n\t\t");
  scanf("%d", &count);

  q = (struct node *)malloc(sizeof(struct node) * count); // Cap phat dong cho bo nho cho q

  for (i = 0; i < count; i++)
  {
    (q + i)->id = i;

    printf("\t\tTrang thai q%d\n", i);
    printf("\t\tTrang thai tiep theo neu dau vao la 0: \t\t");
    scanf("%d", &posi);
    (q + i)->link0 = (q + posi);

    printf("\t\tTrang thai tiep theo neu dau vao la 1: \t\t");
    scanf("%d", &posi);
    (q + i)->link1 = (q + posi);

    printf("\t\tTrang thai nay co thuoc trang thai ket thuc?\n\t\t");
    scanf("%d", &(q + i)->flag_end);
  }

  printf("\t\tHay nhap ten trang thai dau:\n\t\t");
  scanf("%d", &posi); 
  start = q + posi;
  printf("\t\t---------------------------------\n");



    ptr = start;
    printf("\t\tHay nhap xau dau vao \n\t\t");
    scanf("%s", n);
    posi = 0;
    system("cls");

    while (n[posi] != '\0')
    {
      a[posi] = (n[posi] - '0');
      posi++;
    }
    i = 0;
    

    // Display result
    printf("\t\t");
    for (loop = 0; loop < strlen(n); loop++)
    {
      printf("[%d]    ", a[loop]);
    }
    printf("\n");
    printf("\t\t");
    for (loop = 0; loop < strlen(n); loop++)
    {
    
      printf(" ^     ");
    }
    printf("\n");
    printf("\t\t");
    for (loop = 0; loop < strlen(n); loop++)
    {
      printf(" |     ");
    }
    printf("\n");
    printf("\t\t");
    do
    {
      vst_arr[i] = ptr->id;
      if (a[i] == 0)
      {
        ptr = ptr->link0;
      }
      else if (a[i] == 1)
      {
        ptr = ptr->link1;
      }
      else
      {
        system("cls");
        printf("\t\t dau vao sai!\n"); // Kiem tra chuoi dau vao gia tri khac 0 hoac 1 hay khong
        return 0;
      }
      printf("[q%d]-->", vst_arr[i]);
      i++;
    } while (i < posi);
    //***********************************************
    printf("[q%d]", ptr->id);
    if (ptr->flag_end == 1)
      printf(" thuoc F");
    else
      printf(" khong thuoc F");
    printf("\n");
    printf("\n");
    if (ptr->flag_end == 1)
    {
      printf("\t\tDOAN NHAN xau %s\n", n);
      getch();  
      return 1;
    }
    else
    {
      printf("\t\tKHONG doan nhan xau %s\n", n);
      getch();  
      return 0;
    }

}
