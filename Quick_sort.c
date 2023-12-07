#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct stdtype {
    int grade;
    char stname[20];
};

int compare_Grade(const void* arg1, const void* arg2) {
    return ((struct stdtype*)arg1)->grade - ((struct stdtype*)arg2)->grade;
}


int compare_Name(const void* arg1, const void* arg2)
{
    return (strncmp(((struct stdtype*)arg1)->stname,((struct stdtype*)arg2)->stname,20));
}

/*a�� b���� ũ�� *a-*b�� �� return���� ���

b�� a���� ũ�� *a-*b�� �� return���� ���� �̹Ƿ�

a�� b���� Ŭ ���� �� ���� ��ġ�� �ٲ�� �˴ϴ�.

*/

int main(void) {
    
    struct stdtype students[] = {
        {3, "Hong"},
        {3, "John"},
        {2, "Kim"},
        {2, "Park"},
        {1, "Doug"},
        {4, "Lee"},
        {3, "Lee"},
        {1, "Son"},
        {4, "Do"},
        {1, "Joo"}
    };

    int numStudents = sizeof(students) / sizeof(students[0]);

    
    qsort(students, numStudents, sizeof(struct stdtype), compare_Grade);

    
    printf("Sorted by Grade:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Grade %d: %s\n", students[i].grade, students[i].stname);
    }
    printf("\n");

    
    qsort(students, numStudents, sizeof(struct stdtype), compare_Name);

  
    printf("Sorted by Name:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Grade %d: %s\n", students[i].grade, students[i].stname);
    }

    return 0;
}
