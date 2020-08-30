#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head;
void dis(){
	struct node *temp;
	temp=head;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
int count(){
	struct node *temp;
	int c=0;
	temp=head;
	while(temp!=NULL){
		c++;
		temp=temp->next;
	}
	return c;
}
void insbeg(){
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	printf("enter data ");
	scanf("%d",&p->data);
	if(head==NULL){
		p->next=NULL;
	}
	else{
		p->next=head;
	}
	head=p;
}
void insend(){
	struct node *p,*temp;
	p=(struct node*)malloc(sizeof(struct node));
	printf("enter data ");
	scanf("%d",&p->data);
	p->next=NULL;
	if(head==NULL){
		head=p;
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=p;
	}
}
void inssp(){
	struct node *p,*temp;
	int pos,i;
	p=(struct node*)malloc(sizeof(struct node));
	printf("enter data ");
	scanf("%d",&p->data);
	printf("enter position");
	scanf("%d",&pos);
	temp=head;
	for(i=1;i<pos-1;i++){
		temp=temp->next;
	}
	p->next=temp->next;
	temp->next=p;
}
void delbeg(){
	struct node *p;
	p=head;
	if(head==NULL){
		printf("list is empty");
	}
	else{
		head=p->next;
		printf("element deleted is %d\n",p->data);
		free(p);
	}
}
void delend(){
	struct node *p,*temp;
	p=head;
	if(head==NULL){
		printf("list empty");
	}
	else if(head->next==NULL){
		p=head;
		head=NULL;
	}
	else{
		while(p->next!=NULL){
			temp=p;
			p=p->next;
		}
		temp->next=NULL;
		printf("deleted element=%d\n",p->data);
		free(p);
	}
}
void delsp(){
	struct node *p,*temp;
	int pos;
	p=head;
	printf("enter position");
	scanf("%d",&pos);
	if(head==NULL){
		printf("list empty");
	}
	else{
		for(int i=0;i<pos-1;i++){
			temp=p;
			p=p->next;
		}
		temp->next=p->next;
		printf("element deleted= %d\n",p->data);
		free(p);
	}
}
void sort(){
	int t;
	struct node *curr,*temp;
	curr=head;
	while(curr!=NULL){
		temp=curr->next;
		while(temp!=NULL){
			if(temp->data<curr->data){
				t=temp->data;
				temp->data=curr->data;
				curr->data=t;
			}
			temp=temp->next;
		}
		curr=curr->next;
	}
	printf("list is sorted successfully\n");
}
int main(){
	printf("*********creating a linked list*********\n");
	struct node *p;
	char ch='y';
	int choice=0,i;
	p=(struct node*)malloc(sizeof(struct node));
	head=p;
	while(ch=='y'){
		printf("enter data");
		scanf("%d",&p->data);
		printf("Want to continue making node enter y or n =");
		scanf(" %c",&ch);
		if(ch=='y'){
			p->next=(struct node*)malloc(sizeof(struct node));
			p=p->next;
		}
		else{
			p->next=NULL;
		}
	}
	while(choice!=10){
		printf("1.insert a node at beginning\n2.insert a node at end\n3.insert a node at a specified location");
		printf("\n4.delete a node from beginning\n5.delete a node from ending\n6.delete a node from specified position");
		printf("\n7.to sort the linked list\n8.to display the list\n9.to count the no. of nodes in list");
		printf("10.exit\nEnter your choice ");
		scanf("%d",&choice);
		switch(choice){
			case 1:insbeg();
			break;
			case 2:insend();
			break;
			case 3:inssp();
			break;
			case 4:delbeg();
			break;
			case 5:delend();
			break;
			case 6:delsp();
			break;
			case 7:sort();
			break;
			case 8:dis();
			break;
			case 9:i=count();
			printf("%d\n",i);
			break;
		}	
	}
	return 0;
}