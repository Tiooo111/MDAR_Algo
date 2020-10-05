#include <cmath>
#include <complex>

typedef std::complex<double> Comp;  // STL complex

const Comp I(0, 1);  // i
const int MAX_N = 1 << 20;

Comp tmp[MAX_N];

void DFT(Comp *f, int n, int rev) {  // rev=1,DFT; rev=-1,IDFT
  if (n == 1) return;
  for (int i = 0; i < n; ++i) tmp[i] = f[i];
  for (int i = 0; i < n; ++i) {  // 偶数放左边，奇数放右边
    if (i & 1)
      f[n / 2 + i / 2] = tmp[i];
    else
      f[i / 2] = tmp[i];
  }
  Comp *g = f, *h = f + n / 2;
  DFT(g, n / 2, rev), DFT(h, n / 2, rev);  // 递归 DFT
  Comp cur(1, 0), step(cos(2 * M_PI / n), sin(2 * M_PI * rev / n));
  // Comp step=exp(I*(2*M_PI/n*rev)); // 两个 step 定义是等价的
  for (int k = 0; k < n / 2; ++k) {
    tmp[k] = g[k] + cur * h[k];
    tmp[k + n / 2] = g[k] - cur * h[k];
    cur *= step;
  }
  for (int i = 0; i < n; ++i) f[i] = tmp[i];
}
int main()
{
	int n = read<int>();
	int m = read<int>();
	int A[n], B[n];
	for(int i = 0; i < n; ++i) A[i] = read<int>();
	for(int j = 0; j < m; ++j) B[j] = read<int>();
	int limit = 1; while(limit <= n + m) limit <<= 1;
	FFT(limit, a, 1);
	FFT(limit, b, 1);
	for(int i = 0; i <= limit; ++i) a[i] *= b[i];
	FFT(limit, a, -1);
	for(int i = 0; i <= n + m; ++i) 
	return 0;
}
