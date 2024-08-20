SELECT A.ID, CASE
                WHEN A.PER <= 0.25 THEN 'CRITICAL'
                WHEN A.PER <= 0.5 THEN 'HIGH'
                WHEN A.PER <= 0.75 THEN 'MEDIUM'
                ELSE 'LOW'
             END AS COLONY_NAME
FROM (
    SELECT ID, PERCENT_RANK() OVER (ORDER BY SIZE_OF_COLONY DESC) AS PER
    FROM ECOLI_DATA
) AS A
ORDER BY A.ID

-- PERCENT_RANK() OVER 퍼센트 비율로 나눌 속성(입력 시 정렬식 자체를 넣는다) AS 대신 나타낼 레이블(속성) 명
-- 테이블에 속한 필드의 수에 맞춰 0 ~ 1 사이의 비율값을 할당
