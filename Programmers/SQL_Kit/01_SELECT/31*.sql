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

-- PERCENT_RANK() OVER (ORDER BY 퍼센트 비율로 나눌 속성 ASC OR DESC) AS 대신 나타낼 레이블(속성) 명
-- 필드 데이터 길이에 따른 0 ~ 1 사이의 비율값을 할당
