SELECT FISH_INFO.ID, FISH_NAME_INFO.FISH_NAME, FISH_INFO.LENGTH
FROM FISH_INFO, FISH_NAME_INFO
WHERE FISH_INFO.FISH_TYPE = FISH_NAME_INFO.FISH_TYPE
AND (FISH_INFO.FISH_TYPE, FISH_INFO.LENGTH) IN (
                                                  SELECT FISH_TYPE, MAX(LENGTH)
                                                  FROM FISH_INFO
                                                  GROUP BY FISH_TYPE
                                                 )
ORDER BY FISH_INFO.ID;

-- 테이블1 INNER JOIN 테이블2 ~ ON 조인조건 = FROM 테이블1, 테이블2 WHERE 조인조건
