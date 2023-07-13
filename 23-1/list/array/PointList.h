#ifndef __POINT_LIST_H__
#define __POINT_LIST_H__

#define TRUE	1
#define FALSE	0
#define LIST_LEN	100

/* PointList ADT */
typedef struct __Point {
    
    int x;
    int y;

} Point;

typedef struct __PointList {    // 배열 기반 리스트 구조체 정의
    
    Point arr[LIST_LEN]; // 저장소
    int numOfData;  // 데이터 수
    int curPosition;    // 현재 참조중인 위치

} PointList;

void setPoint(Point * p, int x, int y); // 포인트 초기화
void showPointInfo(Point * p);   // 포인트 정보 출력
int comparePoint(Point * p1, Point * p2); // 포인트 비교
void listInit(PointList * list);    // 리스트 초기화
void pInsert(PointList * list, Point data);   // 데이터 저장
int pFirst(PointList * list, Point * data);   // 첫 번째 데이터 참조
int pNext(PointList * list, Point * Data);    // 두 번째 데이터 이후 참조
Point Pdelete(PointList * list);  // 참조 데이터 삭제
int count(PointList * list);    // 데이터 수 반환 

#endif