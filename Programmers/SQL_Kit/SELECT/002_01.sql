SELECT DR_NAME, DR_ID, MCDP_CD, DATE_FORMAT(HIRE_YMD, '%Y-%m-%d') HIRE_YMD
FROM DOCTOR
WHERE MCDP_CD='CS' OR MCDP_CD='GS'
ORDER BY HIRE_YMD DESC, DR_NAME ASC;

-- 형식에 맞게 레이블 출력하기 : DATE_FORMAT(속성, '포멧 형식') AS 대신 나타낼 속성 명
-- %Y-%M-%D, %Y-%m-%d ... 대소문자 구분하기
-- 행 데이터 = 튜플 = 레코드 = row / 속성 = 레이블 / 필드 = 속성(레이블) + 데이터 = 열 데이터 = column