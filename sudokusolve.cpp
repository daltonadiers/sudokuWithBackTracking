#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <set>
#include <utility>
#include <map>
#include <chrono>

struct myStack_
{
    int i, j, valor;
};

namespace sdk
{
    class mySudo
    {
    public:
        mySudo() : backtrack_count(0){}

        void init()
        {
            std::cout << "Lendo arquivo e iniciando..." << std::endl
                      << std::endl;
            chargeData();
            std::cout << "Matriz inicial: " << std::endl;
            print();

            auto start_time = std::chrono::high_resolution_clock::now();

            initBackTracking();

            auto end_time = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_time = end_time - start_time;

            std::cout << "\nResolução: " << std::endl;
            print();

            std::cout << "\nNúmero de tentativas: " << backtrack_count << std::endl;

            std::cout << "Tempo de execução: " << elapsed_time.count() << " segundos" << std::endl;
        }

    private:
        int backtrack_count;
        int lastBackI, lastBackJ;
        std::map<std::pair<int, int>, std::set<int>> mapOfPairsToSets;
        std::stack<myStack_> mystack;
        int sudoTable[9][9];
        void chargeData()
        {
            std::ifstream tabela("sudoku.txt");
            int valor;
            int i = 0;
            int j = 0;
            while (tabela >> valor)
            {
                sudoTable[i][j] = valor;
                j++;
                if (j == 9)
                {
                    j = 0;
                    i++;
                }
                if (i == 9)
                    break;
            }
        }
        void print()
        {
            std::cout << std::endl
                      << "-------------------------" << std::endl;
            for (int i = 0; i < 9; i++)
            {
                std::cout << "| ";
                for (int j = 0; j < 9; j++)
                {
                    std::cout << sudoTable[i][j];
                    if (j == 2 || j == 5 || j == 8)
                    {
                        std::cout << " | ";
                    }
                    else
                    {
                        std::cout << " ";
                    }
                }
                if (i == 2 || i == 5 || i == 8)
                {
                    std::cout << std::endl
                              << "-------------------------";
                }
                std::cout << std::endl;
            }
        }
        bool verifiy(int n, int i, int j)
        {
            if (!verifyLine(n, i))
                return false;
            if (!verifyColumn(n, j))
                return false;
            if (!verifyBlock(n, i, j))
                return false;
            if (!verifySet(n, i, j))
                return false;
            return true;
        }
        bool verifySet(int n, int i, int j)
        {
            if (i == lastBackI && j == lastBackJ)
            {
                auto it = mapOfPairsToSets[std::make_pair(i, j)].find(n);
                if (it != mapOfPairsToSets[std::make_pair(i, j)].end())
                {
                    return false;
                }
                return true;
            }
            return true;
        }
        bool verifyLine(int n, int i)
        {
            for (int j = 0; j < 9; j++)
            {
                if (sudoTable[i][j] == n)
                    return false;
            }
            return true;
        }
        bool verifyColumn(int n, int j)
        {
            for (int i = 0; i < 9; i++)
            {
                if (sudoTable[i][j] == n)
                    return false;
            }
            return true;
        }
        bool verifyBlock(int n, int i, int j)
        {
            int minI, minJ;
            if (i <= 2)
                minI = 0;
            else if (i <= 5)
                minI = 3;
            else
                minI = 6;
            if (j <= 2)
                minJ = 0;
            else if (j <= 5)
                minJ = 3;
            else
                minJ = 6;
            for (int i_ = minI; i_ < minI + 3; i_++)
            {
                for (int j_ = minJ; j_ < minJ + 3; j_++)
                {
                    if (sudoTable[i_][j_] == n)
                        return false;
                }
            }
            return true;
        }
        void initBackTracking()
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (sudoTable[i][j] != 0)
                    {
                        continue;
                    }
                    else
                    {
                        if (i != lastBackI || j != lastBackJ)
                        {
                            mapOfPairsToSets[std::make_pair(i, j)].clear();
                        }
                        int myNumber = changeNumber(i, j);
                        if (myNumber == 20)
                        {
                            myStack_ m;
                            if (!mystack.empty())
                            {
                                m = mystack.top();
                                mystack.pop();
                                backtrack_count++;
                                i = m.i;
                                j = m.j;
                                lastBackI = i;
                                lastBackJ = j;
                                mapOfPairsToSets[std::make_pair(i, j)].insert(m.valor);
                                sudoTable[i][j] = 0;
                                i--;
                                j--;
                            }
                            else
                            {
                                std::cout << "Não há solução!" << std::endl;
                                return;
                            }
                        }
                        else
                        {
                            sudoTable[i][j] = myNumber;
                            mapOfPairsToSets[std::make_pair(i, j)].insert(myNumber);
                            myStack_ m;
                            m.i = i;
                            m.j = j;
                            m.valor = myNumber;
                            mystack.push(m);
                        }
                    }
                }
            }
        }
        int changeNumber(int i, int j)
        {
            for (int p = 1; p < 10; p++)
            {
                if (verifiy(p, i, j))
                    return p;
                else
                    mapOfPairsToSets[std::make_pair(i, j)].insert(p);
            }
            return 20;
        }
    };
}