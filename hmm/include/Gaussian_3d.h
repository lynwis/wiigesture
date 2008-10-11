#ifndef GAUSSIAN_3D_H
#define GAUSSIAN_3D_H

#define MAX_ACC 4.0

#include <math.h>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>


class Gaussian_3d{

public:
    double mean[3];
    boost::numeric::ublas::matrix<double> cov;

    Gaussian_3d(bool rand=false) : cov(3,3) { if(rand) rand_init(); else zero_init(); };
    double pdf_3d(double* x);

private:
    double det_3d(boost::numeric::ublas::matrix<double> mat);
    void inv_3d(boost::numeric::ublas::matrix<double> mat, boost::numeric::ublas::matrix<double> &inv);
    void rand_init();
    void zero_init();
};

#endif // GAUSSIAN_3D_H
