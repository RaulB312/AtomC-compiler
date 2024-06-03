
int sum()
{
	int	 i;
	int v[5];
	int s;
	s=0;
	while (i < 5){
		v[i]=i;
		s=s+v[i];
		i = i + 1;
		}
	return s;
}

void main()
{
	int i;
	int s;
	while(i<1000000) {
	s=sum();
	i = i + 1;
	}
	put_i(s);
}

