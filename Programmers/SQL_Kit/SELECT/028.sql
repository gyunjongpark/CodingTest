SELECT ID, CASE
               WHEN SIZE_OF_COLONY <= 100 THEN 'LOW'
               WHEN SIZE_OF_COLONY <= 1000 THEN 'MEDIUM'
               ELSE 'HIGH'
           END SIZE
FROM ECOLI_DATA
ORDER BY ID;

/*
CASE
    WHEN 값을 비교하는 구문 THEN 값 대신 나타낼 문자 값
    .
    .
    ELSE 값 대신 나타낼 문자 값
END AS 대신 나타낼 레이블 명
*/
