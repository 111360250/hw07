#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct c
{
	const char* f;
	const char* s;
};

typedef struct c C;

void fill(C* const wd, const char* wf[], const char* ws[])
{
	int i;
	for (i = 0; i <= 51; i++)
	{
		wd[i].f = wf[i % 13];
		wd[i].s = ws[i / 13];
	}
}
void sh(C* const wd)
{
	int i, j;
	C t;
	for (i = 0; i <= 51; i++)
	{
		j = rand() % 52;
		t = wd[i];
		wd[i] = wd[j];
		wd[j] = t;
	}
}
void deal(const C* const wd)
{
	for (int i = 0; i <= 51; i++)
	{
		printf("%5s of %-8s%s", wd[i].f, wd[i].s, (i + 1) % 4 ? " " : "\n");
	}
}

int main()
{
	C deck[52];
	const char* f[] = { "Ace","Deuce","Three","Four","Five","Six",
	"Seven","Eight","Nine","Ten","Jack","Queen","King" };
	const char* s[] = { "Hearts","Diamonds","Clubes","Spades" };
	srand(time(NULL));
	fill(deck, f, s);
	sh(deck);
	deal(deck);
	return 0;

}