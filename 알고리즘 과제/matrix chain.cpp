#include <iostream>
#include <vector>

#define MAX 200000000

using namespace std;

string str = "";
int n;
int k;

int matrix_chain(vector<int> &p, int n, int D)
{
    vector<vector<int>> m_table(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> s_table(n + 1, vector<int>(n + 1, 0));




    for (int i = 1; i <= n; i++)
    {
        s_table[i][i] = i;
    }


    for (int l = 2; l <= n; l++){
        {
            for (int i = 1; i <= n - l + 1; i++)
            {
                int j = i + l - 1;
                m_table[i][j] = MAX;

                for (int k = i; k < j; k++)
                {

                    int cost = m_table[i][k] + m_table[k + 1][j] + p[i - 1] * p[k] * p[j];


                    if (cost < m_table[i][j]){
                        m_table[i][j] = cost;

                    s_table[i][j] = ((s_table[i][k] * s_table[i][k]) + (s_table[k + 1][j] * s_table[k + 1][j])) % D;}
                }
            }
        }
    }

    k= s_table[1][n];

    return m_table[1][n];
}

int main()
{
    int TestCase;
    cin >> TestCase;

    while (TestCase--)
    {

        cin >> n;
        int D;
        cin >> D;

        vector<int> p(n + 1);

        for (int i = 0; i < n + 1; i++)
        {

            cin >> p[i];
        }

        int min_cost = matrix_chain(p, n, D);
        cout << min_cost << "\n";
        cout << k<< "\n";

        k= 0;
    }
}