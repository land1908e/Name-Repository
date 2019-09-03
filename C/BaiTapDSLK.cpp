#include<stdio.h>

typedef struct Node{
	int giatri;
	struct Node* next;
} INode;

INode* InNode;
INode* OutNode;

INode* makeNode(int i){
	INode* w = new INode;
	w->giatri = i;
	w->next = NULL;
	return w;
}
INode* InsertLast(INode* t, int i){
	INode* p = t;
	INode* x = makeNode(i);
	if (p==NULL) return x;
	while(p->next != NULL) p = p->next;
	p->next = x;
	return t;
}
void PrintDS(INode* p){
	while(p != NULL){
		printf("%d, ",p->giatri);
		p = p->next;
	}
	printf("\n");
}
int main(){
	int n;
	printf("Nhap so phan tu cua DSLK: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		printf("Nhap ptu thu %d trong DSLK: ",i);
		scanf("%d",&a);
		InNode= InsertLast(InNode,a);
	}
	OutNode = InsertLast(OutNode,InNode->giatri);
	INode* c = InNode;
	INode* b = OutNode;
	for(int i=1;i<n;i++){
		OutNode = InsertLast(OutNode,(c->next->giatri)+(b->giatri));
		c=c->next;
		b=b->next;
	} 
	
	PrintDS(InNode);
	PrintDS(OutNode);           
	
}









