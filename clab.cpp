#include "stdio.h"
#include "time.h"

struct A
{
  public:
    int x;
    int y;
};

enum B{
    K,KK,KKK,KKKK
};

void modfiy(struct A *a, int i)
{
    if (i == 0)
        return;
    int b = 123;
    modfiy(a, i - 1);
}

void modfiy2(struct A a, int i)
{
    if (i == 0)
        return;
    int b = 12344;
    modfiy2(a, i - 1);
}

int main()
{
    printf("lab begin \n");
    struct A a;
    a.x = 12;
    a.y = 15;
    unsigned long t = clock();
    printf("%ld\n",t);
    modfiy(&a, 100000);
    printf("%ld %ld\n", clock() - t, clock());
    
    t = clock();
    modfiy2(a, 100000);
    printf("%ld %ld\n", clock() - t, clock());
    return 0;
}
