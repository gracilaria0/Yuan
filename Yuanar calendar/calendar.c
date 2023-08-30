#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        printf("Error : Too many arguments.");
        return 1;
    }

    time_t time_t_current;
    time(&time_t_current);
    struct tm *tm_current = localtime(&time_t_current);

    struct tm tm_origin = {
        0,
        0,
        23,
        29,
        8 - 1 ,
        2023 - 1900
    };
    time_t time_t_origin = mktime(&tm_origin);

    const time_t SEC_IN_DAY = 60*60*24;
    time_t diff_sec = difftime(time_t_current,time_t_origin);
    int diff_day = diff_sec / SEC_IN_DAY;

    printf("Today is day %d in Yuanar calendar.\n",diff_day);

    system("pause");
    return 0;
}