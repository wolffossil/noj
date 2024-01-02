#include <stdio.h>
#include <math.h>

#define N 11
#define c 299792.458


double X[N],A[N],B[N],C[N],T[N];

void scanf1(double A[N],int n){
    for(int i=0;i<n;i++){
        scanf("%lf",&A[i]);
    }
}

void print1(double A[N],int n) { //输出一个矢量
	int i,tmp;
    double a;
	for (i=0; i<n-1; i++){
        tmp=(int)(A[i]*10000);
        a=(double)tmp/10000.0;
        printf("%.4lf,",a);
    }
    tmp=(int)(A[n-1]*10000);
    a=(double)tmp/10000.0;
    printf("%.4lf",a);
	
}

void print2(double A[N][N],int n) { //输出一个矩阵
	int i, j;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++)
			printf("%.7lf ", A[i][j]);
		printf("\n");
	}
}

// 计算代数余子式函数，结果=dest
int GetCoFactor(double dest[N][N], double src[N][N], int row, int col, int n)
{
	int i, j;
	int colCount=0,rowCount=0;
	for(i=0; i<n; i++ ) {
		if( i!=row ) {
			colCount = 0;
            for(j=0; j<n; j++ )
				if( j != col ) { //当j不是元素时
					dest[rowCount][colCount] = src[i][j];
					colCount++;
				}
			rowCount++;
		}
	}
	return 1;
}
 
// 递归计算行列式，结果=返回值
double CalcDeterminant(double mat[N][N], int n)
{
	int i,j;
	double det = 0; //行列式值
	double minor[N][N]; // allocate 余子式矩阵

    // n 必须 >= 0，当矩阵是单个元素时停止递归
	if( n == 1 ) return mat[0][0];
	for(i = 0; i < n; i++ ) {
		GetCoFactor(minor, mat, 0, i , n);
		det += ( i%2==1 ? -1.0 : 1.0 ) * mat[0][i] * CalcDeterminant(minor,n-1);
	}
	return det;
}
// 伴随矩阵法矩阵求逆 , 结果存放到 inv 数组
void MatrixInversion(double J[N][N], int n)
{
	int i,j;
    double det, temp [N][N], minor[N][N];
    double inv[N][N];
	
	det = 1.0/CalcDeterminant(J,n); //计算行列式
	for(j=0; j<n; j++)
		for(i=0; i<n; i++) {
			// 得到矩阵A(j,i)的代数余子式 
			GetCoFactor(minor,J,j,i,n);
			inv[i][j] = det*CalcDeterminant(minor,n-1);
			if( (i+j)%2 == 1)
				inv[i][j] = -inv[i][j];
		}
	//结果存回J矩阵
	for(j=0; j<n; j++)
		for(i=0; i<n; i++)
			J[i][j] = inv[i][j];
}

// 由Xn计算函数Fn，结果存放到 F
void CalcF(double F[N],double X[N],int n) {
	double f;
	int i;
	for (i=0; i<n; i++) {
		switch (i+1) {
			case 1: 
				f=X[0]*X[0]+X[1]*X[1]-2*X[0]-X[2]+1; //x^2+y^2-2x-z+1
				break;
			case 2: 
				f=X[0]*X[1]*X[1]-X[0]-3*X[1]+X[1]*X[2]+2; //xy^2-x-3y+yz+2
				break;
			case 3: 
				f=X[0]*X[2]*X[2]-3*X[2]+X[1]*X[2]*X[2]+X[0]*X[1]; //xz^2-3z+yz^2+xy
				break;
		}
		F[i]=f;
	}
}

void CalcF_re(double F[N],double X[N],int n) {
	double f;
	int i;
	for (i=0; i<n; i++) {
		switch (i+1) {
			case 1: 
				f=(X[0]-A[0])*(X[0]-A[0])+(X[1]-B[0])*(X[1]-B[0])+(X[2]-C[0])*(X[2]-C[0])-(c*(T[0]-X[3]))*(c*(T[0]-X[3])); 
				break;
			case 2: 
				f=(X[0]-A[1])*(X[0]-A[1])+(X[1]-B[1])*(X[1]-B[1])+(X[2]-C[1])*(X[2]-C[1])-(c*(T[1]-X[3]))*(c*(T[1]-X[3])); 
				break;
			case 3: 
				f=(X[0]-A[2])*(X[0]-A[2])+(X[1]-B[2])*(X[1]-B[2])+(X[2]-C[2])*(X[2]-C[2])-(c*(T[2]-X[3]))*(c*(T[2]-X[3])); 
                break;
            case 4: 
				f=(X[0]-A[3])*(X[0]-A[3])+(X[1]-B[3])*(X[1]-B[3])+(X[2]-C[3])*(X[2]-C[3])-(c*(T[3]-X[3]))*(c*(T[3]-X[3])); 
		}
		F[i]=f;
	}
}

// 由Xn计算偏导数Jacobian矩阵F'n，结果存放到 J
void CalcJ(double J[N][N],double X[N],int n) {
	double f;
	int i,j;
	for (i=0; i<n; i++)
		switch (i+1) {
			case 1:
				for (j=0; j<n; j++) {
					switch (j+1) {
						case 1: f=2*X[0]-2;break; // J1.1=2x-2
						case 2: f=2*X[1];break; // J1.2=2y
						case 3: f=-1;break;  // J1.3=-1
					}
					J[i][j]=f;
				}
				break;
			case 2:
				for (j=0; j<n; j++) {
					switch (j+1) {
						case 1: f=X[1]*X[1]-1;break; // J2.1=y^2-1
						case 2: f=2*X[0]*X[1]-3+X[2];break; // J2.2=2xy-3+z
						case 3: f=X[1];break; // J2.3=y
					}
					J[i][j]=f;
				}
				break;
			case 3:
				for (j=0; j<n; j++) {
					switch (j+1) {
						case 1: f=X[2]*X[2]+X[1];break; // J3.1=z^2+y
						case 2: f=X[2]*X[2]+X[0];break; // J3.2=z^2+x
						case 3: f=2*X[0]*X[2]-3+2*X[1]*X[2];break; // J3.3=2xz-3+2yz
					}
					J[i][j]=f;
				}
				break;								
		}
}

// 由Xn计算偏导数Jacobian矩阵F'n，结果存放到 J
void CalcJ_re(double J[N][N],double X[N],int n) {
	double f;
	int i,j;
	for (i=0; i<n; i++)
		switch (i+1) {
			case 1:
				for (j=0; j<n; j++) {
					switch (j+1) {
						case 1: f=2*(X[0]-A[0]);break; // J1.1=2(x-A1)
						case 2: f=2*(X[1]-B[0]);break; // J1.2=2(y-B1)
						case 3: f=2*(X[2]-C[0]);break;  // J1.3=2(z-C1)
                        case 4: f=2*c*c*(T[0]-X[3]);break;//J1.4=2*c^2(t1-d)
					}
					J[i][j]=f;
				}
				break;
			case 2:
				for (j=0; j<n; j++) {
					switch (j+1) {
						case 1: f=2*(X[0]-A[1]);break; // J1.1=2(x-A1)
						case 2: f=2*(X[1]-B[1]);break; // J1.2=2(y-B1)
						case 3: f=2*(X[2]-C[1]);break;  // J1.3=2(z-C1)
                        case 4: f=2*c*c*(T[1]-X[3]);break;//J1.4=2*c^2(t1-d)
					}
					J[i][j]=f;
				}
				break;
			case 3:
				for (j=0; j<n; j++) {
					switch (j+1) {
						case 1: f=2*(X[0]-A[2]);break; // J1.1=2(x-A1)
						case 2: f=2*(X[1]-B[2]);break; // J1.2=2(y-B1)
						case 3: f=2*(X[2]-C[2]);break;  // J1.3=2(z-C1)
                        case 4: f=2*c*c*(T[2]-X[3]);break;//J1.4=2*c^2(t1-d)
					}
					J[i][j]=f;
				}
				break;
            case 4:
				for (j=0; j<n; j++) {
					switch (j+1) {
						case 1: f=2*(X[0]-A[3]);break; // J1.1=2(x-A1)
						case 2: f=2*(X[1]-B[3]);break; // J1.2=2(y-B1)
						case 3: f=2*(X[2]-C[3]);break;  // J1.3=2(z-C1)
                        case 4: f=2*c*c*(T[3]-X[3]);break;//J1.4=2*c^2(t1-d)
					}
					J[i][j]=f;
				}
				break;									
		}
}

// 计算 J^-1* F，结果存放到 R
void CalcJF(double R[N], double J[N][N], double F[N], int n) {
	int i,j,k;
	for (i=0; i<n; i++) {
		R[i]=0.0;
		for (j=0; j<n; j++)
			R[i] = R[i] + J[i][j]*F[j];
	}
}

// 计算 X=X0-R，结果存放到 X
void CalcX(double X[N],double X0[N],double R[N],int n) {
	int i;
	for (i=0; i<n; i++)
		X[i]=X0[i]-R[i];
}

// 计算 A=B，结果存放到 A
void AequB(double A[N],double B[N],int n) {
	int i;
	for (i=0; i<n; i++)
		A[i]=B[i];
}

// 计算 F-
double Ferror(double F[N], int n) {
	double m=0;
	int i;
	for (i=0; i<n; i++) {
		double t=fabs(F[i]);
		if (m<t) m = t;
	}
	return m;
}

// Newton–Raphson method 牛顿迭代法求非线性方程组的根，存放到X0
void mvNewtons(double X0[N], int n, double e) {
	// Guess为初始猜测值 e为迭代精度要求
	int k;
	double J[N][N],Y[N][N];
	double X[N],R[N],F[N];
	//X0一开始为初始猜测值
	for (k=1; k<=20; k++) { //限定20次迭代
        /*
		printf("-------------- n=%d\n",k);
		printf("X\n");
		print1(X0,n); //输出X0
        */
		CalcF_re(F,X0,n); //计算F矩阵
        /*
		printf("F\n"); //观察 F
		print1(F,n); //输出F
        */
		CalcJ_re(J,X0,n); //计算Jacobian矩阵F'n(x0)
        /*
		printf("J\n");
		print2(J,n); //观察 J
        */
		MatrixInversion(J, n); // 求J的逆矩阵 J^-1
		CalcJF(R,J,F,n); // R=J^-1 * F
		CalcX(X,X0,R,n); // X=X0-R
		AequB(X0,X,n); // X0=X 下次迭代
		if (Ferror(F,n)<e) break; //达到精度要求，终止迭代
	}
}

int main() {
	int n=4;
    scanf("%lf %lf %lf",&A[0],&B[0],&C[0]);
    scanf("%lf %lf %lf",&A[1],&B[1],&C[1]);
    scanf("%lf %lf %lf",&A[2],&B[2],&C[2]);
    scanf("%lf %lf %lf",&A[3],&B[3],&C[3]);
    scanf1(T,n);
    scanf1(X,n);
	mvNewtons(X,n,1e-6); //根存放在X
    print1(X,3);
	return 0;
}

/*
15600 7540 20140
18760 2750 18610
17610 14630 13480
19170 610 18390
0.07074 0.07220 0.07690 0.07242
0 0 6370 0
*/