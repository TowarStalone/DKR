#include <stdio.h>

int main()
{
// ³������� ���������� ����� ��� �������
FILE* fp = fopen("text.txt", "r");
// ��������, �� ������ ������� ����
if (fp == NULL) {
    printf("Error opening file\n");
    return 1;
}

// ����������� ��������� ��� ���������� ������� ����� ����������
int count = 0;

// ������� ����� ������ �� ��������
char c;
while ((c = fgetc(fp)) != EOF) {
    // Check if the character is a punctuation mark
    if (c == '!' || c == ',' || c == '.' || c == '-' || c == '?' || c == ':' || c == ';') {
        count++;
    }
}

// ���� �����
fclose(fp);

// ��������� �������� ����� ����������
printf("Number of punctuation marks: %d\n", count);

return 0;
}
