# Postgresql 분석 및 Zigzag Join 추가용 프로젝트

*** 본 프로젝트는 tech03042의 postgresql-10.5 Reposit을 이어받음 ***


## library dependencies
```
sudo apt-get install libreadline-dev zlib1g-dev flex bison
- libreadline-dev zlib1g-dev : 압축 및 입출력 라이브러리 ( 필수 )
- flex, bsion : parser code 생성 라이브러리 ( 옵션 )

wget https://ftp.postgresql.org/pub/source/v10.5/postgresql-10.5.tar.gz
# 원본 소스, 해당 부분은 이 GitHub 프로젝트로 변경될 수 있음.
tar -xzvf postgresql-10.5.tar.gz

./configure # Build 환경 설정
make -j8 # Build
su # Root 권한 취득
make install # Build된 결과를 바탕으로 시스템에 설치
adduser postgres # 시스템에 postgres 유저 추가
mkdir /usr/local/pgsql/data # data 디덱터리 생성
chown postgres /usr/local/pgsql/data # postgres( DBMS 운영 유저 ) 에게 데이터 폴더 권한 양도
su - postgres # postgres 유저로 콘솔 권한 변경
/usr/local/pgsql/bin/initdb -D /usr/local/pgsql/data
/usr/local/pgsql/bin/postgres -D /usr/local/pgsql/data >logfile 2>&1 &
/usr/local/pgsql/bin/createdb postgres
/usr/local/pgsql/bin/psql postgres
```


### 목표 구절
```
select * from *A* zigzag join *B* ON *A*.id = *B*.id
// 현재 ERROR:  unrecognized node type: 143 발생 ( execExpr.c 에서 T_ZigzagJoin에 대한 동작이 정의되어 있지 않아서 발생하는 문제 )
```


### 완료 작업
- ~ zigzag join ~ on ~ Parser 조건 추가
- 쿼리 트리 생성에서 기존 Merge Join과 동일한 Cost를 가지지만, 작업은 T_ZigzagJoin으로 생성 완료


### 작업 우선 순위
- T_ZigzagJoin 일 경우 execExpr.c에서 적절한 동작을 수행
- nodeMergejoin.c 를 Copy 하여 새롭게 Customizing이 가능한 영역 생성
- 조인의 각 옵션별 해당되는 State 선별
- 내부적인 Loop를 Control 하는 새로운 Flag 생성
