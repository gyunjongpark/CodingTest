SELECT MEMBER_ID, MEMBER_NAME, GENDER, DATE_FORMAT(DATE_OF_BIRTH, '%Y-%m-%d') AS DATE_OF_BIRTH
FROM MEMBER_PROFILE
WHERE MONTH(DATE_OF_BIRTH) = 3
AND GENDER = 'W'
AND TLNO IS NOT NULL
ORDER BY MEMBER_ID;

-- MONTH(DATE 타입의 속성) : 속성에서 '월'만 추출. YEAR(DATE 타입의 속성), DAY(DATE 타입의 속성) ...
-- DATE : 날짜(y-m-d), DATETIME : 날짜 + 시간(y-m-d-h-m-s)

-- 속성 + IS NULL, IS NOT NULL