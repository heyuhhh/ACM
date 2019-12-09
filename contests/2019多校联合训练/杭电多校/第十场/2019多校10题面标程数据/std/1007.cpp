#include<bits/stdc++.h>
using namespace std;

typedef double db;

const int MAXN=10005;
const db eps=1e-9;

struct Point
{
    db x,y;
    Point():x(0.0),y(0.0) {}
    Point(db _x,db _y):x(_x),y(_y) {}
    Point operator + (const Point &t)const
    {
        return Point(x+t.x,y+t.y);
    }
    Point operator - (const Point &t)const
    {
        return Point(x-t.x,y-t.y);
    }
    Point operator * (const db &t)const
    {
        return Point(x*t,y*t);
    }
    Point operator / (const db &t)const
    {
        return Point(x/t,y/t);
    }
    db operator * (const Point &t)const
    {
        return x*t.y-y*t.x;
    }
    db operator ^ (const Point &t)const
    {
        return x*t.x+y*t.y;
    }
    bool operator < (const Point &t)const
    {
        return abs(x-t.x)<eps ? y<t.y : x<t.x;
    }
    db len()const
    {
        return sqrt(x*x+y*y);
    }
    Point norm()const
    {
        return (*this)/len();
    }
    void read()
    {
        int tx,ty;
        scanf("%d%d",&tx,&ty);
        x=tx,y=ty;
    }
};

struct Segment
{
    static db x;
    Point s,e;
    Segment() {}
    Segment(Point _s,Point _e):s(_s),e(_e) {}
    db dis(const Point &t)const
    {
        if(((t-s)^(e-s))<0)return (t-s).len();
        if(((t-e)^(s-e))<0)return (t-e).len();
        return abs((t-s)*(e-s).norm());
    }
    db dis(const Segment &t)const
    {
        return min({dis(t.s),dis(t.e),t.dis(s),t.dis(e)});
    }
    db get_y(const db &x)const
    {
        if(abs(s.x-e.x)<eps)return (s.y+e.y)/2;
        return (x-s.x)/(e.x-s.x)*(e.y-s.y)+s.y;
    }
    bool operator < (const Segment &t)const
    {
        return get_y(x)<t.get_y(x);
    }
    void read()
    {
        s.read(),e.read();
        if(e<s)swap(s,e);
    }
} seg[MAXN],sau[MAXN];
db Segment::x=0;

struct SauComparator
{
    bool operator() (const int &a,const int &b)
    {
        return a!=b ? sau[a]<sau[b] : false;
    }
};

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            seg[i].read();
        db l=0,r=3e9;
        while((r-l)/max(1.0,l)>1e-7)
        {
            db m=(l+r)/2;
            vector<pair<db,int>> event;
            for(int i=1; i<=n; i++)
            {
                sau[i].s=seg[i].s-Point(m/2,0);
                sau[i].e=seg[i].e+Point(m/2,0);
                event.push_back({sau[i].s.x,-i});
                event.push_back({sau[i].e.x,i});
            }
            sort(event.begin(),event.end());
            set<int,SauComparator> scanline;
            bool isok=true;
            for(int i=0;i<(int)event.size();i++)
            {
                Segment::x=event[i].first;
                int sid=event[i].second;
                if(sid<0)
                {
                    sid=-sid;
                    auto itr=scanline.lower_bound(sid);
                    if(itr!=scanline.end() && seg[sid].dis(seg[*itr])<m+eps)
                    {
                        isok=false;
                        break;
                    }
                    if(itr!=scanline.begin() && seg[sid].dis(seg[*--itr])<m+eps)
                    {
                        isok=false;
                        break;
                    }
                    scanline.insert(sid);
                }
                else
                {
                    scanline.erase(sid);
                    auto pre=scanline.lower_bound(sid);
                    if(pre!=scanline.begin() && pre!=scanline.end())
                    {
                        auto nxt=pre--;
                        if(seg[*pre].dis(seg[*nxt])<m+eps)
                        {
                            isok=false;
                            break;
                        }
                    }
                }
            }
            if(isok)l=m;
            else r=m;
        }
        double res=(l+r)/2;
        printf("%.12f\n",res);
    }
    return 0;
}
