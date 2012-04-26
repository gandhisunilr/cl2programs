struct twonos{
	int no1;
	int no2;
};
program idleserver{
	version idleserverversion{
		float getcpu()=1;
		int addnos(twonos)=2;
	}=1;
}=10;
