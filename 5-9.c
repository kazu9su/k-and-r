#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    printf("%d\n", day_of_year(1989, 3, 33));
    printf("%d\n", day_of_year(1989, 2, 30));
    printf("%d\n", day_of_year(1989, 2, 28));

    int pmonth, pday;

    month_day(1989, 40, &pmonth, &pday);
    printf("%d\n", pmonth);
    printf("%d\n", pday);

    return 0;
}

/* day_of_year: 月と日から年内の通算日を求める */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    /* 不正数値チェック */
    if  (month == 0 || month > 12 || day == 0 || day > 31)
        return -1;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    /* 存在しない日付チェック */
    if (*(*(daytab + leap) + month) < day)
        return -1;

    for(i = 1; i < month; i++)
        day += *(*(daytab + leap) + month);
    return day;
}

/* month_day: 年の通算日から月と日を求める */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > *(*(daytab + leap) + i); i++)
        yearday -= *(*(daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;
}
