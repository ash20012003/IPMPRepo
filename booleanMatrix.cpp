#define R 3
#define C 4

void modifyMatrix(bool mat[R][C]) {
    vector<int> ilist;
    vector<int> jlist;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (mat[i][j] == 1) {
                ilist.push_back(i);
                jlist.push_back(j);
            }
        }
    }
    for (int i = 0; i < ilist.size(); i++) {
        for (int j = 0; j < C; j++) mat[ilist[i]][j] = 1;
    }
    for (int i = 0; i < jlist.size(); i++) {
        for (int j = 0; j < R; j++) mat[j][jlist[i]] = 1;
    }
}

void modifyMatrixAlt(int mat[R][C])
{
    // variables to check if there are any 1
    // in first row and column
    bool row_flag = false;
    bool col_flag = false;

    // updating the first row and col if 1
    // is encountered
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i == 0 && mat[i][j] == 1)
                row_flag = true;

            if (j == 0 && mat[i][j] == 1)
                col_flag = true;

            if (mat[i][j] == 1) {

                mat[0][j] = 1;
                mat[i][0] = 1;
            }
        }
    }

    // Modify the input matrix mat[] using the
    // first row and first column of Matrix mat
    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {

            if (mat[0][j] == 1 || mat[i][0] == 1) {
                mat[i][j] = 1;
            }
        }
    }

    // modify first row if there was any 1
    if (row_flag == true) {
        for (int i = 0; i < C; i++) {
            mat[0][i] = 1;
        }
    }

    // modify first col if there was any 1
    if (col_flag == true) {
        for (int i = 0; i < R; i++) {
            mat[i][0] = 1;
        }
    }
}
