#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0
#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0


#include <stdio.h>

void fahrFor() {
    int fahr;
    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr - 32));
    }
}

void celsiumRepeat() {
    float fahr, celsius;
    int low, step, upper;

    low = -276;
    upper = 375;
    step = 20;

    celsius = low;

    while (celsius <= upper) {
        fahr = 9.0 * (celsius + 32.0) / 5.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}

void copyChar() {
    int c;
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}

void copySymbol() {
    long nc;
    nc = 0;

    while (getchar() != EOF) {
        ++nc;
    }
    printf("%ld\n", nc);
}

void countCharacters() {
    int c, i, nwhite, nother;

    // elements this array - ndigit[0], ndigit[1], ndigit[2] ...
    int ndigit[10];

    nwhite = nother = 0;

    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits =");

    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);

    printf(", white space = %d, other symbols = %d\n",
           nwhite, nother);
}

void printHorizontalHistogram() {

    int c, i, nc, state;
    int len, maxvalue, ovflow, wl[MAXWORD];

    state = OUT;
    nc = 0;
    ovflow = 0;

    for (i = 0; i < MAXWORD; ++i)
        wl[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;

            if (nc > 0)
                if (nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;

            nc = 0;
        } else if (state == OUT) {
            state = IN;
            nc = 1;
        } else
            ++nc;
    }

    maxvalue = 0;

    for (i = 1; i < MAXWORD; ++i)
        if (wl[i] > maxvalue)
            maxvalue = wl[i];

    for (i = 1; i < MAXWORD; ++i) {
        printf("%5d - %5d : ", i, wl[i]);
        if (wl[i] > 0) {
            if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
                len = 1;
        } else
            len = 0;
        while (len > 0) {
            putchar('*');
            --len;
        }
        putchar('\n');
    }
    if (ovflow > 0)
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
}

int power(int m, int n);

int power(int base, int n) {
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;

    return p;
}

#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
//    printHorizontalHistogram();
//
//    int i;
//
//    for (i = 0; i < 10; ++i)
//        printf("%d %d %d\n", i, power(2, i), power(-3, i));
//
//    return 0;

    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    if (max > 0)
        printf("$s", longest);

    return 0;
}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == 'n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]) {
    int i;

    i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}


