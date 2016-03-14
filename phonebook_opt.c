#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "phonebook_opt.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry *e)
{
    int judge =strlen(lastName);
    while (e->pNext!=NULL && judge!=strlen(e->pNext->lastName ) ){
        e = e->pNext;
        // count++;
    }
    if(e->pNext==NULL)
        return NULL;
    else if(strcasecmp(lastName, e->pNext->lastName) == 0){
            
            printf("number%s\n",lastName);
            return e->pNext;       
    }
    else if(judge==strlen(e->pNext->lastName) ){
        e=e->pNext->pChild;
        // count++;
        while(e!=NULL) {
            if(strcasecmp(lastName, e->lastName) == 0) {
                printf("%s\n",e->lastName);
                 // printf("number%d\n",count );
                return e;
            }
            e=e->pNext;
            // count++;
        }
        return NULL;
    }
    return NULL;
}
/*
    entry *t;
    t=(entry *) malloc (sizeof(entry));
    t -> pNext= e -> pNext;
    t -> pChild= e -> pChild;
    t -> lastName = e -> lastName;
    */
entry *append(char lastName[], entry *e)
{
   /* allocate memory for the new entry and put lastName */
   entry *init=e;
    // printf("&e %p\n",&e );//0x7fff9515c8e0
    // printf("e %p\n",e );//0xb97240
    // printf("init %p\n",init );//0xb97240
    // printf("&init %p\n",&init );//0x7fff9515c8f8
     // printf("&init %p\n",*init );
    
    
    /*entry *init=&e;
    printf("&e %p\n",&e );// 0x7ffd0d63e810
    printf("e %p\n",e );//0x1fc3240
    printf("init %p\n",init );//0x7ffd0d63e810
    printf("&init %p\n",&init );//0x7ffd0d63e828
    getchar();
    */
    // char judge=lastName[0];
    int judge =strlen(lastName);
    // printf("%c\n", judge);
    while(e->pNext!=NULL && judge!=strlen(e->pNext->lastName)) {
        // printf("in while \n");
        // printf("%p\n", e->pNext);
        // printf("%c\n", judge);
        // printf("%c\n", e->pNext->lastName[0]);
        e = e->pNext;
    }
    if(e->pNext==NULL) {
        e->pNext=(entry *) malloc(sizeof(entry));
        strcpy(e->pNext->lastName, lastName);
        // printf("e->pNext->lastName:%c\n", e->pNext->lastName[0]);
        // printf("e->pNext->lastName:%s\n",e->pNext->lastName);
        e->pNext->pNext=NULL;
    } else if(judge==strlen(e->pNext->lastName)) {
        e=e->pNext;
        if(e->pChild==NULL) {
            e->pChild = (entry *) malloc(sizeof(entry));
            strcpy(e->pChild->lastName, lastName);           
         
            // printf("length:%d\n", strlen(e->pChild->lastName) );
            // printf("e->pChild->lastName:%s\n", e->pChild->lastName);
            e->pChild->pNext=NULL;
        } else {
            entry *tmp=(entry *) malloc(sizeof(entry));
            strcpy(tmp->lastName, lastName);
           
           

            tmp->pNext=e->pChild;
            // printf("tmp->pNext->lastName:%s\n", tmp->pNext->lastName);
            // printf("length:%d\n", strlen(tmp->lastName) );
            e->pChild=tmp;
            // printf("e->pChild->lastName%s\n", e->pChild->lastName);
        }
    }
    return init;
}
