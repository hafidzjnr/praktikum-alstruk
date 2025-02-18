#include <stdio.h>

//inisialisasi data
int angka[10]={6,6,2,5,8,1,7,3,4,1};

 main(){
	//looping sebanyak jumlah data-1
	printf("Data awal:\n ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", angka[i]);
	}
	printf("\n");
	
	for(int i=1; i<10; i++){
		printf("\niterasi %d \n", i);
		//looping selama angka ke-j (j sudah di set sebagai i di awal)
		//lebih kecil dari j-1
		for(int j=i; j>0 && angka[j]<angka[j-1]; j--){
			//lakukan swap value
			int temp=angka[j-1];
			angka[j-1]=angka[j];
			angka[j]=temp;
		}
		for (int m = 0; m < 10; m++)
		{
			printf("%d ", angka[m]);
		}
		printf("\n");
	}
		printf("\nHasil akhir: \n");
	for(int i=0; i<10; i++){
		printf("%d ", angka[i]);
	}
	getchar();
}