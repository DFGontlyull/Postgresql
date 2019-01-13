# Postgresql 분석 및 Zigzag Join 추가용 프로젝트

*** tech03042의 postgresql-10.5 Reposit을 이어받음 ***


library dependencies
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
/usr/local/pgsql/bin/createdb test
/usr/local/pgsql/bin/psql test



