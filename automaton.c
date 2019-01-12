#include "stdio.h"
#include "string.h"
#define to_int(c) ((int) c-(int) '0')
#define FinalState s1
enum state {s0,s1,s2,s3};
enum state transition_table[4][2]= { 
	{s0, s1},
	{s2, s3},
	{s1, s3},
	{s3, s3}
};
enum state delta(enum state s, char v) {
	return transition_table[(int) s][to_int(v)];
}

enum state delta_bar(enum state s) {
	enum state t;
	char v[20];
	t = s;
	printf("Enter the string :");
    v[20]=scanf("%s",v);
    int i;
    for(i=0;i<strlen(v);i++)
    {
		t = delta(t, v[i]);
    }
	return t;
}

int main()
{
	if (delta_bar(s0) == FinalState)
		printf("The string is Accepted\n");
	else
		printf("The string is Rejected\n");
		getchar();
    return 0;
}

