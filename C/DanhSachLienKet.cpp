#include<stdio.h>
typedef struct Nope{
	int giatri;
	Nope* pnext;
}Nope;

Nope* SetNope(Nope* A){
	A = new Nope;
	printf("nhap gia tri can luu: ");
	scanf("%d",&A->giatri);
	A->pnext = new Nope;
	return A;
}
Nope* MakeNope(int a){
	Nope* q=new Nope;
	q->giatri = a;
	q->pnext=NULL;
	return q;
}
void FreeNope(Nope A){
	delete A.pnext;
}

Nope* InsertBeforeNope(Nope* H, int a, int x){
	Nope* p, X= new Nope;
	p=H;
	X= MakeNope(x);
	if(H=NULL) return X;
	while (p->pnext->giatri != a)
		p=p->pnext;
	X->pnext=p->pnext;
	p->pnext=X;
	return H;
}
