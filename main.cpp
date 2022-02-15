#include <fstream>

using namespace std;

int nr_mijloc(int nr){
    int a, b, c;
    c = nr%10;
    nr = nr/10;

    b = nr%10;
    nr = nr/10;

    a = nr%10;

    return a;
}


int main()
{
    int r, r_2, cmmc_r, cmmnr, cmmnr_r, castig_m, castig_i, castig_r, castig, pr_I;

    ifstream fi("joc.in");
    ofstream fe("joc.out");

    cmmnr = 0;

    fi >> r;

    r_2 = r;

    for (int x, mij_m, mij_i, i, m; r>=0; r-=1){
        fi >> i >> m;
        mij_i = nr_mijloc(i);
        mij_m = nr_mijloc(m);
        if (mij_m > mij_i) {
            cmmc_r = mij_m;
            cmmnr_r = m;
            castig_m += 1;
            castig_r = 2;
        }
        else{cmmc_r = mij_m;
             cmmnr_r = i;
             castig_i += 1;
             castig_r = 1;
        }

        if (cmmnr_r > cmmnr) {
                cmmnr = cmmnr_r;
                if (cmmnr_r == i) castig = 1;
                else castig = 2;
        }
    }

    if (castig_i > castig_m) pr_I = 1;
    else pr_I = 2;

    fe << cmmnr << endl << pr_I << endl << castig;

    return 0;
}
