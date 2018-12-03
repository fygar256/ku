#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#define	TRUE	1
#define	FALSE	0
int		N;
int		p[256];
int		count;
int		ok[257];
char	word[256];

void	show(void) {
	int	i;
	
	count++; printf("%5d: ",count);
	for(i=0;i<N;i++) {
		printf("%c",word[p[i]-1]);
		}
	printf("\n");
}

void	put(int pos,int k) {
	int j;
	p[pos]=k;
	if (pos==N-1) show();
	else {
		ok[k]=FALSE;
		for(j=1;j<=N;j++)
			if(ok[j]) put(pos+1,j);
		ok[k]=TRUE;
		}
}

void genperm1(void)
{
	int	k;

	count=0;
	for(k=1;k<=N;k++) ok[k]=TRUE;
	for(k=1;k<=N;k++) put(0,k);

}

int	main(int argc,char *argv[])
{
	if (argc!=2) {
		fprintf(stderr,"Usage kuu word\n");
		exit(1);
		}
	sscanf(*(++argv),"%s",word);
	N=strlen(word);
	genperm1();
}	
