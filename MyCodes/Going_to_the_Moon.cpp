//بِسْمِ ٱللَّهِ ٱلرَّحْمَـٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define fr(v,p,q) for(int v=p;p<=q?v<=q:v>=q;p<=q?v+=1:v-=1)
#define shwp(p) for(auto &v:p){cout<<v.first<<" "<<v.second<<"\n";}
#define shw(v) for(auto &v1:v){cout<<v1<<" ";}nl;
#define UNIQUE(a) (a).erase(unique(all(a)),(a).end())
#define sci(x) scanf("%d", &x)
#define linf (1ll << 62)
#define inf (1 << 30)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl cout << "\n"
#define all(p) (p).begin(),(p).end()
#define mx(_a) *max_element(all(_a))
#define mn(_a) *min_element(all(_a))
#define ll long long
#define vpii vector<pair<int,int> >
#define vpll vector<pair<ll,ll> >
#define vpic vector<pair<int,char> >

const double PI = 3.141592653589793238462643383279502884197169399375105;

double calcX(double centerX, double radius, double angle) {
    return centerX + radius * cos(angle * PI / 180.0);
}

double calcY(double centerY, double radius, double angle) {
    return centerY + radius * sin(angle * PI / 180.0);
}

double distance(double x, double y, double centerX, double centerY) {
    double distance = hypot(x - centerX, y - centerY);
    return distance;
}

bool isPointInCircle(double x, double y, double centerX, double centerY, double radius) {
    double dis = distance(x, y, centerX, centerY);
    return dis <= radius;
}

double distancePointToLine(double xA, double yA, double xB, double yB, double xC, double yC) {
    double A = yB - yA;
    double B = xA - xB;
    double C = xB * yA - xA * yB;

    double distance = abs(A * xC + B * yC + C) / sqrt(A * A + B * B);
    return distance;
}

double searchWithinCircle(double xA, double yA, double xB, double yB, double centerX, double centerY, double radius) {
    double circumference = 2 * PI * radius;
    vector<pair<double, double> > me;
    double x, y, r, l;
    r = 270;
    l = 0;
    x = calcX(centerX, radius, r);
    y = calcY(centerY, radius, r);
    me.push_back({ (distance(xA, yA, x, y) + distance(xB, yB, x, y)),r });
    x = calcX(centerX, radius, 2 * (r + l) / 3);
    y = calcY(centerY, radius, 2 * (r + l) / 3);
    me.push_back({ (distance(xA, yA, x, y) + distance(xB, yB, x, y)),2 * (r + l) / 3 });
    x = calcX(centerX, radius, (r + l) / 3);
    y = calcY(centerY, radius, (r + l) / 3);
    me.push_back({ (distance(xA, yA, x, y) + distance(xB, yB, x, y)),(r + l) / 3 });
    x = calcX(centerX, radius, l);
    y = calcY(centerY, radius, l);
    me.push_back({ (distance(xA, yA, x, y) + distance(xB, yB, x, y)),l });
    sort(all(me));

    if (me[0].second == 0 && me[1].second == 270) {
        me[0].second = 360;
    }
    else if (me[1].second == 0 && me[0].second == 270) {
        me[1].second = 360;
    }
    while (abs(me[0].second - me[1].second) >= 1e-6)
    {
        me[2].first = me[0].first;
        me[2].second = me[0].second;
        r = me[0].second;
        l = me[1].second;
        x = calcX(centerX, radius, min(r, l) + abs(r - l) / 2);
        y = calcY(centerY, radius, min(r, l) + abs(r - l) / 2);
        me[0].first = (distance(xA, yA, x, y) + distance(xB, yB, x, y));
        me[0].second = min(r, l) + abs(r - l) / 2;
        sort(all(me));
    }
    double k = me[0].first;
    return k;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        double xA, yA, xB, yB, xC, yC, r;
        cin >> xA >> yA >> xB >> yB >> xC >> yC >> r;

        if (isPointInCircle(xA, yA, xC, yC, r) || isPointInCircle(xB, yB, xC, yC, r) || distancePointToLine(xA, yA, xB, yB, xC, yC) < r) {
            cout << distance(xA, yA, xB, yB) << endl;
        }
        else {
            cout << searchWithinCircle(xA, yA, xB, yB, xC, yC, r) << endl;
        }
    }
}