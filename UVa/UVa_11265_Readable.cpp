#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#define EPS 1e-9
//#define imax(X, Y) X > Y ? X : Y
//#define imin(X, Y) X < Y ? X : Y

using namespace std;

typedef long long LL;

struct vec;
struct pt;
struct line;

struct vec
{
	double x, y;
	vec(){}
	vec(double _x, double _y): x(_x), y(_y){}
};

struct pt
{
	double x, y;
	pt(){}
	pt(double _x, double _y): x(_x), y(_y){}
	vec operator - (const pt &rhs)
	{
		vec tmp(x - rhs.x, y - rhs.y);
		return tmp;
	}
	line to_line();
	bool above(const line &);
};

struct line
{
	double a, b; // expressed as y = ax + b
	char v;
	static double inf;
	line(){}
	line(double _a, double _b, char _v = 0): a(_a), b(_b), v(_v){}
	pt to_pt()
	{
		pt tmp(a, -b);
		return tmp;
	}
};
double line::inf = 1e9;

bool pt::above(const line &l)
{
	return y > l.a * x + l.b + EPS;
}

line pt::to_line()
{
	line tmp(x, -y);
	return tmp;
}

double cross(const vec &a, const vec &b)
{
	return a.x * b.y - a.y * b.x;
}

bool pt_cmp(pt a, pt b)
{
	if (a.x != b.x)
		return a.x < b.x;
	else
		return a.y < b.y;
}

bool parallel(const line &a, const line &b)
{
	return abs(a.a - b.a) < EPS;
}

pt intersect(const line &a, const line &b)
{
	double x, y;
	// vertical
//	if (a.v)
//	{
//		x = a.a;
//		y = b.a * x + b.b;
//	}
//	else if (b.v)
//	{
//		x = b.a;
//		y = a.a * x + a.b;
//	}
//	else // both line not vertical
//	{
		// parallel
		if (a.a == b.a)
			return pt(line::inf, line::inf);
		x = (b.b - a.b) / (a.a - b.a);
		y = a.a * x + a.b;
//	}
	return pt(x, y);
}

vector<pt> monotone_half(vector<pt> &p, char rev = 0)
{
	const size_t &sz = p.size();
	vector<pt> ret;
	int *stk = new int[p.size() + 1];
	int i, t = 0;
	sort(p.begin(), p.end(), pt_cmp);
	if (!rev)
	{
		for (i = 0; i < sz; i++)
		{
			if (t < 2){ stk[++t] = i; continue; }
			while (t >= 2 && cross(p[i] - p[stk[t]], p[stk[t]] - p[stk[t-1]]) >= 0) --t;
			stk[++t] = i;
		}
	}
	else
	{
		for (i = sz - 1; i >= 0; i--)
		{
			if (t < 2){ stk[++t] = i; continue; }
			while (t >= 2 && cross(p[i] - p[stk[t]], p[stk[t]] - p[stk[t-1]]) >= 0) --t;
			stk[++t] = i;
		}
	}
	for (i = 1; i <= t; i++) ret.push_back(p[stk[i]]);
	delete [] stk;
	return ret;
}


vector<line> lns_l, lns_u;
vector<pt> pt_l, pt_u;
vector<LL> lns_v; // vertical lines
LL w, h;

int main()
{
	freopen("11265.in", "r", stdin);
	freopen("11265.txt", "w", stdout);
	int i, j, tt = 0, n;
	LL x1, y1, x2, y2;
	int it_l, it_u;
	double prev_dy, dy, nxt_x, ans;
	char st;
	pt ref;
	line tmp;
	while (scanf("%d%lld%lld", &n, &w, &h) == 3)
	{
		//		puts("-");
		it_l = it_u = 0;
		st = 0;
		ans = 0.0;
		lns_l.clear();
		lns_u.clear();
		lns_v.clear();
		pt_l.clear();
		pt_u.clear();
		scanf("%lf%lf", &ref.x, &ref.y);
		lns_l.push_back( line(0, 0) );
		lns_u.push_back( line(0, h) );
		lns_v.push_back( 0 );
		lns_v.push_back( w );
		for (i = 0; i < n; i++)
		{
			scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
			if (x1 == x2) // vertical line
				lns_v.push_back(x1);
			else
			{
				tmp = line(double(y2 - y1) / (x2 - x1), double(y2 * x1 - y1 * x2) / (x1 - x2));
				if (ref.above(tmp))
					lns_l.push_back(tmp);
				else
					lns_u.push_back(tmp);
			}
		}
		for (i = 0; i < lns_l.size(); i++)
			pt_l.push_back(lns_l[i].to_pt());
		for (i = 0; i < lns_u.size(); i++)
			pt_u.push_back(lns_u[i].to_pt());
		pt_l = monotone_half(pt_l, 0);
		pt_u = monotone_half(pt_u, 1);
		
		if (pt_l.size() >= 2 && pt_l[pt_l.size() - 1].x == pt_l[pt_l.size() - 2].x) pt_l.pop_back();
		if (pt_u.size() >= 2 && pt_u[pt_u.size() - 1].x == pt_u[pt_u.size() - 2].x) pt_u.pop_back();
		
		sort(lns_v.begin(), lns_v.end());
		int idx = upper_bound(lns_v.begin(), lns_v.end(), ref.x) - lns_v.begin();
		
		lns_l.clear();
		lns_u.clear();
		for (i = 0; i < pt_l.size(); i++) lns_l.push_back(pt_l[i].to_line());
		for (i = 0; i < pt_u.size(); i++) lns_u.push_back(pt_u[i].to_line());
		
		for (double x = lns_v[idx - 1]; x < lns_v[idx] - EPS; )
		{
			for ( ; it_l < lns_l.size() - 1; it_l++) if (intersect(lns_l[it_l], lns_l[it_l + 1]).x >= x) break;
			for ( ; it_u < lns_u.size() - 1; it_u++) if (intersect(lns_u[it_u], lns_u[it_u + 1]).x >= x) break;
			if (it_l >= lns_l.size() && it_u >= lns_u.size()) break;
			if (it_l < lns_l.size() && it_u < lns_u.size())
			{
				pt i_i = intersect(lns_l[it_l], lns_u[it_u]);
				pt i_l = it_l < lns_l.size() - 1 ? intersect(lns_l[it_l], lns_l[it_l + 1]) : pt(1e9, 1e9);
				pt i_u = it_u < lns_u.size() - 1 ? intersect(lns_u[it_u], lns_u[it_u + 1]) : pt(1e9, 1e9);
				if (st == 0 && i_i.x >= x && lns_u[it_u].a * x + lns_u[it_u].b - (lns_l[it_l].a * x + lns_l[it_l].b) >= 0.0) i_i = pt(-1e9, -1e9);
				if (st == 0 && i_i.x <= i_l.x && i_i.x <= i_u.x)
				{	
					nxt_x = max(x, i_i.x);
					dy = i_i.x <= x ? lns_u[it_u].a * x + lns_u[it_u].b - (lns_l[it_l].a * x + lns_l[it_l].b) : 0.0;
					st = 1;
					x = nxt_x; // not counting the first edge (the area between the previous edge and the first edge)
				}
				else if (i_i.x > x + EPS && i_i.x <= i_l.x && i_i.x <= i_u.x)
				{
					nxt_x = min(i_i.x, (double)lns_v[idx]);
					dy = i_i.x <= lns_v[idx] ? 0 : lns_u[it_u].a * lns_v[idx] + lns_u[it_u].b - (lns_l[it_l].a * lns_v[idx] + lns_l[it_l].b);
					st = 2;
				}
				else if (i_l.x <= i_u.x)
				{
					nxt_x = min(i_l.x, (double)lns_v[idx]);
					dy = lns_u[it_u].a * nxt_x + lns_u[it_u].b - (lns_l[it_l].a * nxt_x + lns_l[it_l].b);
					it_l++;
				}
				else // if (i_u.x <= i_l.x)
				{
					nxt_x = min(i_u.x, (double)lns_v[idx]);
					dy = lns_u[it_u].a * nxt_x + lns_u[it_u].b - (lns_l[it_l].a * nxt_x + lns_l[it_l].b);
					it_u++;
				}
			}
			if (st && dy < -EPS) break;
			
			if (st) ans += (dy + prev_dy) * (nxt_x - x) * 0.5;
			if (st == 2) break;
			prev_dy = dy;
			x = nxt_x;
		}
		//		puts("");
		printf("Case #%d: %.3f\n", ++tt, ans);
	}
	return 0;
}