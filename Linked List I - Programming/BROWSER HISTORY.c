#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct domainName
{
char name[50];
struct domainName * link;
};

struct hitcount
{
char name[50];
int occurenceCount;
struct hitcount *link;
};

void appendNode (struct domainName **,char[] );
void updateMetaData(struct hitcount **,char[] );
void appendMetadata (struct hitcount **,char[] );
void displayData(struct domainName *);
void displayMetaData(struct hitcount *);
void sortByFrequency(struct domainName **,struct hitcount *);
void retrive(struct hitcount *);

int main()
{
	
	int choice=1;
	char wname[50];
	struct domainName *list;
	struct hitcount *occuerenceCount;
	list = NULL;	occuerenceCount = NULL;
	while(choice>=1 && choice <5){
		printf("1.Enter the webiste you want to visit\n2.Recently visited\n3.Get hit count\n4.Most visited\n5.Exit\nEnter your choice\n");
		scanf("%d\n",&choice);
			switch(choice)
			{
				case 1:
					printf("Enter the website\n");
					scanf("%s\n",wname);
					appendNode(&list,wname);
					updateMetaData(&occuerenceCount,wname);
					break;
				case 2:
				    printf("Recently visited websites:\n");
					displayData(list);
					break;
				case 3:
				    printf("Hitcounts:\n");
					displayMetaData(occuerenceCount);
					break;
				case 4:
					sortByFrequency(&list,occuerenceCount);
					break;
				case 5:
					printf("Exit\n");
					break;
			}
	}
	return 0;
}


void appendNode(struct domainName **q,char webname[50]){
    struct domainName *nn = (struct domainName *)malloc(sizeof(struct domainName));
    strcpy(nn->name, webname);
    nn->link = NULL;
    
    if(!(*q)){
        *q = nn;
        return;
    }
    nn->link = (*q);
    *q = nn;
}

struct hitcount* findByName(struct hitcount *p, char name[50]){
    while(p){
        if(!strcmp(p->name, name))
            return p;
        p = p->link;
    }
    return NULL;
}

void appendMetadata(struct hitcount **p,char webname[50]){
    struct hitcount *curr = findByName(*p,webname);
    
    if(curr){
        curr->occurenceCount += 1;
        return;
    }

    struct hitcount *nn = (struct hitcount *)malloc(sizeof(struct hitcount));
    strcpy(nn->name, webname);
    nn->occurenceCount = 1;
    nn->link = NULL;
    if(!(*p)){
        *p = nn;
        return;
    }
    nn->link = (*p);
    *p = nn;
}

void displayData(struct domainName *q){
    static int r = 0;
    if(q){
        displayData(q->link);
        printf("%d)%s\n",++r, q->name);
        
        
    }
}
void displayMetaData(struct hitcount *q){
    if(q){
        displayMetaData(q->link);
        printf("%s - %4d\n",q->name, q->occurenceCount);
    }
}

void updateMetaData(struct hitcount **list,char n[50]){
    appendMetadata(list,n);
}

struct hitcount* findMax(struct hitcount *head){
    int max_ = 9999;

    struct hitcount *res;

    while(head){
        if(max_ >= head->occurenceCount){
            max_ = head->occurenceCount;
            res = head;
        }
        head = head->link;
    }
    return res;
}

void sortByFrequency(struct domainName **p, struct hitcount *q){
    struct hitcount *head = NULL, *nn, *t;
    char s_temp[50];
    struct hitcount *temp;
    
    int i_temp;
    
    while(q){
        nn = (struct hitcount*)malloc(sizeof(struct hitcount));
        strcpy(nn->name,q->name);
        nn->occurenceCount = q->occurenceCount;
        nn->link = head;
        head = nn;
        q = q->link;
    }
    t = head;
    while(head){
        temp = findMax(head);
        strcpy(s_temp, temp->name);     i_temp = temp->occurenceCount;
        strcpy(temp->name, head->name); temp->occurenceCount = head->occurenceCount;
        strcpy(head->name,s_temp);      head->occurenceCount = i_temp;

        head = head->link;
    }
    
    printf("Most visited websites\n");
    displayMetaData(t);
}
