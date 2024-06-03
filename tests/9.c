struct Pt{
	int x;
	int y;
	};

struct Pt points[10];

int count()
{
	int i;
	int n;
	n = 0;
	i = 0;
	while (i <= 10) {
		if(points[i].x>=0&&points[i].y>=0)
			n = n + 1;
		i = i + 1;
	}
	return n;
}

void main()
{
	put_i(count());
}
