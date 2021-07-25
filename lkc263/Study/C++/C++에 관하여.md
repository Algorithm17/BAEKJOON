![fill](https://user-images.githubusercontent.com/72541544/126607050-e3399aa0-4faf-4de3-8dba-0ff13708b465.png)



* 입출력 방법에 따른 속도 정리

```c++
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```



# Queue

**1) 정의**

FIFO(First In First Out, 선입선출) 자료구조

**2) 용도**

(1) BFS

(2) 특별한 알고리즘을 사용하는 것이 아니라 직접 문제 상황을 구현하는 문제들 중 FIFO의 구조를 문제를 풀때

**3) 사용법**

```c++
queue q;
q.size(); // q의 사이즈(물리적 저장 용량이 아닌 원소의 개수)
q.empty(); // q의 사이즈가 0인지 아닌지를 확인
q.front(); // q에 가장 먼저 들어간 원소를 리턴
q.back(); // q에 가장 나중에 들어간 원소를 리턴
q.push(val); // q의 뒤에 val 추가
q.pop(); // q에 가장 먼저 들어간 원소를 삭제
```

**중요한 내용**

```c++
queue q, emt;
swap(q, emt);
```

swap 함수 : queue에는 clear() 멤버 함수가 없으므로 swap이라는 함수를 이용해 clear() 하고자 하는 queue를 빈 queue와 swap해줌으로써 clear()와 같은 효과를 낼 수 있다.

***key point***

- swap을 이용하는 것이 queue가 빌 때까지 원소를 pop()하는 것보다 빠르다.



### pair

STL 컨테이너 : pair, vector

1) 정의

이름이 'first', 'second'인 두 개의 변수를 저장할 수 있는 struct이다.

2) 용도

(1) 이차원 배열의 인덱스

(2) 이차원 좌표평면에서의 좌표

(3) 정점 번호와 해당 정점 번호까지의 최단거리를 묶어서 저장해야 되는 경우

3) 사용법

pair를 사용하기 위해서는 <utility>를 include해야 한다.

pair는 다른 컨테이너들에 비해 간단한 구조이기 때문에 멤버 함수가 적다.

```c++
// pair 선언
pair<int, int> p;
pair<char, double> p;

// pair 생성
int a = 1, b = 2;
pair<int, int> p = make_pair(a,b);
pair<int, int> p = make_pair(1,2);

// pair의 멤버 변수에 접군
int valA = p.first;
int valB = p.second;


priority_queue<pair<int, pair<int, int> > >pq; //count, x, y;
		
pq.push({0, {startx, starty}});
// pair을 묶을 때는 중괄호로 묶는다.



```

first가 1이고 second가 2인 pair를 만들기 위해, make_pair를 이용해 바로 만들 수 있다.





### vector

**1) 정의**

사이즈가 유동적인 배열

**2) 용도**

배열을 사용하는 모든 경우

**3) 사용법**

```c++
v.size(); // v의 사이즈
v.resize(new_size); // v를 new_size로 사이즈를 바꿔준다.
v.empty(); // v의 사이즈가 0인지 아닌지를 확인
v.begin(); // v의 마지막 원소를 가리키는 iterator 리턴
v.end(); // v의 마지막 원소를 가리키는 iterator 리턴
v.front(); // v의 0번째 원소를 리턴
v.back(); // v의 마지막 원소를 리턴
v.push_back(val); // v의 끝에 val을 추가
v.pop_back(); // v의 마지막 원소를 삭제
v.clear(); // v의 모든 원소를 삭제
```

<algorithm>에 있는 reverse()를 이용하면, vector에 속한 원소들의 순서를 거꾸로 뒤집을 수가 있다.

<algorithm>에 있는 sort()를 이용하면, vector에 속한 원소들을 오름차순으로 정렬할 수 있다.

sort(v.begin(), v.end());

```c++
vector<int> iv;
vector<pair<int,int>> pv;
 
//사이즈가 3인 vector 생성
vector<int> myv(3);
 
//사이즈가 N(5)이고, 각 원소가 2로 초기화된 vector 생성
int N = 5;
vector<int> myv(N, 2);

//vector에 원소 추가
iv.push_back(1);                 // iv : 1
iv.push_back(2);                 // iv : 1 2
iv.push_back(3);                 // iv : 1 2 3
 
pv.push_back(make_pair(2,4));
 
//vector의 size 조정
iv.resize(4);
cout << iv.size();                // 4
 
cout << iv.front();               // 1
cout << iv.back();                // 0 (resize를 4로 했기 때문에 마지막 원소는 자동적으로 0으로 초기화됨)
 
iv.pop_back();                    // iv : 1 2 
iv.clear();                       // iv : 
```









참고자료 : https://ok4u.tistory.com/82

참고자료 : https://twpower.github.io/121-usage-of-fill-function
