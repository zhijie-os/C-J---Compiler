#include <iostream>

#define printi(x) std::cout << x;
#define prints(x) std::cout << x;

int morerandom();

void INTERNALseed(int seed);

//
//  Linear congruential method of generating pseudorandom
//  numbers, from Knuth's _The Art of Computer Programming, Volume 2:
//  Seminumerical Algorithms_, 3rd edition, Addison-Wesley, 1998.
//  Constants are chosen using Theorem A on page 17.
//
//  XXX - the period is long, but the lsb isn't random!
//
int INTERNALrandom();
void printboard(int gen);
int neighbours(int,int);

int A_0_0;
int A_0_1;
int A_0_2;
int A_0_3;
int A_0_4;
int A_0_5;
int A_0_6;
int A_0_7;
int A_0_8;
int A_0_9;
int A_1_0;
int A_1_1;
int A_1_2;
int A_1_3;
int A_1_4;
int A_1_5;
int A_1_6;
int A_1_7;
int A_1_8;
int A_1_9;
int A_2_0;
int A_2_1;
int A_2_2;
int A_2_3;
int A_2_4;
int A_2_5;
int A_2_6;
int A_2_7;
int A_2_8;
int A_2_9;
int A_3_0;
int A_3_1;
int A_3_2;
int A_3_3;
int A_3_4;
int A_3_5;
int A_3_6;
int A_3_7;
int A_3_8;
int A_3_9;
int A_4_0;
int A_4_1;
int A_4_2;
int A_4_3;
int A_4_4;
int A_4_5;
int A_4_6;
int A_4_7;
int A_4_8;
int A_4_9;
int A_5_0;
int A_5_1;
int A_5_2;
int A_5_3;
int A_5_4;
int A_5_5;
int A_5_6;
int A_5_7;
int A_5_8;
int A_5_9;
int A_6_0;
int A_6_1;
int A_6_2;
int A_6_3;
int A_6_4;
int A_6_5;
int A_6_6;
int A_6_7;
int A_6_8;
int A_6_9;
int A_7_0;
int A_7_1;
int A_7_2;
int A_7_3;
int A_7_4;
int A_7_5;
int A_7_6;
int A_7_7;
int A_7_8;
int A_7_9;
int A_8_0;
int A_8_1;
int A_8_2;
int A_8_3;
int A_8_4;
int A_8_5;
int A_8_6;
int A_8_7;
int A_8_8;
int A_8_9;
int A_9_0;
int A_9_1;
int A_9_2;
int A_9_3;
int A_9_4;
int A_9_5;
int A_9_6;
int A_9_7;
int A_9_8;
int A_9_9;
int not_there;
int T_0_0;
int T_0_1;
int T_0_2;
int T_0_3;
int T_0_4;
int T_0_5;
int T_0_6;
int T_0_7;
int T_0_8;
int T_0_9;
int T_1_0;
int T_1_1;
int T_1_2;
int T_1_3;
int T_1_4;
int T_1_5;
int T_1_6;
int T_1_7;
int T_1_8;
int T_1_9;
int T_2_0;
int T_2_1;
int T_2_2;
int T_2_3;
int T_2_4;
int T_2_5;
int T_2_6;
int T_2_7;
int T_2_8;
int T_2_9;
int T_3_0;
int T_3_1;
int T_3_2;
int T_3_3;
int T_3_4;
int T_3_5;
int T_3_6;
int T_3_7;
int T_3_8;
int T_3_9;
int T_4_0;
int T_4_1;
int T_4_2;
int T_4_3;
int T_4_4;
int T_4_5;
int T_4_6;
int T_4_7;
int T_4_8;
int T_4_9;
int T_5_0;
int T_5_1;
int T_5_2;
int T_5_3;
int T_5_4;
int T_5_5;
int T_5_6;
int T_5_7;
int T_5_8;
int T_5_9;
int T_6_0;
int T_6_1;
int T_6_2;
int T_6_3;
int T_6_4;
int T_6_5;
int T_6_6;
int T_6_7;
int T_6_8;
int T_6_9;
int T_7_0;
int T_7_1;
int T_7_2;
int T_7_3;
int T_7_4;
int T_7_5;
int T_7_6;
int T_7_7;
int T_7_8;
int T_7_9;
int T_8_0;
int T_8_1;
int T_8_2;
int T_8_3;
int T_8_4;
int T_8_5;
int T_8_6;
int T_8_7;
int T_8_8;
int T_8_9;
int T_9_0;
int T_9_1;
int T_9_2;
int T_9_3;
int T_9_4;
int T_9_5;
int T_9_6;
int T_9_7;
int T_9_8;
int T_9_9;
int main()
{
	int i;
	int j;
	int x;
	int n;
	INTERNALseed(123);
	i = 0;
	while (i <= 9)
	{
		if (i == 0)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					A_0_0 = morerandom() % 2;
				}
				else if (j == 1)
				{
					A_0_1 = morerandom() % 2;
				}
				else if (j == 2)
				{
					A_0_2 = morerandom() % 2;
				}
				else if (j == 3)
				{
					A_0_3 = morerandom() % 2;
				}
				else if (j == 4)
				{
					A_0_4 = morerandom() % 2;
				}
				else if (j == 5)
				{
					A_0_5 = morerandom() % 2;
				}
				else if (j == 6)
				{
					A_0_6 = morerandom() % 2;
				}
				else if (j == 7)
				{
					A_0_7 = morerandom() % 2;
				}
				else if (j == 8)
				{
					A_0_8 = morerandom() % 2;
				}
				else if (j == 9)
				{
					A_0_9 = morerandom() % 2;
				}
				j = j + 1;
			}
		}
		else if (i == 1)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					A_1_0 = morerandom() % 2;
				}
				else if (j == 1)
				{
					A_1_1 = morerandom() % 2;
				}
				else if (j == 2)
				{
					A_1_2 = morerandom() % 2;
				}
				else if (j == 3)
				{
					A_1_3 = morerandom() % 2;
				}
				else if (j == 4)
				{
					A_1_4 = morerandom() % 2;
				}
				else if (j == 5)
				{
					A_1_5 = morerandom() % 2;
				}
				else if (j == 6)
				{
					A_1_6 = morerandom() % 2;
				}
				else if (j == 7)
				{
					A_1_7 = morerandom() % 2;
				}
				else if (j == 8)
				{
					A_1_8 = morerandom() % 2;
				}
				else if (j == 9)
				{
					A_1_9 = morerandom() % 2;
				}
				j = j + 1;
			}
		}
		else if (i == 2)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					A_2_0 = morerandom() % 2;
				}
				else if (j == 1)
				{
					A_2_1 = morerandom() % 2;
				}
				else if (j == 2)
				{
					A_2_2 = morerandom() % 2;
				}
				else if (j == 3)
				{
					A_2_3 = morerandom() % 2;
				}
				else if (j == 4)
				{
					A_2_4 = morerandom() % 2;
				}
				else if (j == 5)
				{
					A_2_5 = morerandom() % 2;
				}
				else if (j == 6)
				{
					A_2_6 = morerandom() % 2;
				}
				else if (j == 7)
				{
					A_2_7 = morerandom() % 2;
				}
				else if (j == 8)
				{
					A_2_8 = morerandom() % 2;
				}
				else if (j == 9)
				{
					A_2_9 = morerandom() % 2;
				}
				j = j + 1;
			}
		}
		else if (i == 3)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					A_3_0 = morerandom() % 2;
				}
				else if (j == 1)
				{
					A_3_1 = morerandom() % 2;
				}
				else if (j == 2)
				{
					A_3_2 = morerandom() % 2;
				}
				else if (j == 3)
				{
					A_3_3 = morerandom() % 2;
				}
				else if (j == 4)
				{
					A_3_4 = morerandom() % 2;
				}
				else if (j == 5)
				{
					A_3_5 = morerandom() % 2;
				}
				else if (j == 6)
				{
					A_3_6 = morerandom() % 2;
				}
				else if (j == 7)
				{
					A_3_7 = morerandom() % 2;
				}
				else if (j == 8)
				{
					A_3_8 = morerandom() % 2;
				}
				else if (j == 9)
				{
					A_3_9 = morerandom() % 2;
				}
				j = j + 1;
			}
		}
		else if (i == 4)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					A_4_0 = morerandom() % 2;
				}
				else if (j == 1)
				{
					A_4_1 = morerandom() % 2;
				}
				else if (j == 2)
				{
					A_4_2 = morerandom() % 2;
				}
				else if (j == 3)
				{
					A_4_3 = morerandom() % 2;
				}
				else if (j == 4)
				{
					A_4_4 = morerandom() % 2;
				}
				else if (j == 5)
				{
					A_4_5 = morerandom() % 2;
				}
				else if (j == 6)
				{
					A_4_6 = morerandom() % 2;
				}
				else if (j == 7)
				{
					A_4_7 = morerandom() % 2;
				}
				else if (j == 8)
				{
					A_4_8 = morerandom() % 2;
				}
				else if (j == 9)
				{
					A_4_9 = morerandom() % 2;
				}
				j = j + 1;
			}
		}
		else if (i == 5)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					A_5_0 = morerandom() % 2;
				}
				else if (j == 1)
				{
					A_5_1 = morerandom() % 2;
				}
				else if (j == 2)
				{
					A_5_2 = morerandom() % 2;
				}
				else if (j == 3)
				{
					A_5_3 = morerandom() % 2;
				}
				else if (j == 4)
				{
					A_5_4 = morerandom() % 2;
				}
				else if (j == 5)
				{
					A_5_5 = morerandom() % 2;
				}
				else if (j == 6)
				{
					A_5_6 = morerandom() % 2;
				}
				else if (j == 7)
				{
					A_5_7 = morerandom() % 2;
				}
				else if (j == 8)
				{
					A_5_8 = morerandom() % 2;
				}
				else if (j == 9)
				{
					A_5_9 = morerandom() % 2;
				}
				j = j + 1;
			}
		}
		else if (i == 6)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					A_6_0 = morerandom() % 2;
				}
				else if (j == 1)
				{
					A_6_1 = morerandom() % 2;
				}
				else if (j == 2)
				{
					A_6_2 = morerandom() % 2;
				}
				else if (j == 3)
				{
					A_6_3 = morerandom() % 2;
				}
				else if (j == 4)
				{
					A_6_4 = morerandom() % 2;
				}
				else if (j == 5)
				{
					A_6_5 = morerandom() % 2;
				}
				else if (j == 6)
				{
					A_6_6 = morerandom() % 2;
				}
				else if (j == 7)
				{
					A_6_7 = morerandom() % 2;
				}
				else if (j == 8)
				{
					A_6_8 = morerandom() % 2;
				}
				else if (j == 9)
				{
					A_6_9 = morerandom() % 2;
				}
				j = j + 1;
			}
		}
		else if (i == 7)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					A_7_0 = morerandom() % 2;
				}
				else if (j == 1)
				{
					A_7_1 = morerandom() % 2;
				}
				else if (j == 2)
				{
					A_7_2 = morerandom() % 2;
				}
				else if (j == 3)
				{
					A_7_3 = morerandom() % 2;
				}
				else if (j == 4)
				{
					A_7_4 = morerandom() % 2;
				}
				else if (j == 5)
				{
					A_7_5 = morerandom() % 2;
				}
				else if (j == 6)
				{
					A_7_6 = morerandom() % 2;
				}
				else if (j == 7)
				{
					A_7_7 = morerandom() % 2;
				}
				else if (j == 8)
				{
					A_7_8 = morerandom() % 2;
				}
				else if (j == 9)
				{
					A_7_9 = morerandom() % 2;
				}
				j = j + 1;
			}
		}
		else if (i == 8)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					A_8_0 = morerandom() % 2;
				}
				else if (j == 1)
				{
					A_8_1 = morerandom() % 2;
				}
				else if (j == 2)
				{
					A_8_2 = morerandom() % 2;
				}
				else if (j == 3)
				{
					A_8_3 = morerandom() % 2;
				}
				else if (j == 4)
				{
					A_8_4 = morerandom() % 2;
				}
				else if (j == 5)
				{
					A_8_5 = morerandom() % 2;
				}
				else if (j == 6)
				{
					A_8_6 = morerandom() % 2;
				}
				else if (j == 7)
				{
					A_8_7 = morerandom() % 2;
				}
				else if (j == 8)
				{
					A_8_8 = morerandom() % 2;
				}
				else if (j == 9)
				{
					A_8_9 = morerandom() % 2;
				}
				j = j + 1;
			}
		}
		else if (i == 9)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					A_9_0 = morerandom() % 2;
				}
				else if (j == 1)
				{
					A_9_1 = morerandom() % 2;
				}
				else if (j == 2)
				{
					A_9_2 = morerandom() % 2;
				}
				else if (j == 3)
				{
					A_9_3 = morerandom() % 2;
				}
				else if (j == 4)
				{
					A_9_4 = morerandom() % 2;
				}
				else if (j == 5)
				{
					A_9_5 = morerandom() % 2;
				}
				else if (j == 6)
				{
					A_9_6 = morerandom() % 2;
				}
				else if (j == 7)
				{
					A_9_7 = morerandom() % 2;
				}
				else if (j == 8)
				{
					A_9_8 = morerandom() % 2;
				}
				else if (j == 9)
				{
					A_9_9 = morerandom() % 2;
				}
				j = j + 1;
			}
		}
		i = i + 1;
	}
	x = 1;
	while (x <= 10)
	{
		i = 0;
		while (i <= 9)
		{
			if (i == 0)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						n = neighbours(0, 0);
						if (A_0_0 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_0_0 = 1;
							}
							else
							{
								T_0_0 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_0_0 = 1;
							}
							else
							{
								T_0_0 = 0;
							}
						}
					}
					else if (j == 1)
					{
						n = neighbours(0, 1);
						if (A_0_1 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_0_1 = 1;
							}
							else
							{
								T_0_1 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_0_1 = 1;
							}
							else
							{
								T_0_1 = 0;
							}
						}
					}
					else if (j == 2)
					{
						n = neighbours(0, 2);
						if (A_0_2 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_0_2 = 1;
							}
							else
							{
								T_0_2 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_0_2 = 1;
							}
							else
							{
								T_0_2 = 0;
							}
						}
					}
					else if (j == 3)
					{
						n = neighbours(0, 3);
						if (A_0_3 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_0_3 = 1;
							}
							else
							{
								T_0_3 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_0_3 = 1;
							}
							else
							{
								T_0_3 = 0;
							}
						}
					}
					else if (j == 4)
					{
						n = neighbours(0, 4);
						if (A_0_4 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_0_4 = 1;
							}
							else
							{
								T_0_4 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_0_4 = 1;
							}
							else
							{
								T_0_4 = 0;
							}
						}
					}
					else if (j == 5)
					{
						n = neighbours(0, 5);
						if (A_0_5 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_0_5 = 1;
							}
							else
							{
								T_0_5 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_0_5 = 1;
							}
							else
							{
								T_0_5 = 0;
							}
						}
					}
					else if (j == 6)
					{
						n = neighbours(0, 6);
						if (A_0_6 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_0_6 = 1;
							}
							else
							{
								T_0_6 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_0_6 = 1;
							}
							else
							{
								T_0_6 = 0;
							}
						}
					}
					else if (j == 7)
					{
						n = neighbours(0, 7);
						if (A_0_7 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_0_7 = 1;
							}
							else
							{
								T_0_7 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_0_7 = 1;
							}
							else
							{
								T_0_7 = 0;
							}
						}
					}
					else if (j == 8)
					{
						n = neighbours(0, 8);
						if (A_0_8 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_0_8 = 1;
							}
							else
							{
								T_0_8 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_0_8 = 1;
							}
							else
							{
								T_0_8 = 0;
							}
						}
					}
					else if (j == 9)
					{
						n = neighbours(0, 9);
						if (A_0_9 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_0_9 = 1;
							}
							else
							{
								T_0_9 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_0_9 = 1;
							}
							else
							{
								T_0_9 = 0;
							}
						}
					}
					j = j + 1;
				}
			}
			else if (i == 1)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						n = neighbours(1, 0);
						if (A_1_0 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_1_0 = 1;
							}
							else
							{
								T_1_0 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_1_0 = 1;
							}
							else
							{
								T_1_0 = 0;
							}
						}
					}
					else if (j == 1)
					{
						n = neighbours(1, 1);
						if (A_1_1 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_1_1 = 1;
							}
							else
							{
								T_1_1 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_1_1 = 1;
							}
							else
							{
								T_1_1 = 0;
							}
						}
					}
					else if (j == 2)
					{
						n = neighbours(1, 2);
						if (A_1_2 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_1_2 = 1;
							}
							else
							{
								T_1_2 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_1_2 = 1;
							}
							else
							{
								T_1_2 = 0;
							}
						}
					}
					else if (j == 3)
					{
						n = neighbours(1, 3);
						if (A_1_3 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_1_3 = 1;
							}
							else
							{
								T_1_3 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_1_3 = 1;
							}
							else
							{
								T_1_3 = 0;
							}
						}
					}
					else if (j == 4)
					{
						n = neighbours(1, 4);
						if (A_1_4 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_1_4 = 1;
							}
							else
							{
								T_1_4 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_1_4 = 1;
							}
							else
							{
								T_1_4 = 0;
							}
						}
					}
					else if (j == 5)
					{
						n = neighbours(1, 5);
						if (A_1_5 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_1_5 = 1;
							}
							else
							{
								T_1_5 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_1_5 = 1;
							}
							else
							{
								T_1_5 = 0;
							}
						}
					}
					else if (j == 6)
					{
						n = neighbours(1, 6);
						if (A_1_6 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_1_6 = 1;
							}
							else
							{
								T_1_6 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_1_6 = 1;
							}
							else
							{
								T_1_6 = 0;
							}
						}
					}
					else if (j == 7)
					{
						n = neighbours(1, 7);
						if (A_1_7 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_1_7 = 1;
							}
							else
							{
								T_1_7 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_1_7 = 1;
							}
							else
							{
								T_1_7 = 0;
							}
						}
					}
					else if (j == 8)
					{
						n = neighbours(1, 8);
						if (A_1_8 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_1_8 = 1;
							}
							else
							{
								T_1_8 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_1_8 = 1;
							}
							else
							{
								T_1_8 = 0;
							}
						}
					}
					else if (j == 9)
					{
						n = neighbours(1, 9);
						if (A_1_9 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_1_9 = 1;
							}
							else
							{
								T_1_9 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_1_9 = 1;
							}
							else
							{
								T_1_9 = 0;
							}
						}
					}
					j = j + 1;
				}
			}
			else if (i == 2)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						n = neighbours(2, 0);
						if (A_2_0 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_2_0 = 1;
							}
							else
							{
								T_2_0 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_2_0 = 1;
							}
							else
							{
								T_2_0 = 0;
							}
						}
					}
					else if (j == 1)
					{
						n = neighbours(2, 1);
						if (A_2_1 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_2_1 = 1;
							}
							else
							{
								T_2_1 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_2_1 = 1;
							}
							else
							{
								T_2_1 = 0;
							}
						}
					}
					else if (j == 2)
					{
						n = neighbours(2, 2);
						if (A_2_2 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_2_2 = 1;
							}
							else
							{
								T_2_2 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_2_2 = 1;
							}
							else
							{
								T_2_2 = 0;
							}
						}
					}
					else if (j == 3)
					{
						n = neighbours(2, 3);
						if (A_2_3 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_2_3 = 1;
							}
							else
							{
								T_2_3 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_2_3 = 1;
							}
							else
							{
								T_2_3 = 0;
							}
						}
					}
					else if (j == 4)
					{
						n = neighbours(2, 4);
						if (A_2_4 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_2_4 = 1;
							}
							else
							{
								T_2_4 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_2_4 = 1;
							}
							else
							{
								T_2_4 = 0;
							}
						}
					}
					else if (j == 5)
					{
						n = neighbours(2, 5);
						if (A_2_5 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_2_5 = 1;
							}
							else
							{
								T_2_5 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_2_5 = 1;
							}
							else
							{
								T_2_5 = 0;
							}
						}
					}
					else if (j == 6)
					{
						n = neighbours(2, 6);
						if (A_2_6 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_2_6 = 1;
							}
							else
							{
								T_2_6 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_2_6 = 1;
							}
							else
							{
								T_2_6 = 0;
							}
						}
					}
					else if (j == 7)
					{
						n = neighbours(2, 7);
						if (A_2_7 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_2_7 = 1;
							}
							else
							{
								T_2_7 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_2_7 = 1;
							}
							else
							{
								T_2_7 = 0;
							}
						}
					}
					else if (j == 8)
					{
						n = neighbours(2, 8);
						if (A_2_8 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_2_8 = 1;
							}
							else
							{
								T_2_8 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_2_8 = 1;
							}
							else
							{
								T_2_8 = 0;
							}
						}
					}
					else if (j == 9)
					{
						n = neighbours(2, 9);
						if (A_2_9 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_2_9 = 1;
							}
							else
							{
								T_2_9 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_2_9 = 1;
							}
							else
							{
								T_2_9 = 0;
							}
						}
					}
					j = j + 1;
				}
			}
			else if (i == 3)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						n = neighbours(3, 0);
						if (A_3_0 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_3_0 = 1;
							}
							else
							{
								T_3_0 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_3_0 = 1;
							}
							else
							{
								T_3_0 = 0;
							}
						}
					}
					else if (j == 1)
					{
						n = neighbours(3, 1);
						if (A_3_1 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_3_1 = 1;
							}
							else
							{
								T_3_1 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_3_1 = 1;
							}
							else
							{
								T_3_1 = 0;
							}
						}
					}
					else if (j == 2)
					{
						n = neighbours(3, 2);
						if (A_3_2 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_3_2 = 1;
							}
							else
							{
								T_3_2 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_3_2 = 1;
							}
							else
							{
								T_3_2 = 0;
							}
						}
					}
					else if (j == 3)
					{
						n = neighbours(3, 3);
						if (A_3_3 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_3_3 = 1;
							}
							else
							{
								T_3_3 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_3_3 = 1;
							}
							else
							{
								T_3_3 = 0;
							}
						}
					}
					else if (j == 4)
					{
						n = neighbours(3, 4);
						if (A_3_4 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_3_4 = 1;
							}
							else
							{
								T_3_4 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_3_4 = 1;
							}
							else
							{
								T_3_4 = 0;
							}
						}
					}
					else if (j == 5)
					{
						n = neighbours(3, 5);
						if (A_3_5 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_3_5 = 1;
							}
							else
							{
								T_3_5 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_3_5 = 1;
							}
							else
							{
								T_3_5 = 0;
							}
						}
					}
					else if (j == 6)
					{
						n = neighbours(3, 6);
						if (A_3_6 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_3_6 = 1;
							}
							else
							{
								T_3_6 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_3_6 = 1;
							}
							else
							{
								T_3_6 = 0;
							}
						}
					}
					else if (j == 7)
					{
						n = neighbours(3, 7);
						if (A_3_7 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_3_7 = 1;
							}
							else
							{
								T_3_7 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_3_7 = 1;
							}
							else
							{
								T_3_7 = 0;
							}
						}
					}
					else if (j == 8)
					{
						n = neighbours(3, 8);
						if (A_3_8 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_3_8 = 1;
							}
							else
							{
								T_3_8 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_3_8 = 1;
							}
							else
							{
								T_3_8 = 0;
							}
						}
					}
					else if (j == 9)
					{
						n = neighbours(3, 9);
						if (A_3_9 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_3_9 = 1;
							}
							else
							{
								T_3_9 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_3_9 = 1;
							}
							else
							{
								T_3_9 = 0;
							}
						}
					}
					j = j + 1;
				}
			}
			else if (i == 4)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						n = neighbours(4, 0);
						if (A_4_0 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_4_0 = 1;
							}
							else
							{
								T_4_0 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_4_0 = 1;
							}
							else
							{
								T_4_0 = 0;
							}
						}
					}
					else if (j == 1)
					{
						n = neighbours(4, 1);
						if (A_4_1 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_4_1 = 1;
							}
							else
							{
								T_4_1 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_4_1 = 1;
							}
							else
							{
								T_4_1 = 0;
							}
						}
					}
					else if (j == 2)
					{
						n = neighbours(4, 2);
						if (A_4_2 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_4_2 = 1;
							}
							else
							{
								T_4_2 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_4_2 = 1;
							}
							else
							{
								T_4_2 = 0;
							}
						}
					}
					else if (j == 3)
					{
						n = neighbours(4, 3);
						if (A_4_3 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_4_3 = 1;
							}
							else
							{
								T_4_3 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_4_3 = 1;
							}
							else
							{
								T_4_3 = 0;
							}
						}
					}
					else if (j == 4)
					{
						n = neighbours(4, 4);
						if (A_4_4 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_4_4 = 1;
							}
							else
							{
								T_4_4 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_4_4 = 1;
							}
							else
							{
								T_4_4 = 0;
							}
						}
					}
					else if (j == 5)
					{
						n = neighbours(4, 5);
						if (A_4_5 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_4_5 = 1;
							}
							else
							{
								T_4_5 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_4_5 = 1;
							}
							else
							{
								T_4_5 = 0;
							}
						}
					}
					else if (j == 6)
					{
						n = neighbours(4, 6);
						if (A_4_6 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_4_6 = 1;
							}
							else
							{
								T_4_6 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_4_6 = 1;
							}
							else
							{
								T_4_6 = 0;
							}
						}
					}
					else if (j == 7)
					{
						n = neighbours(4, 7);
						if (A_4_7 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_4_7 = 1;
							}
							else
							{
								T_4_7 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_4_7 = 1;
							}
							else
							{
								T_4_7 = 0;
							}
						}
					}
					else if (j == 8)
					{
						n = neighbours(4, 8);
						if (A_4_8 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_4_8 = 1;
							}
							else
							{
								T_4_8 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_4_8 = 1;
							}
							else
							{
								T_4_8 = 0;
							}
						}
					}
					else if (j == 9)
					{
						n = neighbours(4, 9);
						if (A_4_9 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_4_9 = 1;
							}
							else
							{
								T_4_9 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_4_9 = 1;
							}
							else
							{
								T_4_9 = 0;
							}
						}
					}
					j = j + 1;
				}
			}
			else if (i == 5)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						n = neighbours(5, 0);
						if (A_5_0 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_5_0 = 1;
							}
							else
							{
								T_5_0 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_5_0 = 1;
							}
							else
							{
								T_5_0 = 0;
							}
						}
					}
					else if (j == 1)
					{
						n = neighbours(5, 1);
						if (A_5_1 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_5_1 = 1;
							}
							else
							{
								T_5_1 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_5_1 = 1;
							}
							else
							{
								T_5_1 = 0;
							}
						}
					}
					else if (j == 2)
					{
						n = neighbours(5, 2);
						if (A_5_2 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_5_2 = 1;
							}
							else
							{
								T_5_2 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_5_2 = 1;
							}
							else
							{
								T_5_2 = 0;
							}
						}
					}
					else if (j == 3)
					{
						n = neighbours(5, 3);
						if (A_5_3 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_5_3 = 1;
							}
							else
							{
								T_5_3 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_5_3 = 1;
							}
							else
							{
								T_5_3 = 0;
							}
						}
					}
					else if (j == 4)
					{
						n = neighbours(5, 4);
						if (A_5_4 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_5_4 = 1;
							}
							else
							{
								T_5_4 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_5_4 = 1;
							}
							else
							{
								T_5_4 = 0;
							}
						}
					}
					else if (j == 5)
					{
						n = neighbours(5, 5);
						if (A_5_5 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_5_5 = 1;
							}
							else
							{
								T_5_5 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_5_5 = 1;
							}
							else
							{
								T_5_5 = 0;
							}
						}
					}
					else if (j == 6)
					{
						n = neighbours(5, 6);
						if (A_5_6 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_5_6 = 1;
							}
							else
							{
								T_5_6 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_5_6 = 1;
							}
							else
							{
								T_5_6 = 0;
							}
						}
					}
					else if (j == 7)
					{
						n = neighbours(5, 7);
						if (A_5_7 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_5_7 = 1;
							}
							else
							{
								T_5_7 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_5_7 = 1;
							}
							else
							{
								T_5_7 = 0;
							}
						}
					}
					else if (j == 8)
					{
						n = neighbours(5, 8);
						if (A_5_8 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_5_8 = 1;
							}
							else
							{
								T_5_8 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_5_8 = 1;
							}
							else
							{
								T_5_8 = 0;
							}
						}
					}
					else if (j == 9)
					{
						n = neighbours(5, 9);
						if (A_5_9 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_5_9 = 1;
							}
							else
							{
								T_5_9 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_5_9 = 1;
							}
							else
							{
								T_5_9 = 0;
							}
						}
					}
					j = j + 1;
				}
			}
			else if (i == 6)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						n = neighbours(6, 0);
						if (A_6_0 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_6_0 = 1;
							}
							else
							{
								T_6_0 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_6_0 = 1;
							}
							else
							{
								T_6_0 = 0;
							}
						}
					}
					else if (j == 1)
					{
						n = neighbours(6, 1);
						if (A_6_1 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_6_1 = 1;
							}
							else
							{
								T_6_1 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_6_1 = 1;
							}
							else
							{
								T_6_1 = 0;
							}
						}
					}
					else if (j == 2)
					{
						n = neighbours(6, 2);
						if (A_6_2 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_6_2 = 1;
							}
							else
							{
								T_6_2 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_6_2 = 1;
							}
							else
							{
								T_6_2 = 0;
							}
						}
					}
					else if (j == 3)
					{
						n = neighbours(6, 3);
						if (A_6_3 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_6_3 = 1;
							}
							else
							{
								T_6_3 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_6_3 = 1;
							}
							else
							{
								T_6_3 = 0;
							}
						}
					}
					else if (j == 4)
					{
						n = neighbours(6, 4);
						if (A_6_4 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_6_4 = 1;
							}
							else
							{
								T_6_4 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_6_4 = 1;
							}
							else
							{
								T_6_4 = 0;
							}
						}
					}
					else if (j == 5)
					{
						n = neighbours(6, 5);
						if (A_6_5 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_6_5 = 1;
							}
							else
							{
								T_6_5 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_6_5 = 1;
							}
							else
							{
								T_6_5 = 0;
							}
						}
					}
					else if (j == 6)
					{
						n = neighbours(6, 6);
						if (A_6_6 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_6_6 = 1;
							}
							else
							{
								T_6_6 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_6_6 = 1;
							}
							else
							{
								T_6_6 = 0;
							}
						}
					}
					else if (j == 7)
					{
						n = neighbours(6, 7);
						if (A_6_7 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_6_7 = 1;
							}
							else
							{
								T_6_7 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_6_7 = 1;
							}
							else
							{
								T_6_7 = 0;
							}
						}
					}
					else if (j == 8)
					{
						n = neighbours(6, 8);
						if (A_6_8 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_6_8 = 1;
							}
							else
							{
								T_6_8 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_6_8 = 1;
							}
							else
							{
								T_6_8 = 0;
							}
						}
					}
					else if (j == 9)
					{
						n = neighbours(6, 9);
						if (A_6_9 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_6_9 = 1;
							}
							else
							{
								T_6_9 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_6_9 = 1;
							}
							else
							{
								T_6_9 = 0;
							}
						}
					}
					j = j + 1;
				}
			}
			else if (i == 7)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						n = neighbours(7, 0);
						if (A_7_0 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_7_0 = 1;
							}
							else
							{
								T_7_0 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_7_0 = 1;
							}
							else
							{
								T_7_0 = 0;
							}
						}
					}
					else if (j == 1)
					{
						n = neighbours(7, 1);
						if (A_7_1 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_7_1 = 1;
							}
							else
							{
								T_7_1 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_7_1 = 1;
							}
							else
							{
								T_7_1 = 0;
							}
						}
					}
					else if (j == 2)
					{
						n = neighbours(7, 2);
						if (A_7_2 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_7_2 = 1;
							}
							else
							{
								T_7_2 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_7_2 = 1;
							}
							else
							{
								T_7_2 = 0;
							}
						}
					}
					else if (j == 3)
					{
						n = neighbours(7, 3);
						if (A_7_3 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_7_3 = 1;
							}
							else
							{
								T_7_3 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_7_3 = 1;
							}
							else
							{
								T_7_3 = 0;
							}
						}
					}
					else if (j == 4)
					{
						n = neighbours(7, 4);
						if (A_7_4 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_7_4 = 1;
							}
							else
							{
								T_7_4 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_7_4 = 1;
							}
							else
							{
								T_7_4 = 0;
							}
						}
					}
					else if (j == 5)
					{
						n = neighbours(7, 5);
						if (A_7_5 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_7_5 = 1;
							}
							else
							{
								T_7_5 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_7_5 = 1;
							}
							else
							{
								T_7_5 = 0;
							}
						}
					}
					else if (j == 6)
					{
						n = neighbours(7, 6);
						if (A_7_6 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_7_6 = 1;
							}
							else
							{
								T_7_6 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_7_6 = 1;
							}
							else
							{
								T_7_6 = 0;
							}
						}
					}
					else if (j == 7)
					{
						n = neighbours(7, 7);
						if (A_7_7 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_7_7 = 1;
							}
							else
							{
								T_7_7 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_7_7 = 1;
							}
							else
							{
								T_7_7 = 0;
							}
						}
					}
					else if (j == 8)
					{
						n = neighbours(7, 8);
						if (A_7_8 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_7_8 = 1;
							}
							else
							{
								T_7_8 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_7_8 = 1;
							}
							else
							{
								T_7_8 = 0;
							}
						}
					}
					else if (j == 9)
					{
						n = neighbours(7, 9);
						if (A_7_9 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_7_9 = 1;
							}
							else
							{
								T_7_9 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_7_9 = 1;
							}
							else
							{
								T_7_9 = 0;
							}
						}
					}
					j = j + 1;
				}
			}
			else if (i == 8)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						n = neighbours(8, 0);
						if (A_8_0 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_8_0 = 1;
							}
							else
							{
								T_8_0 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_8_0 = 1;
							}
							else
							{
								T_8_0 = 0;
							}
						}
					}
					else if (j == 1)
					{
						n = neighbours(8, 1);
						if (A_8_1 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_8_1 = 1;
							}
							else
							{
								T_8_1 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_8_1 = 1;
							}
							else
							{
								T_8_1 = 0;
							}
						}
					}
					else if (j == 2)
					{
						n = neighbours(8, 2);
						if (A_8_2 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_8_2 = 1;
							}
							else
							{
								T_8_2 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_8_2 = 1;
							}
							else
							{
								T_8_2 = 0;
							}
						}
					}
					else if (j == 3)
					{
						n = neighbours(8, 3);
						if (A_8_3 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_8_3 = 1;
							}
							else
							{
								T_8_3 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_8_3 = 1;
							}
							else
							{
								T_8_3 = 0;
							}
						}
					}
					else if (j == 4)
					{
						n = neighbours(8, 4);
						if (A_8_4 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_8_4 = 1;
							}
							else
							{
								T_8_4 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_8_4 = 1;
							}
							else
							{
								T_8_4 = 0;
							}
						}
					}
					else if (j == 5)
					{
						n = neighbours(8, 5);
						if (A_8_5 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_8_5 = 1;
							}
							else
							{
								T_8_5 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_8_5 = 1;
							}
							else
							{
								T_8_5 = 0;
							}
						}
					}
					else if (j == 6)
					{
						n = neighbours(8, 6);
						if (A_8_6 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_8_6 = 1;
							}
							else
							{
								T_8_6 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_8_6 = 1;
							}
							else
							{
								T_8_6 = 0;
							}
						}
					}
					else if (j == 7)
					{
						n = neighbours(8, 7);
						if (A_8_7 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_8_7 = 1;
							}
							else
							{
								T_8_7 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_8_7 = 1;
							}
							else
							{
								T_8_7 = 0;
							}
						}
					}
					else if (j == 8)
					{
						n = neighbours(8, 8);
						if (A_8_8 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_8_8 = 1;
							}
							else
							{
								T_8_8 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_8_8 = 1;
							}
							else
							{
								T_8_8 = 0;
							}
						}
					}
					else if (j == 9)
					{
						n = neighbours(8, 9);
						if (A_8_9 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_8_9 = 1;
							}
							else
							{
								T_8_9 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_8_9 = 1;
							}
							else
							{
								T_8_9 = 0;
							}
						}
					}
					j = j + 1;
				}
			}
			else if (i == 9)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						n = neighbours(9, 0);
						if (A_9_0 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_9_0 = 1;
							}
							else
							{
								T_9_0 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_9_0 = 1;
							}
							else
							{
								T_9_0 = 0;
							}
						}
					}
					else if (j == 1)
					{
						n = neighbours(9, 1);
						if (A_9_1 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_9_1 = 1;
							}
							else
							{
								T_9_1 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_9_1 = 1;
							}
							else
							{
								T_9_1 = 0;
							}
						}
					}
					else if (j == 2)
					{
						n = neighbours(9, 2);
						if (A_9_2 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_9_2 = 1;
							}
							else
							{
								T_9_2 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_9_2 = 1;
							}
							else
							{
								T_9_2 = 0;
							}
						}
					}
					else if (j == 3)
					{
						n = neighbours(9, 3);
						if (A_9_3 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_9_3 = 1;
							}
							else
							{
								T_9_3 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_9_3 = 1;
							}
							else
							{
								T_9_3 = 0;
							}
						}
					}
					else if (j == 4)
					{
						n = neighbours(9, 4);
						if (A_9_4 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_9_4 = 1;
							}
							else
							{
								T_9_4 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_9_4 = 1;
							}
							else
							{
								T_9_4 = 0;
							}
						}
					}
					else if (j == 5)
					{
						n = neighbours(9, 5);
						if (A_9_5 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_9_5 = 1;
							}
							else
							{
								T_9_5 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_9_5 = 1;
							}
							else
							{
								T_9_5 = 0;
							}
						}
					}
					else if (j == 6)
					{
						n = neighbours(9, 6);
						if (A_9_6 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_9_6 = 1;
							}
							else
							{
								T_9_6 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_9_6 = 1;
							}
							else
							{
								T_9_6 = 0;
							}
						}
					}
					else if (j == 7)
					{
						n = neighbours(9, 7);
						if (A_9_7 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_9_7 = 1;
							}
							else
							{
								T_9_7 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_9_7 = 1;
							}
							else
							{
								T_9_7 = 0;
							}
						}
					}
					else if (j == 8)
					{
						n = neighbours(9, 8);
						if (A_9_8 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_9_8 = 1;
							}
							else
							{
								T_9_8 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_9_8 = 1;
							}
							else
							{
								T_9_8 = 0;
							}
						}
					}
					else if (j == 9)
					{
						n = neighbours(9, 9);
						if (A_9_9 == 1)
						{
							if (n == 2 || n == 3)
							{
								T_9_9 = 1;
							}
							else
							{
								T_9_9 = 0;
							}
						}
						else
						{
							if (n == 3)
							{
								T_9_9 = 1;
							}
							else
							{
								T_9_9 = 0;
							}
						}
					}
					j = j + 1;
				}
			}
			i = i + 1;
		}
		i = 0;
		while (i <= 9)
		{
			if (i == 0)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						A_0_0 = T_0_0;
					}
					else if (j == 1)
					{
						A_0_1 = T_0_1;
					}
					else if (j == 2)
					{
						A_0_2 = T_0_2;
					}
					else if (j == 3)
					{
						A_0_3 = T_0_3;
					}
					else if (j == 4)
					{
						A_0_4 = T_0_4;
					}
					else if (j == 5)
					{
						A_0_5 = T_0_5;
					}
					else if (j == 6)
					{
						A_0_6 = T_0_6;
					}
					else if (j == 7)
					{
						A_0_7 = T_0_7;
					}
					else if (j == 8)
					{
						A_0_8 = T_0_8;
					}
					else if (j == 9)
					{
						A_0_9 = T_0_9;
					}
					j = j + 1;
				}
			}
			else if (i == 1)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						A_1_0 = T_1_0;
					}
					else if (j == 1)
					{
						A_1_1 = T_1_1;
					}
					else if (j == 2)
					{
						A_1_2 = T_1_2;
					}
					else if (j == 3)
					{
						A_1_3 = T_1_3;
					}
					else if (j == 4)
					{
						A_1_4 = T_1_4;
					}
					else if (j == 5)
					{
						A_1_5 = T_1_5;
					}
					else if (j == 6)
					{
						A_1_6 = T_1_6;
					}
					else if (j == 7)
					{
						A_1_7 = T_1_7;
					}
					else if (j == 8)
					{
						A_1_8 = T_1_8;
					}
					else if (j == 9)
					{
						A_1_9 = T_1_9;
					}
					j = j + 1;
				}
			}
			else if (i == 2)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						A_2_0 = T_2_0;
					}
					else if (j == 1)
					{
						A_2_1 = T_2_1;
					}
					else if (j == 2)
					{
						A_2_2 = T_2_2;
					}
					else if (j == 3)
					{
						A_2_3 = T_2_3;
					}
					else if (j == 4)
					{
						A_2_4 = T_2_4;
					}
					else if (j == 5)
					{
						A_2_5 = T_2_5;
					}
					else if (j == 6)
					{
						A_2_6 = T_2_6;
					}
					else if (j == 7)
					{
						A_2_7 = T_2_7;
					}
					else if (j == 8)
					{
						A_2_8 = T_2_8;
					}
					else if (j == 9)
					{
						A_2_9 = T_2_9;
					}
					j = j + 1;
				}
			}
			else if (i == 3)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						A_3_0 = T_3_0;
					}
					else if (j == 1)
					{
						A_3_1 = T_3_1;
					}
					else if (j == 2)
					{
						A_3_2 = T_3_2;
					}
					else if (j == 3)
					{
						A_3_3 = T_3_3;
					}
					else if (j == 4)
					{
						A_3_4 = T_3_4;
					}
					else if (j == 5)
					{
						A_3_5 = T_3_5;
					}
					else if (j == 6)
					{
						A_3_6 = T_3_6;
					}
					else if (j == 7)
					{
						A_3_7 = T_3_7;
					}
					else if (j == 8)
					{
						A_3_8 = T_3_8;
					}
					else if (j == 9)
					{
						A_3_9 = T_3_9;
					}
					j = j + 1;
				}
			}
			else if (i == 4)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						A_4_0 = T_4_0;
					}
					else if (j == 1)
					{
						A_4_1 = T_4_1;
					}
					else if (j == 2)
					{
						A_4_2 = T_4_2;
					}
					else if (j == 3)
					{
						A_4_3 = T_4_3;
					}
					else if (j == 4)
					{
						A_4_4 = T_4_4;
					}
					else if (j == 5)
					{
						A_4_5 = T_4_5;
					}
					else if (j == 6)
					{
						A_4_6 = T_4_6;
					}
					else if (j == 7)
					{
						A_4_7 = T_4_7;
					}
					else if (j == 8)
					{
						A_4_8 = T_4_8;
					}
					else if (j == 9)
					{
						A_4_9 = T_4_9;
					}
					j = j + 1;
				}
			}
			else if (i == 5)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						A_5_0 = T_5_0;
					}
					else if (j == 1)
					{
						A_5_1 = T_5_1;
					}
					else if (j == 2)
					{
						A_5_2 = T_5_2;
					}
					else if (j == 3)
					{
						A_5_3 = T_5_3;
					}
					else if (j == 4)
					{
						A_5_4 = T_5_4;
					}
					else if (j == 5)
					{
						A_5_5 = T_5_5;
					}
					else if (j == 6)
					{
						A_5_6 = T_5_6;
					}
					else if (j == 7)
					{
						A_5_7 = T_5_7;
					}
					else if (j == 8)
					{
						A_5_8 = T_5_8;
					}
					else if (j == 9)
					{
						A_5_9 = T_5_9;
					}
					j = j + 1;
				}
			}
			else if (i == 6)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						A_6_0 = T_6_0;
					}
					else if (j == 1)
					{
						A_6_1 = T_6_1;
					}
					else if (j == 2)
					{
						A_6_2 = T_6_2;
					}
					else if (j == 3)
					{
						A_6_3 = T_6_3;
					}
					else if (j == 4)
					{
						A_6_4 = T_6_4;
					}
					else if (j == 5)
					{
						A_6_5 = T_6_5;
					}
					else if (j == 6)
					{
						A_6_6 = T_6_6;
					}
					else if (j == 7)
					{
						A_6_7 = T_6_7;
					}
					else if (j == 8)
					{
						A_6_8 = T_6_8;
					}
					else if (j == 9)
					{
						A_6_9 = T_6_9;
					}
					j = j + 1;
				}
			}
			else if (i == 7)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						A_7_0 = T_7_0;
					}
					else if (j == 1)
					{
						A_7_1 = T_7_1;
					}
					else if (j == 2)
					{
						A_7_2 = T_7_2;
					}
					else if (j == 3)
					{
						A_7_3 = T_7_3;
					}
					else if (j == 4)
					{
						A_7_4 = T_7_4;
					}
					else if (j == 5)
					{
						A_7_5 = T_7_5;
					}
					else if (j == 6)
					{
						A_7_6 = T_7_6;
					}
					else if (j == 7)
					{
						A_7_7 = T_7_7;
					}
					else if (j == 8)
					{
						A_7_8 = T_7_8;
					}
					else if (j == 9)
					{
						A_7_9 = T_7_9;
					}
					j = j + 1;
				}
			}
			else if (i == 8)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						A_8_0 = T_8_0;
					}
					else if (j == 1)
					{
						A_8_1 = T_8_1;
					}
					else if (j == 2)
					{
						A_8_2 = T_8_2;
					}
					else if (j == 3)
					{
						A_8_3 = T_8_3;
					}
					else if (j == 4)
					{
						A_8_4 = T_8_4;
					}
					else if (j == 5)
					{
						A_8_5 = T_8_5;
					}
					else if (j == 6)
					{
						A_8_6 = T_8_6;
					}
					else if (j == 7)
					{
						A_8_7 = T_8_7;
					}
					else if (j == 8)
					{
						A_8_8 = T_8_8;
					}
					else if (j == 9)
					{
						A_8_9 = T_8_9;
					}
					j = j + 1;
				}
			}
			else if (i == 9)
			{
				j = 0;
				while (j <= 9)
				{
					if (j == 0)
					{
						A_9_0 = T_9_0;
					}
					else if (j == 1)
					{
						A_9_1 = T_9_1;
					}
					else if (j == 2)
					{
						A_9_2 = T_9_2;
					}
					else if (j == 3)
					{
						A_9_3 = T_9_3;
					}
					else if (j == 4)
					{
						A_9_4 = T_9_4;
					}
					else if (j == 5)
					{
						A_9_5 = T_9_5;
					}
					else if (j == 6)
					{
						A_9_6 = T_9_6;
					}
					else if (j == 7)
					{
						A_9_7 = T_9_7;
					}
					else if (j == 8)
					{
						A_9_8 = T_9_8;
					}
					else if (j == 9)
					{
						A_9_9 = T_9_9;
					}
					j = j + 1;
				}
			}
			i = i + 1;
		}
		printboard(x);
		x = x + 1;
	}
}
int neighbours(int y, int x)
{
	int n;
	n = 0;
	if (y == 0)
	{
		if (x == 0)
		{
			if (0 > 0)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (0 < 9)
				{
					n = n + not_there;
				}
			}
			if (0 > 0)
			{
				n = n + not_there;
			}
			if (0 < 9)
			{
				n = n + A_0_1;
			}
			if (0 < 9)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_1_0;
				if (0 < 9)
				{
					n = n + A_1_1;
				}
			}
		}
		else if (x == 1)
		{
			if (0 > 0)
			{
				if (1 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (1 < 9)
				{
					n = n + not_there;
				}
			}
			if (1 > 0)
			{
				n = n + A_0_0;
			}
			if (1 < 9)
			{
				n = n + A_0_2;
			}
			if (0 < 9)
			{
				if (1 > 0)
				{
					n = n + A_1_0;
				}
				n = n + A_1_1;
				if (1 < 9)
				{
					n = n + A_1_2;
				}
			}
		}
		else if (x == 2)
		{
			if (0 > 0)
			{
				if (2 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (2 < 9)
				{
					n = n + not_there;
				}
			}
			if (2 > 0)
			{
				n = n + A_0_1;
			}
			if (2 < 9)
			{
				n = n + A_0_3;
			}
			if (0 < 9)
			{
				if (2 > 0)
				{
					n = n + A_1_1;
				}
				n = n + A_1_2;
				if (2 < 9)
				{
					n = n + A_1_3;
				}
			}
		}
		else if (x == 3)
		{
			if (0 > 0)
			{
				if (3 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (3 < 9)
				{
					n = n + not_there;
				}
			}
			if (3 > 0)
			{
				n = n + A_0_2;
			}
			if (3 < 9)
			{
				n = n + A_0_4;
			}
			if (0 < 9)
			{
				if (3 > 0)
				{
					n = n + A_1_2;
				}
				n = n + A_1_3;
				if (3 < 9)
				{
					n = n + A_1_4;
				}
			}
		}
		else if (x == 4)
		{
			if (0 > 0)
			{
				if (4 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (4 < 9)
				{
					n = n + not_there;
				}
			}
			if (4 > 0)
			{
				n = n + A_0_3;
			}
			if (4 < 9)
			{
				n = n + A_0_5;
			}
			if (0 < 9)
			{
				if (4 > 0)
				{
					n = n + A_1_3;
				}
				n = n + A_1_4;
				if (4 < 9)
				{
					n = n + A_1_5;
				}
			}
		}
		else if (x == 5)
		{
			if (0 > 0)
			{
				if (5 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (5 < 9)
				{
					n = n + not_there;
				}
			}
			if (5 > 0)
			{
				n = n + A_0_4;
			}
			if (5 < 9)
			{
				n = n + A_0_6;
			}
			if (0 < 9)
			{
				if (5 > 0)
				{
					n = n + A_1_4;
				}
				n = n + A_1_5;
				if (5 < 9)
				{
					n = n + A_1_6;
				}
			}
		}
		else if (x == 6)
		{
			if (0 > 0)
			{
				if (6 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (6 < 9)
				{
					n = n + not_there;
				}
			}
			if (6 > 0)
			{
				n = n + A_0_5;
			}
			if (6 < 9)
			{
				n = n + A_0_7;
			}
			if (0 < 9)
			{
				if (6 > 0)
				{
					n = n + A_1_5;
				}
				n = n + A_1_6;
				if (6 < 9)
				{
					n = n + A_1_7;
				}
			}
		}
		else if (x == 7)
		{
			if (0 > 0)
			{
				if (7 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (7 < 9)
				{
					n = n + not_there;
				}
			}
			if (7 > 0)
			{
				n = n + A_0_6;
			}
			if (7 < 9)
			{
				n = n + A_0_8;
			}
			if (0 < 9)
			{
				if (7 > 0)
				{
					n = n + A_1_6;
				}
				n = n + A_1_7;
				if (7 < 9)
				{
					n = n + A_1_8;
				}
			}
		}
		else if (x == 8)
		{
			if (0 > 0)
			{
				if (8 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (8 < 9)
				{
					n = n + not_there;
				}
			}
			if (8 > 0)
			{
				n = n + A_0_7;
			}
			if (8 < 9)
			{
				n = n + A_0_9;
			}
			if (0 < 9)
			{
				if (8 > 0)
				{
					n = n + A_1_7;
				}
				n = n + A_1_8;
				if (8 < 9)
				{
					n = n + A_1_9;
				}
			}
		}
		else if (x == 9)
		{
			if (0 > 0)
			{
				if (9 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
			if (9 > 0)
			{
				n = n + A_0_8;
			}
			if (9 < 9)
			{
				n = n + not_there;
			}
			if (0 < 9)
			{
				if (9 > 0)
				{
					n = n + A_1_8;
				}
				n = n + A_1_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
		}
	}
	else if (y == 1)
	{
		if (x == 0)
		{
			if (1 > 0)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_0_0;
				if (0 < 9)
				{
					n = n + A_0_1;
				}
			}
			if (0 > 0)
			{
				n = n + not_there;
			}
			if (0 < 9)
			{
				n = n + A_1_1;
			}
			if (1 < 9)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_2_0;
				if (0 < 9)
				{
					n = n + A_2_1;
				}
			}
		}
		else if (x == 1)
		{
			if (1 > 0)
			{
				if (1 > 0)
				{
					n = n + A_0_0;
				}
				n = n + A_0_1;
				if (1 < 9)
				{
					n = n + A_0_2;
				}
			}
			if (1 > 0)
			{
				n = n + A_1_0;
			}
			if (1 < 9)
			{
				n = n + A_1_2;
			}
			if (1 < 9)
			{
				if (1 > 0)
				{
					n = n + A_2_0;
				}
				n = n + A_2_1;
				if (1 < 9)
				{
					n = n + A_2_2;
				}
			}
		}
		else if (x == 2)
		{
			if (1 > 0)
			{
				if (2 > 0)
				{
					n = n + A_0_1;
				}
				n = n + A_0_2;
				if (2 < 9)
				{
					n = n + A_0_3;
				}
			}
			if (2 > 0)
			{
				n = n + A_1_1;
			}
			if (2 < 9)
			{
				n = n + A_1_3;
			}
			if (1 < 9)
			{
				if (2 > 0)
				{
					n = n + A_2_1;
				}
				n = n + A_2_2;
				if (2 < 9)
				{
					n = n + A_2_3;
				}
			}
		}
		else if (x == 3)
		{
			if (1 > 0)
			{
				if (3 > 0)
				{
					n = n + A_0_2;
				}
				n = n + A_0_3;
				if (3 < 9)
				{
					n = n + A_0_4;
				}
			}
			if (3 > 0)
			{
				n = n + A_1_2;
			}
			if (3 < 9)
			{
				n = n + A_1_4;
			}
			if (1 < 9)
			{
				if (3 > 0)
				{
					n = n + A_2_2;
				}
				n = n + A_2_3;
				if (3 < 9)
				{
					n = n + A_2_4;
				}
			}
		}
		else if (x == 4)
		{
			if (1 > 0)
			{
				if (4 > 0)
				{
					n = n + A_0_3;
				}
				n = n + A_0_4;
				if (4 < 9)
				{
					n = n + A_0_5;
				}
			}
			if (4 > 0)
			{
				n = n + A_1_3;
			}
			if (4 < 9)
			{
				n = n + A_1_5;
			}
			if (1 < 9)
			{
				if (4 > 0)
				{
					n = n + A_2_3;
				}
				n = n + A_2_4;
				if (4 < 9)
				{
					n = n + A_2_5;
				}
			}
		}
		else if (x == 5)
		{
			if (1 > 0)
			{
				if (5 > 0)
				{
					n = n + A_0_4;
				}
				n = n + A_0_5;
				if (5 < 9)
				{
					n = n + A_0_6;
				}
			}
			if (5 > 0)
			{
				n = n + A_1_4;
			}
			if (5 < 9)
			{
				n = n + A_1_6;
			}
			if (1 < 9)
			{
				if (5 > 0)
				{
					n = n + A_2_4;
				}
				n = n + A_2_5;
				if (5 < 9)
				{
					n = n + A_2_6;
				}
			}
		}
		else if (x == 6)
		{
			if (1 > 0)
			{
				if (6 > 0)
				{
					n = n + A_0_5;
				}
				n = n + A_0_6;
				if (6 < 9)
				{
					n = n + A_0_7;
				}
			}
			if (6 > 0)
			{
				n = n + A_1_5;
			}
			if (6 < 9)
			{
				n = n + A_1_7;
			}
			if (1 < 9)
			{
				if (6 > 0)
				{
					n = n + A_2_5;
				}
				n = n + A_2_6;
				if (6 < 9)
				{
					n = n + A_2_7;
				}
			}
		}
		else if (x == 7)
		{
			if (1 > 0)
			{
				if (7 > 0)
				{
					n = n + A_0_6;
				}
				n = n + A_0_7;
				if (7 < 9)
				{
					n = n + A_0_8;
				}
			}
			if (7 > 0)
			{
				n = n + A_1_6;
			}
			if (7 < 9)
			{
				n = n + A_1_8;
			}
			if (1 < 9)
			{
				if (7 > 0)
				{
					n = n + A_2_6;
				}
				n = n + A_2_7;
				if (7 < 9)
				{
					n = n + A_2_8;
				}
			}
		}
		else if (x == 8)
		{
			if (1 > 0)
			{
				if (8 > 0)
				{
					n = n + A_0_7;
				}
				n = n + A_0_8;
				if (8 < 9)
				{
					n = n + A_0_9;
				}
			}
			if (8 > 0)
			{
				n = n + A_1_7;
			}
			if (8 < 9)
			{
				n = n + A_1_9;
			}
			if (1 < 9)
			{
				if (8 > 0)
				{
					n = n + A_2_7;
				}
				n = n + A_2_8;
				if (8 < 9)
				{
					n = n + A_2_9;
				}
			}
		}
		else if (x == 9)
		{
			if (1 > 0)
			{
				if (9 > 0)
				{
					n = n + A_0_8;
				}
				n = n + A_0_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
			if (9 > 0)
			{
				n = n + A_1_8;
			}
			if (9 < 9)
			{
				n = n + not_there;
			}
			if (1 < 9)
			{
				if (9 > 0)
				{
					n = n + A_2_8;
				}
				n = n + A_2_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
		}
	}
	else if (y == 2)
	{
		if (x == 0)
		{
			if (2 > 0)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_1_0;
				if (0 < 9)
				{
					n = n + A_1_1;
				}
			}
			if (0 > 0)
			{
				n = n + not_there;
			}
			if (0 < 9)
			{
				n = n + A_2_1;
			}
			if (2 < 9)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_3_0;
				if (0 < 9)
				{
					n = n + A_3_1;
				}
			}
		}
		else if (x == 1)
		{
			if (2 > 0)
			{
				if (1 > 0)
				{
					n = n + A_1_0;
				}
				n = n + A_1_1;
				if (1 < 9)
				{
					n = n + A_1_2;
				}
			}
			if (1 > 0)
			{
				n = n + A_2_0;
			}
			if (1 < 9)
			{
				n = n + A_2_2;
			}
			if (2 < 9)
			{
				if (1 > 0)
				{
					n = n + A_3_0;
				}
				n = n + A_3_1;
				if (1 < 9)
				{
					n = n + A_3_2;
				}
			}
		}
		else if (x == 2)
		{
			if (2 > 0)
			{
				if (2 > 0)
				{
					n = n + A_1_1;
				}
				n = n + A_1_2;
				if (2 < 9)
				{
					n = n + A_1_3;
				}
			}
			if (2 > 0)
			{
				n = n + A_2_1;
			}
			if (2 < 9)
			{
				n = n + A_2_3;
			}
			if (2 < 9)
			{
				if (2 > 0)
				{
					n = n + A_3_1;
				}
				n = n + A_3_2;
				if (2 < 9)
				{
					n = n + A_3_3;
				}
			}
		}
		else if (x == 3)
		{
			if (2 > 0)
			{
				if (3 > 0)
				{
					n = n + A_1_2;
				}
				n = n + A_1_3;
				if (3 < 9)
				{
					n = n + A_1_4;
				}
			}
			if (3 > 0)
			{
				n = n + A_2_2;
			}
			if (3 < 9)
			{
				n = n + A_2_4;
			}
			if (2 < 9)
			{
				if (3 > 0)
				{
					n = n + A_3_2;
				}
				n = n + A_3_3;
				if (3 < 9)
				{
					n = n + A_3_4;
				}
			}
		}
		else if (x == 4)
		{
			if (2 > 0)
			{
				if (4 > 0)
				{
					n = n + A_1_3;
				}
				n = n + A_1_4;
				if (4 < 9)
				{
					n = n + A_1_5;
				}
			}
			if (4 > 0)
			{
				n = n + A_2_3;
			}
			if (4 < 9)
			{
				n = n + A_2_5;
			}
			if (2 < 9)
			{
				if (4 > 0)
				{
					n = n + A_3_3;
				}
				n = n + A_3_4;
				if (4 < 9)
				{
					n = n + A_3_5;
				}
			}
		}
		else if (x == 5)
		{
			if (2 > 0)
			{
				if (5 > 0)
				{
					n = n + A_1_4;
				}
				n = n + A_1_5;
				if (5 < 9)
				{
					n = n + A_1_6;
				}
			}
			if (5 > 0)
			{
				n = n + A_2_4;
			}
			if (5 < 9)
			{
				n = n + A_2_6;
			}
			if (2 < 9)
			{
				if (5 > 0)
				{
					n = n + A_3_4;
				}
				n = n + A_3_5;
				if (5 < 9)
				{
					n = n + A_3_6;
				}
			}
		}
		else if (x == 6)
		{
			if (2 > 0)
			{
				if (6 > 0)
				{
					n = n + A_1_5;
				}
				n = n + A_1_6;
				if (6 < 9)
				{
					n = n + A_1_7;
				}
			}
			if (6 > 0)
			{
				n = n + A_2_5;
			}
			if (6 < 9)
			{
				n = n + A_2_7;
			}
			if (2 < 9)
			{
				if (6 > 0)
				{
					n = n + A_3_5;
				}
				n = n + A_3_6;
				if (6 < 9)
				{
					n = n + A_3_7;
				}
			}
		}
		else if (x == 7)
		{
			if (2 > 0)
			{
				if (7 > 0)
				{
					n = n + A_1_6;
				}
				n = n + A_1_7;
				if (7 < 9)
				{
					n = n + A_1_8;
				}
			}
			if (7 > 0)
			{
				n = n + A_2_6;
			}
			if (7 < 9)
			{
				n = n + A_2_8;
			}
			if (2 < 9)
			{
				if (7 > 0)
				{
					n = n + A_3_6;
				}
				n = n + A_3_7;
				if (7 < 9)
				{
					n = n + A_3_8;
				}
			}
		}
		else if (x == 8)
		{
			if (2 > 0)
			{
				if (8 > 0)
				{
					n = n + A_1_7;
				}
				n = n + A_1_8;
				if (8 < 9)
				{
					n = n + A_1_9;
				}
			}
			if (8 > 0)
			{
				n = n + A_2_7;
			}
			if (8 < 9)
			{
				n = n + A_2_9;
			}
			if (2 < 9)
			{
				if (8 > 0)
				{
					n = n + A_3_7;
				}
				n = n + A_3_8;
				if (8 < 9)
				{
					n = n + A_3_9;
				}
			}
		}
		else if (x == 9)
		{
			if (2 > 0)
			{
				if (9 > 0)
				{
					n = n + A_1_8;
				}
				n = n + A_1_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
			if (9 > 0)
			{
				n = n + A_2_8;
			}
			if (9 < 9)
			{
				n = n + not_there;
			}
			if (2 < 9)
			{
				if (9 > 0)
				{
					n = n + A_3_8;
				}
				n = n + A_3_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
		}
	}
	else if (y == 3)
	{
		if (x == 0)
		{
			if (3 > 0)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_2_0;
				if (0 < 9)
				{
					n = n + A_2_1;
				}
			}
			if (0 > 0)
			{
				n = n + not_there;
			}
			if (0 < 9)
			{
				n = n + A_3_1;
			}
			if (3 < 9)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_4_0;
				if (0 < 9)
				{
					n = n + A_4_1;
				}
			}
		}
		else if (x == 1)
		{
			if (3 > 0)
			{
				if (1 > 0)
				{
					n = n + A_2_0;
				}
				n = n + A_2_1;
				if (1 < 9)
				{
					n = n + A_2_2;
				}
			}
			if (1 > 0)
			{
				n = n + A_3_0;
			}
			if (1 < 9)
			{
				n = n + A_3_2;
			}
			if (3 < 9)
			{
				if (1 > 0)
				{
					n = n + A_4_0;
				}
				n = n + A_4_1;
				if (1 < 9)
				{
					n = n + A_4_2;
				}
			}
		}
		else if (x == 2)
		{
			if (3 > 0)
			{
				if (2 > 0)
				{
					n = n + A_2_1;
				}
				n = n + A_2_2;
				if (2 < 9)
				{
					n = n + A_2_3;
				}
			}
			if (2 > 0)
			{
				n = n + A_3_1;
			}
			if (2 < 9)
			{
				n = n + A_3_3;
			}
			if (3 < 9)
			{
				if (2 > 0)
				{
					n = n + A_4_1;
				}
				n = n + A_4_2;
				if (2 < 9)
				{
					n = n + A_4_3;
				}
			}
		}
		else if (x == 3)
		{
			if (3 > 0)
			{
				if (3 > 0)
				{
					n = n + A_2_2;
				}
				n = n + A_2_3;
				if (3 < 9)
				{
					n = n + A_2_4;
				}
			}
			if (3 > 0)
			{
				n = n + A_3_2;
			}
			if (3 < 9)
			{
				n = n + A_3_4;
			}
			if (3 < 9)
			{
				if (3 > 0)
				{
					n = n + A_4_2;
				}
				n = n + A_4_3;
				if (3 < 9)
				{
					n = n + A_4_4;
				}
			}
		}
		else if (x == 4)
		{
			if (3 > 0)
			{
				if (4 > 0)
				{
					n = n + A_2_3;
				}
				n = n + A_2_4;
				if (4 < 9)
				{
					n = n + A_2_5;
				}
			}
			if (4 > 0)
			{
				n = n + A_3_3;
			}
			if (4 < 9)
			{
				n = n + A_3_5;
			}
			if (3 < 9)
			{
				if (4 > 0)
				{
					n = n + A_4_3;
				}
				n = n + A_4_4;
				if (4 < 9)
				{
					n = n + A_4_5;
				}
			}
		}
		else if (x == 5)
		{
			if (3 > 0)
			{
				if (5 > 0)
				{
					n = n + A_2_4;
				}
				n = n + A_2_5;
				if (5 < 9)
				{
					n = n + A_2_6;
				}
			}
			if (5 > 0)
			{
				n = n + A_3_4;
			}
			if (5 < 9)
			{
				n = n + A_3_6;
			}
			if (3 < 9)
			{
				if (5 > 0)
				{
					n = n + A_4_4;
				}
				n = n + A_4_5;
				if (5 < 9)
				{
					n = n + A_4_6;
				}
			}
		}
		else if (x == 6)
		{
			if (3 > 0)
			{
				if (6 > 0)
				{
					n = n + A_2_5;
				}
				n = n + A_2_6;
				if (6 < 9)
				{
					n = n + A_2_7;
				}
			}
			if (6 > 0)
			{
				n = n + A_3_5;
			}
			if (6 < 9)
			{
				n = n + A_3_7;
			}
			if (3 < 9)
			{
				if (6 > 0)
				{
					n = n + A_4_5;
				}
				n = n + A_4_6;
				if (6 < 9)
				{
					n = n + A_4_7;
				}
			}
		}
		else if (x == 7)
		{
			if (3 > 0)
			{
				if (7 > 0)
				{
					n = n + A_2_6;
				}
				n = n + A_2_7;
				if (7 < 9)
				{
					n = n + A_2_8;
				}
			}
			if (7 > 0)
			{
				n = n + A_3_6;
			}
			if (7 < 9)
			{
				n = n + A_3_8;
			}
			if (3 < 9)
			{
				if (7 > 0)
				{
					n = n + A_4_6;
				}
				n = n + A_4_7;
				if (7 < 9)
				{
					n = n + A_4_8;
				}
			}
		}
		else if (x == 8)
		{
			if (3 > 0)
			{
				if (8 > 0)
				{
					n = n + A_2_7;
				}
				n = n + A_2_8;
				if (8 < 9)
				{
					n = n + A_2_9;
				}
			}
			if (8 > 0)
			{
				n = n + A_3_7;
			}
			if (8 < 9)
			{
				n = n + A_3_9;
			}
			if (3 < 9)
			{
				if (8 > 0)
				{
					n = n + A_4_7;
				}
				n = n + A_4_8;
				if (8 < 9)
				{
					n = n + A_4_9;
				}
			}
		}
		else if (x == 9)
		{
			if (3 > 0)
			{
				if (9 > 0)
				{
					n = n + A_2_8;
				}
				n = n + A_2_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
			if (9 > 0)
			{
				n = n + A_3_8;
			}
			if (9 < 9)
			{
				n = n + not_there;
			}
			if (3 < 9)
			{
				if (9 > 0)
				{
					n = n + A_4_8;
				}
				n = n + A_4_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
		}
	}
	else if (y == 4)
	{
		if (x == 0)
		{
			if (4 > 0)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_3_0;
				if (0 < 9)
				{
					n = n + A_3_1;
				}
			}
			if (0 > 0)
			{
				n = n + not_there;
			}
			if (0 < 9)
			{
				n = n + A_4_1;
			}
			if (4 < 9)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_5_0;
				if (0 < 9)
				{
					n = n + A_5_1;
				}
			}
		}
		else if (x == 1)
		{
			if (4 > 0)
			{
				if (1 > 0)
				{
					n = n + A_3_0;
				}
				n = n + A_3_1;
				if (1 < 9)
				{
					n = n + A_3_2;
				}
			}
			if (1 > 0)
			{
				n = n + A_4_0;
			}
			if (1 < 9)
			{
				n = n + A_4_2;
			}
			if (4 < 9)
			{
				if (1 > 0)
				{
					n = n + A_5_0;
				}
				n = n + A_5_1;
				if (1 < 9)
				{
					n = n + A_5_2;
				}
			}
		}
		else if (x == 2)
		{
			if (4 > 0)
			{
				if (2 > 0)
				{
					n = n + A_3_1;
				}
				n = n + A_3_2;
				if (2 < 9)
				{
					n = n + A_3_3;
				}
			}
			if (2 > 0)
			{
				n = n + A_4_1;
			}
			if (2 < 9)
			{
				n = n + A_4_3;
			}
			if (4 < 9)
			{
				if (2 > 0)
				{
					n = n + A_5_1;
				}
				n = n + A_5_2;
				if (2 < 9)
				{
					n = n + A_5_3;
				}
			}
		}
		else if (x == 3)
		{
			if (4 > 0)
			{
				if (3 > 0)
				{
					n = n + A_3_2;
				}
				n = n + A_3_3;
				if (3 < 9)
				{
					n = n + A_3_4;
				}
			}
			if (3 > 0)
			{
				n = n + A_4_2;
			}
			if (3 < 9)
			{
				n = n + A_4_4;
			}
			if (4 < 9)
			{
				if (3 > 0)
				{
					n = n + A_5_2;
				}
				n = n + A_5_3;
				if (3 < 9)
				{
					n = n + A_5_4;
				}
			}
		}
		else if (x == 4)
		{
			if (4 > 0)
			{
				if (4 > 0)
				{
					n = n + A_3_3;
				}
				n = n + A_3_4;
				if (4 < 9)
				{
					n = n + A_3_5;
				}
			}
			if (4 > 0)
			{
				n = n + A_4_3;
			}
			if (4 < 9)
			{
				n = n + A_4_5;
			}
			if (4 < 9)
			{
				if (4 > 0)
				{
					n = n + A_5_3;
				}
				n = n + A_5_4;
				if (4 < 9)
				{
					n = n + A_5_5;
				}
			}
		}
		else if (x == 5)
		{
			if (4 > 0)
			{
				if (5 > 0)
				{
					n = n + A_3_4;
				}
				n = n + A_3_5;
				if (5 < 9)
				{
					n = n + A_3_6;
				}
			}
			if (5 > 0)
			{
				n = n + A_4_4;
			}
			if (5 < 9)
			{
				n = n + A_4_6;
			}
			if (4 < 9)
			{
				if (5 > 0)
				{
					n = n + A_5_4;
				}
				n = n + A_5_5;
				if (5 < 9)
				{
					n = n + A_5_6;
				}
			}
		}
		else if (x == 6)
		{
			if (4 > 0)
			{
				if (6 > 0)
				{
					n = n + A_3_5;
				}
				n = n + A_3_6;
				if (6 < 9)
				{
					n = n + A_3_7;
				}
			}
			if (6 > 0)
			{
				n = n + A_4_5;
			}
			if (6 < 9)
			{
				n = n + A_4_7;
			}
			if (4 < 9)
			{
				if (6 > 0)
				{
					n = n + A_5_5;
				}
				n = n + A_5_6;
				if (6 < 9)
				{
					n = n + A_5_7;
				}
			}
		}
		else if (x == 7)
		{
			if (4 > 0)
			{
				if (7 > 0)
				{
					n = n + A_3_6;
				}
				n = n + A_3_7;
				if (7 < 9)
				{
					n = n + A_3_8;
				}
			}
			if (7 > 0)
			{
				n = n + A_4_6;
			}
			if (7 < 9)
			{
				n = n + A_4_8;
			}
			if (4 < 9)
			{
				if (7 > 0)
				{
					n = n + A_5_6;
				}
				n = n + A_5_7;
				if (7 < 9)
				{
					n = n + A_5_8;
				}
			}
		}
		else if (x == 8)
		{
			if (4 > 0)
			{
				if (8 > 0)
				{
					n = n + A_3_7;
				}
				n = n + A_3_8;
				if (8 < 9)
				{
					n = n + A_3_9;
				}
			}
			if (8 > 0)
			{
				n = n + A_4_7;
			}
			if (8 < 9)
			{
				n = n + A_4_9;
			}
			if (4 < 9)
			{
				if (8 > 0)
				{
					n = n + A_5_7;
				}
				n = n + A_5_8;
				if (8 < 9)
				{
					n = n + A_5_9;
				}
			}
		}
		else if (x == 9)
		{
			if (4 > 0)
			{
				if (9 > 0)
				{
					n = n + A_3_8;
				}
				n = n + A_3_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
			if (9 > 0)
			{
				n = n + A_4_8;
			}
			if (9 < 9)
			{
				n = n + not_there;
			}
			if (4 < 9)
			{
				if (9 > 0)
				{
					n = n + A_5_8;
				}
				n = n + A_5_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
		}
	}
	else if (y == 5)
	{
		if (x == 0)
		{
			if (5 > 0)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_4_0;
				if (0 < 9)
				{
					n = n + A_4_1;
				}
			}
			if (0 > 0)
			{
				n = n + not_there;
			}
			if (0 < 9)
			{
				n = n + A_5_1;
			}
			if (5 < 9)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_6_0;
				if (0 < 9)
				{
					n = n + A_6_1;
				}
			}
		}
		else if (x == 1)
		{
			if (5 > 0)
			{
				if (1 > 0)
				{
					n = n + A_4_0;
				}
				n = n + A_4_1;
				if (1 < 9)
				{
					n = n + A_4_2;
				}
			}
			if (1 > 0)
			{
				n = n + A_5_0;
			}
			if (1 < 9)
			{
				n = n + A_5_2;
			}
			if (5 < 9)
			{
				if (1 > 0)
				{
					n = n + A_6_0;
				}
				n = n + A_6_1;
				if (1 < 9)
				{
					n = n + A_6_2;
				}
			}
		}
		else if (x == 2)
		{
			if (5 > 0)
			{
				if (2 > 0)
				{
					n = n + A_4_1;
				}
				n = n + A_4_2;
				if (2 < 9)
				{
					n = n + A_4_3;
				}
			}
			if (2 > 0)
			{
				n = n + A_5_1;
			}
			if (2 < 9)
			{
				n = n + A_5_3;
			}
			if (5 < 9)
			{
				if (2 > 0)
				{
					n = n + A_6_1;
				}
				n = n + A_6_2;
				if (2 < 9)
				{
					n = n + A_6_3;
				}
			}
		}
		else if (x == 3)
		{
			if (5 > 0)
			{
				if (3 > 0)
				{
					n = n + A_4_2;
				}
				n = n + A_4_3;
				if (3 < 9)
				{
					n = n + A_4_4;
				}
			}
			if (3 > 0)
			{
				n = n + A_5_2;
			}
			if (3 < 9)
			{
				n = n + A_5_4;
			}
			if (5 < 9)
			{
				if (3 > 0)
				{
					n = n + A_6_2;
				}
				n = n + A_6_3;
				if (3 < 9)
				{
					n = n + A_6_4;
				}
			}
		}
		else if (x == 4)
		{
			if (5 > 0)
			{
				if (4 > 0)
				{
					n = n + A_4_3;
				}
				n = n + A_4_4;
				if (4 < 9)
				{
					n = n + A_4_5;
				}
			}
			if (4 > 0)
			{
				n = n + A_5_3;
			}
			if (4 < 9)
			{
				n = n + A_5_5;
			}
			if (5 < 9)
			{
				if (4 > 0)
				{
					n = n + A_6_3;
				}
				n = n + A_6_4;
				if (4 < 9)
				{
					n = n + A_6_5;
				}
			}
		}
		else if (x == 5)
		{
			if (5 > 0)
			{
				if (5 > 0)
				{
					n = n + A_4_4;
				}
				n = n + A_4_5;
				if (5 < 9)
				{
					n = n + A_4_6;
				}
			}
			if (5 > 0)
			{
				n = n + A_5_4;
			}
			if (5 < 9)
			{
				n = n + A_5_6;
			}
			if (5 < 9)
			{
				if (5 > 0)
				{
					n = n + A_6_4;
				}
				n = n + A_6_5;
				if (5 < 9)
				{
					n = n + A_6_6;
				}
			}
		}
		else if (x == 6)
		{
			if (5 > 0)
			{
				if (6 > 0)
				{
					n = n + A_4_5;
				}
				n = n + A_4_6;
				if (6 < 9)
				{
					n = n + A_4_7;
				}
			}
			if (6 > 0)
			{
				n = n + A_5_5;
			}
			if (6 < 9)
			{
				n = n + A_5_7;
			}
			if (5 < 9)
			{
				if (6 > 0)
				{
					n = n + A_6_5;
				}
				n = n + A_6_6;
				if (6 < 9)
				{
					n = n + A_6_7;
				}
			}
		}
		else if (x == 7)
		{
			if (5 > 0)
			{
				if (7 > 0)
				{
					n = n + A_4_6;
				}
				n = n + A_4_7;
				if (7 < 9)
				{
					n = n + A_4_8;
				}
			}
			if (7 > 0)
			{
				n = n + A_5_6;
			}
			if (7 < 9)
			{
				n = n + A_5_8;
			}
			if (5 < 9)
			{
				if (7 > 0)
				{
					n = n + A_6_6;
				}
				n = n + A_6_7;
				if (7 < 9)
				{
					n = n + A_6_8;
				}
			}
		}
		else if (x == 8)
		{
			if (5 > 0)
			{
				if (8 > 0)
				{
					n = n + A_4_7;
				}
				n = n + A_4_8;
				if (8 < 9)
				{
					n = n + A_4_9;
				}
			}
			if (8 > 0)
			{
				n = n + A_5_7;
			}
			if (8 < 9)
			{
				n = n + A_5_9;
			}
			if (5 < 9)
			{
				if (8 > 0)
				{
					n = n + A_6_7;
				}
				n = n + A_6_8;
				if (8 < 9)
				{
					n = n + A_6_9;
				}
			}
		}
		else if (x == 9)
		{
			if (5 > 0)
			{
				if (9 > 0)
				{
					n = n + A_4_8;
				}
				n = n + A_4_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
			if (9 > 0)
			{
				n = n + A_5_8;
			}
			if (9 < 9)
			{
				n = n + not_there;
			}
			if (5 < 9)
			{
				if (9 > 0)
				{
					n = n + A_6_8;
				}
				n = n + A_6_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
		}
	}
	else if (y == 6)
	{
		if (x == 0)
		{
			if (6 > 0)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_5_0;
				if (0 < 9)
				{
					n = n + A_5_1;
				}
			}
			if (0 > 0)
			{
				n = n + not_there;
			}
			if (0 < 9)
			{
				n = n + A_6_1;
			}
			if (6 < 9)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_7_0;
				if (0 < 9)
				{
					n = n + A_7_1;
				}
			}
		}
		else if (x == 1)
		{
			if (6 > 0)
			{
				if (1 > 0)
				{
					n = n + A_5_0;
				}
				n = n + A_5_1;
				if (1 < 9)
				{
					n = n + A_5_2;
				}
			}
			if (1 > 0)
			{
				n = n + A_6_0;
			}
			if (1 < 9)
			{
				n = n + A_6_2;
			}
			if (6 < 9)
			{
				if (1 > 0)
				{
					n = n + A_7_0;
				}
				n = n + A_7_1;
				if (1 < 9)
				{
					n = n + A_7_2;
				}
			}
		}
		else if (x == 2)
		{
			if (6 > 0)
			{
				if (2 > 0)
				{
					n = n + A_5_1;
				}
				n = n + A_5_2;
				if (2 < 9)
				{
					n = n + A_5_3;
				}
			}
			if (2 > 0)
			{
				n = n + A_6_1;
			}
			if (2 < 9)
			{
				n = n + A_6_3;
			}
			if (6 < 9)
			{
				if (2 > 0)
				{
					n = n + A_7_1;
				}
				n = n + A_7_2;
				if (2 < 9)
				{
					n = n + A_7_3;
				}
			}
		}
		else if (x == 3)
		{
			if (6 > 0)
			{
				if (3 > 0)
				{
					n = n + A_5_2;
				}
				n = n + A_5_3;
				if (3 < 9)
				{
					n = n + A_5_4;
				}
			}
			if (3 > 0)
			{
				n = n + A_6_2;
			}
			if (3 < 9)
			{
				n = n + A_6_4;
			}
			if (6 < 9)
			{
				if (3 > 0)
				{
					n = n + A_7_2;
				}
				n = n + A_7_3;
				if (3 < 9)
				{
					n = n + A_7_4;
				}
			}
		}
		else if (x == 4)
		{
			if (6 > 0)
			{
				if (4 > 0)
				{
					n = n + A_5_3;
				}
				n = n + A_5_4;
				if (4 < 9)
				{
					n = n + A_5_5;
				}
			}
			if (4 > 0)
			{
				n = n + A_6_3;
			}
			if (4 < 9)
			{
				n = n + A_6_5;
			}
			if (6 < 9)
			{
				if (4 > 0)
				{
					n = n + A_7_3;
				}
				n = n + A_7_4;
				if (4 < 9)
				{
					n = n + A_7_5;
				}
			}
		}
		else if (x == 5)
		{
			if (6 > 0)
			{
				if (5 > 0)
				{
					n = n + A_5_4;
				}
				n = n + A_5_5;
				if (5 < 9)
				{
					n = n + A_5_6;
				}
			}
			if (5 > 0)
			{
				n = n + A_6_4;
			}
			if (5 < 9)
			{
				n = n + A_6_6;
			}
			if (6 < 9)
			{
				if (5 > 0)
				{
					n = n + A_7_4;
				}
				n = n + A_7_5;
				if (5 < 9)
				{
					n = n + A_7_6;
				}
			}
		}
		else if (x == 6)
		{
			if (6 > 0)
			{
				if (6 > 0)
				{
					n = n + A_5_5;
				}
				n = n + A_5_6;
				if (6 < 9)
				{
					n = n + A_5_7;
				}
			}
			if (6 > 0)
			{
				n = n + A_6_5;
			}
			if (6 < 9)
			{
				n = n + A_6_7;
			}
			if (6 < 9)
			{
				if (6 > 0)
				{
					n = n + A_7_5;
				}
				n = n + A_7_6;
				if (6 < 9)
				{
					n = n + A_7_7;
				}
			}
		}
		else if (x == 7)
		{
			if (6 > 0)
			{
				if (7 > 0)
				{
					n = n + A_5_6;
				}
				n = n + A_5_7;
				if (7 < 9)
				{
					n = n + A_5_8;
				}
			}
			if (7 > 0)
			{
				n = n + A_6_6;
			}
			if (7 < 9)
			{
				n = n + A_6_8;
			}
			if (6 < 9)
			{
				if (7 > 0)
				{
					n = n + A_7_6;
				}
				n = n + A_7_7;
				if (7 < 9)
				{
					n = n + A_7_8;
				}
			}
		}
		else if (x == 8)
		{
			if (6 > 0)
			{
				if (8 > 0)
				{
					n = n + A_5_7;
				}
				n = n + A_5_8;
				if (8 < 9)
				{
					n = n + A_5_9;
				}
			}
			if (8 > 0)
			{
				n = n + A_6_7;
			}
			if (8 < 9)
			{
				n = n + A_6_9;
			}
			if (6 < 9)
			{
				if (8 > 0)
				{
					n = n + A_7_7;
				}
				n = n + A_7_8;
				if (8 < 9)
				{
					n = n + A_7_9;
				}
			}
		}
		else if (x == 9)
		{
			if (6 > 0)
			{
				if (9 > 0)
				{
					n = n + A_5_8;
				}
				n = n + A_5_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
			if (9 > 0)
			{
				n = n + A_6_8;
			}
			if (9 < 9)
			{
				n = n + not_there;
			}
			if (6 < 9)
			{
				if (9 > 0)
				{
					n = n + A_7_8;
				}
				n = n + A_7_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
		}
	}
	else if (y == 7)
	{
		if (x == 0)
		{
			if (7 > 0)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_6_0;
				if (0 < 9)
				{
					n = n + A_6_1;
				}
			}
			if (0 > 0)
			{
				n = n + not_there;
			}
			if (0 < 9)
			{
				n = n + A_7_1;
			}
			if (7 < 9)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_8_0;
				if (0 < 9)
				{
					n = n + A_8_1;
				}
			}
		}
		else if (x == 1)
		{
			if (7 > 0)
			{
				if (1 > 0)
				{
					n = n + A_6_0;
				}
				n = n + A_6_1;
				if (1 < 9)
				{
					n = n + A_6_2;
				}
			}
			if (1 > 0)
			{
				n = n + A_7_0;
			}
			if (1 < 9)
			{
				n = n + A_7_2;
			}
			if (7 < 9)
			{
				if (1 > 0)
				{
					n = n + A_8_0;
				}
				n = n + A_8_1;
				if (1 < 9)
				{
					n = n + A_8_2;
				}
			}
		}
		else if (x == 2)
		{
			if (7 > 0)
			{
				if (2 > 0)
				{
					n = n + A_6_1;
				}
				n = n + A_6_2;
				if (2 < 9)
				{
					n = n + A_6_3;
				}
			}
			if (2 > 0)
			{
				n = n + A_7_1;
			}
			if (2 < 9)
			{
				n = n + A_7_3;
			}
			if (7 < 9)
			{
				if (2 > 0)
				{
					n = n + A_8_1;
				}
				n = n + A_8_2;
				if (2 < 9)
				{
					n = n + A_8_3;
				}
			}
		}
		else if (x == 3)
		{
			if (7 > 0)
			{
				if (3 > 0)
				{
					n = n + A_6_2;
				}
				n = n + A_6_3;
				if (3 < 9)
				{
					n = n + A_6_4;
				}
			}
			if (3 > 0)
			{
				n = n + A_7_2;
			}
			if (3 < 9)
			{
				n = n + A_7_4;
			}
			if (7 < 9)
			{
				if (3 > 0)
				{
					n = n + A_8_2;
				}
				n = n + A_8_3;
				if (3 < 9)
				{
					n = n + A_8_4;
				}
			}
		}
		else if (x == 4)
		{
			if (7 > 0)
			{
				if (4 > 0)
				{
					n = n + A_6_3;
				}
				n = n + A_6_4;
				if (4 < 9)
				{
					n = n + A_6_5;
				}
			}
			if (4 > 0)
			{
				n = n + A_7_3;
			}
			if (4 < 9)
			{
				n = n + A_7_5;
			}
			if (7 < 9)
			{
				if (4 > 0)
				{
					n = n + A_8_3;
				}
				n = n + A_8_4;
				if (4 < 9)
				{
					n = n + A_8_5;
				}
			}
		}
		else if (x == 5)
		{
			if (7 > 0)
			{
				if (5 > 0)
				{
					n = n + A_6_4;
				}
				n = n + A_6_5;
				if (5 < 9)
				{
					n = n + A_6_6;
				}
			}
			if (5 > 0)
			{
				n = n + A_7_4;
			}
			if (5 < 9)
			{
				n = n + A_7_6;
			}
			if (7 < 9)
			{
				if (5 > 0)
				{
					n = n + A_8_4;
				}
				n = n + A_8_5;
				if (5 < 9)
				{
					n = n + A_8_6;
				}
			}
		}
		else if (x == 6)
		{
			if (7 > 0)
			{
				if (6 > 0)
				{
					n = n + A_6_5;
				}
				n = n + A_6_6;
				if (6 < 9)
				{
					n = n + A_6_7;
				}
			}
			if (6 > 0)
			{
				n = n + A_7_5;
			}
			if (6 < 9)
			{
				n = n + A_7_7;
			}
			if (7 < 9)
			{
				if (6 > 0)
				{
					n = n + A_8_5;
				}
				n = n + A_8_6;
				if (6 < 9)
				{
					n = n + A_8_7;
				}
			}
		}
		else if (x == 7)
		{
			if (7 > 0)
			{
				if (7 > 0)
				{
					n = n + A_6_6;
				}
				n = n + A_6_7;
				if (7 < 9)
				{
					n = n + A_6_8;
				}
			}
			if (7 > 0)
			{
				n = n + A_7_6;
			}
			if (7 < 9)
			{
				n = n + A_7_8;
			}
			if (7 < 9)
			{
				if (7 > 0)
				{
					n = n + A_8_6;
				}
				n = n + A_8_7;
				if (7 < 9)
				{
					n = n + A_8_8;
				}
			}
		}
		else if (x == 8)
		{
			if (7 > 0)
			{
				if (8 > 0)
				{
					n = n + A_6_7;
				}
				n = n + A_6_8;
				if (8 < 9)
				{
					n = n + A_6_9;
				}
			}
			if (8 > 0)
			{
				n = n + A_7_7;
			}
			if (8 < 9)
			{
				n = n + A_7_9;
			}
			if (7 < 9)
			{
				if (8 > 0)
				{
					n = n + A_8_7;
				}
				n = n + A_8_8;
				if (8 < 9)
				{
					n = n + A_8_9;
				}
			}
		}
		else if (x == 9)
		{
			if (7 > 0)
			{
				if (9 > 0)
				{
					n = n + A_6_8;
				}
				n = n + A_6_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
			if (9 > 0)
			{
				n = n + A_7_8;
			}
			if (9 < 9)
			{
				n = n + not_there;
			}
			if (7 < 9)
			{
				if (9 > 0)
				{
					n = n + A_8_8;
				}
				n = n + A_8_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
		}
	}
	else if (y == 8)
	{
		if (x == 0)
		{
			if (8 > 0)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_7_0;
				if (0 < 9)
				{
					n = n + A_7_1;
				}
			}
			if (0 > 0)
			{
				n = n + not_there;
			}
			if (0 < 9)
			{
				n = n + A_8_1;
			}
			if (8 < 9)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_9_0;
				if (0 < 9)
				{
					n = n + A_9_1;
				}
			}
		}
		else if (x == 1)
		{
			if (8 > 0)
			{
				if (1 > 0)
				{
					n = n + A_7_0;
				}
				n = n + A_7_1;
				if (1 < 9)
				{
					n = n + A_7_2;
				}
			}
			if (1 > 0)
			{
				n = n + A_8_0;
			}
			if (1 < 9)
			{
				n = n + A_8_2;
			}
			if (8 < 9)
			{
				if (1 > 0)
				{
					n = n + A_9_0;
				}
				n = n + A_9_1;
				if (1 < 9)
				{
					n = n + A_9_2;
				}
			}
		}
		else if (x == 2)
		{
			if (8 > 0)
			{
				if (2 > 0)
				{
					n = n + A_7_1;
				}
				n = n + A_7_2;
				if (2 < 9)
				{
					n = n + A_7_3;
				}
			}
			if (2 > 0)
			{
				n = n + A_8_1;
			}
			if (2 < 9)
			{
				n = n + A_8_3;
			}
			if (8 < 9)
			{
				if (2 > 0)
				{
					n = n + A_9_1;
				}
				n = n + A_9_2;
				if (2 < 9)
				{
					n = n + A_9_3;
				}
			}
		}
		else if (x == 3)
		{
			if (8 > 0)
			{
				if (3 > 0)
				{
					n = n + A_7_2;
				}
				n = n + A_7_3;
				if (3 < 9)
				{
					n = n + A_7_4;
				}
			}
			if (3 > 0)
			{
				n = n + A_8_2;
			}
			if (3 < 9)
			{
				n = n + A_8_4;
			}
			if (8 < 9)
			{
				if (3 > 0)
				{
					n = n + A_9_2;
				}
				n = n + A_9_3;
				if (3 < 9)
				{
					n = n + A_9_4;
				}
			}
		}
		else if (x == 4)
		{
			if (8 > 0)
			{
				if (4 > 0)
				{
					n = n + A_7_3;
				}
				n = n + A_7_4;
				if (4 < 9)
				{
					n = n + A_7_5;
				}
			}
			if (4 > 0)
			{
				n = n + A_8_3;
			}
			if (4 < 9)
			{
				n = n + A_8_5;
			}
			if (8 < 9)
			{
				if (4 > 0)
				{
					n = n + A_9_3;
				}
				n = n + A_9_4;
				if (4 < 9)
				{
					n = n + A_9_5;
				}
			}
		}
		else if (x == 5)
		{
			if (8 > 0)
			{
				if (5 > 0)
				{
					n = n + A_7_4;
				}
				n = n + A_7_5;
				if (5 < 9)
				{
					n = n + A_7_6;
				}
			}
			if (5 > 0)
			{
				n = n + A_8_4;
			}
			if (5 < 9)
			{
				n = n + A_8_6;
			}
			if (8 < 9)
			{
				if (5 > 0)
				{
					n = n + A_9_4;
				}
				n = n + A_9_5;
				if (5 < 9)
				{
					n = n + A_9_6;
				}
			}
		}
		else if (x == 6)
		{
			if (8 > 0)
			{
				if (6 > 0)
				{
					n = n + A_7_5;
				}
				n = n + A_7_6;
				if (6 < 9)
				{
					n = n + A_7_7;
				}
			}
			if (6 > 0)
			{
				n = n + A_8_5;
			}
			if (6 < 9)
			{
				n = n + A_8_7;
			}
			if (8 < 9)
			{
				if (6 > 0)
				{
					n = n + A_9_5;
				}
				n = n + A_9_6;
				if (6 < 9)
				{
					n = n + A_9_7;
				}
			}
		}
		else if (x == 7)
		{
			if (8 > 0)
			{
				if (7 > 0)
				{
					n = n + A_7_6;
				}
				n = n + A_7_7;
				if (7 < 9)
				{
					n = n + A_7_8;
				}
			}
			if (7 > 0)
			{
				n = n + A_8_6;
			}
			if (7 < 9)
			{
				n = n + A_8_8;
			}
			if (8 < 9)
			{
				if (7 > 0)
				{
					n = n + A_9_6;
				}
				n = n + A_9_7;
				if (7 < 9)
				{
					n = n + A_9_8;
				}
			}
		}
		else if (x == 8)
		{
			if (8 > 0)
			{
				if (8 > 0)
				{
					n = n + A_7_7;
				}
				n = n + A_7_8;
				if (8 < 9)
				{
					n = n + A_7_9;
				}
			}
			if (8 > 0)
			{
				n = n + A_8_7;
			}
			if (8 < 9)
			{
				n = n + A_8_9;
			}
			if (8 < 9)
			{
				if (8 > 0)
				{
					n = n + A_9_7;
				}
				n = n + A_9_8;
				if (8 < 9)
				{
					n = n + A_9_9;
				}
			}
		}
		else if (x == 9)
		{
			if (8 > 0)
			{
				if (9 > 0)
				{
					n = n + A_7_8;
				}
				n = n + A_7_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
			if (9 > 0)
			{
				n = n + A_8_8;
			}
			if (9 < 9)
			{
				n = n + not_there;
			}
			if (8 < 9)
			{
				if (9 > 0)
				{
					n = n + A_9_8;
				}
				n = n + A_9_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
		}
	}
	else if (y == 9)
	{
		if (x == 0)
		{
			if (9 > 0)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + A_8_0;
				if (0 < 9)
				{
					n = n + A_8_1;
				}
			}
			if (0 > 0)
			{
				n = n + not_there;
			}
			if (0 < 9)
			{
				n = n + A_9_1;
			}
			if (9 < 9)
			{
				if (0 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (0 < 9)
				{
					n = n + not_there;
				}
			}
		}
		else if (x == 1)
		{
			if (9 > 0)
			{
				if (1 > 0)
				{
					n = n + A_8_0;
				}
				n = n + A_8_1;
				if (1 < 9)
				{
					n = n + A_8_2;
				}
			}
			if (1 > 0)
			{
				n = n + A_9_0;
			}
			if (1 < 9)
			{
				n = n + A_9_2;
			}
			if (9 < 9)
			{
				if (1 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (1 < 9)
				{
					n = n + not_there;
				}
			}
		}
		else if (x == 2)
		{
			if (9 > 0)
			{
				if (2 > 0)
				{
					n = n + A_8_1;
				}
				n = n + A_8_2;
				if (2 < 9)
				{
					n = n + A_8_3;
				}
			}
			if (2 > 0)
			{
				n = n + A_9_1;
			}
			if (2 < 9)
			{
				n = n + A_9_3;
			}
			if (9 < 9)
			{
				if (2 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (2 < 9)
				{
					n = n + not_there;
				}
			}
		}
		else if (x == 3)
		{
			if (9 > 0)
			{
				if (3 > 0)
				{
					n = n + A_8_2;
				}
				n = n + A_8_3;
				if (3 < 9)
				{
					n = n + A_8_4;
				}
			}
			if (3 > 0)
			{
				n = n + A_9_2;
			}
			if (3 < 9)
			{
				n = n + A_9_4;
			}
			if (9 < 9)
			{
				if (3 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (3 < 9)
				{
					n = n + not_there;
				}
			}
		}
		else if (x == 4)
		{
			if (9 > 0)
			{
				if (4 > 0)
				{
					n = n + A_8_3;
				}
				n = n + A_8_4;
				if (4 < 9)
				{
					n = n + A_8_5;
				}
			}
			if (4 > 0)
			{
				n = n + A_9_3;
			}
			if (4 < 9)
			{
				n = n + A_9_5;
			}
			if (9 < 9)
			{
				if (4 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (4 < 9)
				{
					n = n + not_there;
				}
			}
		}
		else if (x == 5)
		{
			if (9 > 0)
			{
				if (5 > 0)
				{
					n = n + A_8_4;
				}
				n = n + A_8_5;
				if (5 < 9)
				{
					n = n + A_8_6;
				}
			}
			if (5 > 0)
			{
				n = n + A_9_4;
			}
			if (5 < 9)
			{
				n = n + A_9_6;
			}
			if (9 < 9)
			{
				if (5 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (5 < 9)
				{
					n = n + not_there;
				}
			}
		}
		else if (x == 6)
		{
			if (9 > 0)
			{
				if (6 > 0)
				{
					n = n + A_8_5;
				}
				n = n + A_8_6;
				if (6 < 9)
				{
					n = n + A_8_7;
				}
			}
			if (6 > 0)
			{
				n = n + A_9_5;
			}
			if (6 < 9)
			{
				n = n + A_9_7;
			}
			if (9 < 9)
			{
				if (6 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (6 < 9)
				{
					n = n + not_there;
				}
			}
		}
		else if (x == 7)
		{
			if (9 > 0)
			{
				if (7 > 0)
				{
					n = n + A_8_6;
				}
				n = n + A_8_7;
				if (7 < 9)
				{
					n = n + A_8_8;
				}
			}
			if (7 > 0)
			{
				n = n + A_9_6;
			}
			if (7 < 9)
			{
				n = n + A_9_8;
			}
			if (9 < 9)
			{
				if (7 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (7 < 9)
				{
					n = n + not_there;
				}
			}
		}
		else if (x == 8)
		{
			if (9 > 0)
			{
				if (8 > 0)
				{
					n = n + A_8_7;
				}
				n = n + A_8_8;
				if (8 < 9)
				{
					n = n + A_8_9;
				}
			}
			if (8 > 0)
			{
				n = n + A_9_7;
			}
			if (8 < 9)
			{
				n = n + A_9_9;
			}
			if (9 < 9)
			{
				if (8 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (8 < 9)
				{
					n = n + not_there;
				}
			}
		}
		else if (x == 9)
		{
			if (9 > 0)
			{
				if (9 > 0)
				{
					n = n + A_8_8;
				}
				n = n + A_8_9;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
			if (9 > 0)
			{
				n = n + A_9_8;
			}
			if (9 < 9)
			{
				n = n + not_there;
			}
			if (9 < 9)
			{
				if (9 > 0)
				{
					n = n + not_there;
				}
				n = n + not_there;
				if (9 < 9)
				{
					n = n + not_there;
				}
			}
		}
	}
	return n;
}
void printboard(int gen)
{
	int i;
	int j;
	prints("Generation ");
	printi(gen);
	prints(":\n");
	i = 0;
	while (i <= 9)
	{
		if (i == 0)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					printi(A_0_0);
					prints(" ");
				}
				else if (j == 1)
				{
					printi(A_0_1);
					prints(" ");
				}
				else if (j == 2)
				{
					printi(A_0_2);
					prints(" ");
				}
				else if (j == 3)
				{
					printi(A_0_3);
					prints(" ");
				}
				else if (j == 4)
				{
					printi(A_0_4);
					prints(" ");
				}
				else if (j == 5)
				{
					printi(A_0_5);
					prints(" ");
				}
				else if (j == 6)
				{
					printi(A_0_6);
					prints(" ");
				}
				else if (j == 7)
				{
					printi(A_0_7);
					prints(" ");
				}
				else if (j == 8)
				{
					printi(A_0_8);
					prints(" ");
				}
				else if (j == 9)
				{
					printi(A_0_9);
					prints(" ");
				}
				j = j + 1;
			}
		}
		else if (i == 1)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					printi(A_1_0);
					prints(" ");
				}
				else if (j == 1)
				{
					printi(A_1_1);
					prints(" ");
				}
				else if (j == 2)
				{
					printi(A_1_2);
					prints(" ");
				}
				else if (j == 3)
				{
					printi(A_1_3);
					prints(" ");
				}
				else if (j == 4)
				{
					printi(A_1_4);
					prints(" ");
				}
				else if (j == 5)
				{
					printi(A_1_5);
					prints(" ");
				}
				else if (j == 6)
				{
					printi(A_1_6);
					prints(" ");
				}
				else if (j == 7)
				{
					printi(A_1_7);
					prints(" ");
				}
				else if (j == 8)
				{
					printi(A_1_8);
					prints(" ");
				}
				else if (j == 9)
				{
					printi(A_1_9);
					prints(" ");
				}
				j = j + 1;
			}
		}
		else if (i == 2)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					printi(A_2_0);
					prints(" ");
				}
				else if (j == 1)
				{
					printi(A_2_1);
					prints(" ");
				}
				else if (j == 2)
				{
					printi(A_2_2);
					prints(" ");
				}
				else if (j == 3)
				{
					printi(A_2_3);
					prints(" ");
				}
				else if (j == 4)
				{
					printi(A_2_4);
					prints(" ");
				}
				else if (j == 5)
				{
					printi(A_2_5);
					prints(" ");
				}
				else if (j == 6)
				{
					printi(A_2_6);
					prints(" ");
				}
				else if (j == 7)
				{
					printi(A_2_7);
					prints(" ");
				}
				else if (j == 8)
				{
					printi(A_2_8);
					prints(" ");
				}
				else if (j == 9)
				{
					printi(A_2_9);
					prints(" ");
				}
				j = j + 1;
			}
		}
		else if (i == 3)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					printi(A_3_0);
					prints(" ");
				}
				else if (j == 1)
				{
					printi(A_3_1);
					prints(" ");
				}
				else if (j == 2)
				{
					printi(A_3_2);
					prints(" ");
				}
				else if (j == 3)
				{
					printi(A_3_3);
					prints(" ");
				}
				else if (j == 4)
				{
					printi(A_3_4);
					prints(" ");
				}
				else if (j == 5)
				{
					printi(A_3_5);
					prints(" ");
				}
				else if (j == 6)
				{
					printi(A_3_6);
					prints(" ");
				}
				else if (j == 7)
				{
					printi(A_3_7);
					prints(" ");
				}
				else if (j == 8)
				{
					printi(A_3_8);
					prints(" ");
				}
				else if (j == 9)
				{
					printi(A_3_9);
					prints(" ");
				}
				j = j + 1;
			}
		}
		else if (i == 4)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					printi(A_4_0);
					prints(" ");
				}
				else if (j == 1)
				{
					printi(A_4_1);
					prints(" ");
				}
				else if (j == 2)
				{
					printi(A_4_2);
					prints(" ");
				}
				else if (j == 3)
				{
					printi(A_4_3);
					prints(" ");
				}
				else if (j == 4)
				{
					printi(A_4_4);
					prints(" ");
				}
				else if (j == 5)
				{
					printi(A_4_5);
					prints(" ");
				}
				else if (j == 6)
				{
					printi(A_4_6);
					prints(" ");
				}
				else if (j == 7)
				{
					printi(A_4_7);
					prints(" ");
				}
				else if (j == 8)
				{
					printi(A_4_8);
					prints(" ");
				}
				else if (j == 9)
				{
					printi(A_4_9);
					prints(" ");
				}
				j = j + 1;
			}
		}
		else if (i == 5)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					printi(A_5_0);
					prints(" ");
				}
				else if (j == 1)
				{
					printi(A_5_1);
					prints(" ");
				}
				else if (j == 2)
				{
					printi(A_5_2);
					prints(" ");
				}
				else if (j == 3)
				{
					printi(A_5_3);
					prints(" ");
				}
				else if (j == 4)
				{
					printi(A_5_4);
					prints(" ");
				}
				else if (j == 5)
				{
					printi(A_5_5);
					prints(" ");
				}
				else if (j == 6)
				{
					printi(A_5_6);
					prints(" ");
				}
				else if (j == 7)
				{
					printi(A_5_7);
					prints(" ");
				}
				else if (j == 8)
				{
					printi(A_5_8);
					prints(" ");
				}
				else if (j == 9)
				{
					printi(A_5_9);
					prints(" ");
				}
				j = j + 1;
			}
		}
		else if (i == 6)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					printi(A_6_0);
					prints(" ");
				}
				else if (j == 1)
				{
					printi(A_6_1);
					prints(" ");
				}
				else if (j == 2)
				{
					printi(A_6_2);
					prints(" ");
				}
				else if (j == 3)
				{
					printi(A_6_3);
					prints(" ");
				}
				else if (j == 4)
				{
					printi(A_6_4);
					prints(" ");
				}
				else if (j == 5)
				{
					printi(A_6_5);
					prints(" ");
				}
				else if (j == 6)
				{
					printi(A_6_6);
					prints(" ");
				}
				else if (j == 7)
				{
					printi(A_6_7);
					prints(" ");
				}
				else if (j == 8)
				{
					printi(A_6_8);
					prints(" ");
				}
				else if (j == 9)
				{
					printi(A_6_9);
					prints(" ");
				}
				j = j + 1;
			}
		}
		else if (i == 7)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					printi(A_7_0);
					prints(" ");
				}
				else if (j == 1)
				{
					printi(A_7_1);
					prints(" ");
				}
				else if (j == 2)
				{
					printi(A_7_2);
					prints(" ");
				}
				else if (j == 3)
				{
					printi(A_7_3);
					prints(" ");
				}
				else if (j == 4)
				{
					printi(A_7_4);
					prints(" ");
				}
				else if (j == 5)
				{
					printi(A_7_5);
					prints(" ");
				}
				else if (j == 6)
				{
					printi(A_7_6);
					prints(" ");
				}
				else if (j == 7)
				{
					printi(A_7_7);
					prints(" ");
				}
				else if (j == 8)
				{
					printi(A_7_8);
					prints(" ");
				}
				else if (j == 9)
				{
					printi(A_7_9);
					prints(" ");
				}
				j = j + 1;
			}
		}
		else if (i == 8)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					printi(A_8_0);
					prints(" ");
				}
				else if (j == 1)
				{
					printi(A_8_1);
					prints(" ");
				}
				else if (j == 2)
				{
					printi(A_8_2);
					prints(" ");
				}
				else if (j == 3)
				{
					printi(A_8_3);
					prints(" ");
				}
				else if (j == 4)
				{
					printi(A_8_4);
					prints(" ");
				}
				else if (j == 5)
				{
					printi(A_8_5);
					prints(" ");
				}
				else if (j == 6)
				{
					printi(A_8_6);
					prints(" ");
				}
				else if (j == 7)
				{
					printi(A_8_7);
					prints(" ");
				}
				else if (j == 8)
				{
					printi(A_8_8);
					prints(" ");
				}
				else if (j == 9)
				{
					printi(A_8_9);
					prints(" ");
				}
				j = j + 1;
			}
		}
		else if (i == 9)
		{
			j = 0;
			while (j <= 9)
			{
				if (j == 0)
				{
					printi(A_9_0);
					prints(" ");
				}
				else if (j == 1)
				{
					printi(A_9_1);
					prints(" ");
				}
				else if (j == 2)
				{
					printi(A_9_2);
					prints(" ");
				}
				else if (j == 3)
				{
					printi(A_9_3);
					prints(" ");
				}
				else if (j == 4)
				{
					printi(A_9_4);
					prints(" ");
				}
				else if (j == 5)
				{
					printi(A_9_5);
					prints(" ");
				}
				else if (j == 6)
				{
					printi(A_9_6);
					prints(" ");
				}
				else if (j == 7)
				{
					printi(A_9_7);
					prints(" ");
				}
				else if (j == 8)
				{
					printi(A_9_8);
					prints(" ");
				}
				else if (j == 9)
				{
					printi(A_9_9);
					prints(" ");
				}
				j = j + 1;
			}
		}
		prints("\n");
		i = i + 1;
	}
}
int morerandom()
{
	return INTERNALrandom() % 57;
	INTERNALrandom();
}

int INTERNALX;

void INTERNALseed(int seed)
{
	INTERNALX = seed;
}

//
//  Linear congruential method of generating pseudorandom
//  numbers, from Knuth's _The Art of Computer Programming, Volume 2:
//  Seminumerical Algorithms_, 3rd edition, Addison-Wesley, 1998.
//  Constants are chosen using Theorem A on page 17.
//
//  XXX - the period is long, but the lsb isn't random!
//
int INTERNALrandom()
{
	INTERNALX = (17 * INTERNALX + 13) % 32768;
	return INTERNALX;
}