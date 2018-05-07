#include <iostream>
#include <algorithm>

using namespace std;

bool can_make_triangle(int a, int b, int c)
{
	bool c1 = a+b <= c;
	bool c2 = a+c <= b;
	bool c3 = b+c <= a;
	
	return !(c1||c2||c3);
}

void output_max_aroundlength_triangle_naive(int n, int *lines)
{
	int max_length = 0;
	
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			for (int k=j+1; k<n; k++)
			{
				if (can_make_triangle(lines[i], lines[j], lines[k]))
				{
					int len = lines[i] + lines[j] + lines[k];
					if (len > max_length) max_length = len;
				}
			}
		}
	}
	
	printf("%d\n", max_length);
}

void output_max_aroundlength_triangle_smart(int n, int *lines)
{
	std::sort(lines, lines+n);
	
	for (int i=n-1; i>=2; i--)
	{
		if (can_make_triangle(lines[i], lines[i-1], lines[i-2]))
		{
			int max_length = lines[i]+lines[i-1]+lines[i-2];
			printf("%d\n", max_length);
			return;
		}
	}
	printf("0\n");
}

int main()
{
	std::cout << "naive" << std::endl;
	int lines1[] = {2, 3, 4, 5, 10};
	output_max_aroundlength_triangle_naive(5, lines1);

	int lines2[] = {4, 5, 10, 20};
	output_max_aroundlength_triangle_naive(4, lines2);

	std::cout << "smart" << std::endl;
	output_max_aroundlength_triangle_smart(5, lines1);

	output_max_aroundlength_triangle_smart(4, lines2);
	
	
	return 0;
}
