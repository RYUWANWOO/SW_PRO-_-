//
// Created by WanU RYU on 2023/03/13.
#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point{
    int x;
    int y;

    bool operator < (const Point &b) const{
        if(x == b.x)
            return y <b.y;
        else
            return x < b.x;
    }
};


int distance(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y-b.y);
}

bool CompareY(Point a,Point b)
{
    return a.y < b.y;
}

int searchAll(vector<Point> &v,int s, int e)
{
    int minDist = -1;

    for(int i=s;i<=e-1;++i)
    {
        for(int j = i+1;j<=e;++j)
        {
            int dist = distance(v[i],v[j]);
            if(minDist == -1 || minDist > dist)
                minDist = dist;
        }
    }
    return minDist;
}


int searchPoint(vector<Point> &v,int start,int end)
{
    int count = end - start +1;
    if(count <= 2)
        return searchAll(v,start,end);

    int mid = (start + end) / 2;
    int left = searchPoint(v,start,mid);
    int right = searchPoint(v,mid+1,end);

    int answer;
    if(left > right)
        answer = right;
    else
        answer = left;

    vector<Point> final;
    for(int i=start;i<=end;++i)
    {
        int xDistance = v[i].x - v[mid].x;
        if(xDistance * xDistance < answer)
            final.push_back(v[i]);
    }

    size_t maxIndex = final.size();
    sort(final.begin(),final.end(), CompareY);

    for(int i=0;i< maxIndex-1 ;++i){
        for(int j=i+1;j<maxIndex;++j){
            int y = final[j].y - final[i].y;

            if(y*y < answer)
            {
                int dist = distance(final[j],final[i]);
                if(dist < answer)
                    answer = dist;
            }
            else
                break;
        }
    }
    return answer;
}




int main(int argc, char** argv)
{
    int test_case;
    int T;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    //freopen("input.txt", "r", stdin);
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {

        int N;
        cin >> N;
        vector<Point> points(N);
        for(int i=0;i<N;++i)
        {
            cin >> points[i].x >> points[i].y;
        }
        sort(points.begin(),points.end());

        int answer = searchPoint(points,0,N-1);

        cout << "#" << test_case << " " << answer << "\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}