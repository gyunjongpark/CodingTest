SELECT PT_NAME, PT_NO, GEND_CD, AGE, IFNULL(TLNO, 'NONE') AS TLNO
FROM PATIENT
WHERE AGE <= 12
AND GEND_CD = 'W'
ORDER BY AGE DESC, PT_NAME ASC;

-- IFNULL(속성, '해당 속성값이 NULL일 경우 대체할 값') AS 대신 나타낼 이름
