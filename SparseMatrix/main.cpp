#include <vector>
#include <iostream>
#include <utility>
#include <map>

using namespace std;

class SparseMatrix
{
private:
    // hashtable container (key = (row,col), val = entry)
    map<pair<int, int>, double> matrix;

public:
    SparseMatrix( vector<vector<double>> & M)
    {
        for (int row = 0; row < M.size(); row++)
        {
            for (int col = 0; col < M.at(row).size(); col++)
            {
                if (M.at(row).at(col) != 0)
                {
                    matrix.insert(make_pair(pair<int, int>(row, col), M.at(row).at(col)));
                }
            }
        }
    }

    double getElement(const SparseMatrix& M, int row, int col)
    {
        map<pair<int,int>,double>::const_iterator indexPair = M.matrix.find(make_pair(row, col));
        if (indexPair != M.matrix.end())
        {
            return (*indexPair).second;
        }
        else
        {
            return 0;
        }
    }

    double static dot(const SparseMatrix &A, const SparseMatrix &B)
    {
        double dotProduct;
        for (auto itA = A.matrix.begin(); itA != A.matrix.end(); itA++)
        {
            auto itB = B.matrix.find((*itA).first);
            if (itB != B.matrix.end())
            {
                dotProduct = dotProduct += (*itA).second * (*itB).second;
            }
        }
        return dotProduct;
    }
};

int main()
{
    vector<vector<double>> vectA{{6, 2, 3}, {0, 1, 0}};
    vector<vector<double>> vectB{{1, 0, 1}, {0, 1, 0}};
    SparseMatrix matA = SparseMatrix(vectA);
    SparseMatrix matB = SparseMatrix(vectB);

    cout << SparseMatrix::dot(matA,matB) << endl;

}