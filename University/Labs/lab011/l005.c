//
// Created by Volodymyr Avvakumov on 05.10.2024.
//

#include <stdio.h>
#include <string.h>

#define N 4

typedef struct vertex{
    char mount_name[50];
    int height;

}vertex;

vertex vertex_input(){
    vertex v;
    printf("enter vertex height: ");
    scanf("%d", &(v.height));
    printf("enter mountain's name: ");
    scanf("%49s", v.mount_name);
    return v;
}

void fill_m_list(vertex* lst){
    for (int i = 0; i < N; i++){
        lst[i] = vertex_input();
    }

}

void print_mountain(vertex v){
    int height = 3;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }
        printf("/");

        if (i > 0) {
            for (int j = 0; j < 2 * i - 1; j++) {
                printf(" ");
            }
            printf("\\");
        }

        if (i == 0) {
            printf("  Height: %d", v.height);
        }

        printf("\n");
    }

    printf("/");
    for (int i = 0; i < 2 * height - 3; i++) {
        printf("_");
    }
    printf("\\\n");

    int padding = 2 * height - 1 - strlen(v.mount_name);
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s\n", v.mount_name);


}

void find_vertex_by_name(vertex* lst, char* name){
    for (int i = 0; i < N; i++){
        if (strcmp(name,lst[i].mount_name) == 0){
            print_mountain(lst[i]);
            return;
        }
    }
    printf("No vertex with such name");
}

void find_max_vertex(vertex* lst){
    int max = lst[0].height;
    int max_i = 0;
    for (int i = 1; i < N; i ++){
        if (lst[i].height > max){
            max = lst[i].height;
            max_i = i;
        }


    }
    print_mountain(lst[max_i]);

}




int main(){
    vertex m_list[N];
    fill_m_list(m_list);
//    for (int i = 0; i < N; i++){
//        print_mountain(m_list[i]);
//    }
    find_vertex_by_name(m_list, "babka");
    find_max_vertex(m_list);

}