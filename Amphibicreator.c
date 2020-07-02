#include <stdio.h>
#include <stdlib.h>

#define PSEED 75 // Допустимые части амфибий
FILE *fptr;

char *getname(char b[]);
void amphrand(char s[], char t[], int begin, int step, int up, int end);

int main()
{
    // Работаем с именем
    char namph='a'; // Флаг для подтверждения работы программы
    while (namph!=EOF) {
        char name[25];
        puts("Amphibi nickname: ");
        char *p=getname(name);
        printf("Amphibi has such а garbage nickname as: %s\n", p);
        // Стек частей амфибий и рамки персонажа
        char Parts[77]="!\"\'\\#%&^*()+-{}[]><?/|;:~$@_*=,.`QqWeErRTtYuIiopAasDdfFGgHhJjKkLZxcCvBbNnMm";
        char Icon[30]=" ___ \n|   |\n|   |\n|   |\n ^^^ \n";
        // Создаем афибию
        amphrand(Parts, Icon, 7, 3, 3, 22);
        printf("%s", Icon);
        // Сохранение в фаил
        puts("Will it life? Y/N");
        char answer=getchar();
        switch (answer){
            case 'Y':
                fptr=fopen("Paddling pool.txt", "a");
                fprintf(fptr, "%s\n", name);
                fprintf(fptr, "%s", Icon);
                puts("*The smell of a spring pond*");
                fclose(fptr);
                break;
            case 'N':
                puts("Fine, it's dead");
                break;
            case EOF:
                puts("Go away");
                exit(1);
            default:
                puts("You are not a amphibi");
                break;
    }
        namph=getchar(); // Обновления флага для продолжения работы
    }

}

// Взять имя для кастомной амфибии
char *getname(char b[])
{
    char *n;
    n=&b[0];
    int c, i=0;
    while((c=getchar())!='\n')
    {
        b[i++]=c;
    }
    b[i]='\0';
    return n;
}




// Генерируем случайную амфибию
#include <time.h>
#define DeepDive(a) (a==0) ? puts("Deep dive...") : a; // Макрос для отсутствующего героя
#define REPAIRTOOLONE 1 // Выбор отладчика

#if defined (REPAIRTOOLONE)
#define REPAIRON 1 // Переключатель отладчика


void amphrand(char s[], char t[], int begin, int step, int up, int end)
{
    // Чиним недоделанную амфибию
    void repairamph(char t[]);
    // Генерация
    int i=0, sp, prt;
    int Aflag=0;
    time_t h;
    srand(time(&h));
    while(begin<end)
    {
        sp=(rand()%100)+1;
        if (sp>=1 && sp<=34)
        {
            prt=(rand()%PSEED);
            t[begin++]=s[prt];
            i++;
            Aflag=1;
        }
        else
        {
            begin++;
            i++;
        }
        begin=(i==step) ? i=0, begin+up : begin;
    }
    DeepDive(Aflag);
    // Отладчик
    #if REPAIRON>0
    repairamph(t);
    #endif
}

// Проверяем амфибию на наличие пробелов несовместимых с жизнью
#if REPAIRON>0
void repairamph(char t[])
{
    char PartsTool[77]="!\"\'\\#%&^*()+-{}[]><?/|;:~$@_*=,.`QqWeErRTtYuIiopAasDdfFGgHhJjKkLZxcCvBbNnMm";
    time_t h;
    srand(time(&h));
    int n=(rand()%3)+13;
    int j=(rand()%PSEED); t[n]=PartsTool[j];
    if ((t[7]!=' ' && t[21]!=' ') && (t[8]==' ' && t[9]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[19]==' ' && t[20]==' '))
    {
        t[n]=PartsTool[j];
    }
    else if ((t[9]!=' ' && t[19]!=' ') && (t[7]==' ' && t[8]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[20]==' ' && t[21]==' '))
    {
        t[n]=PartsTool[j];
    }
    else if ((t[8]!=' ' && t[20]!=' ') && (t[7]==' ' && t[9]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[19]==' ' && t[21]==' '))
    {
        t[n]=PartsTool[j];
    }
    else if ((t[9]!=' ' && t[20]!=' ') && (t[7]==' ' && t[8]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[19]==' ' && t[21]==' '))
    {
        t[n]=PartsTool[j];
    }
    else if ((t[19]!=' ' && t[8]!=' ') && (t[7]==' ' && t[9]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[20]==' ' && t[21]==' '))
    {
        t[n]=PartsTool[j];
    }
    else if ((t[9]!=' ' && t[19]!=' ') && (t[7]==' ' && t[8]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[20]==' ' && t[21]==' '))
    {
        t[n]=PartsTool[j];
    }
    else if ((t[9]!=' ' && t[21]!=' ') && (t[7]==' ' && t[8]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[19]==' ' && t[20]==' '))
    {
       t[n]=PartsTool[j];
    }
    else if ((t[7]!=' ' && t[19]!=' ') && (t[8]==' ' && t[9]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[20]==' ' && t[21]==' '))
    {
        t[n]=PartsTool[j];
    }
    else if ((t[8]!=' ' && t[21]!=' ') && (t[7]==' ' && t[9]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[19]==' ' && t[20]==' '))
    {
        t[n]=PartsTool[j];
    }
}
#endif


#else
// Не очень хорошо работающий рекурсивный отладчик
void repairamph2(char *t, char *s);
void amphrand2(char s[], char t[], int begin, int step, int up, int end)
{
    char *spp=&s[0];
    char *tpp=&t[0];
    // Генерация
    int i=0, sp, prt;
    int Aflag=0;
    time_t h;
    srand(time(&h));
    while(begin<end)
    {
        sp=(rand()%100)+1;
        if (sp>=1 && sp<=34)
        {
            prt=(rand()%PSEED);
            t[begin++]=s[prt];
            i++;
            Aflag=1;
        }
        else
        {
            begin++;
            i++;
        }
        begin=(i==step) ? i=0, begin+up : begin;
    }
    DeepDive(Aflag);
    // Отладчик
    repairamph2(tpp, spp);
}


// Проверяем амфибию на наличие пробелов несовместимых с жизнью
void repairamph2(char *t, char *s)
{
    if ((t[7]!=' ' && t[21]!=' ') && (t[8]==' ' && t[9]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[19]==' ' && t[20]==' '))
    {
        amphrand2(s, t, 7, 3, 3, 22);
    }
    else if ((t[9]!=' ' && t[19]!=' ') && (t[7]==' ' && t[8]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[20]==' ' && t[21]==' '))
    {
        amphrand2(s, t, 7, 3, 3, 22);
    }
    else if ((t[8]!=' ' && t[20]!=' ') && (t[7]==' ' && t[9]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[19]==' ' && t[21]==' '))
    {
        amphrand2(s, t, 7, 3, 3, 22);
    }
    else if ((t[9]!=' ' && t[20]!=' ') && (t[7]==' ' && t[8]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[19]==' ' && t[21]==' '))
    {
        amphrand2(s, t, 7, 3, 3, 22);
    }
    else if ((t[19]!=' ' && t[8]!=' ') && (t[7]==' ' && t[9]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[20]==' ' && t[21]==' '))
    {
        amphrand2(s, t, 7, 3, 3, 22);
    }
    else if ((t[9]!=' ' && t[19]!=' ') && (t[7]==' ' && t[8]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[20]==' ' && t[21]==' '))
    {
        amphrand2(s, t, 7, 3, 3, 22);
    }
    else if ((t[9]!=' ' && t[21]!=' ') && (t[7]==' ' && t[8]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[19]==' ' && t[20]==' '))
    {
       amphrand2(s, t, 7, 3, 3, 22);
    }
    else if ((t[7]!=' ' && t[19]!=' ') && (t[8]==' ' && t[9]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[20]==' ' && t[21]==' '))
    {
        amphrand2(s, t, 7, 3, 3, 22);
    }
    else if ((t[8]!=' ' && t[21]!=' ') && (t[7]==' ' && t[9]==' ' && t[13]==' ' && t[14]==' ' && t[15]==' ' && t[19]==' ' && t[20]==' '))
    {
        amphrand2(s, t, 7, 3, 3, 22);
    }
}
#endif