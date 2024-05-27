#include<stdio.h>
int address_tranlation(int virtual_add,int pt[]){
            int ptr = 110;
		
			int page=ptr+(virtual_add/10);
			int value=pt[virtual_add/10]; 
			int offset=virtual_add%10;			
			return ((value)*10+(offset));
}

int main(){
    int n;
    printf("\nEnter the Virtual Address(0-99):-");
    scanf("%d",&n);
    int pt[10]={4,12,3,7,10,15,23,26,1,9};

    int RA=address_tranlation(n,pt);
    printf("\nPhysical Address:-%d\n",RA);


}