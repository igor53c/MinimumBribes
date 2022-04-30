// MinimumBribes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void minimumBribes(vector<int>);

int main()
{
	/*vector<int> v{ 2, 1, 5, 3, 4 };
	minimumBribes(v);

	vector<int> v1{ 2, 5, 1, 3, 4 };
	minimumBribes(v1);

	vector<int> v2{ 5, 1, 2, 3, 7, 8, 6, 4 };
	minimumBribes(v2);*/

	vector<int> v3{ 1, 2, 5, 3, 7, 8, 6, 4 };
	minimumBribes(v3);

	return EXIT_SUCCESS;
}

// sporija varijanta
// 
//void minimumBribes(vector<int> q) {
//
//	int b = 0;
//
//	vector<int> m;
//
//	m.push_back(q[q.size() - 1]);
//
//	for (int i = q.size() - 2; i >= 0; i--)
//	{
//		int t = 0;
//
//		for (int j = 0; j < m.size(); j++)
//		{
//			if (m[j] > q[i])
//			{	
//				m.insert(m.begin() + j, q[i]);
//			
//				break;
//			}
//				
//
//			if (j == m.size() - 1)
//			{
//				t++;
//
//				if (t > 2)
//				{
//					cout << "Too chaotic" << endl;
//					return;
//				}
//
//				m.push_back(q[i]);
//
//				break;
//			}
//
//			t++;
//
//			if (t > 2)
//			{
//				cout << "Too chaotic" << endl;
//				return;
//			}
//		}
//
//		b += t;
//	}
//
//	cout << b << endl;
//}

void minimumBribes(vector<int> q) {

	int b = 0;

	list<int> m;

	m.push_back(q[q.size() - 1]);

	for (int i = q.size() - 2; i >= 0; i--)
	{
		int t = 0;

		for (int j = 0; j < m.size(); j++)
		{
			auto it = m.begin();
			advance(it, j);

			if (*it > q[i])
			{
				m.insert(it, q[i]);

				break;
			}


			if (j == m.size() - 1)
			{
				t++;

				if (t > 2)
				{
					cout << "Too chaotic" << endl;
					return;
				}

				m.push_back(q[i]);

				break;
			}

			t++;

			if (t > 2)
			{
				cout << "Too chaotic" << endl;
				return;
			}
		}

		b += t;
	}

	cout << b << endl;
}
