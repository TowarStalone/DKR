#include <stdio.h>

int main()
{
// Відкриття текстового файлу для читання
FILE* fp = fopen("text.txt", "r");
// Перевірка, чи успішно відкрито файл
if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
}

// Ініціалізація лічильника для відстеження кількості знаків пунктуації
int count = 0;

// Читання файлу символ за символом
char c;
while ((c = fgetc(fp)) != EOF) {
    // Check if the character is a punctuation mark
    if (c == '!' || c == ',' || c == '.' || c == '-' || c == '?' || c == ':' || c == ';') {
        count++;
    }
}

// Вибір файлу
fclose(fp);

// Виведення кількосьті знаків пунктуації
printf("Number of punctuation marks: %d\n", count);

return 0;
}
