struct operands{
int a ;
int b;
};
program sunil_prog{
	version sunil_version{
		int add(operands)=1;
		int sub(operands)=2;
	} =1;
}=100;
