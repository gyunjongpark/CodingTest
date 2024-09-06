SELECT ID, CASE
               WHEN SIZE_OF_COLONY <= 100 THEN 'LOW'
               WHEN SIZE_OF_COLONY <= 1000 THEN 'MEDIUM'
               ELSE 'HIGH'
           END AS SIZE
FROM ECOLI_DATA
ORDER BY ID;

/*
CASE
    WHEN 값을 비교하는 구문 THEN '대신 나타낼 값'
    WHEN 값을 비교하는 구문 THEN '대신 나타낼 값'
    .
    .
    ELSE '대신 나타낼 값'
END AS 대신 나타낼 속성명(이름)

C++에서의 switch - case문과 동일한 기능을 가진다
CASE - END 문이 하나의 속성이 된다
*/
