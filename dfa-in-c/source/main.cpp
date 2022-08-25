#include <stdio.h>
#include <stdlib.h>
#include <cstring>

/**
 * @id: id cua trang thai
 * @st_val: flag trang thai cuoi -- 1 true -- o false
 * @link0: dia chi trang thai neu input la 0
 * @link1: dia chi trang thai neu input la 1
 */
struct node
{
  int id_num;
  int st_val;
  struct node *link0;
  struct node *link1;
};

struct node *start, *q, *ptr;
int vst_arr[100], a[10];
int main()
{
  int count, i, posi, j;
  char n[10];

  printf("=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("Hay nhap so luong cua tap trang thai Q\n");
  scanf("%d", &count);

  q = (struct node *)malloc(sizeof(struct node) * count); // Cap phat dong cho bo nho cho q

  for (i = 0; i < count; i++)
  {
    (q + i)->id_num = i;

    printf("Trang thai q%d\n", i);
    printf("Trang thai tiep theo neu dau vao la 0: ");
    fflush(stdin);
    scanf("%d", &posi);
    (q + i)->link0 = (q + posi);

    printf("Trang thai tiep theo neu dau vao la 1: ");
    fflush(stdin);
    scanf("%d", &posi);
    (q + i)->link1 = (q + posi);

    printf("Trang thai nay co thuoc trang thai ket thuc?\n");
    fflush(stdin);
    scanf("%d", &(q + i)->st_val);
  }

  printf("Hay nhap ten trang thai dau:\n");
  fflush(stdin);
  scanf("%d", &posi); 
  start = q + posi;
  printf("=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=\n");

  while (1)
  {

    ptr = start;
    printf("Hay nhap xau dau vao \n");
    fflush(stdin);
    scanf("%s", n);
    posi = 0;
    system("clear");

    while (n[posi] != '\0')
    {
      a[posi] = (n[posi] - '0');
      posi++;
    }
    i = 0;
    int loop;

    // Display result
    for (loop = 0; loop < strlen(n); loop++)
    {
      printf("[%d]    ", a[loop]);
    }
    printf("\n");
    for (loop = 0; loop < strlen(n); loop++)
    {
      printf(" ^     ");
    }
    printf("\n");
    for (loop = 0; loop < strlen(n); loop++)
    {
      printf(" |     ");
    }
    printf("\n");
    // printf("Duong di cua otomat qua cac trang thai:");
    do
    {
      vst_arr[i] = ptr->id_num;
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
        system("clear");
        printf("Chuoi dau vao sai!\n"); // Kiem tra chuoi dau vao gia tri khac 0 hoac 1 hay khong
        return 0;
      }
      printf("[q%d]-->", vst_arr[i]);
      i++;
    } while (i < posi);
    //***********************************************
    printf("[q%d]", ptr->id_num);
    if (ptr->st_val == 1)
      printf(" thuoc F");
    else
      printf(" khong thuoc F");
    printf("\n");
    // printf("Trang thai cua otomat khi ket thuc: %d\n", ptr->id_num);
    printf("\n");
    if (ptr->st_val == 1)
    {
      printf("DOAN NHAN xau %s\n", n);
      return 1;
    }
    else
    {
      printf("KHONG doan nhan xau %s\n", n);
      return 0;
    }
  }
  printf("=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=\n");
  return 0;
}