#include<stdio.h>
#include<string.h>
typedef struct  Books{
    int id;
    int price;
    char title[50];
} book_t;
void total_price(book_t list[], int n){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += list[i].price;
    }
    printf("Sum: %d\n", sum);
}
void list_books(book_t list[], int n){
    for(int i = 0 ; i < n ; i++){
        printf("Book id = %d\n",list[i].id);
        printf("Book price = %d\n",list[i].price);
        printf("Book title = %s\n",list[i].title);
        printf("\n");
    }
}
int main(){
    book_t list[6];
    int price_list[6] = {1000,300,1000,550,870,1344};
    char title_list[6][50] = {"All the Light We Cannot See","The 38 Letters from J.D. Rockefeller to his son","The Ballad of Songbirds and Snakes","Killers of the Flower Moon","Elon Musk","Milk and Honey 12-Month 2024"};
    for(int i = 0; i < 6; i++){
        list[i].id = i+1;
        list[i].price = price_list[i];
        strcpy(list[i].title , title_list[i]);
    }

    total_price(list, 6);
    list_books(list, 6);

    return 0;
}