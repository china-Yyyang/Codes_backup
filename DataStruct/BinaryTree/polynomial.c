//#include<stdio.h>
//#include<stdlib.h>
//struct polynomial
//{
//    int coef;
//    int expon;
//    struct polynomial *next;
//};
//typedef struct polynomial *poly;
//
//void Output(poly head);
//
//int main(){
//    poly p1,p2,p3;
//    p1=(poly)malloc(sizeof(poly));
//    p1->next=NULL;
//    p2=(poly)malloc(sizeof(poly));
//    p2->next=NULL;
//    p3=(poly)malloc(sizeof(poly));
//    p3->next=NULL;
//    int n1=3,n2=2;
//    poly ptr;
//    for (int i=0 ; i<n1 ; i++)
//    {
//        ptr=(poly)malloc(sizeof(poly));  //*poly ?
//        ptr->coef=i+1;
//        ptr->expon=i;
//        ptr->next=p1->next;
//        p1->next=ptr;
//    }
//    for (int i=0;i<n2;i++)
//    {
//        ptr=(poly)malloc(sizeof(poly));  //*poly ?
//        ptr->coef=i+1;
//        ptr->expon=i;
//        ptr->next=p2->next;
//        p2->next=ptr;
//    }
//    Output(p1);
//    printf("\n");
//    Output(p2);
//    printf("\n");
//    
//    poly ptr1,ptr2;
//    ptr1=p1;ptr2=p2;
//    ptr1=ptr1->next;ptr2=ptr2->next;
//    while(ptr1!=NULL || ptr2!=NULL){
////    int n=n1;
////    while(n>0){
//        ptr=(poly)malloc(sizeof(poly));
//        if(ptr1->expon > ptr2->expon)
//        {
//            ptr->coef=ptr1->coef;
//            ptr->expon=ptr1->expon;
//            ptr->next=p3->next;
//            p3->next=ptr;
//            ptr1=ptr1->next;
//        }
//        else if(ptr1->expon < ptr2->expon)
//        {
//            ptr->coef=ptr2->coef;
//            ptr->expon=ptr2->expon;
//            ptr->next=p3->next;
//            p3->next=ptr;
//            ptr2=ptr2->next;
//        }
//        else
//        {
//            ptr->coef=ptr1->coef+ptr2->coef;
//            ptr->expon=ptr1->expon;
//            ptr->next=p3->next;
//            p3->next=ptr;
//            p3->next=ptr;
//            ptr1=ptr1->next;
//            ptr2=ptr2->next;
//        }
//    }
//    Output(p3);
//    return 0;
//}
//
//void Output(poly head){
//    poly p;
//    p=head;
//    p=p->next;
//    while (p!=NULL) {
//        printf("%d %d\n",p->coef,p->expon);
//        p=p->next;
//    }
//}
