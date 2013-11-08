/*
 
*/

#include<stdio.h>

main()
{
	int a, b, sum; //aygsduhuhd bdasdjubshd basbgdjbd
	intro();// gygsyagdiuashdiuhasudx dsdc
	printf("\nEnter the first no: ");
	scanf("%d", &a);// njduasdjalsjdlasjdx
	printf("\nEnter the second no: ");// wehwugheiuwhde
	scanf("%d", &b);
	sum=a+b;//idjijasidjij djsdijasd njsdijs
	if(a==b)
	{
		if(a==2)	//hdfhdh
		{
			equal2();//juhsaudhs shdhashda ashki
		}
		equality();
	}
	if(a>b)		//jdhfjdhjfhdj
	{
		greater();// nsuhaudhjasd nsjdhhs
	}
	
	printf("\nThe sum of %d and %d is: %d", a ,b, sum);// bhsdasahdhasdbds dsbdhs
	thankyou();

}

thankyou()
{
	printf("\n\n*********************** Thank You ***************************\n\n");	
}

greater()
{
	printf("\n -a is greater\n");
}
equality()
{
	printf("\n  -Both values are equal\n");
}

equal2()
{
	printf("\nA is equal to 2\n");

}
intro()
{
	printf("\n********This is a Program of addition of two numbers*********\n");
}
