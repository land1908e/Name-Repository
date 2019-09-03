#include<stdio.h>

typedef struct Node {
	int value;
	struct Node* leftMostChild;
	struct Node* rightSibling;
} Node ;
Node* root;

Node* Find(Node* r, int v){
	if (r== NULL) return NULL;
	if (r->value == v) return r;
	Node* d = r->leftMostChild;
	while (d != NULL){
		Node*h = Find(d,v);
		if(h!= NULL) return h;
		d = d->rightSibling;
	}
	return NULL;
}

Node* makeNode(int a){
	Node* tmt = new Node;
	tmt->rightSibling = NULL;
	tmt->leftMostChild = NULL;
	tmt->value = a; 
	return tmt;
}

void Insert(Node* p, int v){
	Node* m = makeNode(v);
	if(p==NULL) return;
	Node* h= p->leftMostChild;
	if(p->leftMostChild == NULL) { p->leftMostChild = m; 	return; } 
	else {
		while(h->rightSibling != NULL)	 h = h->rightSibling;
		h->rightSibling = m; 
	}
}
void insert(Node* r, int f, int v){
	Node* tmt= Find(root,f);
	Insert(tmt, v);
}

int height(Node* p){
	if (p == NULL) return -1 ;
	if(p->leftMostChild == NULL) return 0;
	else{
		Node*h = p->leftMostChild;
		int high = height(h);
		while (h->rightSibling != NULL){
			h=h->rightSibling;
			if (height(h) > high) high= height(h);
			
		}
	return high+1;		
	}
}	
	
int depth(Node* r, Node*p, int deep){
	if (r==NULL) return -1;
	if (r == p) return deep;
	Node* h= r->leftMostChild;
	while (h!= NULL) {
		if (h == p) return deep+1;
		int i= depth(h, p, deep+1);
		if ( i>0 )	return i;
		h=h->rightSibling;	
	}
}
int depthID(Node* r, int d) {
	Node* tmt= Find(root, d);
	return depth(root, tmt, 1);	
}	
	
int main(){
	root= makeNode(10);
	insert(root,10, 5);	
	insert(root,10, 6);
	insert(root,5, 7);
	insert(root,5, 8);
	insert(root,5, 9);
	insert(root,9, 4);
	insert(root,4, 11);
	insert(root,4, 12);
	insert(root,6, 1);
	insert(root,6, 2);
	insert(root,6, 3);
	
	Node* tmt= Find(root,9);
	printf("%d", depthID(root,12));	
	return 0;

}







