SELECT DR_NAME, DR_ID, MCDP_CD, DATE_FORMAT(HIRE_YMD, '%Y-%m-%d') AS HIRE_YMD
FROM DOCTOR
WHERE MCDP_CD IN ('CS', 'GS')
ORDER BY HIRE_YMD DESC, DR_NAME ASC;

/*
형식에 맞게 날짜 레이블 출력하기 : DATE_FORMAT(DATE 타입의 속성, '포맷 형식') AS 대신 나타낼 이름

행 데이터 = 투플 = 레코드 = row  = 인스턴스
속성 = 레이블, 속성(레이블) + 해당 속성의 값들 = 열 데이터 = column

스키마(내포) : 속성의 전체집합
인스턴스(외연) : 스키마를 기준으로 생성된 행 데이터

%Y-%M-%D, %Y-%m-%d ... 대소문자 구분
select date_format(now(),'%Y-%M-%D') AS date; -- 2024-August-25th
select date_format(now(),'%y-%m-%d') AS date; -- 24-08-25
*/
